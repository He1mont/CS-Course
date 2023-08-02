#include<stdio.h>
#include<string.h>

int main()
{
    // what are the difference between ptr and src? 
	char src[20] = "hello PGA";     // 字符数组
	char *ptr = "hello PGA";        // 字符串常量，无法通过指针间接引用来修改

	printf("Length of src: %ld\n", strlen(src));	
	printf("Length of ptr: %ld\n", strlen(ptr));	
	
	*(src+6) = '\0';
	*(ptr+6) = '\0';  // Do you think this is correct?

	src[6] = '\0';
	ptr[6] = '\0';
	
	printf("Length of src: %ld\n", strlen(src));	
	printf("Length of ptr: %ld\n", strlen(ptr));	
	
	return 0;
}