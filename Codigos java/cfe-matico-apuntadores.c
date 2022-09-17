#include <stdio.h>
#include <string.h>

 struct datos
 {
   long int numservicio;
   float adeudo;
   char nombre[30];
 } usuario[10];

int main()
{
  float pago,efectivo,cambio,aux;
  char opcion;
  char temp[15];
  int pos=100;
  int band=0,oper=0,auxnum,i=0,j=0,maximo=-1,bandera=0;
  struct datos usuario[10];
  struct datos *p;
  p=usuario;

   printf("Programa que emula CFE-MATICO con estructuras\n\n");
   printf("Ingresa el nombre del usuario %d:", i+1);
     gets (temp);
       while(strcmp(temp,"FIN")!=0)
         {
	     strcpy((p+i)->nombre,temp);
           printf("Ingresa el numero de servicio %d:", i+1);
             scanf("%ld%*c", &(p+i)->numservicio);
           printf("Ingresa el adeudo del usuario %d:", i+1);
             scanf("%f%*c", &(p+i)->adeudo);
            i++;
			maximo=i;
           printf("Ingresa el nombre del usuario %d:", i+1);
             gets(temp);
         }
         system("clear");
do
    {
      printf("BIENVENIDO\n\n");
      printf("Menu De Opciones\n");
      printf("\n");
      printf("A.- Busqueda De Usuario Y Consulta De Adeudo\n");
      printf("B.- Pago De Servicio\n");
      printf("C.- Cambio de Usuario\n");
      printf("Selecccione una Opcion...\n");
      scanf("%c%*c",&opcion);
      printf("\n");
    switch(toupper(opcion))
    {
       case 'A':
         {
              if(maximo>=0)
            {
            i=0;
            j=0;
            pos=100;
            printf("Busqueda De Usuario Y Consulta De Adeudo\n");
            printf("Ingrese EL Numero De Servicio\n");
            scanf("%d%*c",&auxnum);
            while(j<=maximo && pos==100)
            {
               if(auxnum!= (p+i)->numservicio)
                {
                    i++;
                }
                else
                {
                    pos=i;
                }
                j++;
            }
          if(pos!=100)
            {
            printf("\nUsuario Encontrado En La Posicion %d",pos);
            printf("\nCONSULTA DE ADEUDO\n");
            printf("\nNombre Del Usuario: ");
            printf("%s",(p+pos)->nombre);
            printf("\nNumero De Servicio: ");
            printf("%ld",(p+pos)->numservicio);
            printf("\nAdeudo: $");
            printf("%.2f",(p+pos)->adeudo);
            }
            else
            {
                printf("\nUsuario no Encontrado\n");
            }
        }
        else
            {
                printf("\nNo hay Ningun Usuario Registrado\nLe Recomendamos Registrar Algunos\n");
            }
            break;

        }/*fin del caso A*/

       case 'B':
             {

        if(pos!=100)
        {
        printf("\nPAGO DE SERVICIO\n\n");
        if((p+pos)->adeudo!=0 && maximo>=0)
        {
        printf("\nNombre Del Usuario: ");
        printf("%s",(p+pos)->nombre);
        printf("\nNumero De Servicio: ");
        printf("%ld",(p+pos)->numservicio);
        printf("\nAdeudo: $%.2f ",(p+pos)->adeudo);
        printf("\nIngrese Su Efectivo\n");
        scanf("%f",&efectivo);
        while (efectivo < (p+pos)->adeudo)
        {
            printf("\nEfectivo Insuficiente\n");
            printf("Efectivo actual: %.2f",efectivo);
            printf("\nIngrese Su Efectivo\n");
            scanf("%f",&aux);
            printf("\n");
            printf("%.2f",efectivo);
            efectivo=efectivo+aux;
        }
        band=1;
        cambio=efectivo-(p+pos)->adeudo;
        printf("\nServicio Pagado\n");
        (p+pos)->adeudo=0;
        bandera=1;
        printf("\nNombre Del Usuario: ");
        printf("%s",(p+pos)->nombre);
        printf("\nNumero De Servicio: ");
        printf("%ld",(p+pos)->numservicio);
        printf("\nAdeudo: ");
        printf("%.2f",(p+pos)->adeudo);
        if(band>0)
        {
            printf("\nCambio:$ ");
            printf("%.2f",cambio);
        }
        printf("\nGracias por su visita...\n");
        }
        else
            {
                printf("\nEl Servicio Esta Pagado\n");
            }
    }
    else
        {
            printf("\nPorfavor Ingrese Su Numero De Servicio En EL Caso *A*\n");
        }
    break;

             }/*fin del caso B*/


       case 'C':
             {
                 if(maximo>=0)
            {
            i=0;
            j=0;
            pos=100;
            printf("\nCambio De Uuario\n");
            printf("Ingrese EL Numero De Servicio\n");
            scanf("%d%*c",&auxnum);
            while(j<=maximo && pos==100)
            {
                if(auxnum!=(p+i)->numservicio)
                {
                    i++;
                }
                else
                {
                    pos=i;
                }
                j++;
            }
            if(pos!=100)
            {
                printf("\nUsuario Encontrado En La Posicion %d",pos);
            }
            else
            {
                printf("\nUsuario no Encontrado\n");
            }
        }
        else
            {
                printf("\nNo hay Ningun Usuario Registrado\nLe Recomendamos Registrar Algunos\n");
            }
            break;
             }
    }
    printf("\nDesea Realizar Otra Operacion\n");
    printf("1.- SI\n2.- NO\nSeleccione Su Opcion...\n");
    scanf("%d%*c",&oper);
   }while(oper!=2);

    return 0;
}
