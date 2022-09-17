#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct clientes{
	char nombre[100];
	float deuda;
	char medidor[10];
	
}usu;
//Prototipos de las funciones
int Llenar(usu *);
void Imprimir(usu *,int);
void AlmacenarArchivo(FILE *,usu *, int);
main()
{
	//Estructura
    usu *u;
    u = (usu *)malloc(1*sizeof(usu));
	char opc1,opc2,opc3;
	 int i,j,temp,sistem=0,pass=12345,cont=0;
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
						 int LlenarAE(usu *u);
						 void AlmacenarArchivo(FILE *f,usu *u, int n);
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
typedef struct clientes{
	char nombre[100];
	float deuda;
	char medidor[10];
	
}usu;
};
//Estructura
    usu *u;
    u = (usu *)malloc(1*sizeof(usu));
	//Apertura de archivo   
    FILE *f;
    f = fopen("usuarios.txt","a+t");
*/
int Llenar(usu *u){
     int i = 0;
     printf("\nLlenando arreglo de estructuras");
     do{
        printf("\n");
        printf("Medidor: ");
        scanf("%d",&((u+i)->medidor));
        
        if(((u+i)->medidor) != 0){
                             printf("Nombre: ");
                             scanf("%s",((u+i)->nombre));
                             printf("Deuda: ");
                             scanf("%f",&((u+i)->deuda));
                             printf("\n");
                             i++;
                             u = (usu *)realloc(u,(i+1)*sizeof(usu));
                             }
        
     }while(((u+i)->medidor) != 0);
     
     return i;         

     }

void AlmacenarArchivo(FILE *f,usu *u, int n)
{
     int i;
     
     for(i = 0; i < n; i++){
                fprintf(f,"Medidor: %c ",(u+i)->medidor);
                fprintf(f,"Nombre: %s ",(u+i)->nombre);
                fprintf(f,"Deuda: %f \n",(u+i)->deuda);
                
           
          }
     }

