#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>
//----------------------------------------------------------------------------------2023.3.21
typedef struct LNobe
{
	int data;//数据域
	struct LNobe* pNext;//指针域
}LNobe,*PNobe;//LNobe等价于struct LNobe ，PNobe等价于struct LNobe *

//-----------------------------------------------------------------------------------
void InitList(PNobe& pL);//初始化函数
void CreateList_H(PNobe& pL, int n);//前插法创建单链表，n表示有效节点个数
void CreateList_R(PNobe& pL, int n);//用后插法创建单链表，n表示要创建的有效结点个数
void TraverseList(PNobe pL);//遍历函数
void MergeList(PNobe& pA, PNobe& pB, PNobe& pC);//合并表A，B
void ReverseList(PNobe& pL);//逆转表
bool GetElem(PNobe pL, int n, int& e);//取值函数
PNobe LocateElem(PNobe& pL, int e);//查找函数
bool InsertList(PNobe& pL, int n, int elem);//插入函数，n为插入位置，elem为插入的数据
int DeleteElem(PNobe& pL, int n);//删除函数
void Sort_List(PNobe pL);//排序函数
int Length_list(PNobe pL);//计算有效结点个数
void Intersertion(PNobe &pA,PNobe &pB);//找出两个递增值的有序表的交集；
void FindDifferent(PNobe& pA, PNobe& pB);//找出两个递增值的有序表的交集,(仅出现在A中的元素)；
int FindMAX(PNobe& pA);//寻找链表最大值
void CreateList_Arr_R(PNobe& pL, int* M, int n);
PNobe TurnLoop(PNobe& pL, int n);//让链表中形成环，n表示第几个元素位置为环的入口
PNobe FindtheAccess(PNobe& pL);//找表的入口
int Length_Hoop(PNobe pL);//计算环的长度
//-----------------------------------------------------------------------------------
int main()
{
	PNobe pL,A,B;
	int M[10]={}, i;
	for (i = 0; i < 10; i++)
		M[i] = i + 1;
	InitList(pL);
	CreateList_Arr_R(pL, M, 10);
	TraverseList(pL);
	A = TurnLoop(pL, 3);
	//TraverseList(pL);
	B = FindtheAccess(pL);
	printf("%p %p %d", A, B, Length_Hoop(A));
	//CreateList_R(pL, 10);
	/*PNobe pA;
	InitList(pA);
	CreateList_R(pA, 3);
	TraverseList(pA);*/
	//FindDifferent(pL, pA);
	//Intersertion(pL, pA);
	//printf("The MAX number:%d\n", FindMAX(pL));
	/*TraverseList(pL);*/

	/*PNobe pC;
	MergeList(pL, pA, pC);
	TraverseList(pC);
	ReverseList(pC);
	TraverseList(pC);*/
	//InsertList(pC, 6, 6);
	//TraverseList(pC);
	//DeleteElem(pC, 6);
	//TraverseList(pC);
	/*int e;
	GetElem(pC, 2, e);
	printf("%d\n", e);
	printf("%p\n", LocateElem(pC, 7));*/
	//printf("%d", length_list(pC));
	//Sort_List(pC);
	//TraverseList(pC);
	return 0;
}
//--------------------------------------------------------------------------------------
int Length_Hoop(PNobe pL)
{
	PNobe P = pL;
	int i = 0;
	while (P)
	{
		P = P->pNext;
		i++;
		if (P == pL)
			break;
	}
	return i;
}
PNobe FindtheAccess(PNobe& pL)
{
	if (pL == NULL)
		exit(-1);
	PNobe P = pL, Q = pL;
	while (Q != NULL && Q->pNext != NULL)
	{
		P = P->pNext;//慢指针
		Q = Q->pNext->pNext;//快指针
		if (P == Q)
		{
			//Q = Q->pNext;
			P = pL;
			break;
		}
	}
	while (Q != NULL && Q->pNext != NULL)
	{
		P = P->pNext;
		Q = Q->pNext/*->pNext*/;
		if (P == Q)
		{
			break;
		}
	}
	return P;
}
PNobe TurnLoop(PNobe& pL, int n)//让单链表中形成环
{
	if (Length_list(pL) < n || pL == NULL)
		exit(-1);
	PNobe P = pL->pNext;
	PNobe H = NULL;
	PNobe R = NULL;
	int i = 1;
	//找到链尾R，找到环的入口位置H
	while (P)
	{
		if (P->pNext == NULL)
			R = P;
		if (i == n)
			H = P;
		P = P->pNext;
		i++;
	}
	//没找到就退出
	if (H == NULL)
	{
		printf("fasle\n");
		exit(-1);
	}
	//找到就链接
	else
	{
		R->pNext = H;
	}
	//返回入口地址
	return H;
}
void CreateList_Arr_R(PNobe& pL, int* M, int n)
{
	PNobe R = pL;//创建一个尾指针，使它与头指针一同指向头结点
	PNobe P;//用于生成新的结点
	int i = 0;
	for (i = 0; i < n; i++)
	{
		P = (PNobe)malloc(sizeof(LNobe));//生成新结点
		if (NULL == P)
		{
			printf("内存分配失败\n");
			exit(-1);
		}
		P->data = M[i];
		P->pNext = NULL;//新节点指针域指向空；
		R->pNext = P;//让头结点指针域指向新节点；
		R = P;//让尾指针指向新结点
	}
}
int FindMAX(PNobe& pA)//寻找链表最大值
{
	PNobe P = pA->pNext;
	int max = P->data;
	while (P)
	{
		if (max < P->data)
		{
			max = P->data;
			P = P->pNext;
		}
		else
		{
			P = P->pNext;
		}
	}
	return max;
}
void FindDifferent(PNobe& pA, PNobe& pB)
{
	if (pA == NULL || pB == NULL)
		exit(-1);
	PNobe pa = pA->pNext;
	PNobe pb = pB->pNext;
	PNobe p1 = pA;
	PNobe pt = NULL;
	while (pa && pb)
	{
		if (pa->data == pb->data)
		{
			pt = pa;
			p1->pNext = pa->pNext;
			pa = pa->pNext;
			p1 = p1->pNext;
			pb = pb->pNext;
			free(pt);
		}
		else if (pa->data < pb->data)
		{
			pa = pa->pNext;
			p1 = p1->pNext;
		}
		else
		{
			pb = pb->pNext;
		}
	}
}
void Intersertion(PNobe &pA, PNobe &pB)//找出两个递增值的有序表的交集；
{
	PNobe pa = pA->pNext;//指向A表的首元节点
	PNobe pb = pB->pNext;//指向B表的首元节点
	PNobe pt;//释放结点
	PNobe p1 = pA;//用于指向pa指向的前一个结点
	PNobe p2 = pB;//用于指向pb指向的前一个结点
	while (pa && pb)
	{
		if (pa->data == pb->data)
		{
			pt = pb;
			p2->pNext = pb->pNext;//删除操作
			pb = pb->pNext;//删除操作
			p1 = p1->pNext;
			pa = pa->pNext;
			free(pt);
		}
		else if (pa->data < pb->data)
		{
			pt = pa;
			p1->pNext = pa->pNext;
			pa = pa->pNext;
			free(pt);
		}
		else//(pa->data > pb->data)
		{
			pt = pb;
			p2->pNext = pb->pNext;
			pb = pb->pNext;
			free(pt);
		}

	}
	
	/*pt = pa->pNext;
	pa = pa->pNext;
	pt->pNext = NULL;
	while (pa)
	{
		pt = pa;
		pa = pa->pNext;
		free(pt);
	}
	pt = pb->pNext;
	pb = pb->pNext;
	pt->pNext = NULL;
	while (pb)
	{
		pt = pb;
		pb = pb->pNext;
		free(pt);
	}*/
}
int Length_list(PNobe pL)
{
	int len = 0;
	PNobe P = pL;
	while (P->pNext != NULL)
	{
		P = P->pNext;
		len++;
	}
	return len;
}
void Sort_List(PNobe pL)//排序函数，将链表中元素按递增顺序排列，len表示链表中有效结点个数
{
	int i, j, t = 0;
	PNobe P, R;
	for (i = 0, P = pL->pNext; i < Length_list(pL)-1 /* && P->pNext != NULL*/; i++, P = P->pNext)//与数组排序相似
	{
		for (j = i+1, R = P->pNext; j < Length_list(pL)  /* && R->pNext != NULL*/; j++, R = R->pNext)
		{
			if (P->data > R->data)
			{
				t = P->data;
				P->data = R->data;
				R->data = t;
			}
		}
	}
}
int DeleteElem(PNobe& pL, int n)
{
	PNobe P = pL, R;
	int i = 0;
	while (P  && i < n - 1)
	{
		P = P->pNext;
		i++;
	}
	if (P == NULL || i > n - 1)
		exit(-1);
	R = P->pNext;
	P->pNext = R->pNext;
	i = R->data;
	free(R);
	return i;
}
bool InsertList(PNobe& pL, int n, int elem)//插入函数，n为插入位置，elem为插入的数据
{
	PNobe P =pL,T=(PNobe)malloc(sizeof(LNobe));
	if (NULL == T)
	{
		return false;
	}
	T->data = elem;
	int i = 0;
	while (P && i <n-1)//找到插入元素的前一个结点
	{
		P = P->pNext;
		i++;
	}
	if (P == NULL || i > n - 1)
	{
		printf("InsertList false\n");
		exit(-1);
	}
	T->pNext = P->pNext;
	P->pNext = T;
	return true;
}
PNobe LocateElem(PNobe& pL, int e)//查找与e值相等的元素
{
	PNobe P = pL->pNext;
	while (P && P->data != e)
	{
		P = P->pNext;
	}
	return P;//查找失败返回NULL
}
bool GetElem(PNobe pL, int n, int& e)//取值函数n为所取元素的序号，e用于接收元素
{
	PNobe P = pL->pNext;//让P指向首元结点也就是第一个有效数据
	int i = 1;//用于计数
	while (P && i < n)
	{
		P = P->pNext;
		i++;
	}
	if (P == NULL || i > n)
		return false;
	e = P->data;
	return true;
}
void ReverseList(PNobe& pL)//“原地逆转”，
{
	PNobe pa=NULL, pb=pL->pNext, pc=pL->pNext->pNext;//让pa指向空，pb指向当前结点，pc指向下一个结点；
	while (pc->pNext != NULL)//直到pc指向的结点为空
	{
		pb->pNext = pa;//让pb的结点指向pa
		pa = pb;//pa向下移动一个结点
		pb = pc;//pb向下移动一个结点
		pc = pc->pNext;//pc向下移动一个结点
	}
	//最后还有pb，pc两个结点的指向没有逆转，
	pb->pNext = pa;
	pc->pNext = pb;
	pL->pNext = pc;//让原头结点指向你逆转后的首结点
}


void MergeList(PNobe& pA, PNobe& pB, PNobe& pC)//合并表A，B
{
	PNobe pa = pA->pNext, pb = pB->pNext, pc = pA;//用pa，pb，pc指向第一个有效结点pa与pc同时指向表a
	pC = pA;
	while (pa && pb)
	{
		if (pa->data <= pb->data)
		{
			pc->pNext = pa;//
			pc = pc->pNext;//让pc，pa指向下一个结点
			pa = pa->pNext;
		}
		else
		{
			pc->pNext = pb;//
			pc = pc->pNext;//让pc，pb指向下一个结点
			pb = pb->pNext;
		}
	}
	pc->pNext =pa? pa : pb;//连接后面的结点,三目运算符；
	free(pB);//释放B的结点

}

void TraverseList(PNobe pL)//遍历函数访问每一个节点
{
	PNobe P = pL->pNext;
	printf("结果:\n");
	while (NULL != P)
	{
		printf("%d ", P->data);
		P = P->pNext;
	}
	printf("\n");
}

void CreateList_H(PNobe& pL, int n)
{
	/*pL = (PNobe)malloc(sizeof(LNobe));
	if (NULL == pL)
	{
		printf("内存分配失败\n");
		exit(-1);
	}
	pL->pNext = NULL;*/
	int i = 0, temp = 0;
	PNobe H;
	for (i = 0; i < n; i++)
	{
		printf("请输入第%d个数据:", i + 1);
		scanf("%d", &temp);
		H = (PNobe)malloc(sizeof(LNobe));//生成新结点
		if (NULL == H)
		{
			printf("内存分配失败\n");
			exit(-1);
		}
		H->data = temp;
		H->pNext = pL->pNext;
		pL->pNext = H;
	}
}
void CreateList_R(PNobe& pL, int n)//用后插法创建单链表，n表示要创建的有效结点个数
{
	//pL = (PNobe)malloc(sizeof(LNobe));//
	//if (NULL == pL)
	//{
	//	printf("内存分配失败\n");
	//	exit(-1);
	//}
	//pL->pNext = NULL;//
	PNobe R = pL;//创建一个尾指针，使它与头指针一同指向头结点
	PNobe P;//用于生成新的结点
	int i = 0, temp = 0;//temp用来存放输入数据；
	for (i = 0; i < n; i++)
	{
		P = (PNobe)malloc(sizeof(LNobe));//生成新结点
		if (NULL == P)
		{
			printf("内存分配失败\n");
			exit(-1);
		}
		printf("请输入第%d个数据:", i + 1);
		scanf("%d", &temp);
		P->data = temp;
		P->pNext = NULL;//新节点指针域指向空；
		R->pNext = P;//让头结点指针域指向新节点；
		R = P;//让尾指针指向新结点
	}
}

void InitList(PNobe& pL)//链表初始化
{
	pL = (PNobe)malloc(sizeof(LNobe));//生成新的结点，用头指针指向它
	if (NULL == pL)
	{
		printf("内存分配失败\n");
		exit(-1);
	}
	pL->pNext = NULL;//头结点指向空
	return;
}



