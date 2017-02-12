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
		//��һ��Ҫע��ĵط����ǣ���i��j�ı仯����֮�У������������ڴ�С�Ͻ��档������Ҫ��whileѭ��֮�У�����i<j������
        //����i��j֮����໥���ƣ�Ϊ�˷�ֹ����һ��������������һ����������֣��������Ƕ�i��j������˳��Ҳ���й涨
        //����pivot������࣬������j���ȼ�С��e.g����1��3��2�����������ʱ�򣬾Ϳ��Կ������ֹ涨����Ҫ��
        
		//j ��СҲӦ�ú�leftһ��
		while(e[j].w>=pivot&&i<j){
			j--;
		}
		//i ���ҲӦ�ú�rightһ��
		while(e[i].w<=pivot&&i<j){
			i++;
		}

		//�����Ѿ������������(i>j)��ֱ������ѭ��
		//if(i>=j)
		//	break;
		printf("find: e[%d], e[%d] \n", i, j);
		swap(&e[i],&e[j]);
	}
    //��i,j ��ͬ���� ��ǰָ���Ԫ�ش��ڱ��Ԫ��pivot��ʱ��
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
	//Kruskal�㷨�Ĺؼ����ڶ��ڱ߽��д�С���������Ȼ�����γ�����һ�Զ���֮�佨����
	//�����һ���Ѿ������ӵĶ���֮���½��ߣ����γɻ�·�����ǲ�������ġ��������ò��鼯���ݽṹ�����ж�����������֮ǰ�Ƿ��Ѿ�������ϵ
	//�������ӱ�edge, ÿ�������ʼ������f[v]��ֵ
	//��������6�����㣬9����
	struct edge *e;
	int *f;
	int i, n, m, count;
	printf("please input n and m: ");
	scanf("%d,%d", &n, &m);
    e = (struct edge *)malloc(sizeof(struct edge)*m);
    f = (int *)malloc(sizeof(int)*n);
	for(i=0; i<m; i++){
		printf("please input e:\n");
		//scanf ""֮�е�%d����ʽӦ�ú�ʵ�����뱣��һ�£�%d֮���ǿո���ô�����Ӧ���ǿո�
		scanf("%d,%d,%d", &e[i].u, &e[i].v, &e[i].w);
	}
	
	quick_sort(e, 0, 3);
    
	//��ʼ�����鼯���ǵ�����һ����v������f[v]=v
	for(i=0;i<n;i++){
		f[i] = i;
    }
            
    //for test 
	int j;
	for(j=0;j<m;j++)
		printf("�����������:\n e[%d]: , u:%d, v:%d, w:%d \n", j, e[j].u, e[j].v, e[j].w);
 
	for(i=0;i<m;i++){
		//��gef֮�У�ע������ķ�Χ����ҪԽ�硣�����нڵ��0��ʼ���
		if(merge_v(f, e[i].u,e[i].v)){
			printf("�ҵ�һ����, e[%d]: , u:%d, v:%d, w:%d \n", i, e[i].u, e[i].v, e[i].w);
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
