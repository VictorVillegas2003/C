#include <stdio.h>

int main()
{
    int c, number, quotes, single_quotes, parenthesis;/*here we declare te things we will use in the code so the output will be right*/

    number = 0;
    quotes = 0;
    single_quotes = 0;
    parenthesis = 0;

    printf("put whatever you want: ");
    scanf("%i",&c);

    while ((c = getchar()) != EOF){ /*the getchar is going to take the information from the input*/
        switch (c){ /* if is going to allow us to put the different cases of parenthesis, quotes, numbers that can be found in the input */

        case '(': parenthesis = 1; putchar (c); break; /* in all this cases we are going to indicate to the code when a parenthesis opens and closes*/
        case ')': parenthesis = 0; putchar (c); break;
        case '{': parenthesis = 1; putchar (c); break;
        case '}': parenthesis = 0; putchar (c); break;
        case '<': parenthesis = 1; putchar (c); break;
        case '>': parenthesis = 0; putchar (c); break;
        case '[': parenthesis = 1; putchar (c); break;
        case ']': parenthesis = 0; putchar (c); break;
        case '\"': quotes = 1; quotes ++; putchar (c); break;/* here we put the two kind of quotes, as they open and close in the same way, we will increase them by one, so when the counter counts two times the same quote the program will know when it closes*/
        case '\'': single_quotes = 1; single_quotes ++; putchar (c); break;

        default:
        if (c!='_' && c!='\?' && c!=':' && c!='.' && c!=';' && c!=',' && c!='!' && c!= '\¿' && c!='-'){ /* with this the program ignores all those punctuation marks*/
            if (parenthesis == 1 || quotes == 1 || single_quotes == 1){
                putchar (c);
            }
            else { /* with this the program detects when the quotes and single quotes colose*/
                if (quotes == 2){
                    quotes = 0;
                    putchar(c);
                }
                if (single_quotes == 2){
                    single_quotes = 0;
                    putchar(c);
                }
            if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9'){ /* here the program detects all the numbers and transform them into an "X"*/
                number ++;
            }
            else{
                number = 0;
            }
            if (number == 1){
                putchar ('X');
            }
            if (number == 0){
                putchar (c);
            }
            }
        }
        }
    }

    return 0;
}
/* this program was made with the help of angel raúl, a youtube video from "programación ats" called "La sentencia switch", the teacher´s repo, and the book "Second edition, the c programming language, by Bria W. Kernighan and Dennis M. Ritchie "
*/
