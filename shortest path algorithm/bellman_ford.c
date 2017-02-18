#include <stdio.h>
#include <stdlib.h>
#define inf 99999
//bellman ford是用来求单一节点到剩余节点的最短值,这点和dijkstra一样
//bellman ford算法和floyd算法也有相似之处
//floyd是遍历所有顶点，所以就可以无视点的松弛顺序，反正松弛中间一段的结果也会保存
//bellman ford遍历所有的边，试图每次循环尝试利用所有边来松弛dis数组

//只利用边的连接情况来表示这个图
struct edge
{
	int u;
	int v;
	int w;
};

void bellman_ford(struct edge* edge, int *dis, int n, int m, int source){
	int i, j;
	for(i=0;i<n;i++){
		dis[i] = inf;
	}
	//使得dis[source]为0，其他点为inf。这样自然表示了从source点开始寻找最小值
	dis[source] = 0;

	//一条最短路径最多只能有n-1个节点构成，所以最多只需要尝试n-1次
	for(j=0;j<n-1;j++){
		//一次尝试利用所有的m条边进行松弛
		for(i=0;i<m;i++){
			if(dis[edge[i].v]>dis[edge[i].u]+edge[i].w){
				dis[edge[i].v] = dis[edge[i].u]+edge[i].w;
			}
		}
	}
}

int main()
{
	int n, m, i, u, v, w;
	int *dis;
	struct edge *e;

	printf("please input n,m: \n");
	scanf("%d,%d",&n,&m);
	dis = (int *)malloc(sizeof(int)*n);

	e = (struct edge *)malloc(sizeof(struct edge)*m);  

	for(i=0;i<m;i++){
		printf("please input u,v,w:\n");
		scanf("%d,%d,%d",&u,&v,&w);
		e[i].u = u;
		e[i].v = v;
		e[i].w = w;
	}

	bellman_ford(e, dis, n, m, 0);

	//for test
	for(i=0;i<n;i++)
		printf("dis[%d] is %d \n", i, dis[i]);

	system("pause");
	return 0;
}
