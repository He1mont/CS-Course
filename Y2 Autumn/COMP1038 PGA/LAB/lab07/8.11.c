// Write a program that uses random-number generation to create sentences.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *art[5] = {"aa", "bb", "cc", "dd", "ee"};
    char *noun[5];
    char *verb[5];
    char *prep[5];

    int i;
	for(i=0; i<5; i++){
		art[i] = malloc(10*sizeof(char));
        printf("arr[%d] = %s\n",i+1, art[i]);
        noun[i] = malloc(10*sizeof(char));
        verb[i] = malloc(10*sizeof(char));
        prep[i] = malloc(10*sizeof(char));
	}

    // 有无更快的赋值方式 ??
    art[0] = "the";
    art[1] = "one";
    art[2] = "some";
    art[3] = "a";
    art[4] = "any";

    noun[0] = "boy";
    noun[1] = "girl";
    noun[2] = "dog";
    noun[3] = "town";
    noun[4] = "çar";

    verb[0] = "drove";
    verb[1] = "jumped";
    verb[2] = "ran";
    verb[3] = "walked";
    verb[4] = "skipped";

    prep[0] = "to";
    prep[1] = "from";
    prep[2] = "over";
    prep[3] = "under";
    prep[4] = "on";



    // free的时候需要一个一个free(art[i])吗？
    // free(art);
    // free(noun);
    // free(verb);
    // free(prep);

    return 0;
}