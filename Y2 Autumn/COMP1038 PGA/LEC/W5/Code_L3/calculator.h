#ifndef CALCULATOR_H
#define CALCULATOR_H

int addInt(int a, int b);
int subInt(int a, int b);
int multiInt(int a, int b);
int divInt(int a, int b);

#endif

int addInt(int a, int b)
{
    return (a+b);
}

int subInt(int a, int b)
{
    return (a-b);
}

int multiInt(int a, int b)
{
    return (a*b);
}

int divInt(int a, int b)
{
    return (a/b);
}