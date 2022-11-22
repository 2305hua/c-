#include<stdio.h>
int main()
{
	int a,b;
	float d,e;
	char c1,c2;
	double f,g;
	long m,n;
	unsigned int p,q;
	int s1,s2,s3,s4,s5,s6;
	c1=a;c2=b;
	f=3157.890121;g=0.123456789;
	d=f;e=g;
	p=a=m=50000;q=b=n=-60000;
	m=50000;n=-60000;
	p=32768;q=40000;
	s1=sizeof(int);
	s2=sizeof(float);
	s3=sizeof(char);
	s4=sizeof(double);
	s5=sizeof(long);
	s6=sizeof(unsigned int);
	printf("a=%d,b=%d\nc1=%c,c2=%c\nd=%6.2f\n,e=%6.2f\n",a,b,c1,c2,d,e);
	printf("f=%15.6f,g=%15.12f\nm=%ld,n=%ld\np=%u,q=%u\n",f,g,m,n,p,q); 
	printf("s1=%d,s2=%d,s3=%d,s4=%d,s5=%d,s6=%d",s1,s2,s3,s4,s5,s6);
	return 0;
}
