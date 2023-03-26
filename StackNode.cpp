/*                     2023.3.23              链栈                                  */
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>
//------------------------------------------------
typedef struct StackNode
{
	int data;
	StackNode* pnext;
}StackNode,*PStackNode;
//------------------------------------------------
void InitStackNode(PStackNode* pS);//初始化
bool Push(PStackNode* pS, int item);//入栈
bool Pop(PStackNode* pS, int* e);//出栈
void TraverseStack(PStackNode pS);//遍历
void TraverseList(PStackNode pS);
//------------------------------------------------
int main()
{
	PStackNode pS;
	int e = 0;
	InitStackNode(&pS);
	Push(&pS, 1);
	Push(&pS, 2);
	Push(&pS, 3);
	Push(&pS, 4);
	TraverseList(pS);
	Pop(&pS, &e);
	TraverseList(pS);
	return 0;
}
//------------------------------------------------
bool Pop(PStackNode* pS, int* e)//出栈
{
	if (*pS == NULL)
		return false;
	PStackNode P = *pS;
	*e = (*pS)->data;
	*pS = (*pS)->pnext;
	free(P);
	return true;
}
void TraverseList(PStackNode pS)
{
	printf("Result:\n");
	while (pS!=NULL)
	{
		printf("%d\n", pS->data);
		pS = pS->pnext;
	}
	printf("\n");
}
void TraverseStack(PStackNode pS)//递归遍历
{
	if (pS)
	{
		printf("%d\n", pS->data);
		TraverseStack(pS->pnext);
	}
}
bool Push(PStackNode* pS, int item)//入栈
{
	PStackNode P;
	P = (PStackNode)malloc(sizeof(StackNode));
	if (P == NULL)
		return false;
	P->pnext = *pS;
	P->data = item;
	*pS = P;
	return true;
}
void InitStackNode(PStackNode* pS)//初始化
{
	*pS = NULL;
	return;
}

