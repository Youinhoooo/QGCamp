#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkStack.h"
#include "LinkStack.c"
int main()
{
	LinkStack *head = (LinkStack *)malloc(sizeof(LinkStack));
	head->count = 0;
	head->top = NULL;
	int num;
	int flag = 0;
	while(1){
		system("cls");
		printf("\n");
		printf("\t\t\t\t\t-----> 1.初始化栈\n");
		printf("\t\t\t\t\t-----> 2.判断栈是否为空\n");
		printf("\t\t\t\t\t-----> 3.得到栈顶元素\n");
		printf("\t\t\t\t\t-----> 4.清空栈\n");
		printf("\t\t\t\t\t-----> 5.销毁栈\n");
		printf("\t\t\t\t\t-----> 6.检测栈长度\n");
		printf("\t\t\t\t\t-----> 7.入栈\n");
		printf("\t\t\t\t\t-----> 8.出栈\n");
		printf("\t\t\t\t\t-----> 9.退出程序\n");
		printf("请选择功能：\n");
		num = checkinput();
		switch(num){
			case 1:
				if(initLStack(head)){
					printf("初始化成功!\n");
					flag = 1;
				}
				else{
					printf("初始化失败!\n");
				}
				break;
			case 2:
				if(flag == 1){
					isEmptyLStack(head);
				}
				else{
					printf("栈不存在，请先初始化\n");
				}
				break;
			case 3:
				if(flag==1){
					ElemType num;
					if(getTopLStack(head,&num)){
						printf("栈顶元素是%d\n",num);
					}
					else{
						printf("没有栈顶元素\n");
					} 
				}
				else{
					printf("栈不存在，请先初始化\n");
				}
				break;
			case 4:
				if(flag == 1){
					if(clearLStack(head)){
						printf("栈已清空\n");
					}
					else{
						printf("栈无法清空\n");
					}
				}
				else{
					printf("栈不存在，请先初始化\n");
				}
				break;
			case 5:
				if(flag == 1)
				{
					if(destroyLStack(head)){
						printf("栈已销毁\n");
						flag = 0;
					}
					else{
						printf("栈无法销毁\n");
					}
				}
				else{
					printf("栈不存在，请先初始化\n");
				}
				break;
			case 6:
				if(flag == 1){
					int num;
					if(LStackLength(head,&num)){
						printf("栈的长度为%d\n",num);
					}
					else{
						printf("栈为空\n");
					}
				}
				else{
					printf("栈不存在，请先初始化\n");
				}
				break;
			case 7:
				if(flag == 1){
					ElemType data;
					printf("请输入入栈的数字：\n");
					scanf("%d",&data);
					if(pushLStack(head,data)){
						printf("元素入栈成功\n");
					}
					else{
						printf("元素入栈失败\n");
					}
				}
				else{
					printf("栈不存在，请先初始化\n");
				}
				break;
			case 8:
				if(flag == 1){
					ElemType data;
					if(popLStack(head,&data)){
						printf("数值为%d的元素已出栈\n",data);
					}
					else{
						printf("这是空栈\n");
					}
				}
				else{
					printf("栈不存在，请先初始化\n");
				}
				break;
			case 9:
                exit(0);
                break;
            default:
            	printf("没有此选项\n"); 
		}
		system("pause");
	}
	return 0;
}
