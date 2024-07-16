
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <math.h>

int main(void)
{

    double a = 0;

    double q = fabs(15 / a);
    printf("%f\n", q == 1e30);
}