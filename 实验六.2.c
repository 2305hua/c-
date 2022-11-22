#include<stdio.h>
int main()
{
	int i,j,t,a[10];
	printf("please input a number:");
	scanf("%d",&t);//输入一个数 
	for(i=0;i<9;i++)//对数组赋值 
	a[i]=i;
	a[9]=t;
	for(j=0;j<9;j++)
	   for(i=0;i<9-j;i++) 
	      if(a[i]>a[i+1])
	         {t=a[i];a[i]=a[i+1];a[i+1]=t;}
	         
	for(i=0;i<10;i++)
	printf("%d",a[i]);
	
	
	return 0; 
	
}
