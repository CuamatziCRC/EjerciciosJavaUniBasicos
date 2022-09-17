#include <stdio.h>
main (){

   int num1,num2,resultado=0;
   printf("Introduce primer numero de la multiplicacion\n");
   scanf("%d",&num1);
   printf("Introduce segundo numero de la multiplicacion\n");
   scanf("%d",&num2);
   while(num1>=1)
   {
       if(num1%2!=0)
       resultado+=num2;    // le sumamos num2 a resultado.(resultado=resultado+num2)
       num1=num1/2;
       num2=num2*2;
   }
   printf("El resultado es: %d",resultado);
}
