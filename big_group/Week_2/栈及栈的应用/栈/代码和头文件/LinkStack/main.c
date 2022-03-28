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
		printf("\t\t\t\t\t-----> 1.��ʼ��ջ\n");
		printf("\t\t\t\t\t-----> 2.�ж�ջ�Ƿ�Ϊ��\n");
		printf("\t\t\t\t\t-----> 3.�õ�ջ��Ԫ��\n");
		printf("\t\t\t\t\t-----> 4.���ջ\n");
		printf("\t\t\t\t\t-----> 5.����ջ\n");
		printf("\t\t\t\t\t-----> 6.���ջ����\n");
		printf("\t\t\t\t\t-----> 7.��ջ\n");
		printf("\t\t\t\t\t-----> 8.��ջ\n");
		printf("\t\t\t\t\t-----> 9.�˳�����\n");
		printf("��ѡ���ܣ�\n");
		num = checkinput();
		switch(num){
			case 1:
				if(initLStack(head)){
					printf("��ʼ���ɹ�!\n");
					flag = 1;
				}
				else{
					printf("��ʼ��ʧ��!\n");
				}
				break;
			case 2:
				if(flag == 1){
					isEmptyLStack(head);
				}
				else{
					printf("ջ�����ڣ����ȳ�ʼ��\n");
				}
				break;
			case 3:
				if(flag==1){
					ElemType num;
					if(getTopLStack(head,&num)){
						printf("ջ��Ԫ����%d\n",num);
					}
					else{
						printf("û��ջ��Ԫ��\n");
					} 
				}
				else{
					printf("ջ�����ڣ����ȳ�ʼ��\n");
				}
				break;
			case 4:
				if(flag == 1){
					if(clearLStack(head)){
						printf("ջ�����\n");
					}
					else{
						printf("ջ�޷����\n");
					}
				}
				else{
					printf("ջ�����ڣ����ȳ�ʼ��\n");
				}
				break;
			case 5:
				if(flag == 1)
				{
					if(destroyLStack(head)){
						printf("ջ������\n");
						flag = 0;
					}
					else{
						printf("ջ�޷�����\n");
					}
				}
				else{
					printf("ջ�����ڣ����ȳ�ʼ��\n");
				}
				break;
			case 6:
				if(flag == 1){
					int num;
					if(LStackLength(head,&num)){
						printf("ջ�ĳ���Ϊ%d\n",num);
					}
					else{
						printf("ջΪ��\n");
					}
				}
				else{
					printf("ջ�����ڣ����ȳ�ʼ��\n");
				}
				break;
			case 7:
				if(flag == 1){
					ElemType data;
					printf("��������ջ�����֣�\n");
					scanf("%d",&data);
					if(pushLStack(head,data)){
						printf("Ԫ����ջ�ɹ�\n");
					}
					else{
						printf("Ԫ����ջʧ��\n");
					}
				}
				else{
					printf("ջ�����ڣ����ȳ�ʼ��\n");
				}
				break;
			case 8:
				if(flag == 1){
					ElemType data;
					if(popLStack(head,&data)){
						printf("��ֵΪ%d��Ԫ���ѳ�ջ\n",data);
					}
					else{
						printf("���ǿ�ջ\n");
					}
				}
				else{
					printf("ջ�����ڣ����ȳ�ʼ��\n");
				}
				break;
			case 9:
                exit(0);
                break;
            default:
            	printf("û�д�ѡ��\n"); 
		}
		system("pause");
	}
	return 0;
}
