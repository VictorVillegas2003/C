#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 80
char linea[MAX];
int saca();//this part of the "saca"  was used thanks to the example in the teacher´s repo and the explanation of raul
int main()
{
    int space, c;
    space = 0;
    int ignore;
    int l = 0;
    extern char linea[];

    while ((l = saca()) == 0)
    {
        if (strstr(linea, "<img") != NULL)
        {
            ignore = 1;
        }
        if (strstr(linea, "<div") != NULL)
        {
            ignore = 1;
        }
        if (strstr(linea, "<script") != NULL)
        {
            ignore = 1;
        }
        if (strstr(linea, "<p>") != NULL)
        {
            ignore = 1;
        }
        if (strstr(linea, "<\p>") != NULL)
        {
            ignore = 1;
        }
        if (strstr(linea, "<\script>") != NULL)
        {
            ignore = 1;
        }
        if (strstr(linea, "<\body>") != NULL)
        {
            ignore = 1;
        }
        if (strstr(linea, "<\html>") != NULL)
        {
            ignore = 1;
        }
    }

    while ((c = getchar())!= EOF)
    {
        if(isspace(c)){
            space = 1;
    }
    else {
        if (space) {
        putchar('_');
        space = 0;

    }
   putchar(c);
    }
    }
    return 0;
}
//This project was based on the book "Second edition, the c programming language, by Brian W. Kernighan and Dennis M. Ritchie", and the examples of the teacher´s repo
//The part of the ignoring comments was ceated thanks to the explanation of Angel Raúl Chavez carrillo, and the example of the Teacher´s repo
