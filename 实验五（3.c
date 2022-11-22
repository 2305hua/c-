#include<stdio.h>
int main()
{
	int x=1,y,n=1;
	for(;n<=9;n++)
	{
	y=(x+2)*2;
	x=y;
    }
	
	printf("%d,%d",x,n);
	return 0;
}
