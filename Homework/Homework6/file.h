#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 50
typedef struct Treenode
{
  char* user;
  char* password;
  struct Treenode* right;
  struct Treenode* left;
  unsigned int deep;
}


node;
char line[MAX], password[MAX], user[MAX];
int out();
void obtain (char l[MAX],char p[MAX],char u[MAX]);
void obtain (char l[MAX],char p[MAX],char u[MAX])
{
    int a = 4, b = 0, c=0;
    while (l[a]!=' '&&l[a]!='\t')
    {
        u[b]=l[a];
        b++;
        a++;
    }
    u[b]='\0';
    int length = strlen(u);
    a++;
    while (l[a]!=' '&&l[a]!='\t'&&l[a]!='\0')
    {
       p[c]=l[a];
       c++;
       a++;
    }
    p[c]='\0';
    int length2 = strlen(p);
}
node* enter(char* u, char* p, node* pos, int d);

void general(node* place) 
{
  if (place != NULL) 
  {
    general(place->left);
    if (place->password!=NULL)
    {
    printf("%s ", place->user);
    }
    general(place->right);
 }
}
