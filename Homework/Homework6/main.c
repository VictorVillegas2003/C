#include "file.h"
void quit(node* place, char* u, char* p, int* n)
{
    if (place != NULL) 
    {
        quit (place->left, u, p, n);
        quit (place->right, u, p, n);
        if (strcmp(place->user, u) == 0&&strcmp(place->password, p) == 0){
            place->password=NULL;
            printf("User %s is deleted\n\n", u);
            *n = 1;
  }
 }
}
node* insert(char* u, char* p, node* pos, int d) 
{
  node* temp;
  if (pos == NULL) 
  {
    pos = (node*)malloc(sizeof(node));
    pos->user = u;
    pos->password = p;
    pos->deep = d;
    printf ("User registered %s with the password %s\n\n", u, p);
  } 
  else 
  {
    if (strcmp(pos->user, u) == 0) 
    {
      if (pos->password!=NULL)
      {
      printf("this user is already registered\n\n");
      }
      else
      {
          pos->password = p;
          printf ("User registered  %s with the password %s\n\n", u, p);
     }
    } 
    else if (strcmp(pos->user, u)>0) 
    {
      temp = insert(u, p, pos->left, d + 1);
      if (pos->left == NULL) 
      {
	pos->left = temp;
     }
    } 
    else if (strcmp(pos->user, u)<0)
    {
      temp = insert(u, p, pos->right, d + 1); 
      if (pos->right == NULL) 
      {
	pos->right = temp;
    }
   }
  }
  return pos;
 }

int main() 
{
  extern char line[];
  node* n = NULL;
  node* Tree = NULL; 
  int i;
  int l = 0;
  char* u;
  char* p;
  int pointer=0; 
  int space=0; 
  int j;
  printf("Please add a name with its password (add name password):\n\n");
    while ((l = out()) == 0) 
  {
      space=0;
    for (j=0; j<MAX; j++)
    {
        if (line[j]==' '||line[j]=='\t')
        {
            space++;
     }
    }
    if (strstr(line, "del") != NULL&&strlen(line)>=7&&space==2) 
    {
      obtain(line, password, user);
      u = (char*)malloc(sizeof(int*) * strlen(user));
      p = (char*)malloc(sizeof(int*) * strlen(password));
      for (i=0; i<strlen(user);i++)
      {
          u[i]=user[i];
      }
      for (i=0; i<strlen(password);i++)
      {
          p[i]=password[i];
      }
      
      pointer=0;
      quit(Tree, u, p, &pointer);
      if (pointer==0)
      {
          printf("This user was not removed\n\n");
      }

      pointer=0;
      space=0;
      }
    
    else if (strstr(line, "add") != NULL&&strlen(line)>=7&&space==2) 
    {
      obtain(line, password, user);
      u = (char*)malloc(sizeof(int*) * strlen(user));
      p = (char*)malloc(sizeof(int*) * strlen(password));
      for (i=0; i<strlen(user);i++)
      {
          u[i]=user[i];
      }
      for (i=0; i<strlen(password);i++)
      {
          p[i]=password[i];
      }
      
      if (strlen(password)>0&&strlen(user)>0)
      {
      n = insert(u,p, Tree, 0); 
	  if (Tree == NULL) 
	  {
	    Tree = n;
	    }
	   space=0;
      }
      else if (strlen(password)<=0||strlen(user)<=0)
      {
          printf ("invalid user\n\n");
      }
     }
      
    else if (strstr(line, "view") != NULL&&strlen(line)==4) 
    {
      general(Tree);
      printf("\n\n");
      space=0;
    }
    else
    {
        printf("invalid user\n\n");
        space=0;
    }
  }
  return 0;
 }


int out() 
{
  extern char line[];
  int c, i = 0;

  for (; i < MAX - 1 && (c = getchar()) != EOF && c != '\n';) 
  {
        line[i++] = c;
  }
  line[i] = '\0';
  return c == EOF;
}


/*this program was made with the help of pedroHC, the teacher's repo, and the book "the c programming language by Brian W. Kernighan and Dennis M. Ritchie"*/