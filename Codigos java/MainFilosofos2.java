
import java.util.*;
import java.util.concurrent.Semaphore;


class Tenedor extends Semaphore
   {
   	int id;
   	public Tenedor(int id, int valor)
   	  {
   	   super(valor);
   	   this.id=id;
   	  }
   	public int getId()
   	  {
   	   return id;
   	  }
   }

class Filosofo extends Thread
   {
    int quienSoy;
    Tenedor tenedorIzq, tenedorDer;
    Semaphore cont;
    int numeroOperaciones=10;

    public Filosofo(int quienSoy, Semaphore cont, Tenedor tenedorIzq, Tenedor tenedorDer)
       {
       	this.quienSoy=quienSoy;
       	this.cont=cont;
   	    this.tenedorIzq=tenedorIzq;
   	    this.tenedorDer=tenedorDer;
       }

    public void run()
       {
       	for(int i=0;i<numeroOperaciones;i++)
       	   {
       	   	try{
         	   	System.out.println("Filosofo "+quienSoy+" pensando...");
                sleep((int)((Math.random()*3000)+1));
         	   	cont.acquire();
        	   	tenedorDer.acquire();
        	   	tenedorIzq.acquire();
        	    System.out.println("Filosofo "+quienSoy+" COMIENDO...MMM "+"Tenedor Izq: "+tenedorIzq.getId()+" Tenedor Der: "+tenedorDer.getId());
        	    sleep((int)((Math.random()*1000)+1));
        	    tenedorDer.release();
       	    	tenedorIzq.release();
       	    	cont.release();
       	   	}catch(InterruptedException e){}
       	   }
       }
   }


public class MainFilosofos2
    {
     public static void main(String args[])
        {
         int totalFilosofos=5;
         Filosofo monjes[]=new Filosofo[totalFilosofos]; //se crea un arreglo para 5 filosofos
         Tenedor [] cubiertos = new Tenedor[totalFilosofos]; //se crean 5 tenedores (semaforos binarios)
         Semaphore cnt = new Semaphore(totalFilosofos-1); //se crea una mesa para cuatro filosofos (semaforo)

         for (int i=0;i<totalFilosofos;i++)  // se crean 5 tenedores
         	cubiertos[i]=new Tenedor(i,1);

         for (int i=0;i<totalFilosofos;i++)  // se crean los 5 filosofos
            {
             monjes[i]=new Filosofo(i,cnt,cubiertos[i],cubiertos[(i+1)%totalFilosofos]);
             monjes[i].start();
            }
         for (int i=0;i<totalFilosofos;i++)
            {
             try{

             monjes[i].join();
             }catch(Exception e){}
            }
        }
    }
