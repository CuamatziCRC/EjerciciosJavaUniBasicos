#include <stdio.h>

struct mat{
	char nom[20];
	int cod;
	float deuda;
	char med[10];

}client[20];



	int Adm(struct mat *cfe,int);
	int Buscar(struct mat *cfe,int);
	int Mostmenu(struct mat *cfe,int);
	int Pagar(struct mat *cfe,int);

    int main() {
    FILE *arch;
	int p,sistema=0,i;
	char adm[3];
	struct mat *cfe;
	cfe=client;


	printf("PROGRAMA QUE EMULA LAS FUNCIONES DE UN CFEMATICO\n");
	printf("\n");

	while(sistema!=1){


		printf("\n");
	    printf("  DESEA INICIAR SESION COMO:     \n");
	    printf("****      A> ADMINISTRADOR   ****\n");
	    printf("****      C> CLIENTE         ****\n");
		printf("****      S> SALIR           ****\n");
		scanf("%s",&adm);
		if(adm[0]=='a' || adm[0]=='A')
			Adm(cfe,p);

		if (adm[0]=='C'|| adm[0]=='c'){
                arch=fopen("cfematico.txt", "r+b");
	            if (arch==NULL){
                  printf("\n");
		         printf("\nNo se encontro  clientes.dat\n");
		         exit (0);
	}
	else {
		printf("\nChecando contenido del archivo...\n");
		while (!feof(arch)) {
                for(i=0;i<50;i++){
			fread (client+i,sizeof(client),1,arch);
          }
		}

		fclose(arch);
	}
		printf("\n");
			printf("|||||||||||||BIENVENIDO A CEFEMATICO|||||||||||||\n");
			printf("\n");
			printf("\n");
			Buscar(cfe,p);
			printf("\n");
			printf("\n");
			printf("///////  GRACIAS POR SU PREFERENCIA  /////\n");
			printf("\n");
		}
		if (adm[0]=='S'|| adm[0]=='s'){
			sistema=1;
			printf("\n");
			arch=fopen("cfematico.txt","w+b");

			if(arch == NULL){
				printf("\nError al abrir el archivo para leer\n");
				exit(0);
			}
			else {	printf("\n");
				printf("\nEscribiendo datos al archivo...\n");
				for(i=0;i<50;i++) {
					fwrite((client+i),sizeof(client),1,arch);
				}
				fclose(arch);
				printf("\n.......SALIENDO DEL SISTEMA......\n");}
		}
	}

}


 int Adm(struct mat *cfe,int i){
	 char sal[1];
	 int pasw={1016},codigo,a,cont=0,ex=1,k;

	 printf("\n");
	 printf(".........Introduce el Password.......\n");
	 scanf("%d",&pasw);
	 getchar();
	 if (pasw==1016){
		 a=1;
		 while(a!=0){
			 printf("\n");
			 printf("---Introduce el CODIGO que le corresponde al cliente---\n");
			 scanf("%d",&codigo);
			 getchar();

			 for(cfe=client,k=0;k<20;k++){
				 if ((cfe+k)->cod==codigo)
					 ex=0;
			 }

			 if(ex!=0){
				 (cfe+cont)->cod = codigo;
				 printf("----Introduce nombre completo del cliente----\n");
				 gets((cfe+cont)->nom);
				 printf("-----Introduce la deuda-----\n");
				 scanf("%f",&(cfe+cont)->deuda);
				 cont=cont+1;
				 printf("\n");
				 getchar();
				 printf("풡esea agragar mas usuarios?. S/N.\n");
				 scanf("%c",&sal);
				 getchar();
				 printf("\n");
				 if(sal[0]=='s' || sal[0]=='S')
					 a=1;
				 else

					 a=0;
			 }
			 else{
				 printf("같같같� Codigo repetido 같같같같�\n");
				 printf("Por favor ingrese nuevamente\n");
				 printf("\n");
				 printf("\n");
				 a=1;
				 ex=1;

			 }
		 }
	 }
	 else{
		 printf("El Password es incorrecto");
		 printf("\n");
	 }

 }



 int Buscar(struct mat *cfe,int i){
	int c,band; char op1;


	printf(" POR FAVOR INGRESE Y COLOQUE EN EL LECTOR SU CODIGO DE BARRAS \n");
	scanf("%d",&c);
	getchar();
	printf("\n");
	printf(" 같같같같같같같  ESPERE UN MOMENTO POR FAVOR   같같같같같같같같� \n");
	printf("\n");
	i=0;
	band=0;
	 while (i<3 && band==0){
		 if (c==((cfe+i)->cod))
			 band=1;
		 else
			 i++;
	 }
	 if (band==0){
		 printf("\n");
		 printf(" SU CODIGO NO ES VALIDO \n");

	 }

	 else

		 {
			 Mostmenu(cfe,i);

			 printf("<<<<          P> PAGAR              >>>>\n");
			 printf("<<<<          S> SALIR              >>>>\n");
			 scanf("%c",&op1);

			 if(op1=='P' ||op1=='p'){
				 Pagar(cfe,i);
			 }


		 }
 }

 int Mostmenu(struct mat *cfe,int i){
	 printf("\n*********************************************\n");
	 printf("\n*             CFEMATICO                     *\n");
	 printf("\n*_____  CLIENTE: %s  ______*\n",(cfe+i)->nom);
	 printf("\n*________ ADEUDO DEL RECIBO:%.2f _________*\n",(cfe+i)->deuda);
	 printf("\n*_________ ADEUDO TOTAL:  %.2f    ________*\n",(cfe+i)->deuda);
	 printf("\n*********************************************\n");
	 printf("\n");
 }


 int Pagar(struct mat *cfe,int i){
	 float efec=0,k1=0,z=0,x=0;
	 printf("\n");
	 printf("\n*********************************************\n");
	 printf("\n*             CFEMATICO                     *\n");
	 printf("\n*_____  CLIENTE: %s  ______*\n",(cfe+i)->nom);
	 printf("\n*________       ADEUDO: %.2f       _______*\n",(cfe+i)->deuda);
	 printf("\n*________     DEPOSITADO: %.2f     _________*\n",efec);
	 printf("\n*_________       CAMBIO:  0.00      ________*\n");
	 printf("\n*********************************************\n");
	 printf("\n");

	 printf("\nIntroduzca el dinero en la ranura\n");
	 scanf("%f",&efec);

	 if (efec>(cfe+i)->deuda){
		 k1=efec-(cfe+i)->deuda;
		 (cfe+i)->deuda=0;
		 /*cambio*/
		 printf("\n");
		 printf("\n*********************************************\n");
		 printf("\n*             CFEMATICO                     *\n");
		 printf("\n*_____  CLIENTE: %s  ______*\n",(cfe+i)->nom);
		 printf("\n*________       ADEUDO: %.2f       _______*\n",(cfe+i)->deuda);
		 printf("\n*________     DEPOSITADO: %.2f     _________*\n",efec);
		 printf("\n*_________       CAMBIO:  %.2f      ________*\n",k1);
		 printf("\n*********************************************\n");
	 }
	 else {

		 if (efec<(cfe+i)->deuda){
			 z=z+efec;

			 while(z<(cfe+i)->deuda){
				 x=(cfe+i)->deuda-z;
				 printf("\n");
				 printf("\n*********************************************\n");
				 printf("\n*             CFEMATICO                     *\n");
				 printf("\n*_____  CLIENTE: %s  ______*\n",(cfe+i)->nom);
				 printf("\n*________       ADEUDO: %.2f       _______*\n",x);
				 printf("\n*________     DEPOSITADO: %.2f     _________*\n",z);
				 printf("\n*_________       CAMBIO:  0.00      ________*\n");
				 printf("\n*********************************************\n");

				 printf("Introduce el resto\n");
				 scanf("%f",&efec);
				 z=z+efec;
				 if (z>(cfe+i)->deuda){
					 k1=z-(cfe+i)->deuda;
					 (cfe+i)->deuda=0;
					 printf("\n");
					 printf("\n*********************************************\n");
					 printf("\n*             CFEMATICO                     *\n");
					 printf("\n*_____  CLIENTE: %s  ______*\n",(cfe+i)->nom);
					 printf("\n*________       ADEUDO: %.2f       _______*\n",(cfe+i)->deuda);
					 printf("\n*________     DEPOSITADO: %.2f     _________*\n",z);
					 printf("\n*_________       CAMBIO:  %.2f      ________*\n",k1);
					 printf("\n*********************************************\n");
				 }


			 }

			 if(z==(cfe+i)->deuda){
				 printf("\n");
				 printf("\n*********************************************\n");
				 printf("\n*             CFEMATICO                     *\n");
				 printf("\n*_____  CLIENTE: %s  ______*\n",(cfe+i)->nom);
				 printf("\n*________       ADEUDO: %.2f       _______*\n",(cfe+i)->deuda-z);
				 printf("\n*________     DEPOSITADO: %.2f     _________*\n",z);
				 printf("\n*_________       CAMBIO:  0.00      ________*\n");
				 printf("\n*********************************************\n");


			 }
			 (cfe+i)->deuda=0;
		 }


		 else {
			 if((cfe+i)->deuda==efec){
				 (cfe+i)->deuda=0;
				 printf("\n");
				 printf("\n*********************************************\n");
				 printf("\n*             CFEMATICO                     *\n");
				 printf("\n*_____  CLIENTE: %s  ______*\n",(cfe+i)->nom);
				 printf("\n*________       ADEUDO: %.2f       _______*\n",(cfe+i)->deuda);
				 printf("\n*________     DEPOSITADO: %.2f     _________*\n",efec);
				 printf("\n*_________       CAMBIO:  0.00      ________*\n");
				 printf("\n*********************************************\n");

			 }
		 }

	 }
 }


