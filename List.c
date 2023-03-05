#include<stdio.h>
#include<malloc.h> 
#include<stdbool.h>
#define MAXSIZE 10
/*
˳���  
*/
struct Arr//����һ���ṹ��
{
	int *pelem;//����Ԫ�ص��׵�ַ 
	int len;//������Ч���� 
};
/*
----------------------------------------------------------------------------------------------------------------
*/
void delete_same3(struct Arr *parr,int item);//ʹ��whlieѭ�� 
void delete_same2(struct Arr *parr,int same);//ɾ��������itemֵ��ͬ��Ԫ�� ;ʹ�õ���forѭ�� 
//void delete_same1(struct Arr *parr);
void ShowList(struct Arr *parr);//չʾ�������� 
void InitList(struct Arr *parr);//��ʼ������ 
bool ListInsert(struct Arr *parr,int data);//׷�����ݣ��ڱ��ĩβ������ 
bool is_full(struct Arr *parr);//�жϱ��Ƿ��Ѿ����� 
bool is_empty (struct Arr *parr);//�жϱ��Ƿ�Ϊ�� 
/*
-----------------------------------------------------------------------------------------------------------------
*/

int main()
{
	struct Arr arr;
	InitList(&arr);//�Խṹ�����arr��ʼ��
	ListInsert(&arr,1);/*��˳���ֵ*/
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
	//delete_same2(&arr,2); //�о�ʱ�临�ӶȲ�������ĿҪ�� 
	delete_same3(&arr,2);//�ο��ǻ�����Ƶ�Ĵ��� 
	printf("ɾ����\n");
	ShowList(&arr);
	return 0;
}

/*
-----------------------------------------------------------------------------------------------------------------
*/
void ShowList(struct Arr *parr)//չʾ�������� 
{
	int i;
	for(i = 0;i < parr->len ;i++)
	{
		printf("%d\n",parr->pelem[i]);
	}
	return;
}

void delete_same2(struct Arr *parr,int item)//ɾ����item��ͬ������ �о�ʱ�临�ӶȲ��������� 
{
	int i = 0,j = parr->len-1;
	for(;j > i;j--) 
	{
		for(;i < j;i++)//�ӱ�ͷ��ʼ�������Ԫ����item��� 
		{
			if(parr->pelem[i] == item)//���ӱ�ͷ��ʼ�Ƿ���Ԫ����item��� 
			{
				parr->len--;//���������Ч����len��һ 
				for(;j > i;j--)
				{
					if(parr->pelem[j] != item)//�ӱ�β��ʼ����Ƿ���Ԫ����itemֵ�������� 
					{
						parr->pelem[i] = parr->pelem[j];
						i++;
						j--;
						break;//�����������������ѭ�� 
					}
					else
					{
						if(parr->pelem[j] == item)//���ӱ�β��ʼ�Ƿ���Ԫ����item���
						parr->len--;//�еĵĻ���Ч���ȼ�һ 
					}
				}			
			}
		}
		if(parr->pelem[j] == item)//�ж����һ��Ԫ���Ƿ����item 
			parr->len--;
	}
	return;
	
}

void delete_same3(struct Arr *parr,int item)//�ο��ǻ�����Ƶ���� 
{
	int i = 0,j = parr->len-1;
	while(i<j)
	{
		while(i<j&&parr->pelem[i] != item)i++;//�ӱ�ͷ��ʼ����ֵΪ item��λ��i 
		while(i<j&&parr->pelem[j] ==item)//�ӱ�β��ʼ����ֵΪitem��λ��j 
		{
			j--;
			parr->len--;
		}
		parr->pelem[i] = parr->pelem[j];
		i++;
		j--;
		parr->len--;
		
	}
	if(parr->pelem[j] == item)//�ж����һ��Ԫ���Ƿ����item 
		parr->len--;
	return;
}

/*void delete_same1(struct Arr *parr)//�������ˣ�ɾ����ͬ������ 
{
	int i = 0,j = parr->len-1,k=0;//i��ʾ��ͷ��j��ʾ��β��
	for(;j > i;j--)//�ӱ�ͷ��ʼ�������Ԫ�������һ��Ԫ����� 
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

void InitList(struct Arr *parr)//�Խṹ�������ʼ�� ������һ���ձ� 
{
	parr->pelem = (int*)malloc(sizeof(int)*MAXSIZE);//�����ڴ棻 
	if(parr->pelem == NULL)
	{
		printf("�ڴ����ʧ��"); 
	}
	parr->len = 0;//��Ч����Ϊ0 
	return;
}

bool is_full(struct Arr *parr)//�жϱ��Ƿ����� 
{
	if(parr->len==MAXSIZE)
	return true;
	else
	return false;
} 
bool is_empty (struct Arr *parr)//�жϱ��Ƿ�Ϊ�� 
{
	if(0 == parr->len)
	return true;
	else
	return false; 
}

bool ListInsert(struct Arr *parr,int data)//׷������ 
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

