#include<stdio.h>
#include<malloc.h> 
#include<stdbool.h>
#define MAXSIZE 10
/*
顺序表  2023.3.5
*/
struct Arr//定义一个结构体
{
	int *pelem;//数组元素的首地址 
	int len;//数组有效长度 
};
/*
----------------------------------------------------------------------------------------------------------------
*/
bool Insert(struct Arr *parr,int pos,int e);//插入函数：pos为插入位置，e为插入的元素 
bool Delete(struct Arr *parr,int pos);//删除函数：删去给定位置第pos的元素； 
int LocateElem(struct Arr *parr,int e);//查找函数：在表中寻找值与e相等的元素； 
bool GetElem(struct Arr *parr,int pos,int *e);//取值函数：选取表中第pos个位置的元素赋值给e 
void delete_same3(struct Arr *parr,int item);//使用whlie循环 
void delete_same2(struct Arr *parr,int same);//删除表中与item值相同的元素 ;使用的是for循环 
//void delete_same1(struct Arr *parr);
void ShowList(struct Arr *parr);//展示表中数据 
void InitList(struct Arr *parr);//初始化函数 
bool ListInsert(struct Arr *parr,int data);//追加数据：在表的末尾加数据 
bool is_full(struct Arr *parr);//判断表是否已经满了 
bool is_empty (struct Arr *parr);//判断表是否为空 
/*
-----------------------------------------------------------------------------------------------------------------
*/

int main()
{
	struct Arr arr;
	int e = 0;
	InitList(&arr);//对结构体变量arr初始化
	ListInsert(&arr,1);/*对顺序表赋值*/
	ListInsert(&arr,4);
	ListInsert(&arr,2);
	ListInsert(&arr,8);
	ListInsert(&arr,2);
	ListInsert(&arr,2);
	ListInsert(&arr,7);
	ListInsert(&arr,2);
	ListInsert(&arr,10);
	ListInsert(&arr,2);
	ShowList(&arr);
	//delete_same1(&arr);
	//delete_same2(&arr,2); //感觉时间复杂度不符合题目要求 
	delete_same3(&arr,2);//参考智慧树视频的代码 
	printf("删除后\n");
	ShowList(&arr);
	//GetElem(&arr,3,&e);
	//printf("e = %d\n",e);
	//LocateElem(&arr,2);
	//Delete(&arr,2);
	//ShowList(&arr);
	printf("插入后：\n");
	Insert(&arr,1,9);
	ShowList(&arr);
	return 0;
}

/*
-----------------------------------------------------------------------------------------------------------------
*/
bool Insert(struct Arr *parr,int pos,int e)//插入函数：pos为插入位置，e为插入的元素
{
	int i = parr->len;
	if(pos < 1 || pos >parr->len || is_full(parr))//判断插入位置合法性及表是否已满 
		return false;
	for(i = parr->len;i >= pos;i--)
	{
		parr->pelem[i] = parr->pelem[i-1];
	}
	parr->pelem[pos-1] = e;
	parr->len++;
	return true;
}
bool Delete(struct Arr *parr,int pos)//删除函数：删去给定位置第pos的元素； 
{
	if(pos < 1 || pos > parr->len)//如果删除位置不合法则返回错误； 
	return false;
	for(pos;pos < parr->len;pos++)
	{
		parr->pelem[pos-1]=parr->pelem[pos];
	}
	parr->len--;
}
int LocateElem(struct Arr *parr,int e)//查找函数 
{
	int i = 0;
	for(i = 0;i < parr->len;i++)
	{
		if(parr->pelem[i] == e)
		{
			return i+1;//查找成功返回该元素所在的位置 
		}
	}
	return 0;//查找失败返回0 
}
bool GetElem(struct Arr *parr,int pos,int *e)//取值函数 
{
	if(pos<1 || pos>(parr->len))
		return false;
	*e = parr->pelem[pos-1];
	return true;
}
void ShowList(struct Arr *parr)//展示表中数据 
{
	int i;
	for(i = 0;i < parr->len ;i++)
	{
		printf("%d\n",parr->pelem[i]);
	}
	return;
}

void delete_same2(struct Arr *parr,int item)//删除与item相同的数据 感觉时间复杂度不符合题意 
{
	int i = 0,j = parr->len-1;
	for(;j > i;j--) 
	{
		for(;i < j;i++)//从表头开始检查有无元素与item相等 
		{
			if(parr->pelem[i] == item)//检查从表头开始是否有元素与item相等 
			{
				parr->len--;//如果有则有效长度len减一 
				for(;j > i;j--)
				{
					if(parr->pelem[j] != item)//从表尾开始检查是否有元素与item值不相等相等 
					{
						parr->pelem[i] = parr->pelem[j];
						i++;
						j--;
						break;//如果条件成立跳出此循环 
					}
					else
					{
						if(parr->pelem[j] == item)//检查从表尾开始是否有元素与item相等
						parr->len--;//有的的话有效长度减一 
					}
				}			
			}
		}
		if(parr->pelem[j] == item)//判断最后一个元素是否等于item 
			parr->len--;
	}
	return;
	
}

void delete_same3(struct Arr *parr,int item)//参考智慧树视频代码 
{
	int i = 0,j = parr->len-1;
	while(i<j)
	{
		while(i<j&&parr->pelem[i] != item)i++;//从表头开始查找值为 item的位置i 
		while(i<j&&parr->pelem[j] ==item)//从表尾开始查找值为item的位置j 
		{
			j--;
			parr->len--;
		}
		parr->pelem[i] = parr->pelem[j];
		i++;
		j--;
		parr->len--;
		
	}
	if(parr->pelem[j] == item)//判断最后一个元素是否等于item 
		parr->len--;
	return;
}

/*void delete_same1(struct Arr *parr)//看错题了：删除相同的数据 
{
	int i = 0,j = parr->len-1,k=0;//i表示表头，j表示表尾；
	for(;j > i;j--)//从表头开始检查有无元素与最后一个元素相等 
	{
		for(;i < j;i++)
		{
			if(parr->pelem[i] == parr->pelem[j])
			{
				k=parr->pelem[i];
				for(;j > i;j--)
				{
					if(k != parr->pelem[j])
					{
						parr->pelem[i] = parr->pelem[j];
						parr->len = parr->len-2;
						j--;
						i++;
						break;
					}
				}

			}
		}
	}
}*/ 

void InitList(struct Arr *parr)//对结构体变量初始化 ：构造一个空表 
{
	parr->pelem = (int*)malloc(sizeof(int)*MAXSIZE);//分配内存； 
	if(parr->pelem == NULL)
	{
		printf("内存分配失败"); 
	}
	parr->len = 0;//有效长度为0 
	return;
}

bool is_full(struct Arr *parr)//判断表是否已满 
{
	if(parr->len==MAXSIZE)
	return true;
	else
	return false;
} 
bool is_empty (struct Arr *parr)//判断表是否为空 
{
	if(0 == parr->len)
	return true;
	else
	return false; 
}

bool ListInsert(struct Arr *parr,int data)//追加数据 
{
	if(is_full(parr))
	return false;
	else
	{
		parr->pelem[parr->len] = data;
		(parr->len)++;
		return true;
	}
}


