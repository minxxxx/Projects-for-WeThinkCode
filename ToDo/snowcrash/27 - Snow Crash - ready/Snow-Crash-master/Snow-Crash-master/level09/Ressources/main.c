#include <unistd.h>
int main(int ac, char **av)
{
        int x;
        char c;

        x = 0;
        while (av[1][x])
        {
                c = av[1][x] - x;
                write(1, &c, 1);
                x++;
        }
        return 0;
}
