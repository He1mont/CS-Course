#include<stdio.h>
#include<string.h>

int main()
{
	char src[20] = "hello PGA";
	
	int len = strlen(src);
	printf("Length of string: %d\n", len);	
	
	src[6] = '\0'; 
	
	len = strlen(src);      // strlen在遇到'\0'的时候停止计算长度
	printf("Length of string: %d\n", len);	
	printf("%s\n", src);
	
	for(int i=0;i<20;i++)
		printf("%d ",src[i]);
	
	return 0;
}