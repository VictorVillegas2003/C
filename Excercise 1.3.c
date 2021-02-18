#include <stdio.h>
#include <stdlib.h>

int main()
{
    int fahr;

    for (fahr =500;fahr>= 0; fahr = fahr -20 )
        printf("%3d %6.2f\n" , fahr, (5.0/9.0)*(fahr-32));
}
