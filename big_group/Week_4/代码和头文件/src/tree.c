#include "binary_sort_tree.h" 
/*初始化*/
Status BST_init(BinarySortTreePtr BST)
{
	BST->root = NULL;
}
/*结点插入*/
Status BST_insert(BinarySortTreePtr BST, ElemType value)
{
	Node* p = (Node*)malloc(sizeof(Node));
	Node* q = BST->root;
	Node* dp = NULL;
	p->value = value;
	p->left = NULL;
	p->right = NULL;
	if(BST_search(BST, value) == true){
		return false; /*要插入的数字已经存在，无法插入*/
	} 
	if(q == NULL){
		BST->root = p;
		return true;
	}
	else
	{
	while(q){ /*通过循环找到要插入的数的父结点*/
		dp = q;
		if(q->value < value){
			q = q->right;
		}
		else{
			q = q->left;
		}
	}
	if(value < dp->value){ /*决定要接在左边还是右边*/
		dp->left = p;
	}
	if(value > dp->value){
		dp->right = p;
	}
	return true;
	}
}

/*结点查找*/
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
		if(p->value > value){ /*通过比较找到此数字所在的子树*/
			p = p->left;
		}
		else{
			p = p->right;
		}
	}
	return false; /*如果没有在中途return，则说明没有找到value*/
}

/*结点删除*/
Status BST_delete(BinarySortTreePtr BST, ElemType value)
{
	NodePtr parent_p,del_p,parent_t,temp;
	del_p = BST->root;
	parent_p = NULL;
	parent_t = NULL; 
	while(del_p != NULL && value != del_p->value) /*先寻找要删除的结点的位置，并用一个指针保存它的上一个结点*/
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
		return false; /*没有找到可删除的结点*/
	}
	if(del_p->left == NULL && del_p->right == NULL) /*当要删除的结点没有子节点时*/
	{
		if(parent_p == NULL)
		{
			BST->root = NULL;
		}
		else if(parent_p->left == del_p)
		{
			parent_p->left = NULL;
			free(del_p); /*释放的结点所占的空间*/ 
		}
		else
		{
			parent_p->right = NULL;
			free(del_p);
		}
		return true;
	}
	else if(del_p->left != NULL && del_p->right == NULL) /*要删除的结点只有左结点时*/
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
	
	else if(del_p->left == NULL && del_p->right != NULL) /*要删除的结点只有右结点*/
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
	
	else /*要删除的结点有两个子节点*/
	{
		parent_t = del_p;
		temp = del_p->left;

		while(temp->right != NULL)
		{
			parent_t = temp;    /*左子树最大值的前一个结点*/
			temp = temp->right; /*寻找要删除数据左子树中的最大值*/
		}
		
		if(parent_p == NULL)
		{
			BST->root = temp;
		}
		else if(parent_p->left == del_p)
		{
			parent_p->left = temp; /*用找到的数取代被删除的数*/
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

/*供调用的访问函数*/
void visit(ElemType data)
{
	printf("%d  ",data);
}

/*先序遍历（非递归）*/
Status BST_preorderI(BinarySortTreePtr BST, void (*visit)(ElemType data))
{
	NodePtr list[20];
	NodePtr l = BST->root;
	int top = -1;
	while(l!=NULL || top!=-1){
		if(l!=NULL){
			list[++top] = l; /*使用++可以避免最后的top比数组中的元素多1，有利于出栈*/
			visit(l->value);
			l = l->left; /*一直访问左子树，直到遇到NULL*/
		}
		else{
			l = list[top--];
			l = l->right; /*当左子树访问完成后，退回上一个父结点，访问他的右子树*/
		}
	}
}

/*先序遍历（递归版）*/
Status BST_preorderR(NodePtr bst, void (*visit)(ElemType data))
{
	if(bst != NULL){
		visit(bst->value);
		BST_preorderR(bst->left, visit);
		BST_preorderR(bst->right, visit);
	}
}

/*中序遍历（非递归）*/
Status BST_inorderI(BinarySortTreePtr BST, void (*visit)(ElemType data))
{
	NodePtr list[20];
	NodePtr l = BST->root;
	int top = -1;
	while(l!=NULL || top!=-1){
		if(l!=NULL){
			list[++top] = l; /*使用++可以避免最后的top比数组中的元素多1，有利于出栈*/
			//visit(l);
			l = l->left; /*一直访问左子树，直到遇到NULL*/
		}
		else{
			l = list[top--];
			visit(l->value);     /*在出栈时访问结点的数据，就可以变前序为中序*/ 
			l = l->right; /*当左子树访问完成后，退回上一个父结点，访问他的右子树*/
		}
	}
}

/*中序遍历（递归版）*/
Status BST_inorderR(NodePtr bst, void (*visit)(ElemType data))
{
	if(bst == NULL)
		return true;
			
	BST_inorderR(bst->left, visit);
	visit(bst->value);
	BST_inorderR(bst->right, visit);
}

/*后序遍历（非递归版）*/
Status BST_postorderI(BinarySortTreePtr BST, void (*visit)(ElemType data))
{
	NodePtr list[20];
	NodePtr l = BST->root;
	int top = -1;
	int flag[20]; /*用来记录访问此结点的次数*/
	while(l!=NULL || top!=-1){
		if(l!=NULL){
			list[++top] = l;
			flag[top] = 1;
			l = l->left;
		}
		else{
			if(flag[top] == 1){
				l = list[top]; /*不用出栈*/
				flag[top] = 2;
				l = l->right; 
			}
			else{
				l = list[top--];
				visit(l->value);
				l = NULL; /*将l设置为空，l指向的结点才能够继续回退*/
			}
		}
	} 
}

/*后序遍历（递归版）*/
Status BST_postorderR(NodePtr bst, void (*visit)(ElemType data))
{
	if(bst == NULL)
		return true;

	BST_postorderR(bst->left, visit);
	BST_postorderR(bst->right, visit);
	visit(bst->value);
}

/*层序遍历*/
Status BST_levelOrder(BinarySortTreePtr BST, void (*visit)(ElemType data))
{
	NodePtr p = BST->root;
	NodePtr temp[20];
	int top = -1;
	int begin,end;
	begin = -1,end = -1; /*代表队头和队尾*/
	temp[++end] = p;
	while(end != begin){
		NodePtr q = temp[++begin]; /*++begin，起始位置的改变可看作是前一个元素已经出栈*/
		visit(q->value);
		if(q->left != NULL){
			temp[++end] = q->left; /*当一个结点出队时，将它的子节点入队*/
		}
		if(q->right != NULL){
			temp[++end] = q->right;
		}
	}
}

/*输入检测*/
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
		printf("请重新输入：\n");
	}while(flag == 0);
	
} 
