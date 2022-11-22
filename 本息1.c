#include<stdio.h>
#include<math.h>
int main()
{
	float r0,r1,r2,r3,r5,m,m1,m2,m3,m4,m5;
	m=1000;
	r5=0.03;
	r3=0.0275;
	r2=0.021;
	r1=0.015;
	r0=0.015;
	m1=m*(1+r5*5);
	m2=m*(1+r2*2)*(1+r3*3);
	m3=m*(1+r3*3)*(1+r2*2);
	m4=m*pow(1+r1,5);
	m5=m*pow(1+r0,4*5);
	printf("m1=%f,m2=%f,m3=%f,m4=%f,m5=%f",m1,m2,m3,m4,m5);
	return 0;
	
	
}
