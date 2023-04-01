// StackNode(max).cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>
//------------------------------------------------
typedef struct Node
{
	int data;//数据域
	Node* pnext;//用于存放下一个结点的指针
}Node, * PNode;
typedef struct Stack
{
	PNode pTop;//栈顶指针
	PNode pMax;//辅助栈
}Stack;
//------------------------------------------------
void InitNode(Stack* pS);//初始化
bool Push(Stack* pS, int item);//入栈
bool Pop(Stack *pS, int* e);//出栈
void NodeTravese(PNode pS);//递归遍历
int GetTop(PNode pS);//取栈顶元素
int Max(Stack pS);//找出当前Max值
//------------------------------------------------
int main()
{
	Stack S;
	int M[11] = { 5,4,10,2,1,10,9,8,8,15,6 };
	int e;
	InitNode(&S);
	for (int i = 0; i < 11; i++)
		Push(&S, M[i]);
	printf("主栈元素：\n");
	NodeTravese(S.pTop);
	Max(S);
	printf("辅助栈元素：\n");
	NodeTravese(S.pMax);
	Pop(&S, &e);
	Pop(&S, &e);
	printf("\n");
	printf("主栈元素：\n");
	NodeTravese(S.pTop);
	Max(S);
	printf("辅助栈元素：\n");
	//printf("%d\n", GetTop(S.pTop));
	NodeTravese(S.pMax);
	return 0;
}
//------------------------------------------------
int Max(Stack pS)
{
	printf("\nThe MAX is %d \n", pS.pMax->data);
	return pS.pMax->data;
}
int GetTop(PNode pS)
{
	if (pS != NULL)
	{
		return pS->data;
	}
}
void InitNode(Stack* pS)
{
	pS->pTop = NULL;
	pS->pMax = NULL;
	return;
}
bool Push(Stack* pS, int item)
{   //push到主栈
	PNode P = (PNode)malloc(sizeof(Node));
	if (P == NULL)
		return false;
	//插入步骤
	P->data = item;
	P->pnext = pS->pTop;
	pS->pTop = P;
	//push到辅助栈
	
	
	if (pS->pMax == NULL)//如果是第一个元素
	{
		PNode Q = (PNode)malloc(sizeof(Node));
		if (Q == NULL)
			return false;
		//插入步骤
		Q->data = P->data;
		Q->pnext = pS->pMax;
		pS->pMax = Q;
	}
	else //如果不是第一个元素
	{

		if (pS->pMax->data <= pS->pTop->data)//满足条件进入辅助栈
		{
			PNode R = (PNode)malloc(sizeof(Node));
			if (R == NULL)
				return false;
			//插入步骤
			R->data = P->data;
			R->pnext = pS->pMax;
			pS->pMax = R;
		}
	}
	return true;
}
bool Pop(Stack* pS, int* e)
{
	if (pS->pTop == NULL)//为空则返回false；
		return false;

	if (pS->pTop->data == pS->pMax->data)//如果满足条件，则删除辅助栈的栈顶元素
	{
		PNode Q = NULL;
		//删除步骤
		Q = pS->pMax;
		pS->pMax = pS->pMax->pnext;
		free(Q);
	}
	*e = pS->pTop->data;
	PNode P = NULL;
	//删除步骤
	P = pS->pTop;
	pS->pTop = pS->pTop->pnext;
	free(P);
	return true;
}
void NodeTravese(PNode pS)//递归遍历
{
	if (pS)
	{
		printf("%d ", pS->data);
		NodeTravese(pS->pnext);
	}
}



