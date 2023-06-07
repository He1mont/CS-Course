#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

int main () {

    int day, year; 
    char weekday[20], month[20]; 
    char dtm[100] = "Friday October 29 2021";

    // weekday和month前面没有&，因为数组名称本身表示了数组的地址
    sscanf( dtm, "%s %s %d %d", weekday, month, &day, &year ); 
    printf( "%s %d, %d = %s\n", month, day, year, weekday );

    return 0;

}