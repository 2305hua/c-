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
	printf("Ӣ����ĸ��Ϊ%d,�ո���Ϊ%d,������Ϊ%d,�����ַ�����Ϊ%d",i,n,m,k);
	return 0;
}
