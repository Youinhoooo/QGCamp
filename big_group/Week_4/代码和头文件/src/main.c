#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_sort_tree.h"
#include "tree.c"
int main()
{
	BinarySortTreePtr p = (BinarySortTreePtr)malloc(sizeof(BinarySortTree));
	int num,n;
	int flag = 0; /*�����ж����Ƿ��Ѿ���ʼ��*/
	while(1){
		system("cls");
		printf("\n");
		printf("\t\t\t\t\t-----> 1.��ʼ��\n");
		printf("\t\t\t\t\t-----> 2.������\n");
		printf("\t\t\t\t\t-----> 3.������\n");
		printf("\t\t\t\t\t-----> 4.���ɾ��\n");
		printf("\t\t\t\t\t-----> 5.�������\n");
		printf("\t\t\t\t\t-----> 6.�������\n");
		printf("\t\t\t\t\t-----> 7.�������\n");
		printf("\t\t\t\t\t-----> 8.�������\n");
		printf("\t\t\t\t\t-----> 9.�˳�����\n");
		printf("��ѡ���ܣ�\n");
		num = checkinput();
		switch(num){
			case 1: /*��ʼ��*/
				if(p == NULL){
					printf("�޷���ʼ��\n");
					break;
				}
				BST_init(p);
				flag = 1;
				break;
				
			case 2: /*������*/
				if(flag == 0){
					printf("���ȳ�ʼ��\n");
					break;
				}
				printf("������Ҫ���������:\n");
				scanf("%d",&n);
				if(BST_insert(p, n) == false){
					printf("�������Ѿ����ڣ��޷�����\n");
				}
				break;
				
			case 3: /*������*/
				if(flag == 0){
					printf("���ȳ�ʼ��\n");
					break;
				}
				printf("������Ҫ���ҵ�����:\n");
				scanf("%d",&n);
				if(BST_search(p, n) == true){
					printf("�������ڶ�������\n");
				}
				else{
					printf("�����ݲ��ڶ�������\n");
				}
				break;
				
			case 4: /*���ɾ��*/
				if(flag == 0){
					printf("���ȳ�ʼ��\n");
					break;
				}
				printf("������Ҫɾ��������:\n");
				scanf("%d",&n);
				if(BST_delete(p, n) == true){
					printf("ɾ���ɹ�\n");
				}
				else{
					printf("û���ҵ��˽�㣬ɾ��ʧ��\n");
				}
				break;
				
			case 5: /*�������*/
				if(flag == 0){
					printf("���ȳ�ʼ��\n");
					break;
				}
				printf("��ѡ��:1.�ǵݹ�� 2.�ݹ��");
				scanf("%d",&n);
				if(n==1){
					BST_preorderI(p, visit);
				}
				else{
					BST_preorderR(p->root, visit);
				}
				break;
				
			case 6: /*�������*/
				if(flag == 0){
					printf("���ȳ�ʼ��\n");
					break;
				}
				printf("��ѡ��:1.�ǵݹ�� 2.�ݹ��");
				scanf("%d",&n);
				if(n==1){
					BST_inorderI(p, visit);
				}
				else{
					BST_inorderR(p->root, visit);
				}
				break;
				
			case 7: /*�������*/
				if(flag == 0){
					printf("���ȳ�ʼ��\n");
					break;
				}
				printf("��ѡ��:1.�ǵݹ�� 2.�ݹ��");
				scanf("%d",&n);
				if(n==1){
					BST_postorderI(p, visit);
				}
				else{
					BST_postorderR(p->root, visit);
				}
				break;
				
			case 8: /*�������*/
			    if(flag == 0){
					printf("���ȳ�ʼ��\n");
					break;
				}
				BST_levelOrder(p, visit);
				break;
				
			case 9: /*�˳�����*/
				exit(0);
                break;

            default:
            	printf("û�д�ѡ��\n"); 
		}
		system("pause");
	}
	return 0;
}
