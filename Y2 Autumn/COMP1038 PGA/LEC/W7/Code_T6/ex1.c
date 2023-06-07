#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, n;
    float *element;
    scanf("%d", &n);
    element = malloc(n*sizeof(float));
    if (element == NULL){
        exit (0);
    }

    for (i=0; i<n; i++){
        scanf("%f", element+i);
    }
    for (i=1; i<n; i++){
        if (*element < *(element+i)){
            *element = *(element+i);
        }
    }
    printf("The wanted element is: %.2f\n\n", *element);

    free(element);

    return 0;
}