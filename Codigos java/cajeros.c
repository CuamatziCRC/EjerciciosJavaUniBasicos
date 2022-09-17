#include <stdio.h>
#include <math.h>


main ()
{
	int band,retiro,pago,abono,cambio;
	int	sal_act=5000,ade_agua=200,ade_tv=500,ade_luz=300,ade_tel=250;
	char opc,opc2,cad3[10],con3[10];	
	char cad[10]="Juan",cad1[10]="Mariel",cad2[10]="Eduardo";	
	char con[10]="12345",con1[10]="67891",con2[10]="65432";
    printf("Este programa en c hace la simulacion de una caja bancaria\n");
	do
	{	
	printf("Usuario: \n");
	gets(cad3);
	
	printf("Contraseña: \n");
	gets(con3);

	if((strcmp(cad3,cad)==0)||(strcmp(cad3,cad1)==0)||(strcmp(cad3,cad2)==0)&&(strcmp(con3,con)==0)||(strcmp(con3,con1)==0)||(strcmp(con3,con2))==0)
	{
	    band=0;
	}	
		if(band==0)
		{
		/*Menu*/
		printf("Bienvenido\n");
		printf("r) Retiro\n");
		printf("p) Pagos\n");
		printf("s) Saldos\n");
		printf("e) Salir\n");
		scanf("%c",opc);
			switch(opc)
			{
			case 'r':
				{
				printf("Retiro de dinero\n");
				printf("Ingrese la cantidad a retirar:\n" );
				scanf("%d",&retiro);
					if(retiro<=sal_act)
						{
							sal_act=sal_act-retiro;
						}
				break;
				}
			case 'p':
				{
				/*Submenu*/
				printf("Pagos de servicios:\n");
				printf("a) Agua\n");
				printf("c) Tv de paga\n");
				printf("l) Luz\n");
				printf("t) Telefonia\n");
					switch(opc2)
						{
						case 'a':
							{
							printf("Ingrese cantidad a pagar\n");
							scanf("%d",&pago);
								while(pago<=ade_agua)
									{
									printf("Ingrese cantidad a pagar\n");
									scanf("%d",&abono);
									pago=pago+abono;
									}/*while*/
								if(pago>ade_agua)
								{
									cambio=pago-ade_agua;
									printf("Su cambio es de: %d",cambio);
								}
								
							break;
							}
						case 'c':
							{
							printf("Ingrese cantidad a pagar\n");
							scanf("%d",&pago);
								while(pago<=ade_tv)
									{
									printf("Ingrese cantidad a pagar\n");
									scanf("%d",&abono);
									pago=pago+abono;
									}/*while*/
								if(pago>ade_tv)
								{
									cambio=pago-ade_tv;
									printf("Su cambio es de: %d",cambio);
								}
							break;
							}
						case 'l':
							{
							printf("Ingrese cantidad a pagar\n");
							scanf("%d",&pago);
								while(pago<=ade_luz)
									{
									printf("Ingrese cantidad a pagar\n");
									scanf("%d",&abono);
									pago=pago+abono;
									}/*while*/
								if(pago>ade_luz)
								{
									cambio=pago-ade_luz;
									printf("Su cambio es de: %d",cambio);
								}
							break;
							}
						case 't':
							{
							printf("Ingrese cantidad a pagar\n");
							scanf("%d",&pago);
								while(pago<=ade_tel)
									{
									printf("Ingrese cantidad a pagar\n");
									scanf("%d",&abono);
									pago=pago+abono;
									}/*while*/
								if(pago>ade_tel)
								{
									cambio=pago-ade_tel;
									printf("Su cambio es de: %d",cambio);
								}
							break;
							}
						}/*switch2*/
				break;
				}
			case 's':
				{
					printf("Su saldo actual es de:,%d",sal_act);
					break;
				}
			}
		}
		else{
			printf("Datos erroneos\n");
		}
	}
	while(opc!='e');
}
