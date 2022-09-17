#include <stdio.h>
  long int cuenta,cuenta2;
  int i,j,k,b1,b2,op3,ban,ban2;
  char op1,op2,car,op4,op5;
  float pago,retiro,cambio,abono;

  struct datos
  {
   char nombre[50];
   long int no_cuenta;
   float saldo;
   float cable,luz,agua,telefono;
   float saldo_final;
   };
main()

{
  struct datos *ap,*p,*ptr,clientes[10];
  /*{
   {"juan sanchez lopez"        ,234568 ,20000 ,159,600.9,100,289},
  };*/
  printf("Programa que emula un cajero automatico\n");
  //ptr = clientes;
  k = 0;
  b1 = 0;
   ptr = clientes;
  while(1)
  {
  printf("n) Nuevo usuario\n");
  printf("u) Usuario\n");
  printf("Ingrese opcion\n");
  scanf(" %c",&op5);
  switch(op5)
  {
   case 'n' :
              j = 0;
              b2 = 1;
              //if (b1 == 0)
              i = 0;
              printf("\nIngresa numero de cuenta:");
	      scanf(" %ld" , &cuenta2);
              for(j = -1 ;j < k ;j++)
              { 
               // j++;
               if(cuenta2 != ((ptr+i)->no_cuenta)) 
                b2 = 0;
               //else b2 = 1;
              }
              printf("%d",b2);
              if (b2 == 0 && (b1 == 0))
              {
              (ptr+k)->no_cuenta = cuenta2;
              getchar();
              printf("\nIngresa Nombre:");
              while(car=getchar() != '\n')
 		 {
  			*((ptr+k)->nombre) = car;
   			car = getchar();
 		 }
              printf("\nIngrese su saldo  :");
              scanf(" %f",&(ptr+k)->saldo);
              printf("\nIngrese pagos"); 
              printf("\n Cable    :");
              scanf(" %f",&(ptr+k)->cable);
              printf("\nLuz       :");
              scanf(" %f",&(ptr+k)->luz);
              printf("\nAgua      :");
              scanf(" %f",&(ptr+k)->agua);
              printf("\nTelefono  :");
              scanf(" %f",&(ptr+k)->telefono);
              k++; 
              }
             
              else printf("la cuenta ya existe\n");
              
              break;
             
  case 'u' :{
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
   //else b1 = 0;
   ap++;
   }
  //printf(" %d",b1);
  if(b1 == 1)
  {
  ap = p;
  ap->saldo_final = ap->saldo;
  do
  {
  printf("\n\tr) Retiro\n");
  printf("\tp) Pagos\n"); 
  printf("\ts) Saldos\n");
  printf("\te) exit");
  printf("\tElije una opcion:\t");
  scanf(" %c" , &op1);
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
                printf("Pagos de servicios:\n");
                printf("c) Tv de paga\n");
                printf("l) Luz\n");
	        printf("a) Agua\n");
	        printf("t) Telefonia\n");
                printf("e) salir\n");
                printf("Elije una opcion :\t");
                scanf("%c",&op2);
               switch (op2)
               {
                  case 'c':{
                            getchar();
                            printf("1 > Efectivo\n");
                            printf("2 > Saldo\n");
                            printf("Ingresa opcion:\t");
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
                            printf("1 > Efectivo\n");
                            printf("2 > Saldo\n");
                            printf("Ingresa opcion:\t");
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
                            printf("1 > Efectivo\n");
                            printf("2 > Saldo\n");
                            printf("Ingresa opcion:\t");
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
                            printf("1 > Efectivo\n");
                            printf("2 > Saldo\n");
                            printf("Ingresa opcion:\t");
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
