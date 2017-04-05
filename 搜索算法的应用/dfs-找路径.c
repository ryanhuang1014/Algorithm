#include <stdio.h>
#include <stdlib.h>

//本题和普通的dfs没有本质的不同，都是寻找从源到目的的最短路径
//不同的地方在于图(graph)的数据结构不同，普通的graph横纵坐标都是点的编号，具体的graph点的数值表示边的连接情况
//本题中的graph点就只是坐标而已，没有表示边连接情况的功能

//用next数组来封装了尝试走步的动作，方便用循环直接调用
int next[4][2] = {{0,1},  //向右走
				{1,0},	  //向下走
				{0,-1},   //向左走
				{-1,0}};  //向上走

//用来保存最短路径的变量
int min = 99999;

void dfs(int **graph, int **book, int n, int m, int sum, int source_x, int source_y, int dest_x, int dest_y){
	int i, tx, ty;
	if(source_x<0 || source_x>=n ||source_y<0 ||source_y>=m){
		printf("the node position is not reasonal\n");
		exit(1);
	}
	if(source_x==dest_x && source_y==dest_y){
		if(sum<min)
			min = sum;
		return;
	}
	//共有上下左右四个方向
	for(i=0;i<4;i++)
	{
		tx = source_x+next[i][0];
		ty = source_y+next[i][1];
		if(tx>=0 && ty>=0 && tx<n && ty<m && graph[tx][ty]!=1 && book[tx][ty]==0)
		{
			sum++;
			book[tx][ty] = 1;
			dfs(graph, book, n, m, sum, tx, ty, dest_x, dest_y);
			book[tx][ty] = 0;
		}
	}
}

int main()
{
	int n, m, i, j, u, v, tmp;
	int **book;
	int **graph;

	//n, m表示:x轴和y轴拥有的点的数目(x轴和y轴的坐标的最大值加一)
	printf("please input n,m: \n");
	scanf("%d,%d",&n,&m);

	//初始化book数组
	book = (int **)malloc(sizeof(int *)*n);
	for(i=0;i<n;i++){
		book[i] = (int *)malloc(sizeof(int)*m);
	}

	//构造book数组
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			book[i][j] = 0;

	//初始化graph数组
	graph = (int **)malloc(sizeof(int *)*n);
	for(i=0;i<n;i++){
		graph[i] = (int *)malloc(sizeof(int)*m);
	}

	//构建graph信息，数字0表示可以连接，数字1表示障碍,不可以连接
	//c语言中scanf如果按下回车表示确认输入，但是由于回车的自有功能，所以会换行
	//可以使用空格代替回车的功能，想要换行之前各个数字输入都用空格分隔，等到要换行的时候再按下回车，一次性确认
	printf("please input graph information:\n");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&tmp);
			graph[i][j] = tmp;
		}
	}
	// for test, (0, 0)-->(3, 2)
	book[0][0] = 1;
	dfs(graph, book, n, m, 0, 0, 0, 1, 2);
	printf("min distance is %d\n", min);

	system("pause");
	return 0;
}
