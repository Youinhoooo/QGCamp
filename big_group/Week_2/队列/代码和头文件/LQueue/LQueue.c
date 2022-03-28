#include "LQueue.h"
/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q){
	Node *p = (Node *)malloc(sizeof(Node));
	if(p == NULL){
		printf("初始化失败\n");
		return;
	}
	printf("初始化成功\n");
	p->next = NULL;
	Q->front = p;
	Q->rear = p; /*头指针和尾指针都指向头结点*/
	Q->length = 0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q){
	ClearLQueue(Q);
	free(Q->front);
	free(Q->rear);
	Q->front = NULL; /*删去头结点，需重新初始化才能使用队列*/
	Q->rear = NULL;
	return;
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q){
	if(Q->front == Q->rear){
		return TRUE;
	}
	else{
		return FALSE;
	}
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, void *e){
	if(IsEmptyLQueue(Q)){
		printf("队列为空\n");
		return FALSE; /*判断队列是否为空*/
	}
	memcpy(e,Q->front->next->data,30);
	if(Q->front->next->type == 'I'){
		printf("队头元素为%d\n",*(int*)e); /*指针转换为相应的类型*/
	}
	if(Q->front->next->type == 'D'){
        printf("队头元素%lf\n",*(double*)e);
	}
	if(Q->front->next->type == 'C'){
		printf("队头元素%c\n",*(char*)e);
	}
	if(Q->front->next->type == 'S'){
		printf("队头元素%s\n",(char*)e);
	}
	return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){
	if(Q == NULL){
		printf("队列不存在，请先初始化\n");
		return;
	}
	else{
		printf("队列长度为%d\n",Q->length);
		return Q->length;
	}
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data, char type){
	Node *p = (Node *)malloc(sizeof(Node));
	if(p == NULL){
		return FALSE;
	}
	p->data = (void *)malloc(31); /*不知道是什么类型数据，给个30的空间*/
	memcpy(p->data,data,31); 
	p->next = NULL;
	p->type=type;
	Q->rear->next = p; /*从尾结点插入新结点*/
	Q->rear = p;
	Q->length = Q->length + 1;
	return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q){
	if(IsEmptyLQueue(Q)){
		return FALSE;
	}
	Node *p = (Node *)malloc(sizeof(Node));
	p = Q->front->next;
	Q->front->next = p->next;
	if(Q->front->next == NULL){ /*队列为空*/
		Q->rear = Q->front;     /*首尾指针都指向头结点*/ 
	}
	free(p);
	Q->length = Q->length - 1;
	return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q){
	if(IsEmptyLQueue(Q)){
		printf("队列已经为空\n");
		return;
	}
	Node *p = Q->front->next; /*不删除头结点，清空后可继续插入结点*/
	Node *q;
	while(p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	Q->rear = Q->front;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q,char type)){
	if(IsEmptyLQueue(Q)){
		printf("队列为空\n");
		return FALSE;
	}
	Node *p = (Node *)malloc(sizeof(Node));
	p = Q->front->next;
	while(p != NULL){
		foo(p->data,p->type);
		p = p->next;
	}
	return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 
 *  @notice      : None
 */
void LPrint(void *q,char type){ /*通过type判断元素中数据的类型*/
	if(type == 'I')
	    printf("%d\n",*(int*)q);
	if(type == 'D')
	    printf("%lf\n",*(double*)q);
	if(type == 'C')
	    printf("%c\n",*(char*)q);
	if(type == 'S')
	    printf("%s\n",(char*)q);
	 
}

int checkinput() /*输入检测*/
{
	int number;
	char str[111];
	int flag = 0;
	do{
		scanf("%s",str);
		if(strlen(str) == 1){
			if('0'<=str[0]&&str[0]<='9')
			{
				number = str[0] - 48;
				return number;
				flag = 1;
			}
		}
		printf("请重新输入：\n");
	}while(flag == 0);
	
} 




