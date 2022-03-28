#include "Arithmetic.h"

/*��ʼ��*/
Status InitStack(Stack **s)
{
	if (s == NULL)
	{
		return ERROR;
	}
	*s = (Stack *)malloc(sizeof(Stack));
	if (NULL == *s)
	{
		return ERROR;
	}
	(*s)->top = NULL;
	(*s)->count = 0;
	return SUCCESS;
}

/*��ջ*/
Status Push(Stack *s, int e)
{
	if (s == NULL)
	{
		return ERROR;
	}

	Node *p = (Node *)malloc(sizeof(Node));
	if (p == NULL)
	{
		return ERROR;
	}

	p->data = e;
	p->next = s->top;
	s->top = p;
	s->count = s->count + 1;

	return SUCCESS;
}

/*�ж��Ƿ�Ϊ��*/
Status EmptyStack(Stack *s)
{
	if (s == NULL)
	{
		return ERROR;
	}
	if(s->top == NULL)
	{
		return SUCCESS;
	}
	else{
		return ERROR;
	}
}

/*�õ�ջ��Ԫ��*/
Status GetTop(Stack *s)
{
	if (s == NULL)
	{
		return ERROR;
	}
	if (s->top == NULL)
	{
		return ERROR;
	}
	return s->top->data;
}

/*��ջ*/
Status Pop(Stack *s)
{
	if (s == NULL)
	{
		return ERROR;
	}
	if (s->top == NULL)
	{
		return ERROR;
	}

	int save;
	Node *p = s->top;
	save = s->top->data;
	s->top = p->next;
	free(p);
	p = NULL;
	s->count = s->count - 1;

	return save;

}

int Priority(char ch) /*�ж����ȼ�*/
{
	switch(ch)
	{
		case '(':
			return 3;
		case '*':
		case '/':
			return 2;
		case '+':
		case '-':
			return 1;
		default:
			return 0;
	} 
}
