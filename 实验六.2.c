#include<stdio.h>
int main()
{
	int i,j,t,a[10];
	printf("please input a number:");
	scanf("%d",&t);//����һ���� 
	for(i=0;i<9;i++)//�����鸳ֵ 
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
