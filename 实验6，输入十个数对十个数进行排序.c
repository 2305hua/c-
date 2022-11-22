#include<stdio.h>
int main()
{
	int a[10],i,j,t;
	printf("请输入10个数：\n");
	for(i=0;i<10;i++)
	{scanf("%d",&a[i]);}             //输入10个数 
	printf("\n");
	for(j=0;j<9;j++)
	   for(i=0;i<9-j;i++) 
	      if(a[i]<a[i+1])
	         {t=a[i];a[i]=a[i+1];a[i+1]=t;}

	for(i=0;i<10;i++)
	printf("%d\n",a[i]);
	return 0;   
	
	
}
