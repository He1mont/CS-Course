#include<stdio.h>
#include<string.h>

int main()
{
	char array[10]={'\0'};
	char c;

	for(int i=0;i<5;i++)
	{
		printf("Enter No. %d char: ",i+1);
		scanf("%c", &array[i]);

//		fflush(stdin);
//		while ((c = getchar()) != EOF && c != '\n');		
	}
	
	printf("\n");
	for(int i=0;i<10;i++)
		printf("%d ",array[i]);
	printf("\n");
		
	return 0;
}