#include<stdio.h>
int main()
{
	int i,j;
	char str1[30],str2[30],x;
	printf("input string1:");
	gets(str1);
	printf("input string2:");
	gets(str2);
	for(i=0;str1[i]==str2[i]&&str1[i]!='\0';i++)//ѭ������ 
	{}
	if(str1[i]==str2[i])//��������� 
	{
	printf("0");//�������0 
	}
	else 
	{
	x=str1[i]-str2[i];
	printf("%d",x);//�����ڱȽϴ�С 
	}
	return 0;
}
