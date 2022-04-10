#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_sort_tree.h"
#include "tree.c"
int main()
{
	BinarySortTreePtr p = (BinarySortTreePtr)malloc(sizeof(BinarySortTree));
	int num,n;
	int flag = 0; /*用以判断树是否已经初始化*/
	while(1){
		system("cls");
		printf("\n");
		printf("\t\t\t\t\t-----> 1.初始化\n");
		printf("\t\t\t\t\t-----> 2.结点插入\n");
		printf("\t\t\t\t\t-----> 3.结点查找\n");
		printf("\t\t\t\t\t-----> 4.结点删除\n");
		printf("\t\t\t\t\t-----> 5.先序遍历\n");
		printf("\t\t\t\t\t-----> 6.中序遍历\n");
		printf("\t\t\t\t\t-----> 7.后序遍历\n");
		printf("\t\t\t\t\t-----> 8.层序遍历\n");
		printf("\t\t\t\t\t-----> 9.退出程序\n");
		printf("请选择功能：\n");
		num = checkinput();
		switch(num){
			case 1: /*初始化*/
				if(p == NULL){
					printf("无法初始化\n");
					break;
				}
				BST_init(p);
				flag = 1;
				break;
				
			case 2: /*结点插入*/
				if(flag == 0){
					printf("请先初始化\n");
					break;
				}
				printf("请输入要插入的数字:\n");
				scanf("%d",&n);
				if(BST_insert(p, n) == false){
					printf("此数据已经存在，无法插入\n");
				}
				break;
				
			case 3: /*结点查找*/
				if(flag == 0){
					printf("请先初始化\n");
					break;
				}
				printf("请输入要查找的数字:\n");
				scanf("%d",&n);
				if(BST_search(p, n) == true){
					printf("此数据在二叉树中\n");
				}
				else{
					printf("此数据不在二叉树中\n");
				}
				break;
				
			case 4: /*结点删除*/
				if(flag == 0){
					printf("请先初始化\n");
					break;
				}
				printf("请输入要删除的数据:\n");
				scanf("%d",&n);
				if(BST_delete(p, n) == true){
					printf("删除成功\n");
				}
				else{
					printf("没有找到此结点，删除失败\n");
				}
				break;
				
			case 5: /*先序遍历*/
				if(flag == 0){
					printf("请先初始化\n");
					break;
				}
				printf("请选择:1.非递归版 2.递归版");
				scanf("%d",&n);
				if(n==1){
					BST_preorderI(p, visit);
				}
				else{
					BST_preorderR(p->root, visit);
				}
				break;
				
			case 6: /*中序遍历*/
				if(flag == 0){
					printf("请先初始化\n");
					break;
				}
				printf("请选择:1.非递归版 2.递归版");
				scanf("%d",&n);
				if(n==1){
					BST_inorderI(p, visit);
				}
				else{
					BST_inorderR(p->root, visit);
				}
				break;
				
			case 7: /*后序遍历*/
				if(flag == 0){
					printf("请先初始化\n");
					break;
				}
				printf("请选择:1.非递归版 2.递归版");
				scanf("%d",&n);
				if(n==1){
					BST_postorderI(p, visit);
				}
				else{
					BST_postorderR(p->root, visit);
				}
				break;
				
			case 8: /*层序遍历*/
			    if(flag == 0){
					printf("请先初始化\n");
					break;
				}
				BST_levelOrder(p, visit);
				break;
				
			case 9: /*退出程序*/
				exit(0);
                break;

            default:
            	printf("没有此选项\n"); 
		}
		system("pause");
	}
	return 0;
}
