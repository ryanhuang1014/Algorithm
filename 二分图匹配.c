#include <stdio.h>
#include <stdlib.h>

//二分图无需保存完整的图信息，只需要保存边的连接情况即可。因为二分图的每个部分内部无联接边
//匹配的过程在于利用已有的match信息作为桥梁，探索新的增广路，即同一个点的新的匹配边
//匹配从二分图左侧开始，利用右侧的匹配作为条件，从新回到左侧开始dfs,直到找到一个没有被匹配过的点,就返回1
//然后逐层返回，更新原来的匹配条件
int dfs(int **edge, int *book, int *match, int n, int u){
	int i;
	for (i = 0; i < n; ++i)
	{
		if(edge[u][i]==1 && book[i]==0){
			book[i] = 1;
			//能找到新的匹配点或者能利用现有匹配点做桥梁，就都一直dfs下去
			if(match[i]==0 || dfs(edge, book, match, n, match[i])){
				match[u] = i;
				match[i] = u;
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int i, j, n, m, u, v, sum=0;
	int **edge;
	int *match, *book;
    int inf = 99999;
    //有n个节点，m个连接关系
	printf("please input n and m: \n");
	scanf("%d,%d",&n,&m);
    
    //初始化所有的指针
    edge = (int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++)
    	edge[i] = (int*)malloc(sizeof(int)*n);
    book = (int*)malloc(sizeof(int)*n);
    match = (int*)malloc(sizeof(int)*n);

    //初始化book
    for (i = 0; i < n; ++i)
    {
    	book[i] = 0;
    }
    //初始化match
    for (i = 0; i < n; ++i)
    {
    	match[i] = 0;
    }
    //初始化边信息数组edge
    for(i=0;i<n;i++)
    	for(j=0;j<n;j++){
			edge[i][j] = 0;
     	}

    for(i=0;i<m;i++){
    	printf("please input u,v:\n");
    	scanf("%d,%d",&u,&v);
    	edge[u][v] = 1;
    	edge[v][u] = 1;
    }

    //for test
    //或许没必要对所有点进行dfs，只需对二分图的一侧节点dfs即可
    for (i = 0; i < n; ++i)
    {
    	for (j = 0; j < n; ++j)
    	{
    		book[j] = 0;
    	}
    	if (dfs(edge, book, match, n, i))
    	{
    		sum++;
    	}
    }
    printf("sum is %d\n", sum);
	system("pause");
	return 0;
}