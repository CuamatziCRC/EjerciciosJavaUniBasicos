#include <stdio.h>
main()
{
  int aux,k,j,i,num[1000],min,p,o;
  char op;
  printf("Programa que lee numeros y los ordena por los diferenrentes metodos de ordenamiento\n");
  for(o=0;o<1000;o++)
	  num[o]='\0';
  do
  {
  printf("l > Leer\n");
  printf("b > Ordena Burbuja\n");
  printf("s > Seleccion Directa\n");
  printf("i > Metodo de Insercion\n");
  printf("e > Exit\n");
  printf("Ingrese opcion\n");
  scanf("%c", &op);
  switch (op)
  {
    case 'l' :{
                printf("Ingresa los numeros y termina con 0\n");
                 i = 0;
                  printf("%d .-  " , i+1);
                  scanf("%d",&num[0]);
                  while(num[i]!= 0)
                  {
                   i++;
                   printf("%d .-  " , i+1);
                   scanf("%d" ,&num[i]);
                   }
                break;
               }
   case 'b'   :{
                printf("Ordenamiento Burbuja\n");
                for(k = 0;k < i ; k++)
                 {
                   for(j = 0;j < i-1 ; j++)
                    {
                      if(num[j] > num[j+1])
                       {
                         aux = num[j];
                         num[j] = num[j+1];
                         num[j+1]= aux;
                        }
                     }
                  }
                   for(j = 0;j < i ; j++)
                   printf("%d\n",num[j]);
                break;
               }
    case 's'   :{
                  printf("Seleccion Directa\n");
                  for(k = 0;k < i-1; k++)
                    {
                      min = k;
                    for(j = k+1;j < i ; j++)
                       if(num[j] < num[min])
                          min = j;
                      if(k != min)
                       {
                         aux = num[k];
                         num[k] = num[min];
                         num[min] = aux; 
                        }
                       }
                        for(j = 0;j < i ; j++)
                       printf("%d\n",num[j]);
                  break;
                  }
     case 'i'   :{
                   printf("Insersion\n");
				   if (num[0]=='\0')
				   {   
				   printf("Ingresa los numeros y termina con 0\n");
				   i = 0;
				   printf("%d .-  " , i+1);
				   scanf("%d",&num[0]);
				   while(num[i]!= 0)
				   {
					   i++;
					   printf("%d .-  " , i+1);
					   scanf("%d" ,&num[i]);
				   }
				   }
                   for (j=1; j< i; j++)
                    {
                      aux = num[j];
                       for (k = j-1; k >= 0 && num[k] > aux; k--)
                              num[k + 1] = num[k];
                                num[k+1] = aux;
                         }
                      for(j = 0;j < i ; j++)
                       printf("%d\n",num[j]);
                       break;
                   }
    }
    getchar();
   }while(op != 'e');
}








