//Arreglo de Estructuras
//Nombre con malloc

#include <stdio.h>
#include <stdlib.h>

typedef struct{
        int matricula;
        char nombre[20];
        float promedio;
        }Student;

int LlenarAE(Student *);
void ImprimirAE(Student *,int);
void AlmacenarArchivo(FILE *,FILE *,Student *, int);

int main(){
    int n = 0;
    char opc;
    
    //Apertura archivos    
    FILE *fp1,*fp2;
    fp1 = fopen("Aprobados.txt","a+t");
    fp2 = fopen("Reprobados.txt","a+t");
    
    if((fp1 == NULL)||(fp2 == NULL)){
            printf("\nError al abrir el archivo");
            return 1;
            }
    
    //Estructura
    Student *A;
    A = (Student *)malloc(1*sizeof(Student));
    
    //Invocación funciones - Menú
    do{
       fflush(stdin);
       printf("\nMen\xA3");
       printf("\nA Lectura registros");
       printf("\nF Archivar registros");
       printf("\nS Salir");
       printf("\nOpci\xA2n == > ");
       scanf("%c",&opc);
       
       switch(opc){
                   case 'a': case 'A':
                        n = LlenarAE(A);
                        ImprimirAE(A,n);
                        break;
                   case 'f': case 'F':
                        AlmacenarArchivo(fp1,fp2,A,n);
                        break;
                   case 's': case 'S':
                        break;
                   default:
                           printf("\nOpción inv\xA0lida");
                           break;
                   }
                 
    }while(toupper(opc) != 'S');

        
    //Cierre archivos
    fclose(fp1);
    fclose(fp2);
    //Liberación memoria
    free(A);
    getch();
    return 0;
    }

int LlenarAE(Student *A){
     int i = 0;
     printf("\nLlenando arreglo de estructuras");
     do{
        printf("\n");
        printf("Matricula: ");
        scanf("%d",&((A+i)->matricula));
        
        if(((A+i)->matricula) != 0){
                             printf("Nombre: ");
                             scanf("%s",((A+i)->nombre));
                             printf("Promedio: ");
                             scanf("%f",&((A+i)->promedio));
                             printf("\n");
                             i++;
                             A = (Student *)realloc(A,(i+1)*sizeof(Student));
                             }
        
     }while(((A+i)->matricula) != 0);
     
     return i;         

     }
     
     
void ImprimirAE(Student *A,int n){
     int i;
     printf("\nImprimiendo arreglo de estructuras");
     for(i = 0; i < n; i++){
          printf("\nMatricula: %d",(A+i)->matricula);
          printf("\nNombre: %s",(A+i)->nombre);
          printf("\nPromedio: %f",(A+i)->promedio);
          printf("\n");
          }
     }

void AlmacenarArchivo(FILE *fp1,FILE *fp2,Student *A, int n){
     int i;
     
     for(i = 0; i < n; i++){
           if(((A+i)->promedio)>=6){
                                    fprintf(fp1,"Matricula: %d ",(A+i)->matricula);
                                    fprintf(fp1,"Nombre: %s ",(A+i)->nombre);
                                    fprintf(fp1,"Promedio: %f \n",(A+i)->promedio);
                                    }
           else{
                fprintf(fp2,"Matricula: %d ",(A+i)->matricula);
                fprintf(fp2,"Nombre: %s ",(A+i)->nombre);
                fprintf(fp2,"Promedio: %f \n",(A+i)->promedio);
                }
           
          }
     }

