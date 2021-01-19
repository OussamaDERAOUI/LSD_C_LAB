#include<stdio.h>
#include <stdlib.h>

float f(int t) { return t; }

double rectangledroit( int a, int b, int n)
{
	double i = 0;
	double h =(double)(b-a)/n;
	double x = a;
	for(int j = 0; j<n ; j++)
	{
		i+=f(x);
		x+=h;
	}
	return h*i;
}
double rectanglegauche( int a , int b , int n)
{
	double i = 0;
	double h=(double)(b-a)/n;
	double x = a + h;
	for(int j = 1; j<n ;j++){
		i+=f(x);
		x+=h; }
	return h*i ;
}
double trapeze( int a, int b , int n)
{
	double i =(1/2)*(f(a)+f(b));
	double h = (double)(b-a)/n;
	double x = a + h;
	for(int j = 0; j<n-1 ; j++)
	{
		i +=f(x);
		x+=h ;
	}
	return h*i;
}
double simpson(int a, int b, int n)
{
	double h=(double)(b-a)/n;
	double x= a + h;
	double z=(double)a+h/2;
	double i1= 0;
	double i2= f(z);
	for(int j = 0; j<n-1; j++)
	{
		z+=h;
		i1+=f(x);
		i2+=f(z);
		x+=h;
	}
	return (h/6)*(f(a)+f(b)+2*i1+4*i2);
}	

int main()
{
	int a= 1,b= 9,n=10;
	float x = rectangledroit(a,b,n);
	printf("%f", x);
}

