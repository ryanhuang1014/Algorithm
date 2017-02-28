#include <stdio.h>
#include <stdlib.h>

//用next数组来封装了尝试走步的动作，方便用循环直接调用
int next[4][2] = {{0,1},  //向右走
				{1,0},	  //向下走
				{0,-1},   //向左走
				{-1,0}};  //向上走

//在bfs之中，队列入队的元素形式
struct node
{
	int x;
	int y;
	int father;
	int step;
};

//由于bfs是逐层往外拓展的形式，所以和dfs一条道走到黑直到找到一条可行路径不同
//bfs一旦找到目的点，就一定是第一次找到目的点，记录下的跳数就是最短路径，即最小跳数

int bfs(int **graph, int **book, int n, int m, int source_x, int source_y, int dest_x, int dest_y){
	//使用一个足够长的数组来作为bfs的队列
	struct node queue[100];
	int head = 0, tail = 0, sum = 0, flag = 0;
	int i, tx, ty, result;
	queue[head].x = source_x;
	queue[head].y = source_y;
	queue[head].father = head;
	queue[head].step = 0;
	tail++;
	while(head<tail){
		if(flag){
			return result;
		}
		//共有上下左右四个方向
		for(i=0;i<4;i++){
			tx = queue[head].x + next[i][0];
			ty = queue[head].y + next[i][1];
			if(tx >= 0 && ty >= 0 && tx < n && ty < m && graph[tx][ty] != 1 && book[tx][ty] == 0){
				book[tx][ty] = 1;
				queue[tail].x = tx;
				queue[tail].y = ty;
				queue[tail].father = head;
				//步数是父亲的步数加一
				queue[tail].step = queue[head].step + 1;
				if(tx == dest_x && ty == dest_y){
					flag = 1;
					result = queue[tail].step;
					break;
				}
				tail++;
			}
		}
		head++;
	} 
}

int main()
{
	int n, m, i, j, tmp, result;
	int **book, **graph;

	//n, m表示:x轴和y轴拥有的点的数目(x轴和y轴的坐标的最大值加一)
	printf("please input n,m: \n");
	scanf("%d,%d",&n,&m);

	//初始化book数组
	book = (int **)malloc(sizeof(int *)*n);
	for(i=0;i<n;i++){
		book[i] = (int *)malloc(sizeof(int)*m);
	}

	//构造book数组
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			book[i][j] = 0;

	//初始化graph数组
	graph = (int **)malloc(sizeof(int *)*n);
	for(i=0;i<n;i++){
		graph[i] = (int *)malloc(sizeof(int)*m);
	}

	//构建graph信息，数字0表示可以连接，数字1表示障碍,不可以连接
	//c语言中scanf如果按下回车表示确认输入，但是由于回车的自有功能，所以会换行
	//可以使用空格代替回车的功能，想要换行之前各个数字输入都用空格分隔，等到要换行的时候再按下回车，一次性确认
	printf("please input graph information:\n");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&tmp);
			graph[i][j] = tmp;
		}
	}

	// for test, (0, 0)-->(3, 2)
	book[0][0] = 1;
	result = bfs(graph, book, n, m, 0, 0, 1, 2);
	printf("min distance is %d\n", result);

	system("pause");
	return 0;
}