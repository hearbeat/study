#include <stdio.h>
#include <stdlib.h>
#define LIST_SIZE 100

/*线性表的定义*/
typedef struct _SeqList
{
	char *data;
	int length;//当前数据的长度
	int listsize;//数据总长度
}SeqList;

/*线性表的初始化*/
int list_init(SeqList *seqList)
{
	seqList->data = (char *)malloc(LIST_SIZE * sizeof(char));
	seqList->length = 0;
	seqList->listsize = LIST_SIZE;
	return 0;
}

/*线性表数据插入*/
int list_insert(SeqList *seqList, int i, char d)
{
	//没有对不安全因素做处理，只进行插入
	char *p = seqList->data+(i-1);
	for (char *q = seqList->data+(seqList->length - 1); q >= p; q --)
	{
		*(p+1) = *p;
	}//i之后的元素右移
	*p = d;
	seqList->length++;
	return 0;
}

/*线性表数据删除*/
int list_delete(SeqList *seqList, int i)
{
	char Data = seqList->data[i -1];
	char *q = seqList->data+(seqList->length - 1);
	for (char *p = seqList->data+(i-1); p < q; p ++)
	{
		*p = *(p + 1);
	}//i之后的元素左移
	seqList->length--;
	return Data;
}

/*线性表数据位置确定*/
int list_elem(SeqList *seqList, char d)
{
	int i = 1;
	char *p = seqList->data;
	while(*p++!=d && i<=seqList->length)//遇到相同的d时退出循环然后付值
		i++;
	if(i >= seqList->length)
		return 0;
	else
		return i;
}

/*主函数编写*/
int main()
{
	SeqList seqList;
	list_init(&seqList);
	for(int i = 1; i<=10; i++)
		list_insert(&seqList, i, i);//前十个数据付值
	printf("deletd_data: %d\n",list_delete(&seqList, 3));//删除第三个元素，返回此元素的值
	printf("elem_data: %d\n",list_elem(&seqList, 5));//定位第五个元素，返回当前值
	
	for(int i = 1; i<=5; i++)//打印前五个元素的值
		printf("data%d: %d\n", i, seqList.data[i-1]);
	return 0;
}
