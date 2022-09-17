#include "stdio.h"
#include "math.h"
int main(int argc, char const *argv[])
{
	int Contador,i,j;
	float suma=0,multiplicacion=1,puntero,x[100],y[100];
	printf("Metodo de Lagrange\n");
	printf("Punto a encontrar  ");
	scanf ("%f",&puntero);
	printf("Cordenas a dar\n");
	scanf("%d",&Contador);
	for (int i = 0; i < Contador; ++i)
	{
		printf("Cordenada X\n");
		scanf("%f",&x[i]);
		printf("Cordenada Y\n");
		scanf("%f",&y[i]);
		printf("***********************\n");
	}
		for (int i = 0; i < Contador; ++i)
		{
			multiplicacion=1;
			for (int j = 0; j < Contador; ++j)
			{
				if (j!=i)
				{
					multiplicacion=multiplicacion*(puntero-x[j])/(x[i]-x[j]);

				}

			}
			multiplicacion=multiplicacion*y[i];
			suma=suma+multiplicacion;
		}

		printf("El punto f(p)=%f",suma);

	return 0;
}
