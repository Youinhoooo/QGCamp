#include "binary_sort_tree.h" 
/*��ʼ��*/
Status BST_init(BinarySortTreePtr BST)
{
	BST->root = NULL;
}
/*������*/
Status BST_insert(BinarySortTreePtr BST, ElemType value)
{
	Node* p = (Node*)malloc(sizeof(Node));
	Node* q = BST->root;
	Node* dp = NULL;
	p->value = value;
	p->left = NULL;
	p->right = NULL;
	if(BST_search(BST, value) == true){
		return false; /*Ҫ����������Ѿ����ڣ��޷�����*/
	} 
	if(q == NULL){
		BST->root = p;
		return true;
	}
	else
	{
	while(q){ /*ͨ��ѭ���ҵ�Ҫ��������ĸ����*/
		dp = q;
		if(q->value < value){
			q = q->right;
		}
		else{
			q = q->left;
		}
	}
	if(value < dp->value){ /*����Ҫ������߻����ұ�*/
		dp->left = p;
	}
	if(value > dp->value){
		dp->right = p;
	}
	return true;
	}
}

/*������*/
Status BST_search(BinarySortTreePtr BST, ElemType value)
{
	Node* p = BST->root;
	Node *q,*dp;
	q = NULL;
	dp = NULL;
	if(p == NULL){
		return false;
	}
	while(p != NULL){
		if(p->value == value){
			return true;
		}
		if(p->value > value){ /*ͨ���Ƚ��ҵ����������ڵ�����*/
			p = p->left;
		}
		else{
			p = p->right;
		}
	}
	return false; /*���û������;return����˵��û���ҵ�value*/
}

/*���ɾ��*/
Status BST_delete(BinarySortTreePtr BST, ElemType value)
{
	NodePtr parent_p,del_p,parent_t,temp;
	del_p = BST->root;
	parent_p = NULL;
	parent_t = NULL; 
	while(del_p != NULL && value != del_p->value) /*��Ѱ��Ҫɾ���Ľ���λ�ã�����һ��ָ�뱣��������һ�����*/
	{
		parent_p = del_p;

		if(del_p->value > value)
		{
			del_p = del_p->left;
		}
		else
		{
			del_p = del_p->right;
		}
	}
	if(del_p == NULL){
		return false; /*û���ҵ���ɾ���Ľ��*/
	}
	if(del_p->left == NULL && del_p->right == NULL) /*��Ҫɾ���Ľ��û���ӽڵ�ʱ*/
	{
		if(parent_p == NULL)
		{
			BST->root = NULL;
		}
		else if(parent_p->left == del_p)
		{
			parent_p->left = NULL;
			free(del_p); /*�ͷŵĽ����ռ�Ŀռ�*/ 
		}
		else
		{
			parent_p->right = NULL;
			free(del_p);
		}
		return true;
	}
	else if(del_p->left != NULL && del_p->right == NULL) /*Ҫɾ���Ľ��ֻ������ʱ*/
	{
		if(parent_p == NULL)
		{
			BST->root = del_p->left;
		}
		else if(parent_p->right == del_p)
		{
			parent_p->right = del_p->left;
			free(del_p); 
		}
		else
		{
			{parent_p->left = del_p->left;}
			free(del_p);
		}
		return true;
	}
	
	else if(del_p->left == NULL && del_p->right != NULL) /*Ҫɾ���Ľ��ֻ���ҽ��*/
	{
		if(parent_p == NULL)
		{
			BST->root = del_p->right;
		}
		else if(parent_p->right == del_p)
		{
			parent_p->right = del_p->right;
			free(del_p);
		}
		else
		{
			parent_p->left = del_p->right;
			free(del_p);
		}
		return true;
	}
	
	else /*Ҫɾ���Ľ���������ӽڵ�*/
	{
		parent_t = del_p;
		temp = del_p->left;

		while(temp->right != NULL)
		{
			parent_t = temp;    /*���������ֵ��ǰһ�����*/
			temp = temp->right; /*Ѱ��Ҫɾ�������������е����ֵ*/
		}
		
		if(parent_p == NULL)
		{
			BST->root = temp;
		}
		else if(parent_p->left == del_p)
		{
			parent_p->left = temp; /*���ҵ�����ȡ����ɾ������*/
		}
		else
		{
			parent_p->right = temp;
		}

		temp->right = del_p->right;

		if(parent_t != del_p)
		{
			temp->left = del_p->left;

			if(parent_t->left == temp)
			{
				parent_t->left = temp->left;
			}
			else
			{
				parent_t->right = temp->left;
			}
		}
		return true;
    }
}

/*�����õķ��ʺ���*/
void visit(ElemType data)
{
	printf("%d  ",data);
}

/*����������ǵݹ飩*/
Status BST_preorderI(BinarySortTreePtr BST, void (*visit)(ElemType data))
{
	NodePtr list[20];
	NodePtr l = BST->root;
	int top = -1;
	while(l!=NULL || top!=-1){
		if(l!=NULL){
			list[++top] = l; /*ʹ��++���Ա�������top�������е�Ԫ�ض�1�������ڳ�ջ*/
			visit(l->value);
			l = l->left; /*һֱ������������ֱ������NULL*/
		}
		else{
			l = list[top--];
			l = l->right; /*��������������ɺ��˻���һ������㣬��������������*/
		}
	}
}

/*����������ݹ�棩*/
Status BST_preorderR(NodePtr bst, void (*visit)(ElemType data))
{
	if(bst != NULL){
		visit(bst->value);
		BST_preorderR(bst->left, visit);
		BST_preorderR(bst->right, visit);
	}
}

/*����������ǵݹ飩*/
Status BST_inorderI(BinarySortTreePtr BST, void (*visit)(ElemType data))
{
	NodePtr list[20];
	NodePtr l = BST->root;
	int top = -1;
	while(l!=NULL || top!=-1){
		if(l!=NULL){
			list[++top] = l; /*ʹ��++���Ա�������top�������е�Ԫ�ض�1�������ڳ�ջ*/
			//visit(l);
			l = l->left; /*һֱ������������ֱ������NULL*/
		}
		else{
			l = list[top--];
			visit(l->value);     /*�ڳ�ջʱ���ʽ������ݣ��Ϳ��Ա�ǰ��Ϊ����*/ 
			l = l->right; /*��������������ɺ��˻���һ������㣬��������������*/
		}
	}
}

/*����������ݹ�棩*/
Status BST_inorderR(NodePtr bst, void (*visit)(ElemType data))
{
	if(bst == NULL)
		return true;
			
	BST_inorderR(bst->left, visit);
	visit(bst->value);
	BST_inorderR(bst->right, visit);
}

/*����������ǵݹ�棩*/
Status BST_postorderI(BinarySortTreePtr BST, void (*visit)(ElemType data))
{
	NodePtr list[20];
	NodePtr l = BST->root;
	int top = -1;
	int flag[20]; /*������¼���ʴ˽��Ĵ���*/
	while(l!=NULL || top!=-1){
		if(l!=NULL){
			list[++top] = l;
			flag[top] = 1;
			l = l->left;
		}
		else{
			if(flag[top] == 1){
				l = list[top]; /*���ó�ջ*/
				flag[top] = 2;
				l = l->right; 
			}
			else{
				l = list[top--];
				visit(l->value);
				l = NULL; /*��l����Ϊ�գ�lָ��Ľ����ܹ���������*/
			}
		}
	} 
}

/*����������ݹ�棩*/
Status BST_postorderR(NodePtr bst, void (*visit)(ElemType data))
{
	if(bst == NULL)
		return true;

	BST_postorderR(bst->left, visit);
	BST_postorderR(bst->right, visit);
	visit(bst->value);
}

/*�������*/
Status BST_levelOrder(BinarySortTreePtr BST, void (*visit)(ElemType data))
{
	NodePtr p = BST->root;
	NodePtr temp[20];
	int top = -1;
	int begin,end;
	begin = -1,end = -1; /*�����ͷ�Ͷ�β*/
	temp[++end] = p;
	while(end != begin){
		NodePtr q = temp[++begin]; /*++begin����ʼλ�õĸı�ɿ�����ǰһ��Ԫ���Ѿ���ջ*/
		visit(q->value);
		if(q->left != NULL){
			temp[++end] = q->left; /*��һ��������ʱ���������ӽڵ����*/
		}
		if(q->right != NULL){
			temp[++end] = q->right;
		}
	}
}

/*������*/
int checkinput()
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
