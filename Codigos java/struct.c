#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>
		struct datos{
		      char nombre[100];
			  float deuda;
		      int medidor;
	    };
	    struct datos clientes [2];
	    

int main()
	
	
{
	int i=0,j=0,falso=0,temp,usu;
	char opc;
	float dep=0,k1=0,z=0,x=0;
	printf("************ CFEmatico ***********\n");
	for (i=0;i<3;i++)
		
	{
	    printf("Proporcionar datos del cliente %d\n ", i+1);
		printf("Nombre completo: ");
		gets(clientes[i].nombre);
		printf("\n");
		fflush(stdin);
		printf("Asigne su deuda: ");
		scanf("%f.2",&clientes[i].deuda);
		fflush(stdin);
		printf("De el numero de su medidor: ");
		scanf("%d",&clientes[i].medidor);
		while(getchar()!='\n');
		//while(getchar()=!"\n");
	}
		do{
			printf("\n");
			while(getchar()!='\n');
			printf("|||||||||||||BIENVENIDO A CEFEMATICO|||||||||||||\n");
			printf("\n");
			printf(" POR FAVOR INGRESE Y COLOQUE EN EL LECTOR SU CODIGO DE BARRAS \n");
			scanf("%d",&temp);
			while(getchar()!='\n');
			printf("\n");
			printf(" 같같같같같같같  ESPERE UN MOMENTO POR FAVOR   같같같같같같같같� \n");
			printf("\n");
			
			while(j<=3&&falso==0){
				if (temp==clientes[j].medidor)
				{
				falso=1;
				}
				else
				j++;
			}//busqueda de los clientes
			if (falso==0)
			{
				printf("\n\tCodigo incorrecto\n");
			}
			else
			{	
				usu=j;
				printf("\n*********************************************\n");
				printf("*****\tCFEMATICO\t*****\n");
				printf("\tnombre del usuario es..%s",clientes[usu].nombre);
				printf("\n*________ NUMERO DE MEDIDOR: %c    _______*\n",clientes[usu].medidor);
				printf("\n*________ ADEUDO DEL RECIBO:%.2f _________*\n",clientes[usu].deuda);
				printf("\n*_________ ADEUDO TOTAL:  %.2f    ________*\n",clientes[usu].deuda);
			    printf("\n*********************************************\n");
				printf("\n");
			
					printf("<<<<          P> PAGAR              >>>>\n");
					printf("<<<<          M> MENU PRINCIPAL     >>>>\n");
					scanf("%c",&opc);
					while(getchar()!='\n');
					switch(opc)
					{
							case 'P': case 'p':   
										printf("\n");
										printf("\n*********************************************\n");
										printf("\n*             CFEMATICO                     *\n");
										printf("\n*_____  CLIENTE: %s  ______*\n",clientes[usu].nombre);
										printf("\n*________       ADEUDO: %.2f       _______*\n",clientes[usu].deuda);
										printf("\n*________     DEPOSITADO: %.2f     _________*\n",dep);
										printf("\n*_________       CAMBIO:  0.00      ________*\n");
										printf("\n*********************************************\n");
										printf("\nIntroduzca el dinero en la ranura\n");
										scanf("%f",&dep);
										while(getchar()!='\n');
										if (dep>clientes[usu].deuda)
											{
												k1=dep-clientes[usu].deuda;
												clientes[usu].deuda=0;
												/*cambio*/
												printf("\n");
												printf("\n*********************************************\n");
												printf("\n*             CFEMATICO                     *\n");
												printf("\n*\tCLIENTE: %s  \t*\n",clientes[usu].nombre);
												printf("\n*\tADEUDO: %.2f \t*\n",clientes[usu].deuda);
												printf("\n*\tCAMBIO:  %.2f\t*\n",k1);
												printf("\n*********************************************\n");
											}
											else
												{
												 if (dep <clientes[usu].deuda)
												 	{
												 		z=z+dep;
												 		while(z<clientes[usu].deuda)
												 			{
												 				x=clientes[usu].deuda-z;
												 					printf("\n");
																	printf("\n*********************************************\n");
																	printf("\n*             CFEMATICO                     *\n");
																	printf("\n*_____  CLIENTE: %s  ______*\n",clientes[usu].deuda);
																	printf("\n*________       ADEUDO: %.2f       _______*\n",x);
																	printf("\n*________     DEPOSITADO: %.2f     _________*\n",z);
																	printf("\n*_________       CAMBIO:  0.00      ________*\n");
																	printf("\n*********************************************\n");
																	printf("\tIntrodusca el resto\n");
																	scanf("%f",&dep);
																	z=z+dep;
																	if(z>clientes[usu].deuda)
																		{
																			k1=z-clientes[usu].deuda;
																			clientes[usu].deuda=0;
																			printf("\n");
																			printf("\n*********************************************\n");
																			printf("\n*             CFEMATICO                     *\n");
																			printf("\n*_____  CLIENTE: %s  ______*\n",clientes[usu].nombre);
																			printf("\n*________       ADEUDO: %.2f       _______*\n",clientes[usu].deuda);
																			printf("\n*________     DEPOSITADO: %.2f     _________*\n",z);
																			printf("\n*_________       CAMBIO:  %.2f      ________*\n",k1);
																			printf("\n*********************************************\n");
																			
																		}//mayor if-while
												 			}//while <
												 				if(z==clientes[usu].deuda)
												 					{
												 						printf("\n*********************************************\n");
																		printf("\n*             CFEMATICO                     *\n");
																		printf("\n*_____  CLIENTE: %s  ______*\n",clientes[usu].deuda);
																		printf("\n*________       ADEUDO: %.2f       _______*\n",clientes[usu].deuda-z);
																		printf("\n*________     DEPOSITADO: %.2f     _________*\n",z);
																		printf("\n*_________       CAMBIO:  0.00      ________*\n");
																		printf("\n*********************************************\n");

												 					}
												 	    clientes[usu].deuda=0;
													      
													 } //if <
												 	else
												 	{
							
												 		if(clientes[usu].deuda==dep)
														 {
												 			clientes[usu].deuda=0;
															printf("\n");
															printf("\n*********************************************\n");
															printf("\n*             CFEMATICO                     *\n");
															printf("\n*_____  CLIENTE: %s  ______*\n",clientes[usu].nombre);
															printf("\n*________       ADEUDO: %.2f       _______*\n",clientes[usu].deuda);
															printf("\n*________     DEPOSITADO: %.2f     _________*\n",dep);
															printf("\n*_________       CAMBIO:  0.00      ________*\n");
															printf("\n*********************************************\n");

												 	     }
												    }
												}
							
							break;
							case 'M': case'm':
							break;
							default :printf ("Opcion no valida ...\n");
							
					}//menu de opc
			
			}//usuario dentro
			
			printf("\n");
			printf("\n");
			printf(">>>>  GRACIAS POR SU PREFERENCIA  <<<<\n");
			
			printf("\n");
			
		 }while(true);//menu principal
	
	return 0;
}

