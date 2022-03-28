#include "Arithmetic.h"
#include "Arithmetic.c"
int main()
{
	int i = 0;
	int num1,num2;
	int tem = 0;         /*������ʱ�洢����*/
	char str[111] = {0}; /*�洢���������ʽ*/
	Stack *res,*ope;    /*�洢����ʽ������ĺͲ������*/
	if(!(InitStack(&res)) || !(InitStack(&ope))){
		printf("��ʼ��ʧ��\n"); 
	}
	printf("����������ʽ��:");
	scanf("%s",str);
	
	while(str[i] != '\0' || ope->count != 0){ /*��������ʽ*/
		if('0'<=str[i] && str[i]<='9'){
			tem = tem*10+str[i]-'0'; /*���ַ���ת��Ϊ����*/
			i++;
			if('0'>=str[i] || str[i]>='9'){
				Push(res,tem); /*������ֵ���һλ�������ͣ������ִ洢����������һ����λ��*/
				tem = 0; 
			}
		} 
		else{ /*�����������ʱ*/
		      /*�������������ջ�����*/
		if (GetTop(ope) == '(' && str[i] ==')')	//ֱ�ӳ�ջ�������㣬ջ��Ϊ'(' �����ʽΪ')'
			{
				Pop(ope);	//����ֱ�ӳ�ջ
				i++;
				continue;	//������һ��ѭ��
			}
			if((EmptyStack(ope) == SUCCESS) || (Priority(str[i]) > Priority(GetTop(ope))) || (GetTop(ope) == '(' && str[i] != ')')) /*�洢�������ջΪ�ա����ȼ�*/
			{
				Push(ope,str[i]);
				i++;
				continue;
			}
		/*����������������������������*/
			if((Priority(str[i]) <= Priority(GetTop(ope)))|| str[i] == ')'|| (str[i] == '\0' && EmptyStack(ope) != SUCCESS))
			{/*���ȼ������������š�����ʽ�������洢�����ջ��δ����*/
				int num; 
				num1 = Pop(res);	//����ջ����ջ
				num2 = Pop(res);	//����ջ�ڶ������ֳ�ջ
				switch (Pop(ope))	//�����������ǰ
				{
					case '+':
						num = num1 + num2;
						Push(res,num); /*������ڷ���ջ��*/
						break;
					case '-':
						num = num2 - num1;
						Push(res,num);
						break;
					case '*':
						num = num1 * num2;
						Push(res,num);
						break;
					case '/':
						num = num2 / num1;
						Push(res,num);
						break;
			}
			
			}
		}	
}
printf("result = %d",GetTop(res));
	return 0;
}
