#include <stdio.h>

int main(void)  // Question 5
{
    int i = 0, *ptr = &i;   // declaration

    /* the declaration above is equivalent to
     * int i = 0;
     * int *ptr;
     * ptr = &i; // *ptr == 0
     */

   *ptr = *ptr ? 10 : 20;
    /* the declaration above is equivalent to
     * if (*pyr != 0){
     *    *ptr = 10;
     * } else {
     *    *ptr = 20;
     * }
     */

    printf("Val = %d\n", i);

    return 0;
}