#include <stdio.h>
#include <stdlib.h>

struct edge{
	int u;
	int v;
	int w;
};

void swap(struct edge *p, struct edge *q){
	struct edge tmp = *p;
	*p = *q;
	*q = tmp;
}

void quick_sort(struct edge* e, int left, int right){
	if(left>right)
		return;
	int pivot = e[left].w;
	int i = left;
	int j = right;
    printf("left is %d, right is %d\n",left,right);
	while(i!=j){
		//有一个要注意的地方就是，在i和j的变化过程之中，不能让他们在大小上交叉。所以需要在while循环之中，保持i<j的条件
        //由于i和j之间会相互限制，为了防止其中一个不正常阻塞另一个的情况出现，所以我们对i和j的增长顺序也进行规定
        //由于pivot在最左侧，所以让j优先减小。e.g：对1，3，2，进行排序的时候，就可以看到这种规定的重要性
        
		//j 最小也应该和left一样
		while(e[j].w>=pivot&&i<j){
			j--;
		}
		//i 最大也应该和right一样
		while(e[i].w<=pivot&&i<j){
			i++;
		}

		//对于已经完成排序的情况(i>j)，直接跳出循环
		//if(i>=j)
		//	break;
		printf("find: e[%d], e[%d] \n", i, j);
		swap(&e[i],&e[j]);
	}
    //当i,j 相同并且 当前指向的元素大于标杆元素pivot的时候
	if(i==j && e[i].w<e[left].w){
		swap(&e[left], &e[i]);
	}
	quick_sort(e, left, i-1);
	quick_sort(e, i+1, right);
}

int getf(int *f, int v){
	if(f[v] == v)
		return v;
	else{
		f[v] = getf(f, f[v]);
        return f[v];
	}
}

int merge_v(int *f, int v1, int v2){
	int t1 = getf(f, v1);
	int t2 = getf(f, v2);
    printf("t1 is: %d, t2 is: %d \n",t1, t2);
	if(t1 != t2){
		f[v2] = t1;
		return 1;
	}
	else
		return 0;
}

int main()
{
	//Kruskal算法的关键在于对于边进行从小到大的排序，然后依次尝试在一对顶点之间建立边
	//如果在一对已经有连接的顶点之间新建边，将形成环路，这是不被允许的。所以利用并查集数据结构，来判断两个顶点在之前是否已经有了联系
	//输入联接边edge, 每个顶点初始化祖先f[v]的值
	//本题中是6个顶点，9条边
	struct edge *e;
	int *f;
	int i, n, m, count;
	printf("please input n and m: ");
	scanf("%d,%d", &n, &m);
    e = (struct edge *)malloc(sizeof(struct edge)*m);
    f = (int *)malloc(sizeof(int)*n);
	for(i=0; i<m; i++){
		printf("please input e:\n");
		//scanf ""之中的%d的形式应该和实际输入保持一致，%d之间是空格那么输入就应该是空格
		scanf("%d,%d,%d", &e[i].u, &e[i].v, &e[i].w);
	}
	
	quick_sort(e, 0, 3);
    
	//初始化并查集，是的任意一个点v的祖先f[v]=v
	for(i=0;i<n;i++){
		f[i] = i;
    }
            
    //for test 
	int j;
	for(j=0;j<m;j++)
		printf("输出边排序结果:\n e[%d]: , u:%d, v:%d, w:%d \n", j, e[j].u, e[j].v, e[j].w);
 
	for(i=0;i<m;i++){
		//在gef之中，注意数组的范围，不要越界。本题中节点从0开始编号
		if(merge_v(f, e[i].u,e[i].v)){
			printf("找到一条边, e[%d]: , u:%d, v:%d, w:%d \n", i, e[i].u, e[i].v, e[i].w);
			count++;
		}
        else{
			printf("aha, i find u! e[%d] \n",e[i]);
        }
		if(count == n-1){
			break;
		}
		
	}
	system("pause");
	return 0;
}
