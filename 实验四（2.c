#include<stdio.h>
#include<math.h>
int main()
{
	float x,z,y;
	printf("������һ��С��1000��������");
	scanf("%f",&x);
	while(x>=1000||x<0)
	{
		printf("���������룺");
		scanf("%f",&x);
	} 
	
	y=floor(sqrt(x));
	
	printf("ƽ��������������Ϊ%.0f",y);
	return 0;
}
