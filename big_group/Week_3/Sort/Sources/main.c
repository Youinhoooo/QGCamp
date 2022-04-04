#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<math.h>
#include "sort.h"
#include "sort.c"
int main()
{
	int check,num,n,m,i,k,c;
	FILE *fp;
	while(1){
		system("cls");
		printf("\n");
		printf("\t\t\t\t\t-----> 1.排序在不同的大数据量下的排序用时\n");
		printf("\t\t\t\t\t-----> 2.排序在大量小数据下的排序用时\n");
		printf("\t\t\t\t\t-----> 3.颜色排序\n");
		printf("\t\t\t\t\t-----> 4.在一个无序序列中找到第k小的数\n");
		printf("\t\t\t\t\t-----> 5.生成随机数组并存储\n");
		printf("\t\t\t\t\t-----> 6.退出程序\n");
		printf("请选择功能：\n");
		num = checkinput();
		switch(num){
			case 1:
				printf("请选择数据的个数：\n1.10000 2.50000 3.200000\n");
				check = checkinput();
				switch(check)
				{
					case 1:
						if((fp = fopen("10000.txt","r"))==NULL){ /*不同量的数据存储在不同的文件中*/
							printf("文件打开失败\n");
							return;
						}
						
						int *arr = (int*)malloc(sizeof(int)*10000);
						ReadedFile(fp,10000,arr);
						SortTime(arr,10000);
						break;
					case 2:
						if((fp = fopen("50000.txt","r"))==NULL){
							printf("文件打开失败\n");
							return;
						}
						int *arry = (int*)malloc(sizeof(int)*50000);
						ReadedFile(fp,50000,arry);
						SortTime(arry,50000);
						break;
					case 3:
						if((fp = fopen("200000.txt","r"))==NULL){
							printf("文件打开失败\n");
							return;
						}
						int *arrt = (int*)malloc(sizeof(int)*200000);
						ReadedFile(fp,200000,arrt);
						SortTime(arrt,200000);
						break;
					case 4:
                        exit(0);
                        break;
                    default:
            	        printf("没有此选项\n");
            	        break;
				}
				break;
			case 2: /*每次排100个随机数据，一共进行100k次*/
			    Timesort();
				break;
			case 3:
			{
				printf("生成的随机数组的长度:\n");
				scanf("%d",&m);
				printf("生成的原数组为:\n");
				int a[m];
				srand((unsigned int)time(0));
				for(i=0;i<m;i++){
				a[i]=rand()%3;
				printf("%d ",a[i]);
				}
				ColorSort(a,m);
			    break;
			}
			case 4:
			{
				printf("生成的随机数组的长度:\n");
				scanf("%d",&m);
				printf("生成的数组为:\n");
				int a[m];
				srand((unsigned int)time(0)); /*随机生成用于测试的数*/
				for(i=0;i<m;i++){
				a[i]=rand()%20;
				printf("%d ",a[i]);
				}
				printf("寻找第k小的数，请问k为多少:\n");
				scanf("%d",&k);
				c = Findk(a,0,m-1,k);
				if(c < 0)
				{
					printf("未找到\n");
				}
				else
				printf("第k小的数为%d\n",c);
				break;
			}
			case 5:
				CreatArray(); 
				break;
			case 6:
				exit(0);
				break;
            default:
            	printf("没有此选项\n");
            	break;
		}
		system("pause");
	}
	return 0;
}
