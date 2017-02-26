#include <stdio.h>
#include <stdlib.h>
#define inf 99999
//求经过几跳可以从source到达destination的时候，采用bfs的方式可以方便求出最短的路径
//因为bfs是逐层向外扩展，一旦第一次遍历到了目的点，此时一定是到达目的点的最短路径点
//dfs则不同，可能存在一条道走到黑，各个从源到目的的path差异很大，需要找出所有path然后比较大小

int bfs(int **graph, int *book, int n, int source, int destination){
	int i, j;
	int flag = 0, sum = 0;
	//一个足够长的数组来作为队列
	int queue[100] = {0};
	int head = 0, tail = 0;
	//源节点入队
	queue[head] = source;
	tail++;
	while(head < tail){
		for(i = 0;i < n;i++){
			if(graph[head][i] == 1 && book[i] == 0){
				book[i] = 1;
				queue[tail] = i;
				tail++;
				if(i == destination){
					flag = 1;
					break;
				}
			}
		}
		if(flag == 1){
			break;
		}
		head++;
		sum++;
	}
	return sum;
}

int main()
{
	int n, m, i, j, u, v, step;
	int *book;
	int **graph;
	printf("please input n,m: \n");
	scanf("%d,%d",&n,&m);

	//初始化book数组
	book = (int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
		book[i] = 0;
	}

	//初始化graph数组
	graph = (int **)malloc(sizeof(int *)*n);
	for(i=0;i<n;i++){
		graph[i] = (int *)malloc(sizeof(int)*n);
	}

	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			if(i==j)
				graph[i][j] = 0;
			else
				graph[i][j] = inf;
		}

	//初始化边信息
	for(i=0;i<m;i++){
		printf("please input u,v:\n");
		scanf("%d,%d,%d",&u,&v);
		graph[u][v] = 1;
		graph[v][u] = 1;
	}

	//for test
	//从0号节点到4号节点
	step = bfs(graph, book, n, 0, 4);

	printf("step is %d\n", step);
	system("pause");
	return 0;
}
