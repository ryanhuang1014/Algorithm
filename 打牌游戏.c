#include <stdio.h>
#include <stdlib.h>

//排火车纸牌游戏

//主要是队列和栈的综合应用
//用队列来模拟每个人手中的牌，用栈来模拟桌面上已经打出的牌

struct queue
{
	int data[100];
	int head;
	int tail;
};

//假设纸牌只有A-9，一共最多10张牌
struct stack
{
	int data[10];
	int top;
};

int main(int argc, char const *argv[])
{
	int book[10];
	int tmp1, tmp2;
	//假设有两个选手q1,和q2在打牌
	struct queue q1, q2;
	struct queue s;

	//初始化队列
	q1.head = 0;
	q1.tail = 0;
	q2.head = 0;
	q2.tail = 0;

	//初始化栈
	s.top = 0;

	//初始化用来标记的数组book,用来标记那些牌在桌上,此时由于已经假设最多只能有10张牌在桌面
	for(i=0;i<10;i++){
		book[i] = 0;
	}

	//初始化的时候，裁判向q1发牌
	for (int i = 0; i < 6; ++i)
	{
		scanf("%d",&q1.data[q1.tail]);
		q1.tail++;
	}

	//初始化的时候，裁判向q2发牌
	for (int i = 0; i < 6; ++i)
	{
		scanf("%d",&q2.data[q2.tail]);
		q2.tail++;
	}


	//当q1或者q2有牌的时候，比赛就一直进行下去
	while(q1.head<q1.tail && q2.head<q2.tail){
		//q1 打出第一张牌，然后出队
		tmp1 = q1.data[q1.tail];
		q1.head++;
		//判断打出的这张牌是否桌面上有相同的牌
		//桌面上此时没有相同的牌
		if(book[tmp1] == 0){
			s.data[s.top] = tmp1;
			s.top++;
			book[tmp1] = 1;
		}
		//如果有相同的牌，就收牌，循环放到牌组的末尾
		else{
			q1.data[q1.tail] = tmp1;
			q1.tail++;
			while(s.data[s.top] != tmp1){
				book[s.data[s.top]] = 0;
				q1.data[q1.tail] = s.data[s.top];
				q1.tail++;
				s.top--;
			}
		}

		//q2 打出第一张牌，然后出队
		tmp1 = q2.data[q2.tail];
		q2.head++;
		//判断打出的这张牌是否桌面上有相同的牌
		//桌面上此时没有相同的牌
		if(book[tmp1] == 0){
			s.data[s.top] = tmp1;
			s.top++;
			book[tmp1] = 1;
		}
		//如果有相同的牌，就收牌，循环放到牌组的末尾
		else{
			q2.data[q2.tail] = tmp1;
			q2.tail++;
			while(s.data[s.top] != tmp1){
				book[s.data[s.top]] = 0;
				q2.data[q2.tail] = s.data[s.top];
				q2.tail++;
				s.top--;
			}
		} 
	}

	if(q1.head == q1.tail)
	{
		printf("q1 win!\n");
		printf("当前手中的牌是:\n");
		for (int i = q1.head; i < q1.tail; ++i)
		{
			printf("%d\n", q1.data[i]);
		}
		//桌面上的牌
		if(s.top>0)
		{
			printf("桌面上的牌是:\n");
			for (int i = s.top; i >=0 ; i--)
			{
				printf("%d\n", s[top]);
				top--;
			}

		}
		else{
			printf("桌面上没有牌了\n");
		}
	//q2 赢了
	else
	{
		printf("q2 win!\n");
		printf("当前手中的牌是:\n");
		for (int i = q2.head; i < q2.tail; ++i)
		{
			printf("%d\n", q2.data[i]);
		}
		//桌面上的牌
		if(s.top>0)
		{
			printf("桌面上的牌是:\n");
			for (int i = s.top; i >=0 ; i--)
			{
				printf("%d\n", s[top]);
				top--;
			}

		}
		else{
			printf("桌面上没有牌了\n");
		}
	}

	}
	return 0;
}