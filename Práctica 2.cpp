#include <stdio.h>
#include <iostream>
#define N 50

void unionde(int A[N],int B[N], int C[N], int termA, int termB, int termC)
{
	int i, j, k;
	//Esta sección indica la memoria que ocupa el conjunto resultante
	termC=termA+termB;
	for (i=0 ; i<termA ; i++)
	{
		for (j=0 ; j<termB ; j++)
		{
			if (A[i]==B[j])
			{
				termC=termC-1;
			}
		}
	}
	//Esta sección limpia los valores del conjunto resultante
	for (k=0 ; k<termC ; k++)
	{
		C[k]=0;
	}
	//Esta sección guarda los valores relevantes
	k=0;
	for (i=0 ; i<termA ; i++)
	{
		for (j=0 ; j<termB ; j++)
		{
			if (A[i]==B[j])
			{
				C[k]=A[i];
				k=k+1;
			}
			else
			{
				C[k]=B[j];
				k=k+1;
			}
		}
	}
	for (k=0 ; k<termC ; k++)
	{
		printf("%d ", C[k]);
	}
	//Este sección imprime el resultado
	printf("Este es su conjunto resultado\n");
	printf("[");
	for (i=0 ; i<termC ; i++)
	{
		printf(" %d ", C[i]);
		if (i<termC-1)
		{
			printf(",");
		}
	}
	printf("]\n");
	return;
}

void interseccionde(int A[N], int B[N], int C[N], int termA, int termB, int termC)
{
	int i, j, k;
	//Esta sección indica la memoria que ocupa el conjunto resultante
	termC=0;
	for (i=0 ; i<termA ; i++)
	{
		for (j=0 ; j<termB ; j++)
		{
			if (A[i]==B[j])
			{
				termC=termC+1;
			}
		}
	}
	//Esta sección limpia los valores del conjunto resultante
	for (k=0 ; k<termC ; k++)
	{
		C[k]=0;
	}
	//Esta sección guarda los valores relevantes
	k=0;
	for (i=0 ; i<termA ; i++)
	{
		for (j=0 ; j<termB ; j++)
		{
			if (A[i]==B[j])
			{
				C[k]=A[i];
				k++;
			}
		}
	}
	//Este sección imprime el resultado
	printf("Este es su conjunto resultado\n");
	printf("[");
	for (i=0 ; i<termC ; i++)
	{
		printf(" %d ", C[i]);
		if (i<termC-1)
		{
			printf(",");
		}
	}
	printf("]\n");
	return;
}
void leer(int A[N], int terminos)
{
	int i;
	for (i=0 ; i<terminos ; i++)
	{
		printf("Ingrese el termino %d: ", i+1);
		scanf("%d",&A[i]);
	}
	return;
}

void imprimir(int A[N], int terminos)
{
	int i;
	printf("[");
	for (i=0 ; i<terminos ; i++)
	{
		printf(" %d ", A[i]);
		if (i<terminos-1)
		{
			printf(",");
		}
	}
	printf("]\n");
	return;
}

int main()
{	
	int x, y, z;
	int A[N], B[N], C[N];
	int opcion;
	int repetir;
	
	repetir = 0;
	
	while (repetir==0)
	{	
		printf("\n\t*** UNION O INTERSECCION ***\n");
    	printf("¿Que calculo desea realizar?\n");
    	printf("1) La union de dos conjuntos.\n");
    	printf("2) La interseccion de dos conjuntos.\n");
    	printf("3) Salir.\n");
    	scanf("%d", &opcion);
    	switch(opcion)
		{
    	case 1:
    		repetir=repetir+1;
			printf("Ingrese la cantidad de terminos que hay dentro de su primer conjunto\n");
			scanf("%d", &x);
			leer(A, x);
			printf("Esta es la informacion ingresada: \n");
			imprimir(A, x);
			printf("Ingrese la cantidad de terminos que hay dentro de su segundo conjunto\n");
			scanf("%d", &y);
			leer(B, y);
			printf("Esta es la informacion ingresada: \n");
			imprimir(B, y);
			z=0;
			unionde(A, B, C, x, y, z);
        	break;
    	case 2:
        	repetir=repetir+1;
			printf("Ingrese la cantidad de terminos que hay dentro de su primer conjunto\n");
			scanf("%d", &x);
			leer(A, x);
			printf("Esta es la informacion ingresada: \n");
			imprimir(A, x);
			printf("Ingrese la cantidad de terminos que hay dentro de su segundo conjunto\n");
			scanf("%d", &y);
			leer(B, y);
			printf("Esta es la informacion ingresada: \n");
			imprimir(B, y);
			z=0;
			interseccionde(A, B, C, x, y, z);
        	break;
    	case 3:
        	return 0;
        	break;
		default:
        	printf("Opcion no valida.\n");
  		}
  	}
  return 0;
}
