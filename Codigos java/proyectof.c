#include <stdio.h>
#include <stdlib.h>
  struct datos
  {
   char nombre[50];
   long int no_cuenta;
   float saldo;
   float cable,luz,agua,telefono;
   float saldo_final;
   };
void administrador()
{
int cont=12345;
int i=0;
int con;
 printf ("Hola administrador\n\nPor favor ingrese su contraseña para salir \n\n");
 do{
    scanf("%d",&con);
    if ((cont)==(con))
    {
    printf("\nEs correcta  su contraseña ,adios:)\n\n");
    }
    else
    {printf("\n Es incorrecta la opcion intente de nuevo \n\n");
    i++;
    }
   }while(i<=3);
}//fin del void de administrador


void menup()
{
  printf("\n\nA)administracion\n\n");
  printf("\n\nC)Clientes \n\n");
}
void menuc()
{
   printf("\nC)consulta de saldo\n");
   printf("\nR)Retiro\n");
   printf("\nP)Pago de servicios\n");
   printf("\ne)Exit\n");
   printf("\tElija su opcion:\t");
   
}
void menua()
{
 printf("\nA)Altas de usuarios\n");
 printf("\nS)Salir\n");
}
void menupagos()
{
 printf("******Pago de servicios******\n\n");
 printf("\nA)Agua\n");
 printf("\nL)Luz\n");
 printf("\nc)television por cable\n");
 printf("\nT)Telefono\n");
 printf("\tE)Exit\salir\n");
 printf("\tElija su opcion:... \t");
}
void menutipo()
{
  printf("\nE)Efectivo\n");
  printf("\nS)saldo\n");
  printf("\tElija su opcion ...\t");
}  

main()

{
  struct datos *ap,*p,*ptr,clientes[10];
  char op5;
  printf("Programa que emula un cajero automatico\n");
  k = 0;
   ptr = clientes;
  while(1)
  {
 void menup()
  printf("Ingrese opcion\n");
  scanf(" %c",&op5);
  switch(op5)
  {
               
  case 'c' :{
  ap = clientes;
  printf("\tBIENVENIDO\n");
  printf("\tIngrese su numero de cuenta\n");
  printf("\t");
  scanf(" %ld" ,&cuenta);
  //ap = p;
  b1 = 0;
  for(i =-1; i < k; i++)
   {
    if(cuenta == (ap->no_cuenta) )
      {
       b1 = 1;
       p = ap ;
        }
   ap++;
   }
  if(b1 == 1)
  {
  ap = p;
  ap->saldo_final = ap->saldo;
  do
  {
  void menuc()
  switch(op1) 
  {
   case 'r':{
              printf ("\nIngrese monto:\n");
              scanf("\t%f",&retiro);
              if(retiro > ap->saldo)
                printf("Saldo insuficiente para realizar la operacion\n");
              else
               {
                ap->saldo_final = ap->saldo - retiro;
               printf("\n");
               }
              break;
             }
   case 'p':{   do
               {
                getchar();
                void menupagos()
                scanf("%c",&op2);
               switch (op2)
               {
                  case 'c':{
                            getchar();
                           void menutipo()
                            scanf(" %d",&op3);
                            switch(op3)
                            {
                              case 1:{
                                      printf("\n\nCABLE: %10.2f", ap->cable);
		                      printf("\n\nIngrese cantidad a pagar: ");
		                      scanf(" %f",&pago);
		                      if(pago > ap->cable)
                                       ban2 = 1;
                                      else 
                                       ban2 = 0;
		       	              if(ban2 == 1)
                                      {
		      	               cambio = pago  - ap->cable;
		      	               printf("\tGRACIAS POR SU PAGO...\n");
		      	               printf("Su cambio es de: %10.2f\n",cambio);
                                       ap->saldo_final = ap->saldo_final - ap->cable;
		     	               }
                                       else
		     	                if(pago == ap->cable)
                                        {
		    	                printf("\tGRACIAS POR SU PAGO...\n");
                                        ap->saldo_final = ap->saldo_final - ap->cable;
                                         }
		                        else
		     	                {
                                         abono = 0;
                                         if (pago < ap->cable)
                                         {
                                          ban = 1;
			                 while(ban == 1)
			                 {
			     	          printf("Ingrese cantidad a pagar: ");
                                          scanf(" %f",& abono);
			     	          pago = abono + pago;
                                          if (pago < ap->cable)
                                          ban = 1;
                                          else
                                          ban = 0;
			    	         }
                                         }
                                         if(pago > ap->cable)
		       	                 {
		      	                   cambio = pago  - ap->cable;
                                           printf("Su cambio es de: %10.2f",cambio);
		     	                   }
                                          printf("\tGRACIAS POR SU PAGO...\n");
                                         ap->saldo_final = ap->saldo_final - ap->cable;
                                         }
                                      break;
                                      }
                              case 2:{
                                      printf("\n\nCABLE: %10.2f\n",ap->cable);
                                      if(ap->cable > ap->saldo_final)
                                      printf("SALDO INSUFICENTE\n");
                                      else
                                      {
                                       ap->saldo_final = ap->saldo_final - ap->cable;
                                     printf("\tGRACIAS POR SU PAGO...\n");
                                       }
                                      break;
                                      }
                              }
                            break;
                            }
                       case 'l':{
                            getchar();
                          void menutipo()  
                         scanf(" %d",&op3);
                            switch(op3)
                            {
                              case 1:{
                                      printf("\n\nLUZ: %10.2f",ap->luz);
		                      printf("\n\nIngrese cantidad a pagar: ");
		                      scanf(" %f",&pago);
		                      if(pago > ap->luz)
                                       ban2 = 1;
                                      else 
                                       ban2 = 0;
		       	              if(ban2 == 1)
                                      {
		      	               cambio = pago  - ap->luz;
		      	               printf("\tGRACIAS POR SU PAGO...\n");
		      	               printf("Su cambio es de: %10.2f\n",cambio);
                                       ap->saldo_final = ap->saldo_final - ap->luz;
		     	               }
                                       else
		     	                if(pago == ap->luz)
                                        {
		    	                printf("\tGRACIAS POR SU PAGO...\n");
                                        ap->saldo_final = ap->saldo_final - ap->luz;
                                         }
		                        else
		     	                {
                                         abono = 0;
                                         if (pago < ap->luz)
                                         {
                                          ban = 1;
			                 while(ban == 1)
			                 {
			     	          printf("Ingrese cantidad a pagar: ");
                                          scanf(" %f",& abono);
			     	          pago = abono + pago;
                                          if (pago < ap->luz)
                                          ban = 1;
                                          else
                                          ban = 0;
			    	         }
                                         }
                                         if(pago > ap->luz)
		       	                 {
		      	                   cambio = pago  - ap->luz;
                                           printf("Su cambio es de: %10.2f",cambio);
		     	                   }
                                          printf("\tGRACIAS POR SU PAGO...\n");
                                          ap->saldo_final = ap->saldo_final - ap->luz;
                                         }
                                      break;
                                      }
                              case 2:{
                                      printf("\n\nLUZ: %10.2f\n",ap->luz);
                                      if(ap->luz >  ap->saldo_final)
                                      printf("SALDO INSUFICENTE\n");
                                      else
                                      {
                                       ap->saldo_final = ap->saldo_final - ap->luz;
                                     printf("\tGRACIAS POR SU PAGO...\n");
                                       }
                                      break;
                                      }
                              }
                            break;
                            }
                 case 'a':{
                            getchar();
                            void menutipo()
                            scanf(" %d",&op3);
                            switch(op3)
                            {
                              case 1:{
                                      printf("\n\nAGUA: %10.2f",ap->agua);
		                      printf("\n\nIngrese cantidad a pagar: ");
		                      scanf(" %f",&pago);
		                      if(pago > ap->agua)
                                       ban2 = 1;
                                      else 
                                       ban2 = 0;
		       	              if(ban2 == 1)
                                      {
		      	               cambio = pago  - ap->agua;
		      	               printf("\tGRACIAS POR SU PAGO...\n");
		      	               printf("Su cambio es de: %10.2f\n",cambio);
                                       ap->saldo_final = ap->saldo_final - ap->agua;
		     	               }
                                       else
		     	                if(pago == ap->agua)
                                        {
		    	                printf("\tGRACIAS POR SU PAGO...\n");
                                        ap->saldo_final = ap->saldo_final - ap->agua;
                                         }
		                        else
		     	                {
                                         abono = 0;
                                         if (pago < ap->agua)
                                         {
                                          ban = 1;
			                 while(ban == 1)
			                 {
			     	          printf("Ingrese cantidad a pagar: ");
                                          scanf(" %f",& abono);
			     	          pago = abono + pago;
                                          if (pago < ap->agua)
                                          ban = 1;
                                          else
                                          ban = 0;
			    	         }
                                         }
                                         if(pago > ap->agua)
		       	                 {
		      	                   cambio = pago  - ap->agua;
                                           printf("Su cambio es de: %10.2f",cambio);
		     	                   }
                                          printf("\tGRACIAS POR SU PAGO...\n");
                                         ap->saldo_final = ap->saldo_final - ap->agua;
                                         }
                                      break;
                                      }
                              case 2:{
                                      printf("\n\nAGUA: %10.2f\n",ap->agua);
                                      if(ap->agua > ap->saldo_final)
                                      printf("SALDO INSUFICENTE\n");
                                      else
                                      {
                                      ap->saldo_final = ap->saldo_final - ap->agua;
                                     printf("\tGRACIAS POR SU PAGO...\n");
                                       }
                                      break;
                                      }
                              }
                            break;
                            }
             case 't':{
                            getchar();
                          void menutipo()
                            scanf(" %d",&op3);
                            switch(op3)
                            {
                              case 1:{
                                      printf("\n\nTELEFONO: %10.2f",ap->telefono);
		                      printf("\n\nIngrese cantidad a pagar: ");
		                      scanf(" %f",&pago);
		                      if(pago > ap->telefono)
                                       ban2 = 1;
                                      else 
                                       ban2 = 0;
		       	              if(ban2 == 1)
                                      {
		      	               cambio = pago  - ap->telefono;
		      	               printf("\tGRACIAS POR SU PAGO...\n");
		      	               printf("Su cambio es de: %10.2f\n",cambio);
                                       ap->saldo_final = ap->saldo_final - ap->telefono;
		     	               }
                                       else
		     	                if(pago == ap->telefono)
                                        {
		    	                printf("\tGRACIAS POR SU PAGO...\n");
                                        ap->saldo_final = ap->saldo_final - ap->telefono;
                                         }
		                        else
		     	                {
                                         abono = 0;
                                         if (pago < ap->telefono)
                                         {
                                          ban = 1;
			                 while(ban == 1)
			                 {
			     	          printf("Ingrese cantidad a pagar: ");
                                          scanf(" %f",& abono);
			     	          pago = abono + pago;
                                          if (pago < ap->telefono)
                                          ban = 1;
                                          else
                                          ban = 0;
			    	         }
                                         }
                                         if(pago > ap->telefono)
		       	                 {
		      	                   cambio = pago  -ap->telefono;
                                           printf("Su cambio es de: %10.2f",cambio);
		     	                   }
                                          printf("\tGRACIAS POR SU PAGO...\n");
                                         ap->saldo_final = ap->saldo_final - ap->telefono;
                                         }
                                      break;
                                      }
                              case 2:{
                                      printf("\n\nTELEFONO: %10.2f\n",ap->telefono);
                                      if(ap->telefono > ap->saldo_final)
                                      printf("SALDO INSUFICENTE\n");
                                      else
                                      {
                                      ap->saldo_final = ap->saldo_final - ap->telefono;
                                     printf("\tGRACIAS POR SU PAGO...\n");
                                       }
                                      break;
                                      }
                              }
                            break;
                            }
                              }
                        
               
               }while(op2 != 'e');//while 2
               break;
             }
   case 's':{
              printf("Saldo Actual : %6.2f\n",ap->saldo_final);
              break;
             }
   
   }//fin switch
   
  }while(op1  != 'e');//fin while 1
  }//fin si
  else
  {
  printf("Numero de Cuenta y Nombre Incorrectos\n");
  printf("Cuenta no existe\n");
  }
 getchar();
 getchar();
 }//fin if principal
 break;
 }//fin switch principal
 }//fin while
}

