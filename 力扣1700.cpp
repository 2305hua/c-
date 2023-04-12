// 力扣1700.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#define MAX 100 
#define N 10 //食物与学生个数
using namespace std;
//-----------stack栈 -------------------
typedef struct Stack
{
    int data;
    Stack* pnext;
}Stack,*PStack;
void InitStack(PStack& S);//初始化
bool Push(PStack& S, int e);//入栈
bool Pop(PStack& S, int& e);//出栈
bool GetTop(PStack S,int &e);//取栈顶元素
//-----------Queue队列-------------------
typedef struct
{
    int front;
    int rear;
    int* base;
}Queue;
bool InitQueue(Queue& L);//初始化
bool EnQueue(Queue& L, int e);//入队
bool DeQueue(Queue& L, int& e);//出队
bool GetHead(Queue L, int& e);//取队首
int LengthQueue(Queue L);//当前队列的长度
//----------------------------------
int Hungrystudent(PStack& S, Queue& L);
//----------------------------------
int main()
{
    PStack S;
    Queue L;
    InitStack(S);
    InitQueue(L);
    int A[N] = {};
    int B[N] = {};
    int e;
    for (int i = 0; i < N; i++)
    {
        A[i] = (rand() % 2);
        B[i] = (rand() % 2);
    }
    cout << "食物种类：（顺序为栈尾到栈顶）";
    for (int i = 0; i < N; i++)
    {
        Push(S, A[i]);
        GetTop(S, e);
        cout << e << " ";
    }
    cout << endl;
    cout << "学生偏好：（顺序为队头到队尾）";
    for (int i = 0; i < N; i++)
    {
        EnQueue(L, B[i]);
        cout << B[i] << " ";
    }
    cout << endl;
    e = Hungrystudent(S, L);
    cout << "挨饿学生：" << e;
    return 0;
}
//--------------------------------------
int Hungrystudent(PStack& S, Queue& L)
{
    //x用来保存从栈顶元素
    //y用来保存队首元素
    //e是用来显示出栈元素
    //t是用来显示出队或入队的元素
    //count 是用来计数，通过它来控制循环的终止
    int x = 0, y = 0, e = 0, t = 0,count = 0;
    while (LengthQueue != 0 && count < LengthQueue(L))
    {
        GetTop(S, x);
        GetHead(L, y);
        //若食物与学生偏好相符合那就出栈
        if (x == y)
        {
            Pop(S, e);
            cout << "出栈：" << e << " ";
            DeQueue(L, t);
            cout << "出队：" << t << endl;
            count = 0;//每次偏好符合就得重置count
        }
        //若不符合那就让学生先出队再入队
        else if (x != y)
        {
            DeQueue(L, t);
            EnQueue(L, t);
            cout << "出队入队：" << t << endl;
            count++;//每次偏好不符合就加一
        }

    }
    return LengthQueue(L);
}
//-----------------------------------
void InitStack(PStack& S)
{
    S = NULL;
    return;
}
bool Push(PStack& S, int e)
{
    PStack p = new Stack;
    if (p == NULL)
        return false;
    p->data = e;
    p->pnext = NULL;
    p->pnext = S;
    S = p;
    return true;
}
bool Pop(PStack& S, int& e)
{
    if (S == NULL)
        return false;
    PStack p = S;
    e = p->data;
    S = S->pnext;
    return true;
}
bool GetTop(PStack S,int &e)
{
    if (S == NULL)
        return false;
    else
    {
        e = S->data;
        return true;
    }
}
//-------------------------------------------
bool InitQueue(Queue& L)
{
    L.base = new int[MAX];
    if (L.base == NULL)
        return false;
    L.front = L.rear = 0;
    return true;
}
bool EnQueue(Queue& L, int e)
{
    if ((L.rear + 1) % MAX == L.front)
        return false;
    L.base[L.rear] = e;
    L.rear = (L.rear+1)%MAX;
    return true;
}
bool DeQueue(Queue& L, int& e)
{
    if (L.front == L.rear)
        return false;
    e = L.base[L.front];
    L.front = (L.front + 1) % MAX;
    return true;
}
bool GetHead(Queue L, int& e)
{
    if (L.front == L.rear)
        return false;
    e = L.base[L.front];
    return true;
}
int LengthQueue(Queue L)
{
    return ((L.rear - L.front + MAX) % MAX);
}

