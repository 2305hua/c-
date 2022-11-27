#include<stdio.h>
int main()
{
	int a[3][4] = { {2,3,1,4},{12,1,2,1},{-2,1,2,4} };
	int max,i,j,x,y;
	max = a[0][0];
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (max < a[i][j])
			{
				max = a[i][j];
				x = i;
				y = j;
			}
		}
	}
	printf("最大数：%d\n最大数的行号：%d\n最大数的列号：%d\n",max, x, y);
	return 0;
}
