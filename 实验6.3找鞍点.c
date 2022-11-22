#include<stdio.h>
#define N 4
#define M 5
int main()
{
	int i,j,a[N][M],max,maxj,flag,k;
	printf("请输入四行五列的数组：\n");
	for(i=0;i<N;i++)
	   for(j=0;j<M;j++)
	   scanf("%d",&a[i][j]);
	for(i=0;i<N;i++)
	   {
	    max=a[i][0];   
	    for(j=0;j<M;j++)
	      if(max<a[i][j])
	      {
	      max=a[i][j];
	      maxj=j;
	      }
	      flag=1;
	        for(k=0;k<N;k++)
	        {
	        if(max>a[k][maxj])
		     {
		       flag=0;
		       continue;	
	         }
		    }
		  if(flag)
		  printf("a[%d][%d]=%d",i,maxj,max);
		  break;
       }
       if(!flag)
	printf("无鞍点"); 

	return 0; 
}
