import java.util.Scanner;


class Fraccion
{
//Declaramos los atributos
int numerador;
int denominador;
//Declaramos los construcotres.
//Necesitamos un constructor que inicialize los valores
Fraccion()
{
	numerador=0;
	denominador=0;
}
Fraccion(int x, int y )
{
this.numerador=x;
this.denominador=y;
}
//Realizamos los metodos
public Fraccion suma(Fraccion z)
{
Fraccion n=new Fraccion();
n.denominador=denominador*z.denominador;
n.numerador= ((n.denominador/denominador)*numerador)+((n.denominador/z.denominador)*z.numerador);
return n;
}
public Fraccion multi(Fraccion zx)
{
Fraccion n=new Fraccion();
n.denominador=denominador*zx.denominador;
n.numerador=numerador*zx.numerador;
return n;
}
public void imprime()
{
	System.out.println("El resultado es:");
	System.out.print(" "+numerador);
	System.out.println("/"+denominador);
}
public Fraccion resta(Fraccion z)
{
Fraccion n=new Fraccion();
n.denominador=denominador*z.denominador;
n.numerador= ((n.denominador/denominador)*numerador)-((n.denominador/z.denominador)*z.numerador);
return n;
}

public Fraccion div(Fraccion g)
{
Fraccion c=new Fraccion();
c.numerador=numerador*g.denominador;
c.denominador=denominador*g.numerador;
return c;
}

}
class OperFraccion
{
public static void menu()
{
	System.out.println("Cual es la operacion que deseas realizar.?");
	System.out.println("1.-Sumar.");
	System.out.println("2.-Restar.");
	System.out.println("3.-Multiplicar.");
	System.out.println("4.-Dividir.");
	System.out.println("0.-Salir.");
}

public static int LeerTeclado()
{
Scanner obj=new Scanner(System.in);
int a=obj.nextInt();
return a;
}

public static void main(String[] args) {
int opc;
do
{
menu();
opc=LeerTeclado();
switch (opc) {
	case 1: 
Fraccion z;
int a,b,c,d;
System.out.println("Cual es el numerador.?");
a=LeerTeclado();
System.out.println("Cual es el denominador");
b=LeerTeclado();
Fraccion x=new Fraccion(a,b);
System.out.println("Proporciona los datos  de la segunda Fraccion");
System.out.println("Cual es el numerador.?");
c=LeerTeclado();
System.out.println("Cual es el denominador");
d=LeerTeclado();
Fraccion y=new Fraccion(c,d);
z=x.suma(y);
z.imprime();
	break;	

case 2:
Fraccion k;
System.out.println("Cual es el numerador.?");
int e=LeerTeclado();
System.out.println("Cual es el denominador");
int f=LeerTeclado();
Fraccion xy=new Fraccion(e,f);
System.out.println("Proporciona los datos  de la segunda Fraccion");
System.out.println("Cual es el numerador.?");
int g=LeerTeclado();
System.out.println("Cual es el denominador");
int h=LeerTeclado();
Fraccion yx=new Fraccion(g,h);
k=xy.resta(yx);
k.imprime();
break;

case 3:
Fraccion ky;
System.out.println("Cual es el numerador.?");
int i=LeerTeclado();
System.out.println("Cual es el denominador");
int j=LeerTeclado();
Fraccion xyz=new Fraccion(i,j);
System.out.println("Proporciona los datos  de la segunda Fraccion");
System.out.println("Cual es el numerador.?");
int xt=LeerTeclado();
System.out.println("Cual es el denominador");
int zs=LeerTeclado();
Fraccion yxz=new Fraccion(xt,zs);
ky=xyz.multi(yxz);
ky.imprime();

break;

case 4:
Fraccion kyz;
System.out.println("Cual es el numerador.?");
int im=LeerTeclado();
System.out.println("Cual es el denominador");
int jm=LeerTeclado();
Fraccion xyzm=new Fraccion(im,jm);
System.out.println("Proporciona los datos  de la segunda Fraccion");
System.out.println("Cual es el numerador.?");
int xtm=LeerTeclado();
System.out.println("Cual es el denominador");
int zsm=LeerTeclado();
Fraccion yxzm=new Fraccion(xtm,zsm);
kyz=xyzm.div(yxzm);
kyz.imprime();

break;

}

}
while(opc!=0);


}
}

