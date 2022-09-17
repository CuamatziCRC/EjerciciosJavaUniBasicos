import java.util.Scanner;

public class MRusa {

 public static void main(String[] args) {

  Scanner sc = new Scanner(System.in);
  int n,m;
  n=sc.nextInt();
  m=sc.nextInt();
  sc.close();
  int sol = mult(n,m);
  System.out.println(sol);

 }
 public static int mult (int n, int m){
  if(m==1){
   return n*2;
  }else{
   if(m%2==0){
    return mult(n*2,m/2);
   }else{
    return n+mult(n*2,m/2);

   }
  }

 }
}