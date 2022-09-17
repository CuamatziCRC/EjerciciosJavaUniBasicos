#include <stdio.h>
#include <stdlib.h>
#include <math.h>
main ()
{
	int a,b,c;
	printf("este programa determina que tipo de triangulo es y en caso de que no lo forme");
	printf("da el valor al lado :'a' ");
	scanf ("%d",&a);
	printf ("da el valor al lado : 'b' ");
	scanf ("%d",&b);
	printf ("da el valor al lado : 'c' ");
	scanf ("%d",&c);
		    if (a==b&&b==c){
		    printf ("el triangulo es equilatero :D\n\n");}
		    else
		    {
		    if ((a+b)==c||(a+c)==b||(b+c)==a){
		    
		    
		    printf("las medidas no corresponden a un triangulo\n\n");}
		    else 
			{
			if ((a==b&&a!=c)||(a==c&&a!=b)||c==b&&c!=a){
		    printf ("el triangulo es isosceles :)\n\n");}
		    else{
	 	    printf ("el triangulo es escaleno \n\n ");}
		   }
        	}
}
