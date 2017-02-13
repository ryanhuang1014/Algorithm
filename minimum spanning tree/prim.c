#include <stdio.h>
#include <stdlib.h>
//prim�㷨�Ǵӳ�ʼ�㿪ʼ�����ҵ����뵱ǰ�ڵ㼯���о�������ĵ㣬Ȼ����뵱ǰ���ϣ�ֱ��ȫ����n���ڵ���뼯��
//�Ե�Ϊ���ĵ��㷨��Ӧ�������ڽӾ���ķ�ʽ���洢���Ա�Ϊ���ĵ��㷨������edge���ݽṹ���洢��
int main()
{
	int n, m, i, j, u, v, w, out_edge, count=0, sum=0, tmp;
    int inf = 9999;
    int *dis, *book;
	printf("please input n and m: \n");
	scanf("%d,%d",&n,&m);
    //dis ���鱣���˴Ӽ��ϵ������е������ʣ��ڵ�ľ�����Сֵ
    dis = (int*)malloc(sizeof(int)*n);
    book = (int*)malloc(sizeof(int)*n);
    int (*graph)[n] = malloc(sizeof(int)*n*n); 
	//���þ������洢��ͱߣ�������ͼ
    //��ʼ��ͼ
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
    
    //����ߵ���ֵ    
    for(i=0;i<m;i++){
		printf("please input u, v and w: \n");
        scanf("%d,%d,%d",&u,&v,&w);
        //����ͼ��������Ҫ�洢
        graph[u][v] = w;
        graph[v][u] = w;
    }
    
	//for test 
    //for(i=0;i<n;i++)
	//	for(j=0;j<n;j++)
	//		printf("graph[%d][%d] is: %d \n",i,j,graph[i][j]);
    
    //�����1�Žڵ㿪ʼ, (��ʼʱ������ֻ��1�Ŷ���)�𽥹�����С��������p.s. ������֮�������λ��
    for(i=0;i<n;i++){
		dis[i] = graph[0][i];
    }
	//prim�㷨���壬�𽥰Ѿ���ڵ㼯������С�ĵ���뼯��
    out_edge = 0;
    book[0] = 1;
    count++;
    while(count<n){
		//�ҵ�dis����֮�е���Сֵ����Ϊ��һ�����뼯�ϵĽڵ�
        //�Խڵ�1��2Ϊ������ʼ��dis[0]��ʾһ�Žڵ����������ڵ��������Сֵ����ѡ��2�Žڵ���Ϊ���ڵ��Ժ󣬻᳢������2�ŵ���Сdis
        //������1��2�����Ժ󣬵õ��˾���1��2�Žڵ㼯�ϣ���С�ľ���
        int k;
        int min = inf;
        for(j=0;j<n;j++){
			tmp = dis[j];
			if(tmp<min && book[j]==0){
				min = tmp;
                k = j;
            }
        }
		//�ҵ���С�����Ժ󣬸���dis����ֵ
        out_edge = k;
        book[out_edge] = 1;
		count++;
        printf("out_edge is %d \n",out_edge);
		sum += dis[out_edge];
        //����dis�����ֵ
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
