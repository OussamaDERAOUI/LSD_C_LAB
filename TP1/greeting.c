#include<stdio.h>


void italian()
{	printf("Mama mia ");
	
}

void german(char a)
{
	printf("nein nein guten gaten");
}
void french()
{
	printf("bonjour oui la baguette");
	
}

int main()
{
	void (*greeting[])(,,)={italian,german,french};
	unsigned int a;
	printf("\n1.italian\n2.german\n3.french\n");
	scanf("%u" , &a);
	(*greeting[a])();
	return 0;

}


