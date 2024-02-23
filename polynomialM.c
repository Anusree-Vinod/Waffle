#include<stdio.h>
void display(int sum[],int deg)
{
	int i;
	for(i=deg;i>=0;i--)
	{
		if(i==0)
		{
			printf("%d",sum[i]);
		}
		else
		{
			printf("%dx^%d + ",prod[i],i);
		}
	}
}
int main()
{
	int pol1[20],pol2[10],prod[10],i,j,deg1,deg2,deg;
	printf("Enter the degree of first polynomial:");
	scanf("%d",&deg1);
	printf("Enter the coefficients of first polynomial\n");
	for(i=deg1;i>=0;i--)
	{
		printf("Coefficient of x^%d:",i);
		scanf("%d",&pol1[i]);
		printf("\n");
	}
	printf("Enter the degree of second polynomial:");
	scanf("%d",&deg2);
	printf("Enter the coefficients of second polynomial\n");
	for(i=deg2;i>=0;i--)
	{
		printf("Coefficient of x^%d:",i);
		scanf("%d",&pol2[i]);
		printf("\n");
	}
	deg=deg1+deg2;
	for(i=0;i<=deg;i++)
	{
		prod[i]=0;
	}
	for(i=0;i<=deg1;i++)
	{
		for(j=0;j<=deg2;j++)
		{
			prod[i+j]=prod[i+j]+pol1[i]*pol2[j];
		}
	}
	printf("First polynomial is:");
	display(pol1,deg1);
	printf("\nSecond polynomial is:");
	display(pol2,deg2);
	printf("\nProduct:");
	display(sum,deg);
	return 0;
}
