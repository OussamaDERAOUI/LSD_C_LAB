#include <stdlib.h>
#include <stdio.h>
#define N 10

float *lu(float A[N][N], float B[N], int n)
{

  /******Implement the solution here******/
  /***************************************/
float M[N][N]={{1,0,0} , {0,1,0} , {0,0,1}};
float *y,*x;
y = malloc(sizeof(float)*n);	
x = malloc(sizeof(float)*n);

for (int i=0;i<n-1;i++)
{
	for (int j=i+1;j<n;j++)
	{
		M[j][i]=A[j][i]/A[i][i];
		for (int k=i+1;k<n;k++)
		{
			A[j][k]=A[j][k]-M[j][i]*A[i][k];
		}
	}
}
y[0]=B[0]/M[0][0];
for (int i=1;i<n;i++)
{
	float r=0;
	for(int j=0;j<=i-1;j++)
	{
		r+=M[i][j]*y[j];
	}
	y[i]=(B[i]-r)/M[i][i];
	
}
x[n-1]=y[n-1]/A[n-1][n-1];
for(int i=n-2;i>=0;i--)
{
	float r=0;
	for(int j=i;j<n;j++)
	{
		r+=A[i][j]*x[j];
	}
	x[i]=(y[i]-r)/A[i][i];
}

  /***************************************/
  return (x);
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

