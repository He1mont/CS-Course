#include <stdio.h>

typedef struct line {
   int x1, y1;
   int x2, y2;
} LINE;

void main()
{
   LINE line1;
   line1.x1 = 12;
   line1.y1 = 14;
   line1.x2 = 50;
   line1.y2 = 52;
   printf("%d, %d, %d, %d", line1.x1,line1.y1,line1.x2,line1.y2);
}
