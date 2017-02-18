#include <stdio.h>
#include <stdlib.h>

int inf = 99999;

//D算法主要是用于求解单点到其他各个顶点的最短路径

//通过传递参数到数组中来获得数组长度是不可行的，表示数组的指针作为函数参数的时候只是一个指针
//所以，sizoef(指针参数)的结果是指针变量a占内存的大小，一般在64位机上是8个字节
void dijkstra(int **edge, int *book, int *dis, int n, int source){
	int i, u, tmp;

	book[source] = 1;
	for(i=0;i<n;i++){
		dis[i] = edge[source][i];
	}

	book[source] = 1;

	for(u=0;u<n-1;u++){
		int min = inf;
		//寻找最短出边点
		for(i=0;i<n;i++){
			if(dis[i]<min && book[i]==0){
				min = dis[i];
				tmp = i;
			}
		}
		//锁定出边点
		book[tmp] = 1;
		//尝试利用出边点松弛其他未被锁定的点
		for(i=0;i<n;i++){
			if(book[i]==0 && dis[i]>dis[tmp]+edge[tmp][i]){
				dis[i] = dis[tmp]+edge[tmp][i];
			}
		}

	}
	
}

int main()
{
	int n, m, i, j, u, v, w;
	int *book, *dis, **edge;
	printf("please input n,m: \n");
	scanf("%d,%d",&n,&m);

	//初始化数组
	book = (int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
		book[i] = 0;
	}

	dis = (int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
		dis[i] = 0;
	}

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
		printf("please input u,v,w:\n");
		scanf("%d,%d,%d",&u,&v,&w);
		edge[u][v] = w;
		edge[v][u] = w;
	}

	dijkstra(edge,book,dis,n,0);
    //for test
	for(i=0;i<n;i++){
		printf("dis[%d] is %d \n", i, dis[i]);
    }

	system("pause");
	return 0;
}
