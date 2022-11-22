#include<stdio.h>
#include<math.h>
int main()
{
	float r,n,p;
	printf("请输入年增长率r，年数n：");
	scanf("%f,%f",&r,&n);
	p=pow(1+r,n);
	printf ("p=%f\n",p);
	return 0;
}
