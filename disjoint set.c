#include <stdio.h>
#include <stdlib.h>

//�������Ĺ���
int getf(int *f, int v){
	if(f[v]==v){
		return v;
    }
    else{
		f[v] = getf(f, f[v]);
        return f[v];
	}
}

//ͨ���޸�v������(����)�ķ�ʽ��ʹ������ϵ�ĵ㹲��һ������(����)
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
    //��n���ڵ㣬m���ڵ�ӹ�ϵ
	printf("please input n and m: \n");
	scanf("%d,%d",&n,&m);
    int *f = (int *)malloc(sizeof(int)*n);
    //���������г�ʼ����һ��ʼ���нڵ�����������Լ�
    for(i=0;i<n;i++){
		f[i] = i;
    }
    
    //�����֮��Ĺ�ϵ
    for(i=0;i<m;i++){
		printf("input the related edge: \n");
		scanf("%d,%d",&x,&y);
        merge_v(f,x,y);
    }
    
    //ɨ������ϲ�֮��Ľڵ㼯��
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
