#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
	char *words[5];
	
	for(int i=0; i<5; i++)
		scanf("%s",words[i]);
		
/*
// two ways to store groups of words in memory
// 1. use two dimentional char array (memory in stack)
	char words[5][20];
	for(int i=0; i<5; i++)
		scanf("%s",words[i]);
		
// 2. use array of pointers and allocate memory with malloc (memory in heap) 
	char *words[5];
	for(int i=0; i<5; i++)
	{
		words[i] = malloc(20*sizeof(char));
		scanf("%s",words[i]);
	}
	
*/ 
}