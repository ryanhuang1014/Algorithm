#include <stdio.h>
#include <stdlib.h>

int n, m;
int **graph, **book;
int source_x, int source_y, int dest_x, int dest_y;

struct node{
	int x;
	int y;
};

//利用栈s来存储经过的路径
struct node s[100];
int top = 0;

//n行，m列二维图
void dfs(int x, int y, int front){
	int x, y;
	//因为此时的最终点出水口在右侧，所以结束条件是m+1
	if(x==n && y==(m+1)){
		for(int i=0;i<top;i++){
			printf("(%d, %d)\n", s[i].x, s[i].y);
		}
		return ;
	}

	if(x<0 || x>=n || y<0 ||y>=m)
		return;

	if(book[x][y] == 1)
		return;

	book[x][y] = 1;

	//把当前节点入栈
	s[top].x = x;
	s[top].y = y;
	top++;

	//如果当前点的水管是直管
	if(graph[x][y] >= 5 && graph[x][y] <= 6){
		//进水口在左面,直管的情况下，下一步拓展右边的点
		if(front == 1)
			dfs(x, y+1, 1);
		//进水口在上面
		if(front == 2)
			dfs(x+1, y, 2);
		//进水口在右面
		if(front == 3)
			dfs(x, y-1, 3);
		//进水口在下面
		if(front == 4)
			dfs(x-1, y, 4);
	}

	//如果当前点是弯管的情况
	if(graph[x][y] >= 1 && graph[x][y] <= 4){

		//进水口在左边
		if(front == 1){
			dfs(x+1, y, 2);
			dfs(x-1, y, 4);
		}
		if(front == 2){
			dfs(x, y+1, 1);
			dfs(x, y-1, 3);
		}
		if(front == 3){
			dfs(x-1, y, 4);
			dfs(x+1, y, 2);
		}
		if(front == 4){
			dfs(x, y+1, 1);
			dfs(x, y-1, 3);
		}
	}

	//取消标记
	book[x][y] = 0;
	//出栈
	top--;
	return;
}

void main()
{
	int i, j, num = 0;
	scanf("%d %d", &n, &m);

	//读入地图
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d", &graph[i][j]);

	dfs(1, 1, 1);
	if(flag == 0)
		printf("impossible..\n");


	getchar();getchar();  
}