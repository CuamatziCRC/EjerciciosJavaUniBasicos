#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
/*
Las funciones de asignación de memoria dinámica en C se definen en la cabecera stdlib.h. (cstdlib en C++)

Función	Descripción
malloc	asigna el número especificado de bytes
realloc	aumenta o disminuye el tamaño del bloque de memoria especificada. Reasigna si es necesario
calloc	asigna el número especificado de bytes y los inicializa a cero(0).
free	libera el bloque de memoria especificada de nuevo al sistema
*/
//Estrcuctura de clientes
struct  usuarios{
	char nombre[100];
	unsigned  int medidor;
	float deuda;
} ;
/*---------------variables globales*/
struct usuarios *u;  /*apuntador necesario para manejo de malloc, realloc, calloc*/
char 	NOMBRE[30]="cfe.txt";
FILE 	*A; //Puntero del archivo

//Funciones
void menuprincipal(char *opcion1);
void menucliente();
void menuadministrador();
int alta(struct usuarios *u,int *contador);
int pagos(struct usuarios *u,int *contador);
void creararchivo(char NOM[30]);

//Cuerpo del programa
main()
{
	char opc,opc1,opc2;
	int s=0,i,contador,pass=12345,temp;
	contador=0;
	creararchivo(NOMBRE); 
	do{
		menuprincipal(&opc);
		switch (opc)
		{
			case 'a': case'A'://Menu del administrador
				menuadministrador();
				switch(opc1);
					{  case 'n': case'N'://submenu del admi nuevo usurio
					  
						system("cls");
						 printf("<  Alta de producto ... >\n");
						 /*crear un nuevo elemento en el arreglo dinamico ARRdin*/
						 u=(struct usuarios*)realloc(u,(contador+1)*sizeof(struct usuarios));
						 
						 /*solicitar y almacenar en el cont-esimo elemento de ARRdin*/
					
						alta(&u[contador],&contador);
						 
						/* escribir datos al archivo*/
						 A=fopen(NOMBRE,"ab");
						 fwrite(&u[contador-1],sizeof(struct usuarios),1,A);			 
						 fclose(A);
						break;
					case's': case'S': //salir del sistema
						do{
							printf("\n\tAdministrador usted saldra del sistema\n");
							printf("\tde su contraseña por favor...\t");
							scanf("%d",&pass);
							printf("\n");
							printf("Que haya tenido un gran dia....");
						}while(pass!=12345);
						s=1;//falta cerrar el archivo
						break;//fin de salir 
						
					}
					break;//salir del caso del administrador
					
			case 'c': case'C': //Menu del cliente
					menucliente();
					switch(opc2);
						{
							case 'p': //case'P':
								int pagos(struct usuarios *u,int *contador);
							break;
							case 'm': case'M':
								printf("\tRegresando al menu inicial.....\n\n"); 
								//salir del menu
								break;
								
						}
						
			default : printf("\n\tOpcion erronea ...\n");
			printf("\n\tPor favor intente de nuevo\n");	
			break;	
		}
	}while(s==0);//while del sistema principal
		free(u); 
}//fin del cuerpo del programa


//Definicion de las Funciones
void creararchivo(char NOM[30])
{
	
	A=fopen(NOM,"rb");
	
	if (A==NULL)   /*no existe */
	{
		printf("\n\tEl documento no se pudo abrir\n");
		A=fopen(NOM,"r+b");
		fclose(A);
	}
		
	else
	{
	  printf("\t\nSe abrio con exito el documento para iniciar...\n");
		fclose(A);
    }
	
}

void menuprincipal(char *opc)
{
	
	system("cls");	
	printf("\n\t||||||Bievenido CFE-MATICO||||||\n");
	printf("\tE) Estado actual de su cuenta\n");
	printf("\tP) Pago de su deuda\n");
	printf("\tElija su opcion....\n");
	printf("\t					Opcion: ");
	*opc=toupper(getchar());
	fflush(stdin);
	
	
}
void menucliente(char *opc2)
{
	
	system("cls");	
	printf("\n\t>>>>>Bievenido Administrador<<<<<\n");
	printf("\tN) Nuevo cliente\n");
	printf("\tS) Salir del sistema\n");
	printf("\tElija su opcion....\n");
	printf("\t					Opcion: ");
	*opc2=toupper(getchar());
	fflush(stdin);
	
	
}
void menuadministrador(char *opc1)
{
	
	system("cls");	
	printf("\n\t<<<<<Bievenido Administrador>>>>>\n");
	printf("\tN) Nuevo cliente\n");
	printf("\tS) Salir del sistema\n");
	printf("\tElija su opcion....\n");
	printf("\t					Opcion: ");
	*opc1=toupper(getchar());
	fflush(stdin);
	
	
}



int alta(struct usuarios *u,int *contador) //al definir funciones ya no lleva ;
{
	printf("Nombre de usuario:");
	gets((*u).nombre);
	printf("Numero del medidor");scanf("%d",&(*u).medidor);
    fflush(stdin);
	printf("deuda $:");
	scanf("%f",&(*u).deuda);
	fflush(stdin);
	
	*contador=(*contador)+1;  /*actualizar contador   (*conta)++*/
	printf("\n\n < Ususario dado de alta ...>");
	getchar();
	fflush(stdin);
	
}

int pagos(struct usuarios *u,int *contador)

{

	 float efec=0,k1=0,z=0,x=0;
	 printf("\n");
	 printf("\n*********************************************\n");
	 printf("\n*             CFEMATICO                     *\n");
	 printf("\n*_____  CLIENTE: %s  ______*\n",(u+contador)->nombre);
	 printf("\n*________       ADEUDO: %.2f       _______*\n",(u+contador)->deuda);
	 printf("\n*________     DEPOSITADO: %.2f     _________*\n",efec);
	 printf("\n*_________       CAMBIO:  0.00      ________*\n");
	 printf("\n*********************************************\n");
	 printf("\n");
	 
	 printf("\nIntroduzca el dinero en la ranura\n");
	 scanf("%f",&efec);
	 
	 if (efec>(u+contador)->deuda){
		 k1=efec-(u+contador)->deuda;
		 (u+contador)->deuda=0; 
		 /*cambio*/
		 printf("\n");
		 printf("\n*********************************************\n");
		 printf("\n*             CFEMATICO                     *\n");
		 printf("\n*_____  CLIENTE: %s  ______*\n",(u+contador)->nombre);
		 printf("\n*________       ADEUDO: %.2f       _______*\n",(u+contador)->deuda);
		 printf("\n*________     DEPOSITADO: %.2f     _________*\n",efec);
		 printf("\n*_________       CAMBIO:  %.2f      ________*\n",k1);
		 printf("\n*********************************************\n");
	 }
	 else {
		 
		 if (efec<(u+contador)->deuda){
			 z=z+efec;
			 
			 while(z<(u+contador)->deuda){
				 x=(u+contador)->deuda-z;
				 printf("\n");
				 printf("\n*********************************************\n");
				 printf("\n*             CFEMATICO                     *\n");
				 printf("\n*_____  CLIENTE: %s  ______*\n",(u+contador)->nombre);
				 printf("\n*________       ADEUDO: %.2f       _______*\n",x);
				 printf("\n*________     DEPOSITADO: %.2f     _________*\n",z);
				 printf("\n*_________       CAMBIO:  0.00      ________*\n");
				 printf("\n*********************************************\n");
				 
				 printf("Introduce el resto\n");
				 scanf("%f",&efec);	
				 z=z+efec;
				 if (z>(u+contador)->deuda){
					 k1=z-(u+contador)->deuda;
					 (u+contador)->deuda=0;
					 printf("\n");
					 printf("\n*********************************************\n");
					 printf("\n*             CFEMATICO                     *\n");
					 printf("\n*_____  CLIENTE: %s  ______*\n",(u+contador)->nom);
					 printf("\n*________       ADEUDO: %.2f       _______*\n",(u+contador)->deuda);
					 printf("\n*________     DEPOSITADO: %.2f     _________*\n",z);
					 printf("\n*_________       CAMBIO:  %.2f      ________*\n",k1);
					 printf("\n*********************************************\n");
				 }
				 
				 
			 }
			 
			 if(z==(u+contador)->deuda){
				 printf("\n");
				 printf("\n*********************************************\n");
				 printf("\n*             CFEMATICO                     *\n");
				 printf("\n*_____  CLIENTE: %s  ______*\n",(u+contador)->nom);
				 printf("\n*________       ADEUDO: %.2f       _______*\n",(u+contador)->deuda-z);
				 printf("\n*________     DEPOSITADO: %.2f     _________*\n",z);
				 printf("\n*_________       CAMBIO:  0.00      ________*\n");
				 printf("\n*********************************************\n");
				 
				 
			 }
			 (u+contador)->deuda=0;	//funtero del arreglo
		 }
		 
		 
		 else {
			 if((u+contador)->deuda==efec){
				 (u+contador)->deuda=0;
				 printf("\n");
				 printf("\n*********************************************\n");
				 printf("\n*             CFEMATICO                     *\n");
				 printf("\n*_____  CLIENTE: %s  ______*\n",(u+contador)->nom);
				 printf("\n*________       ADEUDO: %.2f       _______*\n",(u+contador)->deuda);
				 printf("\n*________     DEPOSITADO: %.2f     _________*\n",efec);
				 printf("\n*_________       CAMBIO:  0.00      ________*\n");
				 printf("\n*********************************************\n");
				 
			 }
		 }
		 
	 }
 }
