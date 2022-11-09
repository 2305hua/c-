#include<stdio.h>
int main()
{
	int a,b,c,i;
	for(i=0,a=1,b=1;i<9;i++)
	{
		c=a*b;
		b++;
		printf("1*=%d\t ",c);
	}
	for(i=0,a=2,b=1;i<8;i++)
	{
		b++;
		c=a*b;
		printf("2*=%d\t ",c);
	}
	for(i=0,a=3,b=2;i<7;i++)
	{
		b++;
		c=a*b;
		printf("3*=%d\t",c);
	}
	for(i=0,a=4,b=3;i<6;i++)
	{
		b++;
		c=a*b;
		printf("4*=%d\t",c);
	}
	for(i=0,a=5,b=4;i<5;i++)
	{
		b++;
		c=a*b;
		printf("5*=%d\t",c);
	}
	for(i=0,a=6,b=5;i<4;i++)
	{
		b++;
		c=a*b;
		printf("6*=%d\t",c);
	}
	for(i=0,a=7,b=6;i<3;i++)
	{
		b++;
		c=a*b;
		printf("7*=%d\t",c);
	}
	for(i=0,a=8,b=7;i<2;i++)
	{
		b++;
		c=a*b;
		printf("8*=%d\t",c);
	}
	for(i=0,a=9,b=8;i<1;i++)
	{
		b++;
		c=a*b;
		printf("9*=%d\t",c);
	}

return 0;
}
