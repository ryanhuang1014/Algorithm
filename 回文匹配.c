#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	char a[101], s[101];
	int i, len, mid, next, top;

	gets(a);
	len = strlen(a);
	mid = len/2;

	top = 0;

	for(i=0;i<mid;i++){
		s[top] = a[i];
		top++;
	}

	//判断从后面开始匹配的字符串
	if(len%2 == 0)
		next = mid+1;
	else
		next = mid+2;

	//开始匹配
	for(i=next;i<len;i++)
	{
		if(a[i]!=s[top])
			break;
		else
			top--;
	}

	if(top==0)
		printf("这是个回文的字符串\n");
	else
		printf("NO\n");
	return 0;
}