#include "sort.h"
/*��������*/
void insertSort(int *a,int n){
	int i,j,temp;
	for(i=1;i<n;i++){
		if(a[i]<a[i-1]){ /*��a[i]С��ǰ�����ź��������Ԫ��ʱ*/
			temp = a[i];
			for(j = i-1;a[j]>temp && j>=0;j--){
				a[j+1] = a[j];
			}
			a[j+1] = temp; /*����temp*/
		}
	}
}

/*���������к�Ϊһ��*/
void MergeArray(int *a,int begin,int mid,int end,int *temp){
	int i =begin,j = mid+1; /*�������е����*/
	int m = mid,n = end; /*�������е��յ�*/
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
	while(i <= m){ /*��δ����������е�ʣ��Ԫ�طŵ�temp��*/
		temp[cout] = a[i];
			cout++;
			i++;
	}
	while(j <= n){
		temp[cout] = a[j];
		cout++;
		j++;
	}
	for(i = 0;i < cout;i++){ /*��ʱ��cout�ǵ�ǰ�ϲ�����ĳ���*/
		a[begin+i] = temp[i];
	}
}
/*�鲢����*/
void MergeSort(int *a,int begin,int end,int *temp){
	if(begin < end){
		int mid = (begin + end)/2;
	    MergeSort(a,begin,mid,temp);
	    MergeSort(a,mid+1,end,temp);
	    MergeArray(a,begin,mid,end,temp);
	}
}
/*�������򣨵ݹ�棩*/
void QuickSort_Recursion(int *a, int begin, int end){
	if(begin>end)//�ݹ���ú�������Ҫ�ж��Ա�������ѭ�� 
	return;
    int star = a[begin]; /*��׼*/
	int i = begin;       /*�����ڱ�*/
	int j = end;
	while(i!=j)
	{while(a[j]>=star&&i<j) /*j����С�ڻ�׼����ͣ�£�i�������ڻ�׼����ͣ��*/
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
	a[begin]=a[i]; /*��i,j�����ĵط�������Ϊ��׼���������˵ط������ŵ���ͷ*/
	a[i]=star; 
	QuickSort_Recursion(a,begin,i-1); /*�ݹ���ã�ֱ��i==j*/
	QuickSort_Recursion(a,i+1,end);
}

/*�������򣨷ǵݹ�棩*/
void QuickSort(int *a,int size){
	int sa[100] = {0}; /*���ڴ洢*/
	int i = 0,top = 0;
	int j = size-1; 
	int l = ReSort(a,i,j); /*����һ��*/
	if(l-1>i){
		sa[top++] = l-1;
		sa[top++] = i;
	}
	if(l+1<j){
		sa[top++] = j;
		sa[top++] = l+1;
	}
	while(top>0){ /*ջ��Ϊ��*/
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
/*���طָ���λ�õĺ���*/
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
/*�������������ţ�*/
//int Partition(int *a, int begin, int end){}

/*��������*/
void CountSort(int *a, int size , int max){
  int *b = (int *)calloc(size, sizeof(int)); /*��ʱ��������������*/
  int *c = (int *)calloc(max, sizeof(int));  /*ͳ�Ʋ�ͬԪ�صĸ���*/
  int i; 
  for(i=0; i<size; i++)
    c[a[i]] = c[a[i]] + 1;
  for(i=1; i<max; i++) /*����Ԫ���������е�λ��*/
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

/*������������*/
void RadixCountSort(int *a,int size)
{
	int *radixArrays[10],i,pos,k,j; /*�ֱ�Ϊ0~9�����пռ�*/
	for (i = 0; i < 10; i++)
	{
		radixArrays[i] = (int *)malloc(sizeof(int) * (size + 1));
		radixArrays[i][0] = 0; /*indexΪ0����¼�������ݵĸ���*/
	}
	
	for (pos = 1; pos <= 10; pos++)   
	{
		for (i = 0; i < size; i++) /*�������*/
		{
			int num = (int)(a[i]/pow(10,pos-1))%10; /*numΪpDataArray[i]��posλ����ֵ*/
			int index = ++radixArrays[num][0];
			radixArrays[num][index] = a[i];
		}
        
		for (i = 0, j =0; i < 10; i++) /*�ռ�*/
		{
			for (k = 1; k <= radixArrays[i][0]; k++)
				a[j++] = radixArrays[i][k];
			radixArrays[i][0] = 0; /*��λ*/
		}
	}
}

/*��ɫ����*/
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
	printf("\n���������Ϊ:\n");
	for(k=0;k<n;k++)
	{printf("%d",a[k]);}
}

/*�ÿ�����һ�������������ҵ���kС����*/
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
	if((k-1) < i) /*����i��k��λ�ù�ϵ����������׼ֵ����һ������*/
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

/*��������ļ��*/
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
/*�ļ���ȡ*/
int ReadedFile(FILE *fp,int num,int *temp){
	int i;
	for(i=0;i<num;i++){
	fscanf(fp,"%d ",&temp[i]);
    }
}
/*�����ڴ��������µ���ʱ*/
int SortTime(int *p,int num){ //numΪ���ݵĸ��� 
	clock_t star,diff;
	int number = num;
	
	clock_t star1 = clock();
    QuickSort_Recursion(p, 0, num-1);
    clock_t diff1 = clock();
    printf("����������ʱ%d ms\n",diff1-star1);
	
	clock_t star2 = clock();
	insertSort(p,num);
	clock_t diff2 = clock();
	printf("����������ʱ%d ms\n",diff2-star2);
	
	int *tem = (int*)malloc(sizeof(int)*number); /*���溯���Ĳ���*/
	star = clock();
	MergeSort(p,0,number-1,tem);
	diff = clock() - star;
	printf("�鲢������ʱ%dms\n",diff);
	free(tem);
	
	star = clock();
	CountSort(p, number , 100000);
	diff = clock() - star;
	printf("����������ʱ%dms\n",diff);
	
	star = clock();
	RadixCountSort(p,number); 
	diff = clock() - star;
	printf("��������������ʱ%dms\n",diff);
	
}
/*�����ڴ���С�����µ���ʱ*/
int Timesort(){
	int n,t1=0,t2=0,t3=0,t4=0,t5=0;
	int *temt = (int*)malloc(sizeof(int)*100);
	for(n=0;n<100000;n++) /*ÿ������һ�����飬����100k��*/
	{
	int *arr = (int*)malloc(sizeof(int)*100);
	srand((unsigned int)time(NULL));
	int i;
	for(i=0;i<100;i++) /*ÿ��������ɺ���100����������*/
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
    printf("����������ʱ%dms\n",t1);
    printf("�鲢������ʱ%dms\n",t2);
    printf("����������ʱ%dms\n",t3);
    printf("����������ʱ%dms\n",t4);
    printf("��������������ʱ%dms\n",t5);
}
/*�����������*/
int *CreatArray() {
	int count;
	printf("�����뽫Ҫ���ɵ����ݵĸ���:\n");
	scanf("%d",&count);
	int *arr = (int*)malloc(sizeof(int)*count);
	srand((unsigned int)time(NULL));
	int i;
	FILE *fp1;
	if((fp1 = fopen("sort.txt","w"))==NULL){
		printf("�ļ���ʧ��\n");
	}
	for (i = 0; i < count; i++) {
		int randNum = rand() % count;
		fprintf(fp1,"%d",randNum);
		fprintf(fp1,"%c",' '); /*����֮���Կո�����������Ժ��ȡ*/
		arr[i] = randNum;
	}
	return arr;
}
