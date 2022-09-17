import java.util.concurrent.Semaphore;

class Hilos extends Thread{
	
	static int n=10;
	static Semaphore s1=new Semaphore(n);
	static Semaphore s2=new Semaphore(0);
	static Semaphore s3=new Semaphore(0);
	static int cont=0;
	
	
	public Hilos(String nombre){
		super(nombre);
	}
	
	
	public void run(){
		
		if(currentThread().getName().equals("A"))
			for(int i=0;i<n;i++){
				s1.release();
				System.out.print("A");
			}
		if(currentThread().getName().equals("B"))
			for(int i=0;i<n;i++)
			System.out.print("B");
		if(currentThread().getName().equals("C"))
			for(int i=0;i<n;i++)
			System.out.print("C");
	}
	
	
}

class ABC{
	public static void main(String[] args){
		Hilos a=new Hilos("A");
		Hilos b=new Hilos("B");
		Hilos c=new Hilos("C");
		
		a.start();
		b.start();
		c.start();
	}
}