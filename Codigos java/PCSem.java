import java.util.concurrent.Semaphore;

class Productor extends Thread{
	Buffer buf;
	private final String letras="abcdefghijklmnopqrstuvxyz";
	public Productor(Buffer b){
		buf=b;
	}
	
	public void run(){
		for(;;){
			char c=letras.charAt((int)(Math.random()*letras.length()));
			buf.poner(c);
			System.out.println(buf.cima+" Productor: " +c);
	/*		try{
            	sleep(100);
        	}catch (InterruptedException e) { }*/
		}
	}
}


class Consumidor extends Thread{
	Buffer buf;
	char valor;
	public Consumidor(Buffer b){
		buf=b;
	}
	
	public void run(){
		for(;;){
		//	try{
        //    	sleep(600);
       // 	}catch (InterruptedException e) { }
			valor=buf.tomar();
			int cim=buf.cima;
			System.out.println(cim+":"+buf.cima+" Consumidor: " +valor);
		
		}
	}
}


class Buffer{
	int cima;
	Semaphore s=new Semaphore(1);
	Semaphore s2=new Semaphore(0);
	Semaphore turno=new Semaphore(1);
	private char[] arreglo;
	public Buffer(int i){
		arreglo=new char[i];
	}
	
	public void poner(char elem){
		while (cima==arreglo.length-1)
			try {
				turno.acquire();
				s.acquire();
				
			} catch (InterruptedException e){}
			arreglo[cima]=elem;
			cima++;
			s2.release();
		///	s.release();
			turno.release();
	}

	public char tomar(){
		while (cima == 0)
			try {
				s2.acquire();
				turno.acquire();
			
			} catch (InterruptedException e){}
			s.release();
			turno.release();
			return arreglo[--cima];
	}
}

public class PCSem {
  public static void main(String[] args) {
    Buffer b=new Buffer(5);
    Productor p=new Productor(b);
    Consumidor c=new Consumidor(b);
    p.start();
    c.start();
  }
}