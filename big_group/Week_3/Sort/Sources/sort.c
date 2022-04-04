#include "sort.h"
/*插入排序*/
void insertSort(int *a,int n){
	int i,j,temp;
	for(i=1;i<n;i++){
		if(a[i]<a[i-1]){ /*当a[i]小于前面已排好序的最大的元素时*/
			temp = a[i];
			for(j = i-1;a[j]>temp && j>=0;j--){
				a[j+1] = a[j];
			}
			a[j+1] = temp; /*插入temp*/
		}
	}
}

/*两个有序列合为一列*/
void MergeArray(int *a,int begin,int mid,int end,int *temp){
	int i =begin,j = mid+1; /*两个序列的起点*/
	int m = mid,n = end; /*两个序列的终点*/
	int cout = 0;
	while(i <= m && j <= n){
		if(a[i]>a[j]){
			temp[cout] = a[j];
			cout++;
			j++;
		}
		else{
			temp[cout] = a[i];
			cout++;
			i++;
		}
	}
	while(i <= m){ /*将未排完的数组中的剩余元素放到temp中*/
		temp[cout] = a[i];
			cout++;
			i++;
	}
	while(j <= n){
		temp[cout] = a[j];
		cout++;
		j++;
	}
	for(i = 0;i < cout;i++){ /*此时的cout是当前合并数组的长度*/
		a[begin+i] = temp[i];
	}
}
/*归并排序*/
void MergeSort(int *a,int begin,int end,int *temp){
	if(begin < end){
		int mid = (begin + end)/2;
	    MergeSort(a,begin,mid,temp);
	    MergeSort(a,mid+1,end,temp);
	    MergeArray(a,begin,mid,end,temp);
	}
}
/*快速排序（递归版）*/
void QuickSort_Recursion(int *a, int begin, int end){
	if(begin>end)//递归调用函数，需要判断以避免无限循环 
	return;
    int star = a[begin]; /*基准*/
	int i = begin;       /*两个哨兵*/
	int j = end;
	while(i!=j)
	{while(a[j]>=star&&i<j) /*j遇到小于基准的数停下，i遇到大于基准的数停下*/
	{j--;}
	while(a[i]<=star&&i<j)
	{i++;}
	if(i<j)
	{
		int as = a[i];
		a[i]=a[j];
		a[j]=as;
	}
	}
	a[begin]=a[i]; /*将i,j相遇的地方的数换为基准的数，而此地方的数放到开头*/
	a[i]=star; 
	QuickSort_Recursion(a,begin,i-1); /*递归调用，直到i==j*/
	QuickSort_Recursion(a,i+1,end);
}

/*快速排序（非递归版）*/
void QuickSort(int *a,int size){
	int sa[100] = {0}; /*用于存储*/
	int i = 0,top = 0;
	int j = size-1; 
	int l = ReSort(a,i,j); /*快排一次*/
	if(l-1>i){
		sa[top++] = l-1;
		sa[top++] = i;
	}
	if(l+1<j){
		sa[top++] = j;
		sa[top++] = l+1;
	}
	while(top>0){ /*栈不为空*/
		i = sa[--top];
		l = sa[--top];
		l = ReSort(a,i,j);
		if (l - 1 > i)
		{
			sa[top++] = l - 1;
			sa[top++] = i;
		}
		
		if (l + 1 < j)
		{
			sa[top++] = j;
			sa[top++] = l + 1;
		} 
	}
}
/*返回分隔的位置的函数*/
int ReSort(int *a,int begin,int end){
	int i = begin,j = end,temp;
	int star = a[begin];
	while(i<j){
		while(j>i && a[i]<star){
			i++;
		}
		while(j>i && a[j]>star){
			j--;
		}
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	return i;
}
/*快速排序（枢轴存放）*/
//int Partition(int *a, int begin, int end){}

/*计数排序*/
void CountSort(int *a, int size , int max){
  int *b = (int *)calloc(size, sizeof(int)); /*临时保存排序后的数据*/
  int *c = (int *)calloc(max, sizeof(int));  /*统计不同元素的个数*/
  int i; 
  for(i=0; i<size; i++)
    c[a[i]] = c[a[i]] + 1;
  for(i=1; i<max; i++) /*计算元素在数组中的位置*/
    c[i] = c[i] + c[i-1]; 
  
  for(i=size-1; i>=0; i--)
  { 
    b[c[a[i]]-1] = a[i];
    c[a[i]] = c[a[i]] - 1;
  } 
  
  for(i=0; i<size; i++)
    a[i] = b[i];
  
  free(b);
  free(c);
}

/*基数计数排序*/
void RadixCountSort(int *a,int size)
{
	int *radixArrays[10],i,pos,k,j; /*分别为0~9的序列空间*/
	for (i = 0; i < 10; i++)
	{
		radixArrays[i] = (int *)malloc(sizeof(int) * (size + 1));
		radixArrays[i][0] = 0; /*index为0处记录这组数据的个数*/
	}
	
	for (pos = 1; pos <= 10; pos++)   
	{
		for (i = 0; i < size; i++) /*分配过程*/
		{
			int num = (int)(a[i]/pow(10,pos-1))%10; /*num为pDataArray[i]第pos位的数值*/
			int index = ++radixArrays[num][0];
			radixArrays[num][index] = a[i];
		}
        
		for (i = 0, j =0; i < 10; i++) /*收集*/
		{
			for (k = 1; k <= radixArrays[i][0]; k++)
				a[j++] = radixArrays[i][k];
			radixArrays[i][0] = 0; /*复位*/
		}
	}
}

/*颜色排序*/
void ColorSort(int *a,int size)
{
	int n = size;
	int red=0,white=0,blue = n-1,t;
		for( ;white <= blue; white++){
			while(a[white] == 2 && white < blue){
				t=a[blue];a[blue--]=a[white];a[white]=t;
			}
			while(a[white] == 0 && white > red){
				t=a[red];a[red++]=a[white];a[white]=t;
			}
		}
		int k;
	printf("\n排序后数组为:\n");
	for(k=0;k<n;k++)
	{printf("%d",a[k]);}
}

/*用快排在一个无序数组中找到第k小的数*/
int Findk(int *arr,int begin,int end,int k)
{
	if(begin>=end)
	{
		return arr[begin];
	}
	int i = begin;
	int j = end;
	int star = arr[begin];
	while(i!=j)
	{
		while(i<j && arr[i]<=star)
		{
			i++;
		}
		while(i<j && arr[j]>=star)
		{
			j--;
		}
		if(i<j)
		{
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	arr[begin] = arr[i];
	arr[i] = star;
	if((k-1) == i)
	{
		return arr[i];
	}
	if((k-1) < i) /*根据i与k的位置关系，决定给基准值的哪一边排序*/
	{
	return Findk(arr,begin,i-1,k);
	}
	if((k-1) > i)
	{
	return Findk(arr,i+1,end,k);
	}
	else
	return -1;
}

/*对于输入的检测*/
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
/*文件读取*/
int ReadedFile(FILE *fp,int num,int *temp){
	int i;
	for(i=0;i<num;i++){
	fscanf(fp,"%d ",&temp[i]);
    }
}
/*排序在大数据量下的用时*/
int SortTime(int *p,int num){ //num为数据的个数 
	clock_t star,diff;
	int number = num;
	
	clock_t star1 = clock();
    QuickSort_Recursion(p, 0, num-1);
    clock_t diff1 = clock();
    printf("快速排序用时%d ms\n",diff1-star1);
	
	clock_t star2 = clock();
	insertSort(p,num);
	clock_t diff2 = clock();
	printf("插入排序用时%d ms\n",diff2-star2);
	
	int *tem = (int*)malloc(sizeof(int)*number); /*下面函数的参数*/
	star = clock();
	MergeSort(p,0,number-1,tem);
	diff = clock() - star;
	printf("归并排序用时%dms\n",diff);
	free(tem);
	
	star = clock();
	CountSort(p, number , 100000);
	diff = clock() - star;
	printf("计数排序用时%dms\n",diff);
	
	star = clock();
	RadixCountSort(p,number); 
	diff = clock() - star;
	printf("基数计数排序用时%dms\n",diff);
	
}
/*排序在大量小数据下的用时*/
int Timesort(){
	int n,t1=0,t2=0,t3=0,t4=0,t5=0;
	int *temt = (int*)malloc(sizeof(int)*100);
	for(n=0;n<100000;n++) /*每次生成一个数组，生成100k次*/
	{
	int *arr = (int*)malloc(sizeof(int)*100);
	srand((unsigned int)time(NULL));
	int i;
	for(i=0;i<100;i++) /*每次随机生成含有100个数的数组*/
	{ 
		int randNum = rand() % 100;
		arr[i] = randNum;
	}
	clock_t star = clock();
	insertSort(arr,100);
	clock_t diff = clock() - star;
	t1 = t1 + diff;
	star = clock();
	MergeSort(arr,0,99,temt);
	diff = clock() - star;
	t2 = t2 + diff;
	star = clock();
	QuickSort_Recursion(arr, 0, 99);
	diff = clock() - star;
	t3 = t3 + diff;
	star = clock();
	CountSort(arr, 100 , 100000);
	diff = clock() - star;
	t4 = t4 + diff;
	star = clock();
	RadixCountSort(arr,100);
	diff = clock() - star;
	t5 = t5 + diff;
    }
    printf("插入排序用时%dms\n",t1);
    printf("归并排序用时%dms\n",t2);
    printf("快速排序用时%dms\n",t3);
    printf("计数排序用时%dms\n",t4);
    printf("基数计数排序用时%dms\n",t5);
}
/*生成随机数组*/
int *CreatArray() {
	int count;
	printf("请输入将要生成的数据的个数:\n");
	scanf("%d",&count);
	int *arr = (int*)malloc(sizeof(int)*count);
	srand((unsigned int)time(NULL));
	int i;
	FILE *fp1;
	if((fp1 = fopen("sort.txt","w"))==NULL){
		printf("文件打开失败\n");
	}
	for (i = 0; i < count; i++) {
		int randNum = rand() % count;
		fprintf(fp1,"%d",randNum);
		fprintf(fp1,"%c",' '); /*数据之间以空格隔开，便于以后读取*/
		arr[i] = randNum;
	}
	return arr;
}
