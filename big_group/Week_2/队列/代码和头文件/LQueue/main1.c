#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include "LQueue.h"
#include "LQueue.c"
int main()
{
	LQueue head; /*函数参数用&head*/
	int num;
	int flag = 0; /*用以判断队列是否已经初始化*/
	while(1){
		system("cls");
		printf("\n");
		printf("\t\t\t\t\t-----> 1.初始化队列\n");
		printf("\t\t\t\t\t-----> 2.摧毁队列\n");
		printf("\t\t\t\t\t-----> 3.判断队列是否为空\n");
		printf("\t\t\t\t\t-----> 4.得到队列的第一个元素\n");
		printf("\t\t\t\t\t-----> 5.检测队列长度\n");
		printf("\t\t\t\t\t-----> 6.元素入队\n");
		printf("\t\t\t\t\t-----> 7.元素出队\n");
		printf("\t\t\t\t\t-----> 8.清空队列\n");
		printf("\t\t\t\t\t-----> 9.遍历队列\n");
		printf("\t\t\t\t\t-----> 0.退出程序\n");
		printf("请选择功能：\n");
		num = checkinput();
		switch(num){
			
			case 1: /*初始化*/
				InitLQueue(&head);
				flag = 1;
				break;
				
			case 2: /*摧毁*/
				if(flag == 1){
					DestoryLQueue(&head);
					flag = 0;
				}
				else{
					printf("队列不存在，请先初始化\n");
				}
				break;
				
			case 3: /*判断空队*/
				if(flag==1){
					if(IsEmptyLQueue(&head)){
						printf("队列为空\n");
					}
					else{
						printf("队列不为空\n");
					}
				}
				else{
					printf("队列不存在，请先初始化\n");
				}
				break;
				
			case 4: /*得到第一个结点*/
				if(flag == 1){
					char str[100];
					GetHeadLQueue(&head, str);
				}
				else{
					printf("队列不存在，请先初始化\n");
				}
				break;
				
			case 5: /*队列长度*/
				if(flag == 1)
				{
					LengthLQueue(&head);
				}
				else{
					printf("队列不存在，请先初始化\n");
				}
				break;
				
			case 6: /*入队*/
				if(flag == 1){
				    char ch;
					printf("请选择存放数据的类型:\nI.整数\nC.字符\nD.小数\nS.字符串\n");
					getchar();
					scanf("%c",&ch);
					getchar();
					switch(ch)
					{
						case 'I':
						{
							printf("请输入要存放的数值(若为字符串,字符数请小于30):");
							int n;
							scanf("%d",&n);
							EnLQueue(&head,&n,ch);
							break;
						}
						case 'C':
							{
								printf("请输入要存放的数值(若为字符串,字符数请小于30):");
								char st;
							    scanf("%c",&st);
							    EnLQueue(&head,&st,ch);
							    break;
							}
							
						case 'D':
							{
								getchar();
								printf("请输入要存放的数值(若为字符串,字符数请小于30):");
								double f;
							    scanf("%lf",&f);
							    EnLQueue(&head,&f,ch);
							    break;
							}

						case 'S':
							{
								printf("请输入要存放的数值(若为字符串,字符数请小于30):");
								char s[25];
							    scanf("%s",s);
							    EnLQueue(&head,s,ch);
							    break;
							}
							
						default:
							printf("没有此选项\n");
							break;
					}
				}
				else{
					printf("队列不存在，请先初始化\n");
				}
				break;
				
			case 7: /*出队*/
				if(flag == 1){
					if(DeLQueue(&head)){
						printf("元素已出队\n"); 
					}
					else{
						printf("元素为空\n"); 
					}
				}
				else{
					printf("队列不存在，请先初始化\n");
				}
				break;
				
			case 8: /*清空*/
				if(flag == 1){
					ClearLQueue(&head);
				}
				else{
					printf("队列不存在，请先初始化\n");
				}
				break;
				
			case 9: /*遍历*/
				if(flag == 1){
					TraverseLQueue(&head, LPrint);
				}
				else{
					printf("队列不存在，请先初始化\n");
				}
				break;
				
			case 0: /*退出程序*/
                exit(0);
                break;
                
            default:
            	printf("没有此选项\n"); 
		}
		system("pause");
	}
	return 0;
}
