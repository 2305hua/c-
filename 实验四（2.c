#include<stdio.h>
#include<math.h>
int main()
{
	float x,z,y;
	printf("请输入一个小于1000的正数：");
	scanf("%f",&x);
	while(x>=1000||x<0)
	{
		printf("请重新输入：");
		scanf("%f",&x);
	} 
	
	y=floor(sqrt(x));
	
	printf("平方根的整数部分为%.0f",y);
	return 0;
}
