#include<stdio.h>
#include<string.h> 
int main()
{
	char a[10], b[10], c[10], str[10];
	printf("�����������ַ���\n");
	gets(a);
	gets(b);
	gets(c);
	if (strcmp(a, b) > 0)
	{
		strcpy(str, a);
	}
	else
	{
		strcpy(str, b);
	}
	if (strcmp(c, str) > 0)
	{
		strcpy(str, c);
	}
	printf("�����ַ����ǣ�%s", str);
	return 0;
}
