#include <stdio.h>

int main(void)
{
    struct address{
        char phone[15];
        char city[25];
        int pin;
    };

    struct emp{
        char name[25];
        struct address a;   // nested structure
    };

    struct emp e = {"Peter", "1234567890", "Ningbo", 315100};

    printf("name = %s\nphone = %s\n", e.name, e.a.phone);
    printf("city = %s\npin %d\n", e.a.city, e.a.pin);

    return 0;
}