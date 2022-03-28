#include "LinkStack.h"
//��ջ

//��ʼ��ջ
Status initLStack(LinkStack *s){
	if(!s){
		printf("�ڴ����ʧ��\n");
		return ERROR;
	}
	else{
	s = (LinkStack*)malloc(sizeof(LinkStack));
    return SUCCESS;
}
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack *s){ /*ջΪ�պ�ջ�治�������������⣬ջΪ��ʱ�Ѿ�������countΪ0����ջ������ʱ��top��count��û�ж���*/
	if(s->count == 0){
		printf("ջ�ĳ�����0\n");
		return ERROR;
	}
	else{
	printf("ջ��Ϊ��\n"); 
	return SUCCESS;
}
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack *s,ElemType *e){
	if(s->top == NULL || s->count == 0){
		return ERROR;
	}
	else{
		*e = s->top->data;
		return SUCCESS;
	}
}

//���ջ
Status clearLStack(LinkStack *s){
	s->count = 0; /*���ı�s->top��ʹ����ָ��ԭ����λ��*/
	LinkStackPtr p,q;
	p = s->top;
	while(p != NULL){
		q = p;
		p = p->next; /*���pΪNULL*/
		free(q);
	}
	
	return SUCCESS; /*�����ɺ�s->top����ָ��һ���ռ�*/
}

//����ջ
Status destroyLStack(LinkStack *s){
	clearLStack(s);
	free(s);
	return SUCCESS; 
}

//���ջ����
Status LStackLength(LinkStack *s,int *length){
	if(s->top == NULL){
		return ERROR;
	}
	else{
		*length = s->count;
		return SUCCESS;
	}
}

//��ջ
Status pushLStack(LinkStack *s,ElemType data){
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
	if(!p){
		printf("�ڴ����ʧ��\n");
		return ERROR;
	}
	p->data = data;
	p->next = s->top;
	s->top = p;
	s->count = s->count + 1;
	return SUCCESS;
}

//��ջ
Status popLStack(LinkStack *s,ElemType *data){
	if(s->count == 0){
		return ERROR;
	}
	*data = (s->top)->data;
	LinkStackPtr p = s->top; /*��ʱ����top*/
	s->top = p->next;
	free(p);
	s->count = s->count - 1;
	return SUCCESS;
}

//��������ļ��
int checkinput()
{
	int number;
	char str[111];
	int flag = 0;
	do{
		scanf("%s",str);
		if(strlen(str) == 1){
			if('0'<=str[0]&&str[0]<='9')
			{
				number = str[0] - 48;
				return number;
				flag = 1;
			}
		}
		printf("���������룺\n");
	}while(flag == 0);
	
} 
