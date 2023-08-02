#include <stdio.h>

struct point {
    int x;
    int y;
};

struct point getStruct(void);
void output(struct point);

int main(int argc, char const *argv[])
{
    struct point y = {0,0};
    
    y = getStruct();
    output(y);

    return 0;
}

struct point getStruct(void)    // 既费空间也费时间更高效的方式是用指针，在mooc3.c
{
    struct point p;     // 在函数内构建结构体
    printf("Please type the value of p.x and p.y: ");
    scanf("%d", &p.x);
    scanf("%d", &p.y);
    printf("%d, %d\n", p.x, p.y);
    return p;

}

void output(struct point p)
{
    printf("%d, %d\n", p.x, p.y);
}