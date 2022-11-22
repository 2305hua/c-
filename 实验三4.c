#include<stdio.h>
int main()
{
	char c1,c2,c3,c4,c5;
	scanf("%c%c%c%c%c",&c1,&c2,&c3,&c4,&c5);
    c1=c1-4;
	c2=c2-4;
	c3=c3-4;
	c4=c4-4;
	c5=c5-4;
	c1=c1<'A'?c1+26:c1;
	c2=c2<'a'?c2+26:c2;
	c3=c3<'a'?c3+26:c3;
	c4=c4<'a'?c4+26:c4;
	c5=c5<'a'?c5+26:c5;
	printf("password=%c%c%c%c%c",c1,c2,c3,c4,c5);
	return 0;
}
