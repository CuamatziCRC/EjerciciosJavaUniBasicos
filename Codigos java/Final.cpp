#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct clientes{
	char nombre[100];
	float deuda;
	char medidor[10];
	
};
//Prototipos de las funciones
void alta(struct clientes *usu, int *cont);
main()
{
	struct clientes *usu;//Puntero de la estructura
	char opc1,opc2,opc3;
	unsigned int i,j,temp,sistem=0,pass=12345,cont=0;
	//Apertura de archivo   
    FILE *f;
    f = fopen("usuarios.txt","a+t");
    
    if(f == NULL)
	{
            printf("\nError al abrir el archivo\n");
            printf("\n\tLamentamos que no pueda ingresar\n");
            return 1;
    }

	do{
		temp=0;
		system("cls");
			printf("Bienvenido al cfe-matico");
		printf("\n\tMenu Principal\n\n\tA>Administrador\n\n\tU>Usuarios\n\nElija su opcion  \t:");
		scanf("%c", &opc1);
		fflush(stdin);
 		switch (opc1)
 		{	 case'a': 
 			{
 				system("cls");
				 printf("\n\tMenu del administrador\n");
				 printf("\n\tE>Extra (Agregar usuarios)\n");
				 printf("\n\tS>Salir (Apagar el sistema)\n");
				 printf("\n\tElija su opcion\t:\n\t");
				 scanf("%c",&opc2);
				 fflush(stdin);
				 switch(opc2)
				 
				 {
				 	case'e':
				 		{
				 		  system("cls");
						 printf("\n\tAgregar usuarios\n\t");
						 getchar();
						  /*crear un nuevo elemento en el arreglo dinamico 	struct clientes *usu;*/
			 			  usu=(struct clientes*)realloc(usu,(cont+1)*sizeof(struct clientes));
			 			  /*solicitar y almacenar en el cont-esimo elemento de ARRdin*/
							void alta(struct clientes *usu, int *cont);
							 
							/* escribir datos al archivo*/
							  f=fopen("usuarios.txt","a+t");
							 fwrite(&usu[cont-1],sizeof(struct clientes),1,f);			 
							 fclose(f);
				 		  
  						  break;
						}
				 		
				 	case's':
				 		{
				 			do{
				 				temp=0;
								system("cls");
								printf("\n\tBienvenido administrador de su contraseña\n\t");
				 				scanf("%d",&temp);
				 			}while(temp!=pass);
				 			sistem=1;
							 break;
				 		}
	     		 }//fin del segundo menu
 				//
				 break;
 			}
 			 case 'u'   :{
 			 	system("cls");
                printf("\n\tMenu del usuario\n");
                 printf("\n\tP>Pagar (pagar servicio electrico)\n");
				 printf("\n\tX>Exit (Apagar el sistema si sabe la contraseña)\n");
				 printf("\n\tElija su opcion\t:\n");
				 scanf("%c",&opc3);
				 fflush(stdin);
				 switch(opc3)
				 {
				 		case'p':
				 		{
				 			
							printf("\n\tBienvenido usuario\n\n\tPago del servicio\n");
				 	        sistem=1;
							 break;
				 		}
						  
						  case'x':
				 		{
				 			do{
				 				temp=0;
								system("cls");
								printf("\n\tBienvenido de la contraseña\n\t");
				 				scanf("%d",&temp);
				 			}while(temp!=pass);
				 			sistem=1;
							 break;
				 		}	
				 	
				 }
                 
                break;
               }
 		}//fin del switch
	}while(sistem==0);
}
//definicion de las funciones
/*
struct clientes{
	char nombre[100];
	float deuda;
	char medidor[10];
	
};
*/
void alta(struct clientes *usu)
{
	
}
