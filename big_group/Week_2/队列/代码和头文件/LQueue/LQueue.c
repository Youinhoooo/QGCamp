#include "LQueue.h"
/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q){
	Node *p = (Node *)malloc(sizeof(Node));
	if(p == NULL){
		printf("��ʼ��ʧ��\n");
		return;
	}
	printf("��ʼ���ɹ�\n");
	p->next = NULL;
	Q->front = p;
	Q->rear = p; /*ͷָ���βָ�붼ָ��ͷ���*/
	Q->length = 0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q){
	ClearLQueue(Q);
	free(Q->front);
	free(Q->rear);
	Q->front = NULL; /*ɾȥͷ��㣬�����³�ʼ������ʹ�ö���*/
	Q->rear = NULL;
	return;
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
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
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue *Q, void *e){
	if(IsEmptyLQueue(Q)){
		printf("����Ϊ��\n");
		return FALSE; /*�ж϶����Ƿ�Ϊ��*/
	}
	memcpy(e,Q->front->next->data,30);
	if(Q->front->next->type == 'I'){
		printf("��ͷԪ��Ϊ%d\n",*(int*)e); /*ָ��ת��Ϊ��Ӧ������*/
	}
	if(Q->front->next->type == 'D'){
        printf("��ͷԪ��%lf\n",*(double*)e);
	}
	if(Q->front->next->type == 'C'){
		printf("��ͷԪ��%c\n",*(char*)e);
	}
	if(Q->front->next->type == 'S'){
		printf("��ͷԪ��%s\n",(char*)e);
	}
	return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){
	if(Q == NULL){
		printf("���в����ڣ����ȳ�ʼ��\n");
		return;
	}
	else{
		printf("���г���Ϊ%d\n",Q->length);
		return Q->length;
	}
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue *Q, void *data, char type){
	Node *p = (Node *)malloc(sizeof(Node));
	if(p == NULL){
		return FALSE;
	}
	p->data = (void *)malloc(31); /*��֪����ʲô�������ݣ�����30�Ŀռ�*/
	memcpy(p->data,data,31); 
	p->next = NULL;
	p->type=type;
	Q->rear->next = p; /*��β�������½��*/
	Q->rear = p;
	Q->length = Q->length + 1;
	return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q){
	if(IsEmptyLQueue(Q)){
		return FALSE;
	}
	Node *p = (Node *)malloc(sizeof(Node));
	p = Q->front->next;
	Q->front->next = p->next;
	if(Q->front->next == NULL){ /*����Ϊ��*/
		Q->rear = Q->front;     /*��βָ�붼ָ��ͷ���*/ 
	}
	free(p);
	Q->length = Q->length - 1;
	return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q){
	if(IsEmptyLQueue(Q)){
		printf("�����Ѿ�Ϊ��\n");
		return;
	}
	Node *p = Q->front->next; /*��ɾ��ͷ��㣬��պ�ɼ���������*/
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
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q,char type)){
	if(IsEmptyLQueue(Q)){
		printf("����Ϊ��\n");
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
 *    @description : ��������
 *    @param         q ָ��q
 
 *  @notice      : None
 */
void LPrint(void *q,char type){ /*ͨ��type�ж�Ԫ�������ݵ�����*/
	if(type == 'I')
	    printf("%d\n",*(int*)q);
	if(type == 'D')
	    printf("%lf\n",*(double*)q);
	if(type == 'C')
	    printf("%c\n",*(char*)q);
	if(type == 'S')
	    printf("%s\n",(char*)q);
	 
}

int checkinput() /*������*/
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
		printf("���������룺\n");
	}while(flag == 0);
	
} 




