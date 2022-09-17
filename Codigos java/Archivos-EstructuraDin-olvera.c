/*arreglo dinamico de estructuras y escritura de estos datos a un archivo binario*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



struct ITEM  /* definir estructura*/
	{
		
	 char 		nombre[50];
	 float 		precio;
		
		
	};



/*---------------prototipo de funciones*/
void menu(char *opcion);  /*paso de parametro por referencia*/

void alta(struct ITEM *ELEM, int *conta);

void creararchivo(char NOM[30]);

void muestraarchivo(char NOM[30]);



/*---------------variables globales*/
struct ITEM *ARRdin;  /*apuntador necesario para manejo de malloc, realloc, calloc*/

char 	NOMBRE[30]="prod.ven";
FILE 	*A;



/*-------------------funcion principal*/
int main ()
{
	
	 char		op;
	 int		i,cont;
	
	
	cont=0;  /*contador necesario para determinar cuantos elementos hay en el arreglo dinamico*/
	creararchivo(NOMBRE); 
	
	do
		{
		 
		 
		 menu(&op);  /*función que muestra el menu*/
		 switch(op)
		 {
			 
			 
		 case 'A':
			 
			 muestraarchivo(NOMBRE);
			 
			 break;
			 
		 case 'N':
			 
			 system("cls");
			 printf("<  Alta de producto ... >\n");
			 /*crear un nuevo elemento en el arreglo dinamico ARRdin*/
			 ARRdin=(struct ITEM*)realloc(ARRdin,(cont+1)*sizeof(struct ITEM));
			 
			 /*solicitar y almacenar en el cont-esimo elemento de ARRdin*/
			 alta(&ARRdin[cont],&cont);
			 
			/* escribir datos al archivo*/
			 A=fopen(NOMBRE,"ab");
			 fwrite(&ARRdin[cont-1],sizeof(struct ITEM),1,A);			 
			 fclose(A);
			 
			 
			 
			 break;
			 
		 case 'V':
			 
			/* visualizar los elementos almacenados en el arreglo dinamico*/
			 system("cls");
			 printf("Los productos en la base de datos son : \n\n");
			 for (i=0;i<cont;i++)
			 {
			  printf("--Producto %d-----\n",i+1);
			  puts(ARRdin[i].nombre);
			  printf("%f \n",ARRdin[i].precio);
			 	 
			 }
			 printf("\n\n < Presione tecla para continuar ...>");
			 getchar();
			 
			 break;
			 
		 }
		
		}
	
	while (op!='S');
	
	
	
	free(ARRdin);  /*liberar memoria*/
	
	return 0;
}




/*-------funciones propias*/

void menu(char *opcion)
{
	
	system("cls");	
	printf("Base de datos de productos\n");
	printf("N) Nuevo producto\n");
	printf("V) Ver productos\n");
	printf("A) Mostrar datos del archivo\n");
	
	printf("S) Salir\n");
	printf("					Opcion: ");
	*opcion=toupper(getchar());
	fflush(stdin);
	
	
}



void alta(struct ITEM *ELEM, int *conta)
{
	printf("Producto:");
	gets((*ELEM).nombre);

	fflush(stdin);
	printf("Precio $:");
	scanf("%f",&(*ELEM).precio);
	fflush(stdin);
	
	*conta=(*conta)+1;  /*actualizar contador   (*conta)++*/
	printf("\n\n < Producto dado de alta ...>");
	getchar();
	fflush(stdin);
	
}

void creararchivo(char NOM[30])
{
	
	A=fopen(NOM,"rb");
	
	if (A==NULL)   /*no existe */
	{
		
		A=fopen(NOM,"wb");
		fclose(A);
	}
		
	else
		fclose(A);
	
	
}


void muestraarchivo(char NOM[30])
{
 struct ITEM DATO;
	
	
 A=fopen(NOM,"rb");
 
 system("cls");
 printf("Los elemento almacenados en el archivo son:\n");
 while (!feof(A))
 {
	
	if (  fread(&DATO,sizeof(struct ITEM),1,A) )
	{
	 printf("--------------------\n");	
	 puts(DATO.nombre);
	 printf("%f",DATO.precio);
	
	 
	 printf("--------------------\n");
	 
	}
	 
 }
 
 
 fclose(A);
	
 getchar();	
	
}

