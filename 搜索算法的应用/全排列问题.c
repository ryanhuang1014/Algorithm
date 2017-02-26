#include <stdio.h>
#include <stdlib.h>

//全排序的结果用一个数组array顺序保存
//就好像一个个array的小盒子，到一个盒子面前把一个数组n放入其中

//打印完整数组信息
void print_array(int *array, int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d\t", array[i]);
	}
}

//这里用一个数组array来保存全排列的结果
void dfs(int *array, int *book, int n, int current){
	int i;
	if(current==n){
		print_array(array, n);
		printf("\n");
	}
	if(current>n-1)
		return;
	//i是尝试填入array数组的数字
	//先放入i然后收回，就好像先做了某个尝试，在递归退出的时候，又说我没做过这种尝试，下一次递归的时候你们可以使用
	for(i=0;i<n;i++){
		if(book[i]==0){
			book[i] = 1;
			array[current] = i;
			dfs(array, book, n, current+1);
			book[i] = 0;
		}
	}
}


int main()
{
	int i, n;
	int *book, *array;
	printf("please input n:\n");
	scanf("%d", &n);

	//初始化book，book数组用来标记哪些数字已经被排序
	book = (int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
		book[i] = 0;
	}

	//初始化array
	array = (int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
		array[i] = 0;
	}

	//for test
	dfs(array, book, n, 0);

	system("pause");
	return 0;
}
