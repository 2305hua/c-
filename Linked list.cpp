#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>
//----------------------------------------------------------------------------------
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
int DeleteElem(PNobe& pL, int n);
//-----------------------------------------------------------------------------------
int main()
{
	PNobe pL;
	InitList(pL);
	CreateList_R(pL, 3);
	TraverseList(pL);
	PNobe pA;
	InitList(pA);
	CreateList_H(pA, 3);
	TraverseList(pA);
	PNobe pC;
	InitList(pC);
	MergeList(pL, pA, pC);
	TraverseList(pC);
	ReverseList(pC);
	TraverseList(pC);
	InsertList(pC, 6, 6);
	TraverseList(pC);
	DeleteElem(pC, 1);
	TraverseList(pC);
	/*int e;
	GetElem(pC, 2, e);
	printf("%d\n", e);
	printf("%p\n", LocateElem(pC, 7));*/
	return 0;
}
//--------------------------------------------------------------------------------------
int DeleteElem(PNobe& pL, int n)
{
	PNobe P = pL, R;
	int i = 0;
	while (P && i < n - 1)
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
	pc->pNext =pa? pa : pb;//连接后面的结点；
	free(pB);//

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


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
