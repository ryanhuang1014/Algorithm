#include <stdio.h>
#include <stdlib.h>
#define inf 99999

//bfs有个注意点，一旦某个节点入过队以后，那么就需要标记，以后不能重复入队


void bfs(int **edge, int *book, int n, int source){
	int i, j;
	int head = 0, tail = 0;
	// 申请一个足够大的数组来作为队列
	int queue[100];
	queue[head] = source;
	tail++;
	printf("node is %d\n", source);

	while(head<tail){
		for(i=0;i<n;i++){
			if(edge[head][i]==1 && book[i]==0){
				book[i] = 1;
				queue[tail] = i;
				tail++;
				printf("node is %d\n", i);
			}
		}
		head++;
	}
}

int main()
{
	int n, m, i, j, u, v;
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

	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			if(i==j)
				edge[i][j] = 0;
			else
				edge[i][j] = inf;
		}

	for(i=0;i<m;i++){
		printf("please input u,v:\n");
		scanf("%d,%d,%d",&u,&v);
		edge[u][v] = 1;
		edge[v][u] = 1;
	}

	source = 0;
	book[source] = 1;
	bfs(edge, book, n, source);

	system("pause");
	return 0;
}
