#include <stdio.h>
#include <stdlib.h>

//找树根的过程
int getf(int *f, int v){
	if(f[v]==v){
		return v;
    }
    else{
		f[v] = getf(f, f[v]);
        return f[v];
	}
}

//通过修改v点树根(祖宗)的方式，使得有联系的点共享一个树根(祖宗)
void merge_v(int *f, int v1, int v2){
	int t1 = getf(f, v1);
    int t2 = getf(f, v2);
    if(t1!=t2){
		f[t2] = t1;
    }
}
int main()
{
	int i, n, m, x, y;
    int sum = 0;
    //有n个节点，m个节点接关系
	printf("please input n and m: \n");
	scanf("%d,%d",&n,&m);
    int *f = (int *)malloc(sizeof(int)*n);
    //对树根进行初始化，一开始所有节点的树根都是自己
    for(i=0;i<n;i++){
		f[i] = i;
    }
    
    //输入点之间的关系
    for(i=0;i<m;i++){
		printf("input the related edge: \n");
		scanf("%d,%d",&x,&y);
        merge_v(f,x,y);
    }
    
    //扫描输出合并之后的节点集合
    for(i=0;i<n;i++){
		if(f[i]==i)
        {	
			sum++;
		}
    }
    
    //for test
	for(i=0;i<n;i++){
		printf("f[%d] is %d \n", i, f[i]);
    }
    printf("sum is %d",sum);
	system("pause");
	return 0;
}
