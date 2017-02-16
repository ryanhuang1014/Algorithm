#include <stdio.h>
#include <stdlib.h>

//利用染色法求割点：先把割点排除在外，然后从所有未被染色的点开始利用dfs对所有可以到达的节点进行染色
//看染色以后的块的数目，如果把割点排除前后数目有区别，则说明该点为割点

int count = 0;

void dfs(int **graph, int *book, int *color, int source, int mark){
	int n = sizeof(graph[0]);
	int i;
	color[source] = mark;
	if(count==n-1)
		return;
	for(i=0;i<n;i++){
		if(graph[source][i]==1 && book[i]==0){
			book[i] = 1;
			count++;
			dfs(graph, book, color, i, mark);
		}
	}
}

int main()
{
	int n, m, i, j, u, w;
	int *book, *color;
	int **graph;
	int mark = 1;
	int inf = 99999;
	printf("please input n and m:\n");
	scanf("%d,%d",&n,&m);
	//初始化book数组
	book = (int*)malloc(sizeof(int)*n);
	color = (int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
		book[i] = 0;
		color[i] = -1;
	}
	//初始化graph数组	
	graph = (int**)malloc(sizeof(int*)*n);
	for(i=0;i<n;i++)
		graph[i] = (int*)malloc(sizeof(int)*n);

	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
				if(i==j)
					graph[i][j] = 0;	
				else
					graph[i][j] = inf;
		}

	//开始输入连接的边
	for(i=0;i<m;i++){
		printf("please input u and w:\n");
		scanf("%d,%d",&u,&w);
		graph[u][w] = 1;
		graph[w][u] = 1;
	}

	//输入你想验证是否是割点的点,这里是零号节点
	book[0] = 1;
	color[0] = inf;

	for(i=0;i<n;i++)
	{
		if(color[i]<0)
			dfs(graph, book, color, i, mark++);
	}

	//for test
	for(i=0;i<n;i++)
		printf("color[%d] is : %d\n", i, color[i]);
	
	system("pause");
	return 0;
}
