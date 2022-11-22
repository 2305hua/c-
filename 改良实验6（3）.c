#include<stdio.h>
int main()
{
	int i,j,d=0,x=0,s=0,k=0,o=0;
	char a[3][80];
	for(i=0;i<3;i++)
	{
		printf("请输入第%d行：\n",i+1);
		gets(a[i]);
		for(j=0;j<80&&a[i][j]!='\0';j++)
		{
		    if(a[i][j]>'A'&&a[i][j]<'Z')d++;
			else if(a[i][j]>'a'&&a[i][j]<'z')x++;
			else if(a[i][j]>'0'&&a[i][j]<'9')s++;
			else if(a[i][j]==' ')k++;
			else  o++;
			
		}
		
	}
	printf("大写字母：%d，小写字母：%d,数字：%d,空格：%d,其他字符：%d",d,x,s,k,o);
	return 0;
}
