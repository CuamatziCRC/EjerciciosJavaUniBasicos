import java.awt.Color;
import java.awt.Frame;
import java.awt.Graphics;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.util.Scanner;

class piramide extends Frame
{
	public piramide()
	{
		super( "Lados" );
        setSize( 1000, 1000 );
         setVisible( true );
    }
    
    public void paint(Graphics g)
    {
    	super.paint( g );  // llamar al método paint de la superclase   
    	Scanner lerr=new Scanner(System.in);
    	int op=0;
    	double x[] = {400.0, 550.0, 400.0, 550.0, 450.0};
        double y[] = {450.0, 450.0, 350.0, 350.0, 400.0};
        double z[] = {-100.0, -100.0, -100.0, -100.0, -400.0}; 
        double xp[] = new double[5];
        double yp[] = new double[5];
         int[ ] x1 = new int[5];
        int[ ] y1 = new int[5];
        int[ ] z1 = new int[5];
        
        
        double xx5[] = {120.0, 180.0, 230.0, 190.0, 115.0, 180.0};
        double yy5[] = {135.0, 160.0, 120.0, 70.0, 95.0, 200.0};
        double zz5[] = {-100.0, -100.0, -100.0, -100.0, -100.0, -400.0}; 
        double xp5[] = new double[6];
        double yp5[] = new double[6];  
        int[ ] x5 = new int[6];
        int[ ] y5 = new int[6];
        int[ ] z5 = new int[6];
        
        
       	double xx3[] = {200.0, 350.0, 200.0, 350.0};
        double yy3[] = {250.0, 250.0, 150.0, 350.0};
        double zz3[] = {-120.0, -150.0, -120.0, -300.0}; 
         double xp3[] = new double[4];
        double yp3[] = new double[4];    
        int[ ] x3 = new int[4];
        int[ ] y3 = new int[4];
        int[ ] z3 = new int[4];
        
        
        double xc, yc, zc, traslada, escala, angulo=0;
        double fx[] = {220.0, 280.0, 310.0, 280.0, 220.0, 190.0, 250.0};
        double fy[] = {440.0, 440.0, 380.0, 320.0, 320.0, 380.0, 380.0};
        double fz[] = {-30.0, -30.0, -30.0, -30.0, -30.0, -30.0, -150.0};
        double fxp[] = new double[7];
        double fyp[] = new double[7];
          int[ ] fx1 = new int[7];
        int[ ] fy1 = new int[7];
        int[ ] fz1 = new int[7];
       
        double fxc, fyc, fzc;
        
         do
        {
        //	System.out.println("1.- 4 Lados");
          //  System.out.println("2.- 6 Lados");
          //   System.out.println("3.- 3 lados");
           //     System.out.println("5.- 5 lados");
            System.out.println(" 1 para salir");
            System.out.print("2 para iniciar.... ");
            op = lerr.nextInt();
           
//***************************************************************************************************************************************************************
            
           
//***************************************************************************************************************************************************
          
            
            
//****************************************************************************************************************************************            
            	//PIRAMIDE 6 LADOS
            
            		int op2=0;
            		 
                     System.out.print("Obsevardor x: ");
                     fxc = lerr.nextDouble();
                     System.out.print("Obsevardor y: ");
                     fyc = lerr.nextDouble();
                     System.out.print("Obsevardor z: ");
                     fzc = lerr.nextDouble();
                     
                     g.setColor(Color.magenta);
                     g.drawLine(x1[0],y1[0],x1[1],y1[1]);
                     g.drawLine(x1[0],y1[0],x1[2],y1[2]);
                     g.drawLine(x1[0],y1[0],x1[4],y1[4]);
                     g.drawLine(x1[4],y1[4],x1[1],y1[1]);
                     g.drawLine(x1[4],y1[4],x1[2],y1[2]);
                     g.drawLine(x1[4],y1[4],x1[3],y1[3]);
                     g.drawLine(x1[2],y1[2],x1[3],y1[3]);
                     g.drawLine(x1[1],y1[1],x1[3],y1[3]);
                     g.drawLine(fx1[0], fy1[0], fx1[1], fy1[1]);
                     g.drawLine(fx1[1], fy1[1], fx1[2], fy1[2]);
                     g.drawLine(fx1[2], fy1[2], fx1[3], fy1[3]);
                     g.drawLine(fx1[3], fy1[3], fx1[4], fy1[4]);
                     g.drawLine(fx1[4], fy1[4], fx1[5], fy1[5]);
                     g.drawLine(fx1[5], fy1[5], fx1[0], fy1[0]);
                     g.drawLine(fx1[0], fy1[0], fx1[6], fy1[6]);
                     g.drawLine(fx1[1], fy1[1], fx1[6], fy1[6]);
                     g.drawLine(fx1[2], fy1[2], fx1[6], fy1[6]); 
                     g.drawLine(fx1[3], fy1[3], fx1[6], fy1[6]);
                     g.drawLine(fx1[4], fy1[4], fx1[6], fy1[6]);
                     g.drawLine(fx1[5], fy1[5], fx1[6], fy1[6]);
                     
                     for(int j=0; j<7; j++)
                     {
                     	double alfa = (-1.0*fzc)/(fz[j]-fzc);
                        fxp[j] = (alfa*fx[j])+((1-alfa)*fxc);
                        fyp[j] = (alfa*fy[j])+((1-alfa)*fyc);
                     }                    
                     
                     for(int i=0; i<7; i++)
                     {
                     	fx1[i]=(int) Math.floor(fxp[i]);
      	                fy1[i]=(int) Math.floor(fyp[i]);
                     }
                     
                     g.setColor(Color.black);	
                     g.drawLine(fx1[0], fy1[0], fx1[1], fy1[1]);
                     g.drawLine(fx1[1], fy1[1], fx1[2], fy1[2]);
                     g.drawLine(fx1[2], fy1[2], fx1[3], fy1[3]);
                     g.drawLine(fx1[3], fy1[3], fx1[4], fy1[4]);
                     g.drawLine(fx1[4], fy1[4], fx1[5], fy1[5]);
                     g.drawLine(fx1[5], fy1[5], fx1[0], fy1[0]);
                     g.drawLine(fx1[0], fy1[0], fx1[6], fy1[6]);
                     g.drawLine(fx1[1], fy1[1], fx1[6], fy1[6]);
                     g.drawLine(fx1[2], fy1[2], fx1[6], fy1[6]); 
                     g.drawLine(fx1[3], fy1[3], fx1[6], fy1[6]);
                     g.drawLine(fx1[4], fy1[4], fx1[6], fy1[6]);
                     g.drawLine(fx1[5], fy1[5], fx1[6], fy1[6]); 
                     
                     do
                    {
                    	System.out.println("Selecciona Opcion");
                     	System.out.println("1.- Trasladar");
                        System.out.println("2.- Escalar");
                        System.out.println("3.- Rotar");
                        System.out.println("4.- Salir");
                        System.out.print("Op: ");
                        op2 = lerr.nextInt();
                        
                        switch(op2)
                        {
                        	case 1:
                        		System.out.print("Trasladar: ");
                                traslada = lerr.nextDouble();
                                
                                g.setColor(Color.black);
                                g.drawLine(fx1[0], fy1[0], fx1[1], fy1[1]);
                     			g.drawLine(fx1[1], fy1[1], fx1[2], fy1[2]);
                     			g.drawLine(fx1[2], fy1[2], fx1[3], fy1[3]);
                     			g.drawLine(fx1[3], fy1[3], fx1[4], fy1[4]);
                     			g.drawLine(fx1[4], fy1[4], fx1[5], fy1[5]);
                     			g.drawLine(fx1[5], fy1[5], fx1[0], fy1[0]);
                     			g.drawLine(fx1[0], fy1[0], fx1[6], fy1[6]);
                     			g.drawLine(fx1[1], fy1[1], fx1[6], fy1[6]);
                     			g.drawLine(fx1[2], fy1[2], fx1[6], fy1[6]); 
                     			g.drawLine(fx1[3], fy1[3], fx1[6], fy1[6]);
                     			g.drawLine(fx1[4], fy1[4], fx1[6], fy1[6]);
                    		    g.drawLine(fx1[5], fy1[5], fx1[6], fy1[6]);                         
                                
                        		double[ ] xtf = new double[7];
       							double[ ] ytf = new double[7];
       
       							for(int i=0; i<7; i++)
       							{
           							xtf[i] = fx[i]+traslada;
           							ytf[i] = fy[i]-traslada;
       							}
       
       							for(int i=0; i<7; i++)
       							{
           							double alfa = (-1.0*fzc)/(fz[i]-fzc);
           							fxp[i] = (alfa*xtf[i])+((1-alfa)*fxc);
           							fyp[i] = (alfa*ytf[i])+((1-alfa)*fyc);
       							}
       
       							for(int i=0; i<7; i++)
       							{
           							fx1[i]=(int) Math.floor(fxp[i]);
      	   							fy1[i]=(int) Math.floor(fyp[i]);
       							}
 
       							g.setColor(Color.cyan);
       							g.drawLine(fx1[0], fy1[0], fx1[1], fy1[1]);
                     			g.drawLine(fx1[1], fy1[1], fx1[2], fy1[2]);
                    			g.drawLine(fx1[2], fy1[2], fx1[3], fy1[3]);
                     			g.drawLine(fx1[3], fy1[3], fx1[4], fy1[4]);
                     			g.drawLine(fx1[4], fy1[4], fx1[5], fy1[5]);
                     			g.drawLine(fx1[5], fy1[5], fx1[0], fy1[0]);
                     			g.drawLine(fx1[0], fy1[0], fx1[6], fy1[6]);
                     			g.drawLine(fx1[1], fy1[1], fx1[6], fy1[6]);
                     			g.drawLine(fx1[2], fy1[2], fx1[6], fy1[6]); 
                     			g.drawLine(fx1[3], fy1[3], fx1[6], fy1[6]);
                     			g.drawLine(fx1[4], fy1[4], fx1[6], fy1[6]);
                     			g.drawLine(fx1[5], fy1[5], fx1[6], fy1[6]);
                     
                     	        break;
                     	        
                     	    case 2:
                     	    	System.out.print("Escalar: ");
                                escala = lerr.nextDouble();
                                
                                g.setColor(Color.black);
                                g.drawLine(fx1[0], fy1[0], fx1[1], fy1[1]);
                     			g.drawLine(fx1[1], fy1[1], fx1[2], fy1[2]);
                     			g.drawLine(fx1[2], fy1[2], fx1[3], fy1[3]);
                     			g.drawLine(fx1[3], fy1[3], fx1[4], fy1[4]);
                     			g.drawLine(fx1[4], fy1[4], fx1[5], fy1[5]);
                     			g.drawLine(fx1[5], fy1[5], fx1[0], fy1[0]);
                     			g.drawLine(fx1[0], fy1[0], fx1[6], fy1[6]);
                     			g.drawLine(fx1[1], fy1[1], fx1[6], fy1[6]);
                     			g.drawLine(fx1[2], fy1[2], fx1[6], fy1[6]); 
                     			g.drawLine(fx1[3], fy1[3], fx1[6], fy1[6]);
                     			g.drawLine(fx1[4], fy1[4], fx1[6], fy1[6]);
                     			g.drawLine(fx1[5], fy1[5], fx1[6], fy1[6]);
                     
                                
                     	    	double[ ] xef = new double[7];
    							double[ ] yef = new double[7];
    							double[ ] zef = new double[7];
    
    							for(int i=0; i<7; i++)
    							{
        							double xu = fx[i]-fx[0];
        							double yu = fy[i]-fy[0];
        							double zu = fz[i]-fz[0];
        							double auxx = xu*escala;
        							double auxy = yu*escala;
        							double auxz = zu*escala;
        
        							xef[i] = auxx+fx[0];
        							yef[i] = auxy+fy[0];
        							zef[i] = auxz+fz[0];
    							}
    
    							for(int i=0; i<7; i++)
    							{
        							double alfa = (-1.0*fzc)/(zef[i]-fzc);
        							fxp[i] = (alfa*xef[i])+((1-alfa)*fxc);
        							fyp[i] = (alfa*yef[i])+((1-alfa)*fyc);
    							}
    
    							for(int i=0; i<7; i++)
    							{
         							fx1[i]=(int) Math.floor(fxp[i]);
      	 							fy1[i]=(int) Math.floor(fyp[i]);
    							}
    
   	 							g.setColor(Color.red);
   	 							g.drawLine(fx1[0], fy1[0], fx1[1], fy1[1]);
                     			g.drawLine(fx1[1], fy1[1], fx1[2], fy1[2]);
                     			g.drawLine(fx1[2], fy1[2], fx1[3], fy1[3]);
                     			g.drawLine(fx1[3], fy1[3], fx1[4], fy1[4]);
                     			g.drawLine(fx1[4], fy1[4], fx1[5], fy1[5]);
                     			g.drawLine(fx1[5], fy1[5], fx1[0], fy1[0]);
                     			g.drawLine(fx1[0], fy1[0], fx1[6], fy1[6]);
                     			g.drawLine(fx1[1], fy1[1], fx1[6], fy1[6]);
                     			g.drawLine(fx1[2], fy1[2], fx1[6], fy1[6]); 
                     			g.drawLine(fx1[3], fy1[3], fx1[6], fy1[6]);
                     			g.drawLine(fx1[4], fy1[4], fx1[6], fy1[6]);
                     			g.drawLine(fx1[5], fy1[5], fx1[6], fy1[6]);
                     	    	break;
                     	    case 3:
                     	    	System.out.println("1.- Rota_x");
                     	    	System.out.println("2.- Rota_y");
                     	    	System.out.println("3.- Rota_z");
                     	    	System.out.print("Op: ");
                     	    	int rota = lerr.nextInt();
                                switch(rota)
                     	    	{
                     	    		case 1:
                     	    			System.out.print("Angulo: ");
                                    	angulo = lerr.nextDouble();
                                    	
                                    	g.setColor(Color.black);
                                		g.drawLine(fx1[0], fy1[0], fx1[1], fy1[1]);
                     					g.drawLine(fx1[1], fy1[1], fx1[2], fy1[2]);
                     					g.drawLine(fx1[2], fy1[2], fx1[3], fy1[3]);
                     					g.drawLine(fx1[3], fy1[3], fx1[4], fy1[4]);
                     					g.drawLine(fx1[4], fy1[4], fx1[5], fy1[5]);
                     					g.drawLine(fx1[5], fy1[5], fx1[0], fy1[0]);
                     					g.drawLine(fx1[0], fy1[0], fx1[6], fy1[6]);
                     					g.drawLine(fx1[1], fy1[1], fx1[6], fy1[6]);
                     					g.drawLine(fx1[2], fy1[2], fx1[6], fy1[6]); 
                     					g.drawLine(fx1[3], fy1[3], fx1[6], fy1[6]);
                     					g.drawLine(fx1[4], fy1[4], fx1[6], fy1[6]);
                     					g.drawLine(fx1[5], fy1[5], fx1[6], fy1[6]);
                                    	
                     	    			double[ ] yrotax = new double[7];
    									double[ ] zrotax = new double[7];
    
   									 	for(int i=0; i<7; i++)
    									{
        									double yr = fy[i]-fy[0];
        									double zr = fz[i]-fz[0];
        									double angulo1 = Math.toRadians(angulo);
        									double auxy = (yr*Math.cos(angulo1))-(zr*Math.sin(angulo1));
        									double auxz = (yr*Math.sin(angulo1))+(zr*Math.cos(angulo1));
        
        									yrotax[i] = auxy+fy[0];
        									zrotax[i] = auxz+fz[0];
    									}
    
    									for(int i=0; i<7; i++)
    									{
        									double alfa = (-1.0*fzc)/(zrotax[i]-fzc);
        									fxp[i] = (alfa*fx[i])+((1-alfa)*fxc);
        									fyp[i] = (alfa*yrotax[i])+((1-alfa)*fyc);
    									}
    
    									for(int i=0; i<7; i++)
    									{
        									fx1[i]=(int) Math.floor(fxp[i]);
      										fy1[i]=(int) Math.floor(fyp[i]);
     									}
    
    									g.setColor(Color.BLUE);
                                		g.drawLine(fx1[0], fy1[0], fx1[1], fy1[1]);
                     					g.drawLine(fx1[1], fy1[1], fx1[2], fy1[2]);
                     					g.drawLine(fx1[2], fy1[2], fx1[3], fy1[3]);
                     					g.drawLine(fx1[3], fy1[3], fx1[4], fy1[4]);
                     					g.drawLine(fx1[4], fy1[4], fx1[5], fy1[5]);
                     					g.drawLine(fx1[5], fy1[5], fx1[0], fy1[0]);
                     					g.drawLine(fx1[0], fy1[0], fx1[6], fy1[6]);
                     					g.drawLine(fx1[1], fy1[1], fx1[6], fy1[6]);
                     					g.drawLine(fx1[2], fy1[2], fx1[6], fy1[6]); 
                     					g.drawLine(fx1[3], fy1[3], fx1[6], fy1[6]);
                     					g.drawLine(fx1[4], fy1[4], fx1[6], fy1[6]);
                     					g.drawLine(fx1[5], fy1[5], fx1[6], fy1[6]);
                     					break;
                     	    		case 2:
                     	    			System.out.print("Angulo: ");
                                    	angulo = lerr.nextDouble();
                                    	
                                    	g.setColor(Color.black);
                                		g.drawLine(fx1[0], fy1[0], fx1[1], fy1[1]);
                     					g.drawLine(fx1[1], fy1[1], fx1[2], fy1[2]);
                     					g.drawLine(fx1[2], fy1[2], fx1[3], fy1[3]);
                     					g.drawLine(fx1[3], fy1[3], fx1[4], fy1[4]);
                     					g.drawLine(fx1[4], fy1[4], fx1[5], fy1[5]);
                     					g.drawLine(fx1[5], fy1[5], fx1[0], fy1[0]);
                     					g.drawLine(fx1[0], fy1[0], fx1[6], fy1[6]);
                     					g.drawLine(fx1[1], fy1[1], fx1[6], fy1[6]);
                     					g.drawLine(fx1[2], fy1[2], fx1[6], fy1[6]); 
                     					g.drawLine(fx1[3], fy1[3], fx1[6], fy1[6]);
                     					g.drawLine(fx1[4], fy1[4], fx1[6], fy1[6]);
                     					g.drawLine(fx1[5], fy1[5], fx1[6], fy1[6]);
                                    	
                     	    			double[ ] xrotay = new double[7];
    									double[ ] zrotay = new double[7];
    
    									for(int i=0; i<7; i++)
    									{
        									double xr = fx[i]-fx[0];
        									double zr = fz[i]-fz[0];
        									double angulo1 = Math.toRadians(angulo);
        									double auxy = (xr*Math.cos(angulo1))-(zr*Math.sin(angulo1));
        									double auxz = -(xr*Math.sin(angulo1))+(zr*Math.cos(angulo1));
        
        									xrotay[i] = auxy+fx[0];
        									zrotay[i] = auxz+fz[0];
    									}
    
    									for(int i=0; i<7; i++)
    									{
        									double alfa = (-1.0*fzc)/(zrotay[i]-fzc);
        									fxp[i] = (alfa*xrotay[i])+((1-alfa)*fxc);
        									fyp[i] = (alfa*fy[i])+((1-alfa)*fyc);
    									}
    
    									for(int i=0; i<7; i++)
    									{
        									fx1[i]=(int) Math.floor(fxp[i]);
      										fy1[i]=(int) Math.floor(fyp[i]);
    									}
    	
    									g.setColor(Color.yellow);
                                        g.drawLine(fx1[0], fy1[0], fx1[1], fy1[1]);
                     					g.drawLine(fx1[1], fy1[1], fx1[2], fy1[2]);
                     					g.drawLine(fx1[2], fy1[2], fx1[3], fy1[3]);
                     					g.drawLine(fx1[3], fy1[3], fx1[4], fy1[4]);
                     					g.drawLine(fx1[4], fy1[4], fx1[5], fy1[5]);
                     					g.drawLine(fx1[5], fy1[5], fx1[0], fy1[0]);
                     					g.drawLine(fx1[0], fy1[0], fx1[6], fy1[6]);
                     					g.drawLine(fx1[1], fy1[1], fx1[6], fy1[6]);
                     					g.drawLine(fx1[2], fy1[2], fx1[6], fy1[6]); 
                     					g.drawLine(fx1[3], fy1[3], fx1[6], fy1[6]);
                     					g.drawLine(fx1[4], fy1[4], fx1[6], fy1[6]);
                     					g.drawLine(fx1[5], fy1[5], fx1[6], fy1[6]);
                     	    			break;
                     	    			
                     	    		case 3:
                     	    			System.out.print("Angulo: ");
                                    	angulo = lerr.nextDouble();
                                    	
                                    	g.setColor(Color.black);
                                		g.drawLine(fx1[0], fy1[0], fx1[1], fy1[1]);
                     					g.drawLine(fx1[1], fy1[1], fx1[2], fy1[2]);
                     					g.drawLine(fx1[2], fy1[2], fx1[3], fy1[3]);
                     					g.drawLine(fx1[3], fy1[3], fx1[4], fy1[4]);
                     					g.drawLine(fx1[4], fy1[4], fx1[5], fy1[5]);
                     					g.drawLine(fx1[5], fy1[5], fx1[0], fy1[0]);
                     					g.drawLine(fx1[0], fy1[0], fx1[6], fy1[6]);
                     					g.drawLine(fx1[1], fy1[1], fx1[6], fy1[6]);
                     					g.drawLine(fx1[2], fy1[2], fx1[6], fy1[6]); 
                     					g.drawLine(fx1[3], fy1[3], fx1[6], fy1[6]);
                     					g.drawLine(fx1[4], fy1[4], fx1[6], fy1[6]);
                     					g.drawLine(fx1[5], fy1[5], fx1[6], fy1[6]);
                                    	
                     	    			double[ ] fxrotaz = new double[7];
     									double[ ] fyrotaz = new double[7];
    
   				                        for(int i=0; i<7; i++)
                			            {
                			            	double xr = fx[i]-fx[0];
        									double yr = fy[i]-fy[0];
        									double angulo1 = Math.toRadians(angulo);
        									double auxx = (xr*Math.cos(angulo1))-(yr*Math.sin(angulo1));
        									double auxy = (xr*Math.sin(angulo1))+(yr*Math.cos(angulo1));
        
        									fxrotaz[i] = auxx+fx[0];
        									fyrotaz[i] = auxy+fy[0];
                         				}
    
   				 						for(int i=0; i<7; i++)
    									{
        									double alfa = (-1.0*fzc)/(fz[i]-fzc);
        									fxp[i] = (alfa*fxrotaz[i])+((1-alfa)*fxc);
        									fyp[i] = (alfa*fyrotaz[i])+((1-alfa)*fyc);
    									}
    
    									for(int i=0; i<7; i++)
    									{
            								fx1[i]=(int) Math.floor(fxp[i]);
      										fy1[i]=(int) Math.floor(fyp[i]);
    									}
    
    									g.setColor(Color.orange);
    									g.drawLine(fx1[0], fy1[0], fx1[1], fy1[1]);
                     					g.drawLine(fx1[1], fy1[1], fx1[2], fy1[2]);
                     					g.drawLine(fx1[2], fy1[2], fx1[3], fy1[3]);
                     					g.drawLine(fx1[3], fy1[3], fx1[4], fy1[4]);
                     					g.drawLine(fx1[4], fy1[4], fx1[5], fy1[5]);
                     					g.drawLine(fx1[5], fy1[5], fx1[0], fy1[0]);
                     					g.drawLine(fx1[0], fy1[0], fx1[6], fy1[6]);
                     					g.drawLine(fx1[1], fy1[1], fx1[6], fy1[6]);
                     					g.drawLine(fx1[2], fy1[2], fx1[6], fy1[6]); 
                     					g.drawLine(fx1[3], fy1[3], fx1[6], fy1[6]);
                     					g.drawLine(fx1[4], fy1[4], fx1[6], fy1[6]);
                     					g.drawLine(fx1[5], fy1[5], fx1[6], fy1[6]);
                     	    			break;
                     	    			
                     	    	} 
                     	    
                     	    	break;
                       }
                     }
                     while(op2 != 4);
            //		break;
            
            
        }while(op != 1);
       
    }
}



public class Proyec  
{
	public static void main(String[] args) 
	{
		piramide p=new piramide();
        p.setBackground(java.awt.Color.white);
        p.addWindowListener(new WindowAdapter()
        {
        	public void windowClosing(WindowEvent we)
            {
            System.exit(0);
            }
            }
        );
    }
}
