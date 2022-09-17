//MatrizSimetrica
/*
Determinar si una matriz es simetrica.la matrzi es genera  con numeros aleatorios de 0a7.
el programa generara matrizes hasta encontrar una que sea simetrica
*/
import java.io.*;
//import junit.framework.TestCase;
import java.util.Random;
class MatrizSimetrica  { 
    BufferedReader entrada = new BufferedReader(new InputSreamReader(System.in));
    public static void main(String[] args)throws IOException
     {
        int a[][];
        int i,j,n;
        boolean es_sim;
        System.out.print("Numero de filas y columnas:\t");
        System.out.flush();
        n= Integer.parseInt(entrada.readLine());
        a=new int [n][n];
        do{
            gen_mat(a);
            es_sim=simetrica(int a , int n);
            if (es_sim) {
               System.out.println("\n\tEncontrada la Matriz Simetrica\n"); 
               escribe_mat(a);
            }
        }while (!es_sim);
    }
   
   static void gen_mat(int a[][]){
    int i,j;
    final int N=8;
    for (i=0;i<a.length ;i++ ) {
        for (j=0;j<a[i].length ;j++ ) {
            a[i][j]=(int) Math.random()*N;
        }
    }

   }
   static boolean simetrica(int a[][], int n)
   {
    int i,j;
    boolean es_simetrica = true;
    for (i=0;i<a.length-1&&es_simetrica ;i++ ) {
        for (j=i+1;j<a[i].length&& es_simetrica ;j++ ) {
            //asigna si es  falso
            es_simetrica=a [i][j] == a [j][i];
        }
        
    }
    return es_simetrica;
   } 

   static void escribe_mat(int a [][]){
    int i,j;
    System.out.println("\t Matriz analisada");
    System.out.println("\t\n");
    for (i=0;i<a.length ;i++ ) {
        System.out.print("\t");
        for (j=0;j<a[i].length ;j++ ) {
            System.out.print(a[i][j]+(j==a[i].length-1?"\n":""));
        }
        
    }
   }
}
