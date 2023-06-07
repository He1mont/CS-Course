// mooc2.c的优化版

#include <stdio.h>

struct point {
    int x;
    int y;
};

struct point *getStruct(struct point*);     // 用指针传值
void output(struct point);
void print(const struct point *p);

int main(int argc, char const *argv[])
{
    struct point y = {0,0};
    getStruct(&y);
    output(y);
    output(*getStruct(&y));
    // *运算符用来取出右边的指针所指的变量
    // 右边的指针是(&y)在getStruct函数中的返回值

    print(getStruct(&y));

    return 0;
}

struct point *getStruct(struct point*p)      // 既费空间也费时间更高效的方式是用指针
{
    printf("Please type the value of x and y : ");
    scanf("%d", &p->x);
    scanf("%d", &p->y);
    printf("%d, %d\n", p->x, p->y);
    return p;

}

void output(struct point p)
{
    printf("%d, %d\n", p.x, p.y);
}

void print(const struct point *p)
{
    printf("%d, %d\n", p->x, p->y);
}