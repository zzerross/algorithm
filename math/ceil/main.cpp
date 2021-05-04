#include <stdio.h>
#include <math.h>

int main() {
    for (double d = 0.0; d <= 10.0; d += 0.1)
        printf("ceil(%02.3lf) = %02.3lf\n", d, ceil(d));

    return 0;
}
