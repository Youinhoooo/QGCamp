#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include "duLinkedList.h"
/*链表初始化*/
Status InitList_DuL(DuLinkedList *L) 
{
	*L = (DuLinkedList)malloc(sizeof(DuLNode));
	if(!(*L))
	{
		return ERROR;
	}
	(*L)->prior = NULL;
	(*L)->next = NULL;
	return SUCCESS; 
}
/*清除链表*/
void DestroyList_DuL(DuLinkedList *L)  
{
	DuLinkedList p;
	while((*L)!=NULL){
		p = *L;
		(*L) = (*L)->next;
		free(p);
	}
}
/*在某一结点前插入新结点 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) 
{
	if(p==NULL){
		printf("没有此结点，插入失败\n");
		return ERROR;
	}
	else{
		q->prior = p->prior; /*先处理q与p的前一个结点的联系*/
		p->prior->next = q;  
		q->next = p;         /*再处理q与p的关系*/
		p->prior = q;
		return SUCCESS;
	}
}
/*在某一结点后插入新结点*/
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) 
{
	if(p==NULL){
		printf("没有此结点，插入失败\n");
		return ERROR;
	}
	else{
		q->next = p->next;
		p->next->prior = q;
		p->next = q;
		q->prior = p;
		return SUCCESS;
	}
}
/*删除结点 */
Status DeleteList_DuL(DuLNode *p, ElemType *e)
{
	if(p==NULL){
		printf("没有找到此结点，结点删除失败\n");
		return ERROR;
	}
	else
	{
		*e = p->data;
		p->prior->next = p->next;
		p->next->prior = p->prior;
		free(p);
	}
}
/*遍历链表 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
{
	DuLinkedList p;
	if(!L||!(L->next)){
		printf("链表不存在\n");
	}
	else{
		for(p = L->next;p!=NULL;p = p->next)
		{
			(*visit)(p->data); /*将结点的数据通过visit函数展示*/
		}
		printf("NULL\n");
	}
}
/*供遍历函数调用的函数 */
void visit(ElemType e)
{
	printf("%d-> ",e);	
}
/*定义一个函数用于查找结点并返回相应的指针，供删除和插入函数调用*/
DuLNode* Search(DuLinkedList L,ElemType e) 
{
	DuLNode *p = L->next;
	while(p){
		if(p->data==e)
		{
			return p;
		}
		p=p->next;
	}
	return NULL;//若查找不到，返回空指针 
}

int main()
{
	DuLinkedList head = NULL;
	char ele;
	do
	{
		printf("\n");
		printf("---a.链表初始化---\n");
		printf("---b.清除链表---\n");
		printf("---c.在结点前插入结点---\n"); 
		printf("---d.在结点后插入结点---\n");
		printf("---e.删除结点---\n");
		printf("---f.遍历链表---\n");
		printf("---g.退出程序---\n");
		scanf("%c",&ele); 
		
		switch(ele)
		{
			case 'a':
				{
					if(InitList_DuL(&head)){
						DuLinkedList L = head;
						printf("成功创建空链表\n");
						ElemType n,i;
						printf("请问要创建几个结点\n");
						scanf("%d",&n);
						for(i=1;i<=n;i++){ /*创建结点并连接*/
							DuLinkedList p = (DuLinkedList)malloc(sizeof(DuLNode));
							L->next = p;
							p->prior = L;
							p->next = NULL;
							L = L->next; /*L一直指向链表的最后一个结点*/ 
						}
						DuLinkedList h = head->next;
						for(i=1;i<=n;i++){
							printf("请输入第%d个结点的数值：",i);
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
			case 'b':
				{
					DestroyList_DuL(&head);
					printf("链表删除成功\n");
					getchar();
					break;
				}
			case 'c':
				{
					ElemType num1,num2;
					printf("请输入要在哪一结点前插入新结点\n");
					scanf("%d",&num1);
					DuLinkedList p = Search(head,num1); /*调用Search函数，为InsertBeforeList_DuL函数提供指针参数*/
					DuLinkedList q = (DuLinkedList)malloc(sizeof(DuLNode)); 
					if(InsertBeforeList_DuL(p,q)){
						printf("结点插入成功，请输入此结点的数值\n");
						scanf("%d",&num2);
						q->data = num2;
					}
					getchar();
					break;
				}
			case 'd':
				{
					ElemType num1,num2;
					printf("请输入要在哪一结点后插入新结点\n");
					scanf("%d",&num1);
					DuLinkedList p = Search(head,num1); /*调用Search函数，为InsertBeforeList_DuL函数提供指针参数*/
					DuLinkedList q = (DuLinkedList)malloc(sizeof(DuLNode)); 
					if(InsertAfterList_DuL(p,q)){
						printf("结点插入成功，请输入此结点的数值\n");
						scanf("%d",&num2);
						q->data = num2;
					}
					getchar();
					break;
		        }
			case 'e':
			    {
			    	ElemType num;
			    	ElemType *e = &num; /*e要指向一个空间，不然会错误*/ 
			    	printf("请输入要删除结点的数值\n");
			    	scanf("%d",&num);
			    	DuLinkedList p = Search(head,num); /*调用Search函数，为DeleteList_DuL函数提供指针参数*/
			    	if(DeleteList_DuL(p,e)){
			    		printf("结点删除成功\n");
					}
					getchar();
					break;
				}
			case 'f':
				{
					TraverseList_DuL(head,visit);
					getchar();
					break;
				}
			case 'g':
				{
					break;
				}
			default:
		    printf("选择错误，请按回车键返回菜单重选\n");getchar();getchar();break;
	}}
	while(ele != 'g');
	
	return 0;
}
