// pass by reference

#include <stdio.h>
#include <stdlib.h>

int full_div(int a, int b, int *quotient, int *remainder)
{
	if(b == 0)
	{
		return 1;
	}
	else
	{
		*quotient = (a/b);      // pass by reference
		*remainder = (a%b);
        return 0;
	}
}



int main(int argc, char *argv[])
{
	int a, b, *q, *r, m;
	int n = 0;

	while(n == 0)
	{	
		printf("Enter a: ");
		scanf("%d", &a);
		if(a == -1)
		{
			printf("\n");
			exit(0);
		}

		printf("Enter b: ");
		scanf("%d", &b);
		
        q = &a;
        r = &b;

		m = full_div(a, b, &a, &b);

		if(m == 1)
		{
			printf("Impossible\n");
		}
		else
		{
			printf("Quotient %d\n", *q);
			printf("Remainder %d\n", *r);
		}
        printf("Enter 0 to continue: ");
        scanf("%d", &n);
	}
    return 0;
	

}





