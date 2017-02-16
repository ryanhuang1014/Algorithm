#include <stdio.h>
#include <stdlib.h>
//primËã·¨ÊÇ´Ó³õÊ¼µã¿ªÊ¼£¬Öð½¥ÕÒµ½¾àÀëµ±Ç°½Úµã¼¯ºÏÖÐ¾àÀë×î½üµÄµã£¬È»ºó¼ÓÈëµ±Ç°¼¯ºÏ£¬Ö±µ½È«²¿µÄn¸ö½Úµã½øÈë¼¯ºÏ
//ÒÔµãÎªºËÐÄµÄËã·¨£¬Ó¦¸ÃÀûÓÃÁÚ½Ó¾ØÕóµÄ·½Ê½À´´æ´¢£»ÒÔ±ßÎªºËÐÄµÄËã·¨£¬ÀûÓÃedgeÊý¾Ý½á¹¹À´´æ´¢±ß
int main()
{
	int n, m, i, j, u, v, w, out_edge, count=0, sum=0, tmp;
    int inf = 9999;
    int *dis, *book;
	printf("please input n and m: \n");
	scanf("%d,%d",&n,&m);
    //dis Êý×é±£´æÁË´Ó¼¯ºÏµãÄÚËùÓÐµã³ö·¢µ½Ê£Óà½ÚµãµÄ¾àÀë×îÐ¡Öµ
    dis = (int*)malloc(sizeof(int)*n);
    book = (int*)malloc(sizeof(int)*n);
    //×¢ÒâÕâÖÖ¶¯Ì¬´æ´¢¶þÎ¬Êý×éµÄ·½·¨£¬±È³£¼ûµÄ·½Ê½¸ü¼Ó·½±ãÊÍ·ÅÄÚ´æ
    //graphÔÚÕâÀïÊÇÊý×éµÄÖ¸Õë£¬Õâ¸öÖ¸ÕëÖ¸ÏòÁËÒ»¸ö³¤¶ÈÎªnµÄÇøÓò£¬ÕæÊµµÄÐ´·¨: int[n] (*graph) 
    //graphÖ¸ÏòÁËÒ»¸ö³¤¶ÈÎªnµÄÄäÃûÊý×é£¬graph+1Ö±½ÓÒÆ¶¯³¤¶ÈÎªnµÄintÊý×éÄÇÃ´³¤
    int (*graph)[n] = malloc(sizeof(int)*n*n); 
	//ÀûÓÃ¾ØÕóÀ´´æ´¢µãºÍ±ß£¬À´¹¹³ÉÍ¼
    //³õÊ¼»¯Í¼
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
    
    //ÊäÈë±ßµÄÊýÖµ    
    for(i=0;i<m;i++){
		printf("please input u, v and w: \n");
        scanf("%d,%d,%d",&u,&v,&w);
        //ÎÞÏòÍ¼Õý·´¶¼ÐèÒª´æ´¢
        graph[u][v] = w;
        graph[v][u] = w;
    }
    
	//for test 
    //for(i=0;i<n;i++)
	//	for(j=0;j<n;j++)
	//		printf("graph[%d][%d] is: %d \n",i,j,graph[i][j]);
    
    //¼ÙÉè´Ó1ºÅ½Úµã¿ªÊ¼, (³õÊ¼Ê±¼¯ºÏÄÚÖ»ÓÐ1ºÅ¶¥µã)Öð½¥¹¹Ôì×îÐ¡Éú³ÉÊ÷¡£p.s. ÔÚÊý×éÖ®ÖÐÊÇÁãºÅÎ»ÖÃ
    for(i=0;i<n;i++){
		dis[i] = graph[0][i];
    }
	//primËã·¨Ö÷Ìå£¬Öð½¥°Ñ¾àÀë½Úµã¼¯ºÏÄÚ×îÐ¡µÄµã¼ÓÈë¼¯ºÏ
    out_edge = 0;
    book[0] = 1;
    count++;
    while(count<n){
		//ÕÒµ½disÊý×éÖ®ÖÐµÄ×îÐ¡Öµ£¬×÷ÎªÏÂÒ»¸ö¼ÓÈë¼¯ºÏµÄ½Úµã
        //ÒÔ½Úµã1ºÍ2ÎªÀý¡£³õÊ¼»¯dis[0]±íÊ¾Ò»ºÅ½ÚµãºÍÆäÓà¸÷¸ö½ÚµãµÄÁ¬½Ó×îÐ¡Öµ£¬µ±Ñ¡Ôñ2ºÅ½Úµã×÷Îª³ö½ÚµãÒÔºó£¬»á³¢ÊÔÀûÓÃ2ºÅµãËõÐ¡dis
        //ÕâÑùÔÚ1£¬2½áÊøÒÔºó£¬µÃµ½ÁË¾àÀë1£¬2ºÅ½Úµã¼¯ºÏ£¬×îÐ¡µÄ¾àÀë
        int k;
        int min = inf;
        for(j=0;j<n;j++){
			tmp = dis[j];
			if(tmp<min && book[j]==0){
				min = tmp;
                k = j;
            }
        }
		//ÕÒµ½×îÐ¡³ö±ßÒÔºó£¬¸üÐÂdisµÄÊýÖµ
        out_edge = k;
        book[out_edge] = 1;
		count++;
        printf("out_edge is %d \n",out_edge);
		sum += dis[out_edge];
        //¸üÐÂdisÊý×éµÄÖµ
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
