// SqList (max).cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/* 顺序栈 2023.3.23  */
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#define _CRT_SECURE_NO_WARNINGS
#define MAXSIZE 100
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>
//----------------------------------------------------------------------------------------------------------
typedef struct
{
	int* pBase;//栈底指针
	int* pTop;//栈顶指针
	int SqStacksize;//栈可用的最大容量
	int maxE;//存储最大数
	int* M[MAXSIZE];//存放找到的最大值的地址
	int tail;//存放当前的最大值地址在数组中的位置

}SqStack;
//----------------------------------------------------------------------------------------------------------
bool InitStack(SqStack* List);//初始化顺序栈
void TraverStack(SqStack List);//遍历
bool Push(SqStack* List, int item);//入栈
bool Pop(SqStack* List);//出栈
int GetTop(SqStack List);//取栈顶元素
//----------------------------------------------------------------------------------------------------------
int main()
{
	SqStack S;
	int M[11] = {5,4,1,2,3,10,9,8,7,6,15};
	InitStack(&S);
	int i;
	for ( i = 0; i < 11; i++)
	{
		Push(&S, M[i]);
	}
	printf("%d\n", S.maxE);
	Pop(&S);
	Pop(&S);
	Pop(&S);
	Pop(&S);
	Pop(&S);
	Pop(&S);
	Pop(&S);
	printf("%d", S.maxE);
	return 0;
}
//----------------------------------------------------------------------------------------------------------
int GetTop(SqStack List)
{
	if (List.pTop != List.pBase)
		return *--List.pTop;
}
bool Pop(SqStack* List)//出栈
{
	if (List->pTop == List->pBase)//判断是否栈空
		return false;
	List->pTop--;
	if (*List->pTop == List->maxE)
	{
		List->tail--;
		List->maxE = *List->M[List->tail];
	}
	return true;
}
bool Push(SqStack* List, int item)
{
	if (List->pTop - List->pBase == List->SqStacksize)
		return false;
	*List->pTop = item;//给顺序栈赋值
	if (List->pTop == List->pBase)//此时为第一个元素
	{
		List->maxE = *List->pBase;//将第一个元素赋值给maxE保存
		List->tail = 0;//
		List->M[List->tail] = List->pBase;//第一个元素地址保存起来
	}
	else//不是以上情况
	{
		if (List->maxE <= *List->pTop)
		{
			List->maxE = *List->pTop;
			List->tail++;
			List->M[List->tail] = List->pTop;
		}
	}
	List->pTop++;
	return true;
}
void TraverStack(SqStack List)
{
	int i = 0;
	for (i = 0; i < List.pTop - List.pBase; i++)
	{
		printf("The %d number is: %d\n", i + 1, List.pBase[i]);
	}
	return;
}
bool InitStack(SqStack* List)//初始化顺序栈
{
	List->pBase = (int*)malloc(sizeof(int) * MAXSIZE);
	if (List->pBase == NULL)
		return false;
	List->pTop = List->pBase;
	List->SqStacksize = MAXSIZE;
	List->maxE = -100;
	List->tail = 0;
	return true;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
