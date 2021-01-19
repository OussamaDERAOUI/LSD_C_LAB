#include <stdio.h>
#include <stdlib.h>
#define N 10
float *descente(float A[N][N], float B[N], int n)
{
	
	/*took from excercice1_a.c*/

	 float   *x;

	 x = malloc(sizeof(float) * n); 

	x[0] = B[0]/A[0][0];
	for(int i=1 ; i<SIZE ; i++)
	{
		float s=0;
		for(int j=0 ; j<=i-1 ; j++)
		{
			s = s + A[ i][j] * x[ j];
		}
		x[ i]=(B[ i] - s)/A[ i][ i];
	}  
  
  return (x);
}
float *remontee(float A[N][N], float B[N], int n)
{
	/*took from excercice1_b.c */

	float *x;
	x=malloc(sizeof(float)*n);
	x[N-1] = B[N-1]/A[N-1][N-1];
	for(int i=N - 2 ; i>=0 ; i--)
	{
		float s=0;
		for(int j=i+1 ; j<SIZE ; j++)
		{
			s = s + A[ i][j] * x[ j];
		}
	x[ i]=(B[ i] - s)/A[ i][ i];
	}
  return x;
}

float *cholesky(float A[N][N], float B[N], int n)
{
	float C[N][N];
	C[0][0]=sqrt(A[0][0]);
	for(int i=1;i<n;i++)
	{
		C[i][0]=A[i][0]/C[0][0];
	}
	for(int j=1;j<n;j++)
	{
		for(int i=0;i<j;i++)	
		{
			C[i][j]=0;	
		}

		float s=0;
		for(int k=0;k<=j-1;k++)
		{
			s=s+C[j][k]*C[j][k];
		}
		C[j][j]=sqrt(A[j][j]-s);
		for(int i=j+1;i<n;i++)
		{
			float r=0;
			for(int k=0;k<=j-1;k++)
			{
				r+=C[i][k]*C[j][k];
			}
			C[i][j]=(A[i][j]-r)/C[j][j];

		}
	}
	
	float D[N][N];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			D[j][i]=C[i][j];
		}
	}

	float *y = descente(C, B, n);
	float   *x ;
	x = malloc(sizeof(float) * n);
	x=remontee(D, y, n);
	return x;
}

int main()
{
 float   A[N][N], B[N];
  float   *x;
  int     n;

  printf("Enter the size of the matrix: ");
  scanf("%d", &n);

  /* Filling the matrix A */
  printf("Filling the matrix A\n");
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      printf("A[%d][%d] = ", i, j);
      scanf("%f", &A[i][j]);
    }
  }

  /* Filling the vector B*/
  printf("Filling the matrix B\n");
  for (int i = 0; i < n; i++)
  {
    printf("B[%d] = ", i);
    scanf("%f", &B[i]);
  }

  /* The calculation of the result */
  x = lu(A, B, n);

  /* Printing the results */
  printf("\nThe resulting vector: [");
  for (int i = 0; i < n; i++)
    printf("%f%c", x[i], ",]"[i == n - 1]);
}
