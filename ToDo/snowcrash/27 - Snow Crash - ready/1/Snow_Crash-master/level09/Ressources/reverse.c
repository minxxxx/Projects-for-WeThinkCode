#include <stdio.h>

int main(int ac, char ** av)
{
    int k = 0;


    if (ac > 1)
    {
        while (av[1][k])
        {
            printf("%c", av[1][k] - k);
            k++;
        }
        printf("\n");
    }
}
