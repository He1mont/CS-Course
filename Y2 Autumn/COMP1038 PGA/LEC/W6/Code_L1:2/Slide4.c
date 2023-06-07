#include <stdio.h>
#include <ctype.h>

int main(void)
{
    printf("%s\n%s%s\n%s%s\n\n", "According to is digit:",
    isdigit('8') ? "8 is a" : "8 is not a", "digit",
    isdigit('#') ? "# is a" : "# is not a", "digit");

    printf("%s\n%s%s\n%s%s\n%s%s\n%s%s\n\n", 
    "According to isalpha:",
    isalpha('A') ? "A is a" : "A is not a", "letter",
    isalpha('b') ? "b is a" : "b is not a", "letter",
    isalpha('&') ? "& is a" : "& is not a", "letter",
    isalpha('4') ? "4 is a" : "4 is not a", "letter");

    return 0;
}