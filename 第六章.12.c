#include<stdio.h>
int main()
{
	int i,j,k;
	char a[5],b[4];
	for(i=0;i<5;i++)
	a[i]='*';
	for(k=0;k<4;k++)
	b[k]=' ';
	for(j=0;j<5;j++)
	{
		for(k=0;k<=j;k++)
		printf("%c",b[k]);
		for(i=0;i<5;i++)
		{
			printf("%c",a[i]);
			
		}
		printf("\n");
	}
	return 0;
}
