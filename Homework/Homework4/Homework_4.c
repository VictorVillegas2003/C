#include "File.h"

int main()
{
    int sample;
    printf ("Enter a variable with a value: ");
    scanf ("%i",&sample);
    int warning = 0;
    double op2, a = 0;
    char s[MAXOP];
    while ((sample = getop(s)) != EOF) {
        switch (tolower (sample)) {
            case NUMBER:if (warning < 2){
            push(atof(s));
            warning = 0;
            }
            if (warning >= 2){
            a=atof(s);
            }
            break;
            case '+':push(pop() + pop());break;
            case '*':push(pop() * pop());break;
            case '-':op2 = pop();push(pop() - op2);break;
            case '/': op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
            case 'a':push(a);warning++;break;
            case '=':warning++;break;
            case ':':warning++;break;
            case '\n':if (warning<2){
            warning=0;
            printf("\t%.8g\n", pop());}
            if (warning >= 2){
            printf("successful assignment\n");
            warning=0;}
            break;
            default:printf("error: unknown command %s\n", s);break;
        }
    }
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f)
{
    if(sp < MAXVAL)
        val[sp++]=f;
    else
        printf("error:stack full, cant push %g\n",f);
}

double pop(void)
{
    if(sp>0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

#include<ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[])
{
    int i,c;

    while((s[0] = c = getch()) == ' ' || c =='\t')
        ;
    s[1] = '\0';
    
    i = 0;
    if(!isdigit(c) && c!='.' && c!='-')
        return c;

    if(c=='-')
        if(isdigit(c=getch()) || c == '.')
            s[++i]=c;
        else
        {
            if(c!=EOF)
                ungetch(c);
            return '-';
        }
    
    if(isdigit(c))
        while(isdigit(s[++i] =c =getch()))
            ;

    if(c=='.')
        while(isdigit(s[++i] = c=getch()))
            ;
    
    s[i] = '\0';
    if(c!=EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
/*This program was made thanks to the help of a webpage called "Learn To Solve It", and the explanation of majo*/
