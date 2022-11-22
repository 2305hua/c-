#include<stdio.h>
int main()
{
	char x;
	int i=0,n=0,m=0,k=0;
	while((x=getchar())!='\n')
	{if(x>='a'&&x<='z'||x>='A'&&x<='Z')
	i++;
	else if(x==' ')
	n++;
	else if(x>='0'&&x<='9')
	m++;
	else  
	k++;
	
	}
	printf("英文字母数为%d,空格数为%d,数字数为%d,其他字符个数为%d",i,n,m,k);
	return 0;
}
