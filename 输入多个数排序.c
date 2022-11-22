#include<stdio.h>
int main()
{
	int i,j,t;
	int a[10]={1,2,3,4,5};
	for(i=5;i<10;i++)
	scanf("%d",&a[i]);
	for(j=0;j<9;j++)
	{
		for(i=0;i<9-j;i++)
		if(a[i]>a[i+1])
	         {t=a[i];a[i]=a[i+1];a[i+1]=t;}
	}
	
	for(i=0;i<10;i++)
	printf("%d\n",a[i]);
	return 0;   
}
