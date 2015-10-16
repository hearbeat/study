#include <stdio.h>
#include <stdlib.h>
#define LIST_SIZE 100

/*���Ա�Ķ���*/
typedef struct _SeqList
{
	char *data;
	int length;//��ǰ���ݵĳ���
	int listsize;//�����ܳ���
}SeqList;

/*���Ա�ĳ�ʼ��*/
int list_init(SeqList *seqList)
{
	seqList->data = (char *)malloc(LIST_SIZE * sizeof(char));
	seqList->length = 0;
	seqList->listsize = LIST_SIZE;
	return 0;
}

/*���Ա����ݲ���*/
int list_insert(SeqList *seqList, int i, char d)
{
	//û�жԲ���ȫ����������ֻ���в���
	char *p = seqList->data+(i-1);
	for (char *q = seqList->data+(seqList->length - 1); q >= p; q --)
	{
		*(p+1) = *p;
	}//i֮���Ԫ������
	*p = d;
	seqList->length++;
	return 0;
}

/*���Ա�����ɾ��*/
int list_delete(SeqList *seqList, int i)
{
	char Data = seqList->data[i -1];
	char *q = seqList->data+(seqList->length - 1);
	for (char *p = seqList->data+(i-1); p < q; p ++)
	{
		*p = *(p + 1);
	}//i֮���Ԫ������
	seqList->length--;
	return Data;
}

/*���Ա�����λ��ȷ��*/
int list_elem(SeqList *seqList, char d)
{
	int i = 1;
	char *p = seqList->data;
	while(*p++!=d && i<=seqList->length)//������ͬ��dʱ�˳�ѭ��Ȼ��ֵ
		i++;
	if(i >= seqList->length)
		return 0;
	else
		return i;
}

/*��������д*/
int main()
{
	SeqList seqList;
	list_init(&seqList);
	for(int i = 1; i<=10; i++)
		list_insert(&seqList, i, i);//ǰʮ�����ݸ�ֵ
	printf("deletd_data: %d\n",list_delete(&seqList, 3));//ɾ��������Ԫ�أ����ش�Ԫ�ص�ֵ
	printf("elem_data: %d\n",list_elem(&seqList, 5));//��λ�����Ԫ�أ����ص�ǰֵ
	
	for(int i = 1; i<=5; i++)//��ӡǰ���Ԫ�ص�ֵ
		printf("data%d: %d\n", i, seqList.data[i-1]);
	return 0;
}
