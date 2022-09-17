#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
struct datos
 {
 char nom[100];
 long int mat;
 char genero;
 long int grado;
 char nac[40];
 };
 
struct datos estud[100], *str=&estud[0];

int creusrs();
int addusrs();
int downusers(struct datos *str, int *m);
int cargusers(struct datos *str, int *m);
void coparch();
void consade(struct datos *str,int *p,int maximo);
void cambusr(struct datos *str,int *p,int maximo);

main()

{
 char opcion;
 int pos=100, maximo=0, *p=&pos, *m=&maximo, op1=0, op2=0, f1=0, f2=0;
 
 printf("\nPROGRAMACION ORIENTADA A OBJETOS\n");
	printf("\n\nBienvenido\n\n");
	do
	{
	  printf("En que modo desea entrar\n");
	  printf("1.-Modo Administrador\n");
          printf("2.-Modo Usuario\n");
          printf("3.-Salir\n");
	    scanf("%d%*c",&op1);
	      if (op1==3)
		{
		   f1=1;
		}
                else
		{
			if(op1==1)
			{
			 printf("\n BIENVENIDO AL MODO ADMINISTRADOR\n");
			 printf("\n Que desea realizar");
			 printf("\n!!!!!!WARNING!!!!!\n");
		       	 printf("TENGA EN CUENTA QUE SI A CREADO UN ARCHIVO ANTERIORMENTE LO PODRIA DESTRUIR CON OPCION 1\n");
			 printf("\n1.-Crear archivo de estudiantes\n");
                         printf("2.-Agregar estudiantes\n");
		           scanf("%d%*c",&op2);
				if(op2==1)
				{
					creusrs();
				}
				else
				{
					addusrs();
				}
			}
			else
			{
				f2=0;
				downusers(str,m);
				getchar();
				do
  				{
			
					printf("\nMenu De Opciones");
   					printf("\n");
    					printf("A.- Busqueda De Estudiante\n");
   					printf("C.- Cambio De Estudiante\n");
    					printf("Selecccione una Opcion...\n");
   					scanf("%c%*c",&opcion);
   					printf("\n");
					if(toupper(opcion)=='S')
					{
						f2=1;
						cargusers(str,m);
                                                coparch();
					}
					else
					{
   						switch(toupper(opcion))
						{
							case 'A':
							{
      								consade(str,p,maximo);
       								break;
							}
							//fin del caso 1
							
							case 'C':
							{
      								cambusr(str,p,maximo);
       								break;
      							}
						}
					}
				}
				while(f2!=1);
			}
			
		}
	}						
	while(f1!=1);	
	return (0);
}
//primera funcion... crear archivo estudiantes
int creusrs()
	{
		char temp[60];
		char dire[20];
		int arer=0;
		FILE *fich;
		struct datos r;

		if ((fich=fopen("betauser.dat","wb"))==NULL)
		{	
			printf("\n Error en la apertura del archivo \n");
			arer=1;
		}
		else
		{
			getchar();
			printf("Para terminar de introducir estudiantes introduzca FIN\n");
			printf("\nIngresa el Nombre Del Esudiante\n");
			gets(temp);
			while(strcmp(temp,"FIN")!=0)
			{
				strcpy(r.nom,temp);
       				printf("\nIngresa La Matricula\n");
        			scanf("%ld%*c", &r.mat);
                                printf("\nIngresa el genero\n");
                                scanf("%c%*c", &r.genero);
                                printf("\nIngresa el grado\n");
                                scanf("%ld%*c", &r.grado);
        			printf("\nIngresa La direccion\n");
        			gets(dire);
				strcpy(r.nac,dire);
        			printf("\nIngresa El Nombre Del Estudiante\n");
				gets(temp);
				fwrite(&r,sizeof(r),1,fich);
			}
			fclose(fich);
		}
		return(arer);
	}

//segunda funcion... agregar estudiantes
int addusrs()
	{
		FILE *fich;
		char temp[60];
		char dire[20];
		int arer=0;
		struct datos r;		

		if ((fich=fopen("betauser.dat","ab"))==NULL)
			{	
				printf("\n Error en la apertura del archivo \n");
				arer=1;
			}
			else
			{
				getchar();
				printf("Agrege usuario, al finalizar de FIN");
				printf("\nIngresa el Nombre Del Estudiante\n");
				gets(temp);
				while(strcmp(temp,"FIN")!=0)
				{
					strcpy(r.nom,temp);
       					printf("\nIngresa La Matricula\n");
        			        scanf("%ld%*c", &r.mat);
                                        printf("\nIngresa el genero\n");
                                        scanf("%c%*c", &r.genero);
                                        printf("\nIngresa el grado\n");
                                        scanf("%ld%*c", &r.grado);
        			        printf("\nIngresa la fecha de nacimiento\n");
        			        gets(dire);
					strcpy(r.nac,dire);
        				printf("\nIngresa el Nombre Del Estudiante\n");
					gets(temp);
					fwrite(&r,sizeof(r),1,fich);
				}
				fclose(fich);
			}
		return(arer);
	}

//tercera funcion
int downusers(struct datos *str,int *m)
	{
		int i=0,arer=0;
		struct datos g;
		FILE *f;

		if ((f=fopen("betauser.dat","rb"))==NULL)
		{	
			printf("\n Error en la apertura del archivo \n");
			arer=1;
		}
		else
		{
			fread(&g,sizeof(g),1,f);
			while(!feof(f))
			{
				strcpy((*(str+i)).nom,g.nom);
        			(*(str+i)).mat=g.mat;
                                (*(str+i)).genero=g.genero;
                                (*(str+i)).grado=g.grado;
				strcpy((*(str+i)).nac,g.nac);
        			*m=i;
        			i++;
        			fread(&g,sizeof(g),1,f);
        		}
		}
		return(arer);
	}

//cuarta funcion
int cargusers(struct datos *str, int *m)
	{
		FILE *fich;
		char temp[60];
		int arer=0, i=0;
		struct datos r;		

		if ((fich=fopen("betauser.dat","wb"))==NULL)
		{	
			printf("\n Error en la apertura del archivo \n");
			arer=1;
		}
		else
		{
			for(i=0;i<=*m;i++)
			{
				strcpy(r.nom,(*(str+i)).nom);
       				r.mat=(*(str+i)).mat;
                                r.genero=(*(str+i)).genero;
                                r.grado=(*(str+i)).grado;
				strcpy(r.nac,(*(str+i)).nac);
				fwrite(&r,sizeof(r),1,fich);
			}
			fclose(fich);
		}
		return(arer);
	}

//quinta funcion
void coparch()
	{
		FILE *org,*dest;
		int arer=0;
		struct datos r,g;
		if (((org=fopen("betauser.dat","rb"))==NULL) || ((dest=fopen("archuser.dat","w+b"))==NULL))
		{	
			printf("\n Error en la apertura de los archivos \n");
			arer=1;
		}
		else
		{
			fread(&g,sizeof(g),1,org);
			while(!feof(org))
			{
				r.mat=g.mat;
                                r.genero=g.genero;
                                r.grado=g.grado;
				strcpy(r.nom,g.nom);
				strcpy(r.nac,g.nac);
				fwrite(&r,sizeof(r),1,dest);
				fread(&g,sizeof(g),1,org);
			}
			fclose(org);
			fclose(dest);
		}
		return;
	}
//sexta funcion.. busqueda de estudiante
void consade(struct datos *str,int *p,int maximo)
	{
		int auxnum=0, i=0, j=0;
		if(maximo>=0)
            	{
            		i=0;
            		j=0;
            		*p=100;
            		printf("Consulta De Estudiante\n");
            		printf("Ingrese La Matricula Del EStudiante\n");
            		scanf("%d%*c",&auxnum);
            		while(j<=maximo && *p==100)
            		{
                		if(auxnum!=(*(str+i)).mat)
				{
                    			i++;
                		}
                		else
                		{
                    			*p=i;
                		}
                		j++;
				}
           			if(*p!=100)
            			{
            				printf("\nBUSQUEDA DE ESTUDIANTE\n");
            				printf("\nNombre Del Estudiante\t: ");
            				printf("%s", (*(str+(*p))).nom);
            				printf("\nMatricula\t: ");
            				printf("%ld", (*(str+(*p))).mat);
                                        printf("\nGenero: ");
                                        printf("%c", (*(str+(*p))).genero);
                                        printf("\nGrado\t: ");
                                        printf("%ld", (*(str+(*p))).grado);
            				printf("\nFecha de nacimiento\t: ");
            				printf("%s", (*(str+(*p))).nac);
            			}
            			else
            			{
                			printf("\nEstudiante No Encontrado\n");
            			}
		}
		else
            	{
                	printf("\nNohay Ningun Estudiante Registrado\nLe Recomendamos Registrar Algunos\n");
            	}
		return;
	}

//septima funicon... cambio de estudiante
void cambusr(struct datos *str,int *p,int maximo)
	{
		int i=0,auxnum=0,j=0;
		if(maximo>=0)
            	{
            		i=0;
            		j=0;
            		*p=100;
            		printf("\nCambio De Estudiante\n");
            		printf("Ingrese La Matricula Del Estudiante\n");
            		scanf("%d%*c",&auxnum);
            		while(j<=maximo && *p==100)
            		{
               			if(auxnum!=(*(str+i)).mat)
                		{
                    			i++;
                		}
                		else
                		{
                    			*p=i;
                		}
                	j++;
            		}
            		if(*p!=100)
            		{
                		printf("\nCONSULTA DE ESTUDIANTE\n");
            			printf("\nNombre Del EStudiante: ");
            			printf("%s", (*(str+(*p))).nom);
            			printf("\nMatricula: ");
            			printf("%ld", (*(str+(*p))).mat);
                                printf("\nGenero: ");
                                printf("%c", (*(str+(*p))).genero);
                                printf("\nGrado\t: ");
                                printf("%ld", (*(str+(*p))).grado);
            			printf("\nFecha de nacimiento\t: ");
            			printf("%s", (*(str+(*p))).nac);	
            		}
            		else
            		{
                		printf("\nEstudiante No Encontrado\n");
            		}
        	}
        	else
            	{
                	printf("\nNohay Ningun Usuario Registrado\nLe Recomendamos Registrar Algunos\n");
            	}
		return;
	}

