#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "linkedList.h"
/*链表初始化*/
Status InitList(LinkedList *L)
{
	*L = (LinkedList)malloc(sizeof(LNode)); /*开辟一个新结点，不存放数据*/ 
	if(!(*L)){
		printf("内存分配失败");
		return ERROR;
	}
	(*L)->next = NULL;
	return SUCCESS;
}
/*清除链表 */
void DestroyList(LinkedList *L)
{
	LinkedList p;
	p = *L;
	while(*L != NULL){
		*L = (*L)->next; /*用p存储*L,*L不断指向下一个结点直到遇到空指针。最后p和*L都指向空指针*/ 
		free(p);
		p = *L;
	} 
}
/*插入结点*/
Status InsertList(LNode *p, LNode *q) 
{
	if(p){
		q->next = p->next;
		p->next = q;
		return SUCCESS;
	}
	else{
		return ERROR; 
	}
}
/*删除结点*/
Status DeleteList(LNode *p, ElemType *e) 
{
	if(p == NULL||(p->next) == NULL){
		return ERROR;
	} 
	LNode *q = p->next; //q指向p的下一个结点 
	p->next = q->next;
	*e = q->data;
	free(q);
	return SUCCESS;
}
/*遍历链表 */
void TraverseList(LinkedList L, void (*visit)(ElemType e))
{
	LinkedList p;
	for(p=L->next;p!=NULL;p=p->next){
		(*visit)(p->data);
	}
	printf("NULL");
}

void visit(ElemType e)
{
	printf("%d-> ",e);	
}
/*结点查找 */
Status SearchList(LinkedList L, ElemType e)
{
	LinkedList p =L->next;
	int i = 1;
	for(p;p != NULL;p=p->next) {
		if((p->data)==e){
			printf("此数据在第%d个结点\n",i);
			return SUCCESS; //当在链表中首次找到e时，返回SUCCESS 
		}
		i++;
	}
	return ERROR; //当遍历整个链表没有找到e时，返回ERROR 
}
/*链表反向(非递归)*/
Status ReverseList(LinkedList *L)
{
	LinkedList p,q,r; 
	p = (*L)->next,q = p->next;
	if((p == NULL)||(q == NULL)){
		return ERROR;
	}
	p->next = NULL;
	r = q;
	while(r != NULL){
		r = q->next; /*先将q->next存储在r中，防止将q反向后此结点丢失*/ 
		q->next = p; /*q指向它的上一个结点*/
		p = q;       /*p沿着链表的原顺序移动一位*/ 
		q = r;       /*q沿着链表的原顺序移动一位*/
	}
	(*L)->next = p;  /*L指向原来链表的最后一个节点*/
	return SUCCESS;
}
/*判断链表是否成环 */
Status IsLoopList(LinkedList L)
{
	LinkedList fast,slow; //定义一个快指针和一个慢指针 
	slow = L;
	fast = L; /*两个指针最开始都在L*/
	while((fast != NULL) && (fast->next != NULL)){
		fast = (fast->next)->next; /*快指针一次走两步*/
		slow = slow->next;         /*慢指针一次走一步*/
		if(fast==slow){
			return SUCCESS; /*如果快、慢指针相遇，则链表成环*/ 
		}
	}
	return ERROR;
}
/*链表奇偶调换*/
LNode* ReverseEvenList(LinkedList *L)
{
	LinkedList p,q,r,m;
	p = (*L)->next;
	q = p->next;
	(*L)->next = q;
	while(p!=NULL) /*p,q两个指针看成一组，当!p时表示结点有偶数个结点，当!(p->next)时表示有奇数个结点，最后一个结点不交换位置 */
	{
		q = p->next;
		r = q->next; /*将p,q所指向的结点交换位置*/
		q->next = p;
		p->next = r;
		m = p; 
		p = r;
		if(p!=NULL){
		m->next = p->next; /*p指向下一个组的第一个结点*/
		}
		if(p==NULL){
			m->next = NULL;
			break;
		}
		if((p->next)==NULL){
			m->next = p;
			break;
		}
	}
	return *L;
}
/*寻找链表中间结点*/
LNode* FindMidNode(LinkedList *L)
{
	LNode *fast,*slow; /*定义快、慢指针*/
	fast = *L;
	slow = *L;
	while((fast != NULL) && (fast->next != NULL)){
		slow = slow->next;
		fast = (fast->next)->next;
	} /*当快指针停止移动时，慢指针指向的结点就是中间结点*/ 
	return slow;
}
/*定义一个函数用于查找结点并返回相应的指针，供删除和插入函数调用*/
LNode* Search(LinkedList L,ElemType e)
{
	LNode *p = L->next;
	while(p != NULL){
		if(p->data==e){
			return p;
		}
		p=p->next;
	}
	return NULL; /*若查找不到，返回空指针*/
}

int main()
{
	LinkedList head = NULL;
	char ele;
	do{
	printf("\n");
	printf("---a.初始化链表---\n");
	printf("---b.清除链表---\n");
	printf("---c.插入结点---\n");
	printf("---d.删除结点---\n");
	printf("---e.遍历链表---\n");
	printf("---f.结点查找---\n");
	printf("---g.链表反向---\n");
	printf("---h.判断链表是否成环---\n");
	printf("---i.奇偶调换---\n");
	printf("---j.寻找中间结点---\n");
	printf("---k.退出程序---\n");
	LinkedList p = NULL;
	ElemType i;
	scanf("%c",&ele);
	
	switch(ele){
		case 'a': /*初始化链表*/ 
			{
				if(InitList(&head)){
					LinkedList L = *(&head);
					printf("成功创建空链表\n");
					ElemType n,a;
					printf("请输入要创建的结点数\n");
					scanf("%d",&n);
					for(a=1;a<=n;a++) /*创建新结点并连接*/ {
						LinkedList p = (LinkedList)malloc(sizeof(LNode));
						L->next = p;
						L = L->next;
						L->next = NULL;
					}
					
					LinkedList h = head->next;
					for(a=1;a<=n;a++) /*给结点赋值*/{
						printf("请输入第%d个结点的数值\n",a);
						scanf("%d",&(h->data));
						h = h->next;
					} 
				}
				else{
					printf("链表创建失败\n");
				}
				getchar();
				break;
			}
		case 'b': /*清除链表*/
			{
				DestroyList(&head);
				printf("已清除链表\n"); 
				break;
			}
		case 'c': /*插入结点*/
			{
				LinkedList p = NULL;
				 printf("请输入要插入结点的前结点的数值：");
				 scanf("%d",&i);
				 p = Search(head,i); /*先用Search函数找到InsertList需要用到的指针参数*/
				 LinkedList q = (LinkedList)malloc(sizeof(LNode));
				if(InsertList(p, q)){
					printf("结点插入成功\n");
					printf("请输入此结点的数值\n");
					scanf("%d",&(q->data)); 
				}
				else{
					printf("查无此前结点, 结点插入失败\n");
				}
				getchar();
				break;
			}
		case 'd': /*删除结点*/
			{
				ElemType num;
				printf("请输入要删除的结点的前一个结点存储的数字:\n");
				scanf("%d",&num);
				LinkedList h = Search(head,num); /*先用Search函数找到Deletelist需要用到的指针参数*/
				if(DeleteList(h,&num)){
					printf("结点删除成功\n");
				}
				else{
					printf("没有找到此结点，结点删除失败\n");
				}
				getchar();
				break;
			}
	    case 'e':/*遍历链表*/
	    	{
	    		void *f = visit;
	    		TraverseList(head,f);
	    		getchar();
				break;
			}
		case 'f': /*结点查找*/
			{
				int num;
				printf("请输入要查找的数据：");
				scanf("%d",&num);
				if(!(SearchList(head,num))){
					printf("没有此数值\n");
				}
				getchar();
				break;
			}
		case 'g': /*链表反向*/
			{
				if(ReverseList(&head)){
					printf("反向成功\n");
				}
				else{
					printf("反向失败\n");
				}
				getchar();
				break;
			}
		case 'h': /*判断链表是否成环*/
			{
				if(IsLoopList(head)){
					printf("链表已成环\n");
				}
				else{
					printf("链表未成环\n");
				}
				getchar();
				break;
			}
		case 'i':/*奇偶调换*/
			{
				head = ReverseEvenList(&head);
				printf("链表调换成功\n");
				getchar();
				break;
			}
		case 'j':/*寻找中间结点*/ 
			{
				p = FindMidNode(&head);
				printf("中间结点是%d",p->data);
				getchar();
				break;
			}
		case 'k': /*退出程序*/
			{
				break;
			}
		default:
		    printf("选择错误，请按回车键返回菜单重选\n");getchar();getchar();break;
	}}
	while(ele != 'k');
	
	return 0;
}
