#include <stdio.h>
#include <stdlib.h>

//最基础的dfs算法，用来输出遍历一个图的时候的节点顺序
int sum = 1;
int inf = 99999;

void dfs(int **edge, int *book, int n, int source){
	int i;
	printf("the node is %d\n", source);
	if(sum==n)
		return;
	for(i=0;i<n;i++){
		if(edge[source][i]==1 && book[i]==0){
			book[i] = 1;
			sum++;
			dfs(edge, book, n, i);
		}
	}
}

int main()
{
	int i, j, n, m, u, v;
	int source;
	int *book;
	int **edge;

	printf("please input n,m: \n");
	scanf("%d,%d",&n,&m);
	book = (int*)malloc(sizeof(int)*n);

	for(i=0;i<n;i++)
		book[i] = 0;

	edge = (int**)malloc(sizeof(int*)*n);
	for(i=0;i<n;i++)
		edge[i] = (int*)malloc(sizeof(int)*n);

	//初始化二维数组表示的图
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			if(i==j)
				edge[i][j] = 0;
			else
				edge[i][j] = inf;
		}

	for(i=0;i<m;i++){
		printf("please input u,v,w:\n");
		scanf("%d,%d,%d",&u,&v);
		edge[u][v] = 1;
		edge[v][u] = 1;
	}
	//输入决定访问的起始点
	source = 0;
	book[source] = 1;
	dfs(edge, book ,n ,source);
	system("pause");
	return 0;
}
