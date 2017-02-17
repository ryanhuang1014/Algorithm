#include <stdio.h>
#include <stdlib.h>

//为了方便排序算法，这里就不动态生成数组，而采用足够大的数组来保存
//本题建立最小堆,堆排序就使用从大到小排序

void swap(int *num, int i, int j){
	int tmp;
	tmp = num[i];
	num[i] = num[j];
	num[j] = tmp;
}

//虽然堆的左右孩子间没有大小关系，但是为了保证在下沉过程中一次性把沿路的点位置固定，所以
//同时比较当前结点和左右两个孩子的数值，父节点和两个孩子中较小的点交换
//n个数字，第i号节点
//从第0号节点开始排序，i号节点的左孩子是i*2+1，右孩子是i*2+2
//从第1号节点开始排序，i号节点的左孩子是i*2，右孩子是i*2+1
void siftdown(int *num, int n, int i){
	int t;
	//有孩子，即最少有左孩子
	while(i*2+1<n){
		//相当于一次需要选出当前节点和两个子节点中的较小值
		if(num[i]>num[2*i+1]){
			t = i*2+1;
		}
		else{
			t = i;
		}
		//如果有右孩子
		if(i*2+2<n){
			if(num[t]>num[i*2+2]){
				t = i*2+2;
			}
		}
		//如果父节点已经没法继续下沉，所以已经调整到位,跳出循环
		if(t==i){
			break;
		}
		else{
			swap(num, i, t);
			i = t;
		}
	}
}

//堆顶对应的数组编号是0,从1号开始就直接除以2即可
void siftup(int *num, int i){
	while(i > 0){
		if(num[i] < num[(i-1)/2]){
			swap(num, i, (i-1)/2);
			i = (i-1)/2;
		}
		else
			break;
	}
}

//建立堆的过程其实很简单，只要从有子节点的点开始，尝试对所有这样的节点siftdown
//建立长度为n的最小堆
void create_heap(int *num, int n){
	int i;
	//由于涉及到减法，所以需要保证减法之后的结果非负
	i = (n-1-1)/2;
	if(i<0)
		i = 0;
	for (; i >= 0; i--)
	{
		siftdown(num, n, i);
	}
}

//对长度为n的数组进行排序
void heap_sort(int *num, int n){
	int i;
	for (i = n-1; i >=0; i--)
	{
		swap(num, 0, i);
		siftdown(num, i, 0);
	}
}

int main()
{
	int i, n, x;
	//最多排序100个数字
	int num[100] = {0};
    //有n个数字需要排序
	printf("please input n: \n");
	scanf("%d,%d",&n);

    //对树根进行初始化，一开始所有节点的树根都是自己
    for(i=0;i<n;i++){
    	printf("please input num:\n");
		scanf("%d",&num[i]);
    }
    //初始化建立堆
	create_heap(num, n);

	heap_sort(num, n);
    
    //for test
	for(i=0;i<n;i++){
		printf("num[%d] is %d \n", i, num[i]);
    }
	system("pause");
	return 0;
}
