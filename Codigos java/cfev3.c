#include <stdio.h>
#include <string.h>

struct datos
	{
		long int cod;
		char nom[100];
		float ade;
	};

struct datos usuario[100], *str=&usuario[0];




main()
{
	float pago,efectivo,cambio,aux;
	char opcion, temp[60];
	int pos=100,band=0,oper=0,auxnum=0,i=0,j=0,maximo=0,bandera=0,k=0;

	printf("\nPrograma Que Emula Un CFE-MATICO\n");
	printf("Al terminar de introducir sus datos escribir FIN \n");
	printf("\nIngresa el Nombre Del Usuario\n");
	gets(temp);
	while(strcmp(temp,"FIN")!=0)
	{
		strcpy((*(str+i)).nom,temp);
       		printf("\nIngresa el Numero Del Servicio\n");
        	scanf("%ld%*c", &(*(str+i)).cod);
        	printf("\nIngresa El Adeudo\n");
        	scanf("%f%*c", &(*(str+i)).ade);
        	maximo=i;
        	i++;
        	printf("\nIngresa el Nombre Del Usuario\n");
        	gets(temp);
	}

	printf("\n\nBienvenido\n\n");
    	do
  	{
   		printf("\nMenu De Opciones");
   		printf("\n");
    		printf("A.- Consulta De Adeudo\n");
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
            				printf("Consulta De Adeudo\n");
            				printf("Ingrese EL Numero De Servicio\n");
            				scanf("%d%*c",&auxnum);
            				while(j<=maximo && pos==100)
            				{
                				if(auxnum!=(*(str+i)).cod)
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
            					printf("\nCONSULTA DE ADEUDO\n");
            					printf("\nNombre Del Usuario: ");
            					printf("%s", (*(str+pos)).nom);
            					printf("\nNumero De Servicio: ");
            					printf("%ld", (*(str+pos)).cod);
            					printf("\nAdeudo: $");
            					printf("%.2f", (*(str+pos)).ade);
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
			//fin del caso 1
			case 'B':
        		{
        			if(pos!=100)
        			{
        				printf("\nPAGO DE SERVICIO\n\n");
        				if((*(str+pos)).ade!=0 && maximo>=0)
        				{
        					printf("\nNombre Del Usuario: ");
        					printf("%s", (*(str+pos)).nom);
        					printf("\nNumero De Servicio: ");
        					printf("%ld", (*(str+pos)).cod);
        					printf("\nAdeudo: $%.2f ", (*(str+pos)).ade);
        					printf("\nIngrese Su Efectivo\n");
        					scanf("%f",&efectivo);
        					while (efectivo < (*(str+pos)).ade)
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
        					cambio=efectivo-(*(str+pos)).ade;
        					printf("\nServicio Pagado\n");
        					(*(str+pos)).ade=0;
        					bandera=1;
        					printf("\nNombre Del Usuario: ");
        					printf("%s", (*(str+pos)).nom);
        					printf("\nNumero De Servicio: ");
        					printf("%ld", (*(str+pos)).cod);
        					printf("\nAdeudo: ");
        					printf("%.2f", (*(str+pos)).ade);
        					if(band>0)
        					{
           						printf("\nCambio:$ ");
            						printf("%.2f",cambio);
							printf("\nGracias por su visita...\n");
        					}
        					}
        					else
            					{
                					printf("\nEl Servicio Esta Pagado\n");
							printf("\nGracias por su visita...\n");
            					}
    				}
    				else
        			{
            				printf("\nPorfavor Ingrese Su Numero De Servicio En EL Caso *A*\n");
        			}
				getchar();
    				break;
			}	
			//fin del caso 2
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
                				if(auxnum!=(*(str+i)).cod)
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
                				printf("\nCONSULTA DE ADEUDO\n");
            					printf("\nNombre Del Usuario: ");
            					printf("%s", (*(str+pos)).nom);
            					printf("\nNumero De Servicio: ");
            					printf("%ld", (*(str+pos)).cod);
            					printf("\nAdeudo: $");
            					printf("%.2f", (*(str+pos)).ade);	
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
    	}
	while(1);

    	return 0;
}
