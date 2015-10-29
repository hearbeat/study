#include <stdio.h>
#include <stdlib.h>

typedef struct _linknode_ {
	int data;
	struct _linknode_ *next;
}lnode_t;//节点

typedef struct _linklist_ {
	lnode_t *head;
	int clen;
	int tlen;
}list_t;//头节点

//创建节点
lnode_t *create_linknode(int value)
{
	lnode_t *node = NULL;

	node = malloc(sizeof(*node));
	node->data = value;
	node->next = NULL;

	return node;
}
//链表初始化
list_t *list_init(int len)
{
	list_t *list = NULL;

	list = malloc(sizeof(*list));
	list->head = create_linknode(0);
	list->clen = 0;
	list->tlen = len;

	return list;
}
//链表释放
int list_destroy(list_t *list)
{
	lnode_t *p = list->head;
	lnode_t *tmp;

	while (NULL != p) {
		tmp = p;
		p = p->next;
		free(tmp);
	}

	free(list);

	return 0;
}
//链表数据插入（头插法）
int list_insert(list_t *list, int value)
{
	lnode_t *node;
	lnode_t *h = list->head;

	if (list->clen >= list->tlen)
		return -1;

	node = create_linknode(value);
	node->next = h->next;
	h->next = node;
	list->clen++;

	return 0;
}

//打印链表
int list_show(list_t *list)
{
	lnode_t *p = list->head->next;

	printf("Clen: %d\tTlen: %d\n", list->clen, list->tlen);
	while (NULL != p) {
		printf("%3d", p->data);
		p = p->next;
	}
	putchar('\n');

	return 0;
}
//链表数据查询
lnode_t *list_search(list_t *list, int target)
{
	lnode_t *p = list->head->next;

	while (NULL != p) {
		if (p->data == target)
			break;
		p = p->next;
	}

	return p;
}
//数据修改
int list_modify(list_t *list, int old, int new)
{
	lnode_t *p = list->head->next;

	while (NULL != p) {
		if (p->data == old)
			break;
		p = p->next;
	}
	if (NULL == p)
		return -1;
	
	p->data = new;

	return 0;
}
//链表数据删除
int list_delete(list_t *list, int target)
{
	lnode_t *p = list->head;
	lnode_t *tmp;

	while (NULL != p->next && p->next->data != target)
		p = p->next;
	if (NULL == p->next)
		return -1;

	tmp = p->next;
	p->next = tmp->next;
	free(tmp);
	
	list->clen--;

	return 0;
}
//列表反转（指针向后移，每取数据头插法）
int list_reverse(list_t *list)
{
	lnode_t *p = list->head->next;
	lnode_t *tmp;

	list->head->next = NULL;

	while (NULL != p) {
		tmp = p;
		p = p->next;
		
		tmp->next = list->head->next;
		list->head->next = tmp;
	}

	return 0;
}
//链表主函数
int main()
{
	list_t *list = NULL;
	int value;
	lnode_t *ret;
	
	list = list_init(10);//初始化十个数据进来

	value = 1;
	while (0 == list_insert(list, value))//插入0~10数据
		value++;
	list_show(list);

#if 0
	if (NULL == (ret = list_search(list, 5)))
		puts("NO");
	else
		printf("%d\n", ret->data);
	list_modify(list, 1, 50);
	list_show(list);
	
	list_delete(list, 10);
	list_show(list);
#endif


	list_reverse(list);//反转
	list_show(list);
	list_destroy(list);

	return 0;
}

