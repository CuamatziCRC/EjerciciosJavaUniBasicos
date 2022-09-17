#include <stdio.h>
#include <string.h>

 struct datos
 {
   long int numservicio;
   float adeudo;
   char nombre[30];
 } usuario[10];

main()
{
  float pago,efectivo,cambio,aux;
  char opcion;
  char temp[15];
  int pos=100;
  int band=0,oper=0,auxnum,i=0,j=0,maximo=-1,bandera=0;

   printf("Programa que emula CFE-MATICO con estructuras");
   printf("Ingresa el nombre del usuario %d:", i+1);
     gets (&temp);
       while(&temp!="FIN")
         {
           usuario[i].nombre==temp;
           printf("Ingresa el numero de servicio %d:", i+1);
             scanf("%ld%*c", &usuario[i].numservicio);
           printf("Ingresa el adeudo del usuario %d:", i+1);
             scanf("%.2f%*c", &usuario[i].adeudo);
            i++;
           printf("Ingresa el nombre del usuario %d:", i+1);
             gets(&temp);
         }
         system("clear");
do
    {
      printf("BIENVENIDO");
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
               if(auxnum!=usuario[j].numservicio)
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
            printf("%s",usuario[j].nombre);
            printf("\nNumero De Servicio: ");
            printf("%ld",usuario[j].numservicio);
            printf("\nAdeudo: $");
            printf("%.2f",usuario[j].adeudo);
            }
            else
            {
                printf("\nUsuario no Encontrado\n");
            }
        }
        else
            {
                printf("\nNohay Ningun Usuario Registrado\nLe Recomendamos Registrar Algunos\n");
            }
            break;

        }//fin del caso A

       case 'B':
             {
               
        if(pos!=100)
        {
        printf("\nPAGO DE SERVICIO\n\n");
        if(usuario[pos].adeudo!=0 && maximo>=0)
        {
        printf("\nNombre Del Usuario: ");
        printf("%s",usuario[pos].nombre);
        printf("\nNumero De Servicio: ");
        printf("%ld",usuario[pos].numservicio);
        printf("\nAdeudo: $%.2f ",usuario[pos].adeudo);
        printf("\nIngrese Su Efectivo\n");
        scanf("%f",&efectivo);
        while (efectivo < usuario[pos].adeudo)
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
        cambio=efectivo-usuario[pos].adeudo;
        printf("\nServicio Pagado\n");
        usuario[pos].adeudo=0;
        bandera=1;
        printf("\nNombre Del Usuario: ");
        printf("%s",usuario[pos].nombre);
        printf("\nNumero De Servicio: ");
        printf("%ld",usuario[pos].numservicio);
        printf("\nAdeudo: ");
        printf("%.2f",usuario[pos].adeudo);
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
          
             }//fin del caso B


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
                if(auxnum!=usuario[i].numservicio)
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
                printf("\nNohay Ningun Usuario Registrado\nLe Recomendamos Registrar Algunos\n");
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
