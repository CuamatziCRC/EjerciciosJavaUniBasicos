// Suposiciones:
	// - El barbero corta el pelo fuera del objeto protegido
	//   Si lo cortara dentro, seria menos realista la simulacion
	//   del tiempo en que se tarda en hacer esta operacion. Si
	//   no se hace este retardo, es decir si el tiempo de corte
	//   de pelo fuera practicamente 0, no habria casi nunca
	//   procesos esperando.
	// - Se simula la silla del barbero y las sillas de la sala
	//   de espera.
import java.util.concurrent.*;

class barberia {
	
	private int nSillasEspera;
	private int nSillasEsperaOcupadas = 0;
	private boolean sillaBarberoOcupada = false;
	private boolean finCorte = false;
	private boolean barberoDormido = false;
	
	//JAVA: sólo puede haber N_Sillas_Espera_max hebras 
	//esperando dentro del monitor a que le toque.

	  public barberia(int nSillasEspera) {
		  this.nSillasEspera = nSillasEspera;
	  }
	
	  public synchronized boolean entrar(int clienteId)
	      throws InterruptedException {
		  
	   if (nSillasEsperaOcupadas == nSillasEspera) {
		   // Si no hay sillas libres, me voy sin cortar el pelo
			System.out.println
				("---- El cliente " + clienteId + " se va sin cortarse el pelo");
		   return false; }
	   else { 
		   //Me quedo esperando si la silla del barbero está
		   //ocupada
		   nSillasEsperaOcupadas ++;
  		   
		   if (sillaBarberoOcupada) System.out.println
  		   		("---- El cliente " + clienteId + " se sienta en la silla de espera");
		   
  		   while (sillaBarberoOcupada) {wait();}
	
		   //Desocupo la silla de espera 
		   nSillasEsperaOcupadas --;

		   //Me siento en la silla del barbero 
		   sillaBarberoOcupada = true;
		   finCorte = false;
		   
		   //Si el barbero está dormido le despierto
		   if (barberoDormido) {
			   System.out.println
			   	("---- El cliente " + clienteId + " despierta al barbero");
			   notifyAll();}
		   
		   //Espero a que me corte el pelo
		   System.out.println
		   	    ("---- El cliente " + clienteId + " en la silla de barbero");
		   while (!finCorte) {wait();}
		   
		   sillaBarberoOcupada = false;

		   //Que pase el siguiente
		   notifyAll();
		   
		   System.out.println
		       ("---- El cliente " + clienteId + " se va con el pelo cortado");
		   return true;
	   }

	  }

	   public synchronized void esperarCliente()
	      throws InterruptedException {

		   //El barbero espera a que llegue un cliente
		   //Se supone que le corta el pelo fuera del 
		   //monitor
		   barberoDormido = true;
		   while(!sillaBarberoOcupada || finCorte) {
			   System.out.println("++++ Barbero esperando cliente");
			   wait();
			   }
		   barberoDormido = false;		   
		   System.out.println("++++ Barbero cortando el pelo");
	   }
	   
	   public synchronized void acabarCorte(){
		   finCorte = true;
		   System.out.println("++++ Barbero termina de cortar el pelo");
		   notifyAll();
	   }

}


class barbero extends Thread{

	private barberia laBarberia;
	
	public barbero(barberia laBarberia) {
		this.laBarberia = laBarberia;
	}
	
	public void run(){
		
	while (true) {
		
		try {
			laBarberia.esperarCliente();
			//Cortar pelo
			Thread.sleep(5000);
			laBarberia.acabarCorte();
			//Decansa un poco
			Thread.sleep(1000);
		} catch (InterruptedException e){};
	}

	}
}

 class cliente extends java.lang.Thread {
	
	private barberia laBarberia;
	private int clienteId;
	private boolean cortePelo = false;
	
	public cliente(barberia laBarberia, int clienteId){
		this.laBarberia = laBarberia;
		this.clienteId  = clienteId;
	}
	
	public void run(){
		
		while (true) {
		
			try{
				Thread.sleep(2000);
				cortePelo = laBarberia.entrar(clienteId);
				//Cortar pelo
				if (cortePelo){
					//Espero hasta que me crezca el pelo
					Thread.sleep(25000);
				}
				else {
					//Espero y lo vuelvo a intentar
					Thread.sleep(4000);
				}
			} catch (InterruptedException e){};
		}
	}
}

public class laBarberia {


	public static void main(String[] args) {
		
		final int nSillas     = 4;
		final int nClientes   = 10;
		barberia  laBarberia  = new barberia(nSillas);
		barbero   elBarbero   = new barbero(laBarberia);
		cliente[] losClientes = new cliente[10];
		
		elBarbero.start();
		
		for (int i = 0; i < nClientes; i++ ) {
			losClientes[i] = new cliente(laBarberia, i);
			losClientes[i].start();
		}
	}
}
