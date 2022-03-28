#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include "LQueue.h"
#include "LQueue.c"
int main()
{
	LQueue head; /*����������&head*/
	int num;
	int flag = 0; /*�����ж϶����Ƿ��Ѿ���ʼ��*/
	while(1){
		system("cls");
		printf("\n");
		printf("\t\t\t\t\t-----> 1.��ʼ������\n");
		printf("\t\t\t\t\t-----> 2.�ݻٶ���\n");
		printf("\t\t\t\t\t-----> 3.�ж϶����Ƿ�Ϊ��\n");
		printf("\t\t\t\t\t-----> 4.�õ����еĵ�һ��Ԫ��\n");
		printf("\t\t\t\t\t-----> 5.�����г���\n");
		printf("\t\t\t\t\t-----> 6.Ԫ�����\n");
		printf("\t\t\t\t\t-----> 7.Ԫ�س���\n");
		printf("\t\t\t\t\t-----> 8.��ն���\n");
		printf("\t\t\t\t\t-----> 9.��������\n");
		printf("\t\t\t\t\t-----> 0.�˳�����\n");
		printf("��ѡ���ܣ�\n");
		num = checkinput();
		switch(num){
			
			case 1: /*��ʼ��*/
				InitLQueue(&head);
				flag = 1;
				break;
				
			case 2: /*�ݻ�*/
				if(flag == 1){
					DestoryLQueue(&head);
					flag = 0;
				}
				else{
					printf("���в����ڣ����ȳ�ʼ��\n");
				}
				break;
				
			case 3: /*�жϿն�*/
				if(flag==1){
					if(IsEmptyLQueue(&head)){
						printf("����Ϊ��\n");
					}
					else{
						printf("���в�Ϊ��\n");
					}
				}
				else{
					printf("���в����ڣ����ȳ�ʼ��\n");
				}
				break;
				
			case 4: /*�õ���һ�����*/
				if(flag == 1){
					char str[100];
					GetHeadLQueue(&head, str);
				}
				else{
					printf("���в����ڣ����ȳ�ʼ��\n");
				}
				break;
				
			case 5: /*���г���*/
				if(flag == 1)
				{
					LengthLQueue(&head);
				}
				else{
					printf("���в����ڣ����ȳ�ʼ��\n");
				}
				break;
				
			case 6: /*���*/
				if(flag == 1){
				    char ch;
					printf("��ѡ�������ݵ�����:\nI.����\nC.�ַ�\nD.С��\nS.�ַ���\n");
					getchar();
					scanf("%c",&ch);
					getchar();
					switch(ch)
					{
						case 'I':
						{
							printf("������Ҫ��ŵ���ֵ(��Ϊ�ַ���,�ַ�����С��30):");
							int n;
							scanf("%d",&n);
							EnLQueue(&head,&n,ch);
							break;
						}
						case 'C':
							{
								printf("������Ҫ��ŵ���ֵ(��Ϊ�ַ���,�ַ�����С��30):");
								char st;
							    scanf("%c",&st);
							    EnLQueue(&head,&st,ch);
							    break;
							}
							
						case 'D':
							{
								getchar();
								printf("������Ҫ��ŵ���ֵ(��Ϊ�ַ���,�ַ�����С��30):");
								double f;
							    scanf("%lf",&f);
							    EnLQueue(&head,&f,ch);
							    break;
							}

						case 'S':
							{
								printf("������Ҫ��ŵ���ֵ(��Ϊ�ַ���,�ַ�����С��30):");
								char s[25];
							    scanf("%s",s);
							    EnLQueue(&head,s,ch);
							    break;
							}
							
						default:
							printf("û�д�ѡ��\n");
							break;
					}
				}
				else{
					printf("���в����ڣ����ȳ�ʼ��\n");
				}
				break;
				
			case 7: /*����*/
				if(flag == 1){
					if(DeLQueue(&head)){
						printf("Ԫ���ѳ���\n"); 
					}
					else{
						printf("Ԫ��Ϊ��\n"); 
					}
				}
				else{
					printf("���в����ڣ����ȳ�ʼ��\n");
				}
				break;
				
			case 8: /*���*/
				if(flag == 1){
					ClearLQueue(&head);
				}
				else{
					printf("���в����ڣ����ȳ�ʼ��\n");
				}
				break;
				
			case 9: /*����*/
				if(flag == 1){
					TraverseLQueue(&head, LPrint);
				}
				else{
					printf("���в����ڣ����ȳ�ʼ��\n");
				}
				break;
				
			case 0: /*�˳�����*/
                exit(0);
                break;
                
            default:
            	printf("û�д�ѡ��\n"); 
		}
		system("pause");
	}
	return 0;
}
