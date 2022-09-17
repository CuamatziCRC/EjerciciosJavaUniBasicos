#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//fflush(stdin); limpia el buffer del teclado
struct usuarios{ 
	unsigned int cuenta;
	char nombre[100];
	float saldo;
	float d_agua,d_luz,d_tv,d_telefono;
}usuario[10];
main ()
{

	int opc,i=0,j,temp,r=0,t,opc2,opc3,bandera;
	float abono;
	float cambio,retiro,pago;
	do 
	{
		printf ("1)alta de usuario\n\n2)Retiro de su saldo\n\n3)Pago de servicios\n\n\n4)salir");
		printf ("\n\n elija su opcion...\n\n");
		scanf("%d",&opc);
		while(getchar()!='\n'); 
		 //esto sirve como fflush
		//fflush(stdin);
		switch (opc)
		{
		
		case 1:
			printf ("Bienvenido nuevo usuario\n\n\n De el numero de su cuenta de usuario");
			scanf("%d",&temp);
			while(getchar()!='\n'); 
			 //esto sirve como fflush
			//fflush(stdin);
			j=0;
			while (j<i&&usuario[j].cuenta==temp)
				i++;
			if(usuario[j].cuenta==temp)
			{
				printf("\n\nLo sentimos el numero de su cuenta es ya existente\n\n");
				
			}
			else
			{
				usuario[i].cuenta=temp;
				printf("\n\nsu cuenta ha sido creada con exito...\n\n");
				//system("pause");
				//system ("cls");
				printf ("Su nombre y apellidos....\n\n");
			
				gets(usuario[i].nombre);
				 //esto sirve como fflush
				//fflush (stdin);
				printf("Saldo inicial\n\n");
				scanf("%f",&usuario[i].saldo);
				 
				//esto sirve como fflush
				//fflush(stdin);
				printf("Por favor asigne su deuda de agua\n\n");
				scanf("%f",&usuario[i].d_agua);
				//esto sirve como fflush
				//fflush(stdin);
				printf("Por favor asigne su deuda de luz\n\n");
				scanf("%f",&usuario[i].d_luz);	
				 //esto sirve como fflush
				//fflush(stdin);	
				printf("Por favor asigne su deuda de tv. por cable\n\n");
				scanf("%f",&usuario[i].d_tv);
				    //fflush(stdin);
				  //esto sirve como fflush
				  printf("\n\nPor favor asigne su deuda de el telefono\n\n");
				  scanf("%f",&usuario[i].d_telefono);
				    //fflush(stdin);
				    i++;
				   // system("pause");
					//system ("cls");
			
			}
			break;
			case 2:
				printf("\n\ningrese su numero de cuenta\n\n");
				 scanf("%d",&temp);	

				 j=0;r=0;
				do
				{
					if (usuario[j].cuenta==temp)
					{
						r++;t=j;
					}
					j++;
				}while (j<i);
				if(r==1)
				{
					printf("\n\nSu saldo actual es de....\n\n%2.2f\n\nCuanto desea retirar....",usuario[t].saldo);
					scanf("%f",&retiro);
					fflush(stdin);
					
					if (retiro<=usuario[t].saldo)
					{
						usuario[t].saldo-=retiro;
						printf("\n\nsu saldo total es de ....\n\n%2.2f",usuario[t].saldo);
						
					}
					else
					{
					   	printf("\n\nEl saldo es insuficiente para retirar .....\n\n");
					}
				}
				else
				{
				 	printf("\n\nno existe la cuenta.. le sujerimos que se cree una cuenta con nosotros.....\n\n"); 					 }
			break;
		 	case 3:
		 		printf("\n\ningrese su numero de cuenta\n\n");
			        scanf("%d",&temp);	
			        //fflush(stdin);
				j=0;r=0;
				do
				{
					if (usuario[j].cuenta==temp)
					{
						r++;t=j;
					}
					j++;
				}while (j<i);
				if(r==1)
				{
					while (opc2!=5){
						printf("***Opciones de pago de servicios***\n\n\n1)Pago del servicio del agua\n\n\n");
						printf("2)Pago del servicio de electricidad\n\n\n3)Pago del servicio de tv. por cable\n\n\n");
						printf("4)pago del servicio de telefono\n\n\n5)salir de este menu...\n\n");
		 				printf ("\n\n elija su opcion...");
		        			scanf("%d",&opc2);
		        			 switch (opc)						 
						{
		         	 		case 1:
				            		printf("1 > Efectivo\n");
						            printf("2 > Saldo\n");
						            printf("Ingresa opcion:\t");
						            scanf(" %d",&opc3);
						            switch(opc3)
						            {
						              case 1:
						                      printf("\n\nAGUA: %.2f",usuario[t].d_agua);
								      printf("\n\nIngrese cantidad a pagar: ");
					       	                      scanf(" %f",&pago);
								      if(pago > usuario[t].d_agua)
							                       bandera= 1;
						                      else 
							                       bandera= 0;
						       	              if(bandera == 1)
							              {
							      	               cambio = pago  - usuario[t].d_agua;
								      	               printf("\tGRACIAS POR SU PAGO...\n");
							      	               printf("Su cambio es de: %10.2f\n",cambio);
							              }
						                       else
							     	                if(pago == usuario[t].d_agua)
								                {
				    	        				        printf("\tGRACIAS POR SU PAGO...\n");
				                				}
									        else
				     	        			        {
				                				         abono = 0;
				                				         if (pago < usuario[t].d_agua )
				                        				 {			
				                          					bandera = 1;
												 while(bandera == 1)	
												 {
											     	          printf("Ingrese cantidad a pagar: ");
				        						                  scanf(" %f",&abono);
											     	          pago = abono + pago;
				        						                  if (pago < usuario[t].d_agua)
				        							                  bandera = 1;
				        						                  else
				        							                  bandera = 0;
										    	         }
				        				                 }
				        				                 if(pago > usuario[t].d_agua)
				       					                 {
				      						                   cambio = pago  - usuario[t].d_agua;
				       						                    printf("Su cambio es de: %10.2f",cambio);
				     					                   }
				       					                   printf("\tGRACIAS POR SU PAGO...\n");
				                 				}
				       	       			break;
				                      
				              			case 2:
									printf("\n\nAgua: %10.2f\n",usuario[t].d_agua);
						                      if(usuario[t].d_agua> usuario[t].saldo)
							                      printf("SALDO INSUFICENTE\n");
						                      else
						                      {
							                      usuario[t].saldo = usuario[t].saldo - usuario[t].d_agua;
							                     printf("\tGRACIAS POR SU PAGO...\n");
						                       }
					                      break;
						              }
						break;
				                  case 2:
			                            getchar();
			                            printf("1 > Efectivo\n");
			                            printf("2 > Saldo\n");
			                            printf("Ingresa opcion:\t");
			                            scanf(" %d",&opc3);
			                            switch(opc3)
			                            {
			                              case 1:
			                                      printf("\n\nLUZ: %10.2f",usuario[t].d_luz);
					                      printf("\n\nIngrese cantidad a pagar: ");
				       	                      scanf(" %f",&pago);
					                      if(pago > usuario[t].d_luz)
				                                       bandera= 1;
			                                      else 
				                                       bandera= 0;
					       	              if(bandera == 1)
				                              {
						      	               cambio = pago  - usuario[t].d_luz;
						      	               printf("\tGRACIAS POR SU PAGO...\n");
		      	        				       printf("Su cambio es de: %10.2f\n",cambio);
                              					}					
                                       				else
		     	                				if(pago == usuario[t].d_luz)
                                					{
		    	                					printf("\tGRACIAS POR SU PAGO...\n");
                                					}
		                        				else
		     	                				{
                                         					abono = 0;	
					                                         if (pago < usuario[t].d_luz )
                                        					 {
                                        						  bandera = 1;
			                						 while(bandera == 1)
			                						 {
			     	        							  printf("Ingrese cantidad a pagar: ");
                                        							  scanf(" %f",&abono);
			     	        							  pago = abono + pago;
                                          							if (pago < usuario[t].d_luz)
                                          								bandera = 1;
                                          							else
                                          								bandera = 0;
			    	         						}
                                         					}
                                         					if(pago > usuario[t].d_luz)
		       	                 					{
		      	                   						cambio = pago  - usuario[t].d_luz;
                                          						 printf("Su cambio es de: %10.2f",cambio);
							     	                   }
					                                          printf("\tGRACIAS POR SU PAGO...\n");
                                         				}
                                			break;
                                                        case 2:printf("\n\nAgua: %10.2f\n",usuario[t].d_luz);
                                      				if(usuario[t].d_luz> usuario[t].saldo)
                                     					 printf("SALDO INSUFICENTE\n");
                                     				 else
                                     				 {
                     					                 usuario[t].saldo = usuario[t].saldo - usuario[t].d_luz;
                 					                    printf("\tGRACIAS POR SU PAGO...\n");
                 				                      }
                                      			break;
                           				}
                            			break;
                            			case 3:
                            				
                    				 printf("1 > Efectivo\n");
                            				printf("2 > Saldo\n");
                   				         printf("Ingresa opcion:\t");
                  				          scanf(" %d",&opc3);
                  				          switch(opc3)
                  				          {
                  				            case 1:
                  				                    printf("\n\nTELEVISION POR CABLE : %10.2f",usuario[t].d_tv);
		  				                    printf("\n\nIngrese cantidad a pagar: ");
       	          					            scanf(" %f",&pago);
       	          					            __fpurge(stdin);
		  				                    if(pago > usuario[t].d_tv)
                  					                     bandera= 1;
                  				                    else 
                                       						bandera= 0;
		       	              					if(bandera == 1)
                              						{	
							      	               cambio = pago  - usuario[t].d_tv;	
							      	               printf("\tGRACIAS POR SU PAGO...\n");
							      	               printf("Su cambio es de: %10.2f\n",cambio);
                              						}		
                                       					else	
		     	        					        if(pago == usuario[t].d_agua)
                                						{
								    	                printf("\tGRACIAS POR SU PAGO...\n");
						                                }
		                        					else
		     	                					{
                                         						abono = 0;
						                                         if (pago < usuario[t].d_tv)
						                                         {
							                                          bandera = 1;
										                 while(bandera == 1)
										                 {
			     	          								printf("Ingrese cantidad a pagar: ");
								                                          scanf(" %f",&abono);
											     	          pago = abono + pago;
								                                          if (pago < usuario[t].d_tv)
									                                          bandera = 1;
								                                          else
									                                          bandera = 0;
										    	         }
						                                         }
						                                         if(pago > usuario[t].d_tv)
								       	                 {
									      	                   cambio = pago  - usuario[t].d_tv;
							                                           printf("Su cambio es de: %10.2f",cambio);
								     	                   }
							                                          printf("\tGRACIAS POR SU PAGO...\n");
                                         			
                                						}
                                			      break;
                                	                           case 2:
                                				      printf("\n\nAgua: %10.2f\n",usuario[t].d_tv);
                                				      if(usuario[t].d_agua> usuario[t].saldo)
                                					      printf("SALDO INSUFICENTE\n");
                                				      else
                                				      {
                                					      usuario[t].saldo = usuario[t].saldo - usuario[t].d_tv;
                                					     printf("\tGRACIAS POR SU PAGO...\n");
                                				       }
                                     				 break;
                                      
                              				}
                            			break;
                      		         	case 4:
                      				      getchar();
                      				      printf("1 > Efectivo\n");
              					      printf("2 > Saldo\n");
              				              printf("Ingresa opcion:\t");
              				              scanf(" %d",&opc3);
              				              switch(opc3)
              				              {
                        			      case 1:
                        			              printf("\n\nTELEFONO: %10.2f",usuario[t].d_telefono);
		        			              printf("\n\nIngrese cantidad a pagar: ");
       	                				      scanf(" %f",&pago);
		        			              if(pago > usuario[t].d_telefono)
                        				               bandera= 1;
                        			              else 
                        				               bandera= 0;
		       				              if(bandera == 1)
                        				      {
		      					               cambio = pago  - usuario[t].d_telefono;
		      					               printf("\tGRACIAS POR SU PAGO...\n");
		      					               printf("Su cambio es de: %10.2f\n",cambio);
                        				      }
                        			               else
		     					                if(pago == usuario[t].d_telefono)
                                					{			
		    	                					printf("\tGRACIAS POR SU PAGO...\n");
                                					}
		                        				else		
		     	                				{
                                         					abono = 0;
                                        					 if (pago < usuario[t].d_telefono)
                                       						  {
                                          						bandera = 1;
									                 while(bandera == 1)
									                 {
										     	          printf("Ingrese cantidad a pagar: ");
							                                          scanf(" %f",&abono);
										     	          pago = abono + pago;
							                                          if (pago < usuario[t].d_telefono)
								                                          bandera = 1;
							                                          else
								                                          bandera = 0;
									    	         }
                                         					}			
					                                         if(pago > usuario[t].d_telefono)		
							       	                 {
								      	                   cambio = pago  - usuario[t].d_telefono;
						                                           printf("Su cambio es de: %10.2f",cambio);
							     	                   }
					                                          printf("\tGRACIAS POR SU PAGO...\n");
                                         
					                                }
		                                      break;
                                     
			                              case 2:
			                                      printf("\n\nAgua: %10.2f\n",usuario[t].d_telefono);
			                                      if(usuario[t].d_luz> usuario[t].d_telefono)
                        				              printf("SALDO INSUFICENTE\n");
                        			              else
                        			              {
                                      					usuario[t].saldo = usuario[t].saldo - usuario[t].d_telefono;
                                     					printf("\tGRACIAS POR SU PAGO...\n");
			                                       }
		                                      break;
							}
                            			break;
						 }//fin del switch de los pagos
					}//fin de while los pagos :D
				
				}
	      			else 
		  		{
	      				printf("no existe la cuenta.. le sujerimos que se cree una cuenta con nosotros.....\n\n");
	      			}
		}
	}while (opc!=4);//fin fel ciclo del programa
}
	

