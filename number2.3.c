#include<stdio.h>
int main()
{
	int i,j,m=0,n=0;
	i=8;
	j=10;
	m+=i++;n-=--j;
	printf("i=%d,j=%d,m=%d,n=%d\n",i,j,m,n);
	return 0;
	
}
