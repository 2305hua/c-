#include<stdio.h>
int main()
{
	int i,j,d=0,x=0,s=0,k=0,o=0;
	char a[3][80];
	for(i=0;i<3;i++)
	{
		gets(a[i]);
		for(j=0;j<80&&a[i][j]!='\0' ;j++)
		{
			//a[i][j]=getchar();
			if(a[i][j]>'A'&&a[i][j]<'Z')d++;
			else if(a[i][j]>='a'&&a[i][j]<='z')x++;
			else if(a[i][j]>='0'&&a[i][j]<='9')s++;
			else if(a[i][j]==' ')k++;
			else o++;
			
		}
		
		
	}
	
	printf("´óÐ´×ÖÄ¸£º%d£¬Ð¡Ð´×ÖÄ¸£º%d,Êý×Ö£º%d,¿Õ¸ñ£º%d,ÆäËû×Ö·û£º%d",d,x,s,k,o);
	return 0;
	
	
}
