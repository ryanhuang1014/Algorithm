#include <stdio.h>
#include <stdlib.h>
//prim算法是从初始点开始，逐渐找到距离当前节点集合中距离最近的点，然后加入当前集合，直到全部的n个节点进入集合
//以点为核心的算法，应该利用邻接矩阵的方式来存储；以边为核心的算法，利用edge数据结构来存储边
int main()
{
	int n, m, i, j, u, v, w, out_edge, count=0, sum=0, tmp;
    int inf = 9999;
    int *dis, *book;
	printf("please input n and m: \n");
	scanf("%d,%d",&n,&m);
    //dis 数组保存了从集合点内所有点出发到剩余节点的距离最小值
    dis = (int*)malloc(sizeof(int)*n);
    book = (int*)malloc(sizeof(int)*n);
    int (*graph)[n] = malloc(sizeof(int)*n*n); 
	//利用矩阵来存储点和边，来构成图
    //初始化图
    for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j){
				graph[i][j] = 0;
			}
			else{
				graph[i][j] = inf;
			}
        }
    }
	
	for(i=0;i<n;i++)
		book[i] = 0;
    
    //输入边的数值    
    for(i=0;i<m;i++){
		printf("please input u, v and w: \n");
        scanf("%d,%d,%d",&u,&v,&w);
        //无向图正反都需要存储
        graph[u][v] = w;
        graph[v][u] = w;
    }
    
	//for test 
    //for(i=0;i<n;i++)
	//	for(j=0;j<n;j++)
	//		printf("graph[%d][%d] is: %d \n",i,j,graph[i][j]);
    
    //假设从1号节点开始, (初始时集合内只有1号顶点)逐渐构造最小生成树。p.s. 在数组之中是零号位置
    for(i=0;i<n;i++){
		dis[i] = graph[0][i];
    }
	//prim算法主体，逐渐把距离节点集合内最小的点加入集合
    out_edge = 0;
    book[0] = 1;
    count++;
    while(count<n){
		//找到dis数组之中的最小值，作为下一个加入集合的节点
        //以节点1和2为例。初始化dis[0]表示一号节点和其余各个节点的连接最小值，当选择2号节点作为出节点以后，会尝试利用2号点缩小dis
        //这样在1，2结束以后，得到了距离1，2号节点集合，最小的距离
        int k;
        int min = inf;
        for(j=0;j<n;j++){
			tmp = dis[j];
			if(tmp<min && book[j]==0){
				min = tmp;
                k = j;
            }
        }
		//找到最小出边以后，更新dis的数值
        out_edge = k;
        book[out_edge] = 1;
		count++;
        printf("out_edge is %d \n",out_edge);
		sum += dis[out_edge];
        //更新dis数组的值
        for(j=0;j<n;j++){
			if(book[j]==0 && dis[j]>graph[out_edge][j]){
				dis[j] = graph[out_edge][j];
            }
        }
    }
    printf("sum is :%d",sum);
    free(graph);
    free(dis);
    free(book);
	system("pause");
	return 0;
}
