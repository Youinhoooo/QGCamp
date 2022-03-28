#include "LinkStack.h"
//链栈

//初始化栈
Status initLStack(LinkStack *s){
	if(!s){
		printf("内存分配失败\n");
		return ERROR;
	}
	else{
	s = (LinkStack*)malloc(sizeof(LinkStack));
    return SUCCESS;
}
}

//判断栈是否为空
Status isEmptyLStack(LinkStack *s){ /*栈为空和栈存不存在是两个问题，栈为空时已经定义了count为0，而栈不存在时，top、count都没有定义*/
	if(s->count == 0){
		printf("栈的长度是0\n");
		return ERROR;
	}
	else{
	printf("栈不为空\n"); 
	return SUCCESS;
}
}

//得到栈顶元素
Status getTopLStack(LinkStack *s,ElemType *e){
	if(s->top == NULL || s->count == 0){
		return ERROR;
	}
	else{
		*e = s->top->data;
		return SUCCESS;
	}
}

//清空栈
Status clearLStack(LinkStack *s){
	s->count = 0; /*不改变s->top，使其仍指向原来的位置*/
	LinkStackPtr p,q;
	p = s->top;
	while(p != NULL){
		q = p;
		p = p->next; /*最后p为NULL*/
		free(q);
	}
	
	return SUCCESS; /*清空完成后，s->top仍有指向一个空间*/
}

//销毁栈
Status destroyLStack(LinkStack *s){
	clearLStack(s);
	free(s);
	return SUCCESS; 
}

//检测栈长度
Status LStackLength(LinkStack *s,int *length){
	if(s->top == NULL){
		return ERROR;
	}
	else{
		*length = s->count;
		return SUCCESS;
	}
}

//入栈
Status pushLStack(LinkStack *s,ElemType data){
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
	if(!p){
		printf("内存分配失败\n");
		return ERROR;
	}
	p->data = data;
	p->next = s->top;
	s->top = p;
	s->count = s->count + 1;
	return SUCCESS;
}

//出栈
Status popLStack(LinkStack *s,ElemType *data){
	if(s->count == 0){
		return ERROR;
	}
	*data = (s->top)->data;
	LinkStackPtr p = s->top; /*暂时保存top*/
	s->top = p->next;
	free(p);
	s->count = s->count - 1;
	return SUCCESS;
}

//对于输入的检测
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
		printf("请重新输入：\n");
	}while(flag == 0);
	
} 
