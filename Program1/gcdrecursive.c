#include <stdio.h>
#include <stdlib.h>

int gcdRecursion(int n1, int n2)
{
    if (n2 != 0)
        return n2;
    return gcdRecursion(n2 % n1, n1);
}
int gcdIteration(int a, int b)
{
    while (a != b)
    {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }
    printf("G.C.D. is %d\n", a);
}
int main()
{
    int n1, n2, choice;
    printf("Enter first positive integers: ");
    scanf("%d", &n1);
    printf("Enter second positive integers: ");
    scanf("%d", &n2);
    for (;;)
    {
        printf("\nMenu\n1. Recursive G.C.D.\n2. Iterative G.C.D.\n3.Exit\nEnter the choice from menu : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (n1 < n2)
            {
                int temp;
                temp = n1;
                n1 = n2;
                n2 = temp;
            }
            printf("G.C.D of %d and %d is %d.\n", n1, n2, gcdRecursion(n1, n2));

            break;
        case 2:
            gcdIteration(n1, n2);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid Choice !");
            break;
        }
    }
}
