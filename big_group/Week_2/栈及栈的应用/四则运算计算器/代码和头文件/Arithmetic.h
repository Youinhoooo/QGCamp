#ifndef LINKSTACK_H
#define	LINKSTACK_H

#include <stdlib.h>
#include <stdio.h>

typedef enum Status 
{
    ERROR = 0, 
	SUCCESS = 1
} Status;

typedef struct StackNode
{
	int data;
	struct StackNode *next;
}Node;

typedef struct StackInfo
{
	struct StackNode *top;
	int count;
}Stack;

Status InitStack(Stack **s);
Status Push(Stack*s, int e);
Status EmptyStack(Stack *s);
Status GetTop(Stack *s);
Status Pop(Stack *s);
int Priority(char ch); 
#endif
