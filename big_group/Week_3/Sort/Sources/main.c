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
		printf("\t\t\t\t\t-----> 1.�����ڲ�ͬ�Ĵ��������µ�������ʱ\n");
		printf("\t\t\t\t\t-----> 2.�����ڴ���С�����µ�������ʱ\n");
		printf("\t\t\t\t\t-----> 3.��ɫ����\n");
		printf("\t\t\t\t\t-----> 4.��һ�������������ҵ���kС����\n");
		printf("\t\t\t\t\t-----> 5.����������鲢�洢\n");
		printf("\t\t\t\t\t-----> 6.�˳�����\n");
		printf("��ѡ���ܣ�\n");
		num = checkinput();
		switch(num){
			case 1:
				printf("��ѡ�����ݵĸ�����\n1.10000 2.50000 3.200000\n");
				check = checkinput();
				switch(check)
				{
					case 1:
						if((fp = fopen("10000.txt","r"))==NULL){ /*��ͬ�������ݴ洢�ڲ�ͬ���ļ���*/
							printf("�ļ���ʧ��\n");
							return;
						}
						
						int *arr = (int*)malloc(sizeof(int)*10000);
						ReadedFile(fp,10000,arr);
						SortTime(arr,10000);
						break;
					case 2:
						if((fp = fopen("50000.txt","r"))==NULL){
							printf("�ļ���ʧ��\n");
							return;
						}
						int *arry = (int*)malloc(sizeof(int)*50000);
						ReadedFile(fp,50000,arry);
						SortTime(arry,50000);
						break;
					case 3:
						if((fp = fopen("200000.txt","r"))==NULL){
							printf("�ļ���ʧ��\n");
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
            	        printf("û�д�ѡ��\n");
            	        break;
				}
				break;
			case 2: /*ÿ����100��������ݣ�һ������100k��*/
			    Timesort();
				break;
			case 3:
			{
				printf("���ɵ��������ĳ���:\n");
				scanf("%d",&m);
				printf("���ɵ�ԭ����Ϊ:\n");
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
				printf("���ɵ��������ĳ���:\n");
				scanf("%d",&m);
				printf("���ɵ�����Ϊ:\n");
				int a[m];
				srand((unsigned int)time(0)); /*����������ڲ��Ե���*/
				for(i=0;i<m;i++){
				a[i]=rand()%20;
				printf("%d ",a[i]);
				}
				printf("Ѱ�ҵ�kС����������kΪ����:\n");
				scanf("%d",&k);
				c = Findk(a,0,m-1,k);
				if(c < 0)
				{
					printf("δ�ҵ�\n");
				}
				else
				printf("��kС����Ϊ%d\n",c);
				break;
			}
			case 5:
				CreatArray(); 
				break;
			case 6:
				exit(0);
				break;
            default:
            	printf("û�д�ѡ��\n");
            	break;
		}
		system("pause");
	}
	return 0;
}
