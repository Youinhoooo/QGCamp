#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "linkedList.h"
/*�����ʼ��*/
Status InitList(LinkedList *L)
{
	*L = (LinkedList)malloc(sizeof(LNode)); /*����һ���½�㣬���������*/ 
	if(!(*L)){
		printf("�ڴ����ʧ��");
		return ERROR;
	}
	(*L)->next = NULL;
	return SUCCESS;
}
/*������� */
void DestroyList(LinkedList *L)
{
	LinkedList p;
	p = *L;
	while(*L != NULL){
		*L = (*L)->next; /*��p�洢*L,*L����ָ����һ�����ֱ��������ָ�롣���p��*L��ָ���ָ��*/ 
		free(p);
		p = *L;
	} 
}
/*������*/
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
/*ɾ�����*/
Status DeleteList(LNode *p, ElemType *e) 
{
	if(p == NULL||(p->next) == NULL){
		return ERROR;
	} 
	LNode *q = p->next; //qָ��p����һ����� 
	p->next = q->next;
	*e = q->data;
	free(q);
	return SUCCESS;
}
/*�������� */
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
/*������ */
Status SearchList(LinkedList L, ElemType e)
{
	LinkedList p =L->next;
	int i = 1;
	for(p;p != NULL;p=p->next) {
		if((p->data)==e){
			printf("�������ڵ�%d�����\n",i);
			return SUCCESS; //�����������״��ҵ�eʱ������SUCCESS 
		}
		i++;
	}
	return ERROR; //��������������û���ҵ�eʱ������ERROR 
}
/*������(�ǵݹ�)*/
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
		r = q->next; /*�Ƚ�q->next�洢��r�У���ֹ��q�����˽�㶪ʧ*/ 
		q->next = p; /*qָ��������һ�����*/
		p = q;       /*p���������ԭ˳���ƶ�һλ*/ 
		q = r;       /*q���������ԭ˳���ƶ�һλ*/
	}
	(*L)->next = p;  /*Lָ��ԭ����������һ���ڵ�*/
	return SUCCESS;
}
/*�ж������Ƿ�ɻ� */
Status IsLoopList(LinkedList L)
{
	LinkedList fast,slow; //����һ����ָ���һ����ָ�� 
	slow = L;
	fast = L; /*����ָ���ʼ����L*/
	while((fast != NULL) && (fast->next != NULL)){
		fast = (fast->next)->next; /*��ָ��һ��������*/
		slow = slow->next;         /*��ָ��һ����һ��*/
		if(fast==slow){
			return SUCCESS; /*����졢��ָ��������������ɻ�*/ 
		}
	}
	return ERROR;
}
/*������ż����*/
LNode* ReverseEvenList(LinkedList *L)
{
	LinkedList p,q,r,m;
	p = (*L)->next;
	q = p->next;
	(*L)->next = q;
	while(p!=NULL) /*p,q����ָ�뿴��һ�飬��!pʱ��ʾ�����ż������㣬��!(p->next)ʱ��ʾ����������㣬���һ����㲻����λ�� */
	{
		q = p->next;
		r = q->next; /*��p,q��ָ��Ľ�㽻��λ��*/
		q->next = p;
		p->next = r;
		m = p; 
		p = r;
		if(p!=NULL){
		m->next = p->next; /*pָ����һ����ĵ�һ�����*/
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
/*Ѱ�������м���*/
LNode* FindMidNode(LinkedList *L)
{
	LNode *fast,*slow; /*����졢��ָ��*/
	fast = *L;
	slow = *L;
	while((fast != NULL) && (fast->next != NULL)){
		slow = slow->next;
		fast = (fast->next)->next;
	} /*����ָ��ֹͣ�ƶ�ʱ����ָ��ָ��Ľ������м���*/ 
	return slow;
}
/*����һ���������ڲ��ҽ�㲢������Ӧ��ָ�룬��ɾ���Ͳ��뺯������*/
LNode* Search(LinkedList L,ElemType e)
{
	LNode *p = L->next;
	while(p != NULL){
		if(p->data==e){
			return p;
		}
		p=p->next;
	}
	return NULL; /*�����Ҳ��������ؿ�ָ��*/
}

int main()
{
	LinkedList head = NULL;
	char ele;
	do{
	printf("\n");
	printf("---a.��ʼ������---\n");
	printf("---b.�������---\n");
	printf("---c.������---\n");
	printf("---d.ɾ�����---\n");
	printf("---e.��������---\n");
	printf("---f.������---\n");
	printf("---g.������---\n");
	printf("---h.�ж������Ƿ�ɻ�---\n");
	printf("---i.��ż����---\n");
	printf("---j.Ѱ���м���---\n");
	printf("---k.�˳�����---\n");
	LinkedList p = NULL;
	ElemType i;
	scanf("%c",&ele);
	
	switch(ele){
		case 'a': /*��ʼ������*/ 
			{
				if(InitList(&head)){
					LinkedList L = *(&head);
					printf("�ɹ�����������\n");
					ElemType n,a;
					printf("������Ҫ�����Ľ����\n");
					scanf("%d",&n);
					for(a=1;a<=n;a++) /*�����½�㲢����*/ {
						LinkedList p = (LinkedList)malloc(sizeof(LNode));
						L->next = p;
						L = L->next;
						L->next = NULL;
					}
					
					LinkedList h = head->next;
					for(a=1;a<=n;a++) /*����㸳ֵ*/{
						printf("�������%d��������ֵ\n",a);
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
		case 'b': /*�������*/
			{
				DestroyList(&head);
				printf("���������\n"); 
				break;
			}
		case 'c': /*������*/
			{
				LinkedList p = NULL;
				 printf("������Ҫ�������ǰ������ֵ��");
				 scanf("%d",&i);
				 p = Search(head,i); /*����Search�����ҵ�InsertList��Ҫ�õ���ָ�����*/
				 LinkedList q = (LinkedList)malloc(sizeof(LNode));
				if(InsertList(p, q)){
					printf("������ɹ�\n");
					printf("������˽�����ֵ\n");
					scanf("%d",&(q->data)); 
				}
				else{
					printf("���޴�ǰ���, ������ʧ��\n");
				}
				getchar();
				break;
			}
		case 'd': /*ɾ�����*/
			{
				ElemType num;
				printf("������Ҫɾ���Ľ���ǰһ�����洢������:\n");
				scanf("%d",&num);
				LinkedList h = Search(head,num); /*����Search�����ҵ�Deletelist��Ҫ�õ���ָ�����*/
				if(DeleteList(h,&num)){
					printf("���ɾ���ɹ�\n");
				}
				else{
					printf("û���ҵ��˽�㣬���ɾ��ʧ��\n");
				}
				getchar();
				break;
			}
	    case 'e':/*��������*/
	    	{
	    		void *f = visit;
	    		TraverseList(head,f);
	    		getchar();
				break;
			}
		case 'f': /*������*/
			{
				int num;
				printf("������Ҫ���ҵ����ݣ�");
				scanf("%d",&num);
				if(!(SearchList(head,num))){
					printf("û�д���ֵ\n");
				}
				getchar();
				break;
			}
		case 'g': /*������*/
			{
				if(ReverseList(&head)){
					printf("����ɹ�\n");
				}
				else{
					printf("����ʧ��\n");
				}
				getchar();
				break;
			}
		case 'h': /*�ж������Ƿ�ɻ�*/
			{
				if(IsLoopList(head)){
					printf("�����ѳɻ�\n");
				}
				else{
					printf("����δ�ɻ�\n");
				}
				getchar();
				break;
			}
		case 'i':/*��ż����*/
			{
				head = ReverseEvenList(&head);
				printf("��������ɹ�\n");
				getchar();
				break;
			}
		case 'j':/*Ѱ���м���*/ 
			{
				p = FindMidNode(&head);
				printf("�м�����%d",p->data);
				getchar();
				break;
			}
		case 'k': /*�˳�����*/
			{
				break;
			}
		default:
		    printf("ѡ������밴�س������ز˵���ѡ\n");getchar();getchar();break;
	}}
	while(ele != 'k');
	
	return 0;
}
