#include <stdio.h>
#include <stdlib.h>

// Iterative implementation of search
int search_iter(const int *ns, int len, int target)
{
    int i = 0;
    for (i=0; i<len; i++){
        if (ns[i] == target){
            return i;
        }
    }
    return -1;
}