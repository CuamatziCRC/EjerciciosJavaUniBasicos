#include <stdio.h>
#include <math.h>

main ()
{
	int a,b,c; float dis;
        float disc;

	printf ("este programa hace la funcion cuadratica a**2+bx+c=0 \n\n");
	printf("da el valor de 'a' ");
	scanf ("%d",&a);
	printf ("da el valor de 'b' ");
	scanf("%d",&b);
	printf ("da el valor de 'c' ");
	scanf ("%d",&c);
	dis=b*b-(4*a*c);

	if(dis<0||a==0){
	printf("no se pudo realizar la operacion\n\n");system("pause");return 0;}

	disc=(-b+sqrt(dis))/(2*a);
	printf("\n\n el resultado 1 es: %f\n\n ",disc);
	disc=(-b-sqrt(dis))/(2*a);
	printf("\n\n el resultado 2 es: %f \n\n ",disc);
	}
