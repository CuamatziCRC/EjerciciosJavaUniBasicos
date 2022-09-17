#include<stdio.h>
#include<conio.h>
main()
{
	int i=0,j=0,k=0;
	int vacio=0,n=0;
	printf("\n\tPrograma en C que realiza el conjunto potencia\n\t en un rango del uno al nueve\n");
	printf("\tDe el digito del numero\n\t");
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			printf("\tconjunto potencia de uno es = {{0}{1}} ");
			break;
		case 2:
			printf("\tConjunto potencia de dos es ={{0}{1}{2}{1,2}}");
			break;
		case 3:
			printf("\tConjunto potencia de tres es = {{0}{1}{2}{3}{1,2}{1,3}{2,3}{1,2,3}}");
			break;
		case 4:
			printf("\tconjunto potenciade 4 es = {0} ");
			for(i=1;i<5;i++)
			{
				printf(" {%d} ",i);
				
			}  
		     for(i=1;i<4;i++)
		    {
		    	printf(" {1,%d}",j=i+1);
		    }
			for(i=1;i<3;i++)
			{
				printf(" {2,%d}",j=i+2);
			}
			printf(" {3,4} {2,3,4} {1,2,3,4}");
			break;
		case 5:  i=0;j=1;
		printf("\tConjunto potencia de 5 es = {0}");
		     for(i=1;i<6;i++)
		     {
		     	printf("{ %d}",i);
		     }
		     for(i=1;i<5;i++)
		     {
		     	printf("{ 1,%d}",j+=1);
		     }
		    for(i=1;i<4)
			break;
	}
}
