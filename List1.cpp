#define MAXSIZE 10
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <iostream>


struct Arr
{
    int* pelem;//
    int len;//有效长度
};
//-------------------------------------------
void MergeList(struct Arr& parr, struct Arr& pbrr, struct Arr& pcrr);
bool AddArr(struct Arr* parr, int* M,int n);//将数组赋值给表//M为数组地址，n为数组长度
bool InitList(struct Arr* parr);//初始化
void ShowList(struct Arr* parr);//展示数据
bool is_full(struct Arr* parr);//判断表是否已经满了 
bool is_empty(struct Arr* parr);//判断表是否为空 
void MergeList(struct Arr* parr, struct Arr* pbrr, struct Arr* pcrr);//将按非递减排序的表A，表B的值，合并且按照非递减排序赋值给表C
//-------------------------------------------------
int main()
{
    Arr arr,brr,crr;
    InitList(&arr);//初始化表A
    InitList(&brr);//初始化表B
    InitList(&crr);//初始化表C
    int A[3] = { 1,7,8 };
    int B[6] = { 2,4,6,8,10,11 };
    AddArr(&arr, A, 3);
    AddArr(&brr, B, 6);
    printf("表A:");
    ShowList(&arr);
    printf("\n");
    printf("表B:");
    ShowList(&brr);
    MergeList(&arr, &brr, &crr);
    printf("\n");
    printf("表C:");
    ShowList(&crr);
    return 0;
}
//---------------------------------------------------------
void MergeList(struct Arr* parr, struct Arr* pbrr, struct Arr* pcrr)
{
    int i = 0, j = 0, k = 0;
    while (i < parr->len && j < pbrr->len)
    {
        if (parr->pelem[i] <= pbrr->pelem[j])
        {
            pcrr->pelem[k] = parr->pelem[i];
            i++;
            k++;
        }
        else
        {
            pcrr->pelem[k] = pbrr->pelem[j];
            j++;
            k++;
        }
    }
    while (i < parr->len)
    {
        pcrr->pelem[k] = parr->pelem[i];
        i++;
        k++;
    }
    while (j < pbrr->len)
    {
        pcrr->pelem[k] = pbrr->pelem[j];
        j++;
        k++;
    }
    pcrr->len = k;
}
bool AddArr(struct Arr* parr,int* M,int n)
{
    int i;
    if (n > MAXSIZE)
    {
        printf("数组长度大于表长");
        return false;
    }
    for (i = 0; i < n; i++)
    {
        parr->pelem[i] = M[i];
        parr->len++;
    }
    return true;
}
void ShowList(struct Arr* parr)//展示数据
{
    int i;
    for (i = 0; i < parr->len; i++)
    {
        printf("%d ", parr->pelem[i]);
    }
}
bool InitList(struct Arr* parr)
{
    parr->pelem = (int*)malloc(sizeof(int) * MAXSIZE);//分配内存
    if (NULL == parr)
    {
        return false;
    }
    parr->len = 0;//初始化有效长度为0
    return true;
}
bool is_empty(struct Arr* parr)//判断表是否为空 
{
    if (0 == parr->len)
        return true;
    else
        return false;
}
bool is_full(struct Arr* parr)//判断表是否已满 
{
    if (parr->len == MAXSIZE)
        return true;
    else
        return false;
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
