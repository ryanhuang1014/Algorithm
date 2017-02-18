#include <stdio.h>
#include <stdlib.h>
#define inf 99999
//floyd的特点在于，它是在原有的二维数组上直接进行修改
//表示任意i到j初始连接情况的二维数组edge[i][j]，逐渐被修改成表示i到j最短路径的数组

void floyd(int **edge, int n){
	int i, j, k;
	//利用i点来尝试缩短j到k的距离，和i的先后顺序无关
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			for(k=0;k<n;k++){
				if(edge[j][k]>edge[j][i]+edge[i][k]){
					edge[j][k] = edge[j][i]+edge[i][k];
				}
			}
}


int main()
{
	int n, m, i, j, u, v, w;
	int **edge;
	printf("please input n,m: \n");
	scanf("%d,%d",&n,&m);

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

	floyd(edge, n);
	//for test
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",edge[i][j] );
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
