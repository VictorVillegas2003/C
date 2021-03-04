#include<stdio.h>
#include<math.h>
#define K 15
int prime(int n);
int binary(int u);

main() {
  prime(K);
}

int prime(int k){ //This based on a youtube video from the channel "Abel Guitian"

        int i, count, sr, warning;
        int n;

        n = 2;
        count = 1;

        while (count <= K)
        {
            sr = sqrt(n);
            warning = 0;
            for (i = 2; i <= sr; i++){
                if (n % i == 0){
                 warning = 1;
                break;
                }
            }
            if (warning == 0){
                    binary (n);
                    count ++;
            }
            n++;
        }

}
int binary (int u) //This based on the Angel Raul Chavez Carrillo
{
    int i, nprime;
    i = 0;
    nprime = u;
    int base[8]={0};

    while (nprime > 0)
    {
        base[i] = nprime % 2;
        nprime/=2;
        ++i;
    }
    for (int x = 7; x >= 0; --x)
    {
        printf ("%01d", base[x]);
    }
    printf ("\n");
}
//This code was base on the examples of the teacher´s repo, the explanation of angel raúl, and the book "Second edition, the c programming language, by Bria W. Kernighan and Dennis M. Ritchie "
