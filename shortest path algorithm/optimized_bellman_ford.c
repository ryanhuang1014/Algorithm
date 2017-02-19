#include <stdio.h>
#include <stdlib.h>

#define inf 99999
//本题利用队列并且使用了邻接表来存储了图边的信息，对bellman_ford 算法进行优化
//使用队列的思想在于：只有那些在前一遍松弛中改变了最短路程估计值的顶点，才可能引起他们临界点最短路程估计值发生改变

struct edge
{
	int u;
	int v;
	int w;
};

void optimized_bellman_ford(struct edge* edge, int *dis, int *first, int *next, int n, int m, int source){
	int i, j, k;
	int *book;
	int head = 0, tail = 0;
	//构建一个足够长的队列
	strct edge queue[100];

	//使得dis[source]为0，其他点为inf。这样自然表示了从source点开始寻找最小值
	dis[source] = 0;
	queue[tail] = source;
	book[source] = 1;
	tail++;

	while(head<tail){
		k = first[queue[head].u];
		//通过这个k=-1的条件，可以得到同一顶点所连接的所有边
		while(k=-1){
			//在这里节点可以重复入队，这和bfs不同，只需保证在队列里面不要出项相同的节点即可
			if(dis[edge[k].v]>dis[edge[k].u]+edge[k].w){
				dis[edge[k].v] = dis[edge[k].u]+edge[k].w;
				if(book[edge[k].v]==0){
					//对松弛的v节点入队操作
					queue[tail] = edge[k].v;
					tail++;
					book[edge[k].v] = 1;
				}
			}
			k = next[k];
		}
		//节点出队列
		//这个解除锁定的点为什么是这个？？？
		book[queue[head]] = 0;
		head++;
	}
}



int main()
{
	int n, m, i, u, v, w;
	//利用邻接表来表示图的连接信息
	//first 数组保存有每个节点所连接的第一条边的编号
	int *first;
	//next 数组保存有某个边下一条边的编号，next[1]保存了编号1的边的下一条边的编号
	int *next；
	//e 数组是表示边信息的数组
	struct edge *e;
	//dis 数组用来保存从源点 到其他各个节点的最短路径
	int *dis;

	int *book;

	printf("please input n,m: \n");
	scanf("%d,%d",&n,&m);

	dis = (int *)malloc(sizeof(int)*n);
	book = (int *)malloc(sizeof(int)*n);
	e = (struct edge *)malloc(sizeof(struct edge)*m);  

	//点的初始化
	for (i = 0; i < n; ++i)
	{
		dis[i] = inf;
		book[i] = 0;
	}

	for(i=0;i<m;i++){
		printf("please input u,v,w:\n");
		scanf("%d,%d,%d",&u,&v,&w);
		e[i].u = u;
		e[i].v = v;
		e[i].w = w;
	}

	//边的初始化，利用邻接表存储边信息
	for (int i = 0; i < m; ++i)
	{
		next[i] = first[e[i].u];
		first[e[i].u] = i;
	}



	//for test
	for(i=0;i<n;i++)
		printf("dis[%d] is %d \n", i, dis[i]);

	system("pause");
	return 0;
}
