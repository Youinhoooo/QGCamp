#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include "duLinkedList.h"
/*�����ʼ��*/
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
/*�������*/
void DestroyList_DuL(DuLinkedList *L)  
{
	DuLinkedList p;
	while((*L)!=NULL){
		p = *L;
		(*L) = (*L)->next;
		free(p);
	}
}
/*��ĳһ���ǰ�����½�� */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) 
{
	if(p==NULL){
		printf("û�д˽�㣬����ʧ��\n");
		return ERROR;
	}
	else{
		q->prior = p->prior; /*�ȴ���q��p��ǰһ��������ϵ*/
		p->prior->next = q;  
		q->next = p;         /*�ٴ���q��p�Ĺ�ϵ*/
		p->prior = q;
		return SUCCESS;
	}
}
/*��ĳһ��������½��*/
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) 
{
	if(p==NULL){
		printf("û�д˽�㣬����ʧ��\n");
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
/*ɾ����� */
Status DeleteList_DuL(DuLNode *p, ElemType *e)
{
	if(p==NULL){
		printf("û���ҵ��˽�㣬���ɾ��ʧ��\n");
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
/*�������� */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
{
	DuLinkedList p;
	if(!L||!(L->next)){
		printf("��������\n");
	}
	else{
		for(p = L->next;p!=NULL;p = p->next)
		{
			(*visit)(p->data); /*����������ͨ��visit����չʾ*/
		}
		printf("NULL\n");
	}
}
/*�������������õĺ��� */
void visit(ElemType e)
{
	printf("%d-> ",e);	
}
/*����һ���������ڲ��ҽ�㲢������Ӧ��ָ�룬��ɾ���Ͳ��뺯������*/
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
	return NULL;//�����Ҳ��������ؿ�ָ�� 
}

int main()
{
	DuLinkedList head = NULL;
	char ele;
	do
	{
		printf("\n");
		printf("---a.�����ʼ��---\n");
		printf("---b.�������---\n");
		printf("---c.�ڽ��ǰ������---\n"); 
		printf("---d.�ڽ��������---\n");
		printf("---e.ɾ�����---\n");
		printf("---f.��������---\n");
		printf("---g.�˳�����---\n");
		scanf("%c",&ele); 
		
		switch(ele)
		{
			case 'a':
				{
					if(InitList_DuL(&head)){
						DuLinkedList L = head;
						printf("�ɹ�����������\n");
						ElemType n,i;
						printf("����Ҫ�����������\n");
						scanf("%d",&n);
						for(i=1;i<=n;i++){ /*������㲢����*/
							DuLinkedList p = (DuLinkedList)malloc(sizeof(DuLNode));
							L->next = p;
							p->prior = L;
							p->next = NULL;
							L = L->next; /*Lһֱָ����������һ�����*/ 
						}
						DuLinkedList h = head->next;
						for(i=1;i<=n;i++){
							printf("�������%d��������ֵ��",i);
							scanf("%d",&(h->data));
							h = h->next;
						}
					}
					else{
						printf("������ʧ��\n"); 
					}
					getchar();
					break;
				}
			case 'b':
				{
					DestroyList_DuL(&head);
					printf("����ɾ���ɹ�\n");
					getchar();
					break;
				}
			case 'c':
				{
					ElemType num1,num2;
					printf("������Ҫ����һ���ǰ�����½��\n");
					scanf("%d",&num1);
					DuLinkedList p = Search(head,num1); /*����Search������ΪInsertBeforeList_DuL�����ṩָ�����*/
					DuLinkedList q = (DuLinkedList)malloc(sizeof(DuLNode)); 
					if(InsertBeforeList_DuL(p,q)){
						printf("������ɹ���������˽�����ֵ\n");
						scanf("%d",&num2);
						q->data = num2;
					}
					getchar();
					break;
				}
			case 'd':
				{
					ElemType num1,num2;
					printf("������Ҫ����һ��������½��\n");
					scanf("%d",&num1);
					DuLinkedList p = Search(head,num1); /*����Search������ΪInsertBeforeList_DuL�����ṩָ�����*/
					DuLinkedList q = (DuLinkedList)malloc(sizeof(DuLNode)); 
					if(InsertAfterList_DuL(p,q)){
						printf("������ɹ���������˽�����ֵ\n");
						scanf("%d",&num2);
						q->data = num2;
					}
					getchar();
					break;
		        }
			case 'e':
			    {
			    	ElemType num;
			    	ElemType *e = &num; /*eҪָ��һ���ռ䣬��Ȼ�����*/ 
			    	printf("������Ҫɾ��������ֵ\n");
			    	scanf("%d",&num);
			    	DuLinkedList p = Search(head,num); /*����Search������ΪDeleteList_DuL�����ṩָ�����*/
			    	if(DeleteList_DuL(p,e)){
			    		printf("���ɾ���ɹ�\n");
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
		    printf("ѡ������밴�س������ز˵���ѡ\n");getchar();getchar();break;
	}}
	while(ele != 'g');
	
	return 0;
}
