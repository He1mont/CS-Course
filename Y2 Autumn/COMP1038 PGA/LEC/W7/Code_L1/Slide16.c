#include <stdio.h>
#include <string.h>

int main(void)
{
    struct employee{
        char name[10];
        int age;
        float salary;
    };
    struct employee e1 = {"Peter", 30, 10000.00};
    struct employee e2, e3;

    // member by member copy
    strcpy(e2.name, e1.name);
    e2.age = e1.age;
    e2.salary = e1.salary;

    e3 = e2;

    printf("%s %d %.2f\n", e1.name, e1.age, e1.salary);
    printf("%s %d %.2f\n", e2.name, e2.age, e2.salary);
    printf("%s %d %.2f\n", e3.name, e3.age, e3.salary);


    return 0;
}