#include "Arithmetic.h"
#include "Arithmetic.c"
int main()
{
	int i = 0;
	int num1,num2;
	int tem = 0;         /*用来暂时存储数据*/
	char str[111] = {0}; /*存储输入的运算式*/
	Stack *res,*ope;    /*存储运算式中输出的和不输出的*/
	if(!(InitStack(&res)) || !(InitStack(&ope))){
		printf("初始化失败\n"); 
	}
	printf("请输入您的式子:");
	scanf("%s",str);
	
	while(str[i] != '\0' || ope->count != 0){ /*遍历运算式*/
		if('0'<=str[i] && str[i]<='9'){
			tem = tem*10+str[i]-'0'; /*将字符型转换为整型*/
			i++;
			if('0'>=str[i] || str[i]>='9'){
				Push(res,tem); /*如果数字的下一位不是整型，则将数字存储，否则这是一个多位数*/
				tem = 0; 
			}
		} 
		else{ /*当遇到运算符时*/
		      /*首先是运算符入栈的情况*/
		if (GetTop(ope) == '(' && str[i] ==')')	//直接出栈，不计算，栈顶为'(' ，表达式为')'
			{
				Pop(ope);	//括号直接出栈
				i++;
				continue;	//继续下一次循环
			}
			if((EmptyStack(ope) == SUCCESS) || (Priority(str[i]) > Priority(GetTop(ope))) || (GetTop(ope) == '(' && str[i] != ')')) /*存储运算符的栈为空、优先级*/
			{
				Push(ope,str[i]);
				i++;
				continue;
			}
		/*接下来是运算符输出并且运算的情况*/
			if((Priority(str[i]) <= Priority(GetTop(ope)))|| str[i] == ')'|| (str[i] == '\0' && EmptyStack(ope) != SUCCESS))
			{/*优先级、遇到右括号、运算式结束而存储运算的栈还未结束*/
				int num; 
				num1 = Pop(res);	//数字栈顶出栈
				num2 = Pop(res);	//数字栈第二个数字出栈
				switch (Pop(ope))	//后出的数字在前
				{
					case '+':
						num = num1 + num2;
						Push(res,num); /*运算后在放入栈内*/
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
