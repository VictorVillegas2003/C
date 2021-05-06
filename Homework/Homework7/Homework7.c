/*it doesn't really work, i tried , but i couldn't :((
in order to run this you have to add a new file with the name "File.h, so this header can be included"
Also you have to add another file with the name "workers.txt" so the program can take the information from that database
*/

#include "File.h"

int options (void){
 printf("option 1 = New employee\n");
 printf("option 2 = Register employee\n");
 printf("option 3 = Finish\n");
 printf("Choose an option from 1 to 3: ");

}
int main(int x, char** y) {
  int posi;
  int I=0;
  char c;
   int i, count = 0;
   worker** w;
  
  activity();
  posi==options();
 scanf ("%d", &posi);
 while (posi !=4){
 switch(posi){
  case '1':printf ("\nAdd employee.\n");activity();posi==options();scanf ("%d", &posi);break;
  case '2':printf ("\nShow attendance records.\n");show ();posi==options();scanf ("%d", &posi);break;
  case '3':break;
 }
}
 return 0;
}
void show ()
{
 int I;
 I=0;
 voids=0;
 for (I=voids; I<100; I++)
 {
  printf ("%s ", wRegister[I].Day);
  printf ("%s ", wRegister[I].begining);
  printf ("%s\n ", wRegister[I].end);
  
  voids==I;
 }
}
void activity()/*teacher's repo example*/
{
  int posi;
  int I=0;
  char c;
   int i, count = 0;
   worker** w;
   
   FILE* workers = fopen("workers.txt", "r");
   while ((c = fgetc(workers)) != EOF) 
   {
     if (c == '\n') 
     {
       count++;
       
     }
    }
  
  w = (worker**)malloc(sizeof(worker*) * count);
  rewind(workers);
  for (i = 0; i < count; i++) 
  {
    w[i] = (worker*)malloc(sizeof(worker));
    w[i]->name = (char*)malloc(sizeof(char) * (NAME + 1));
    w[i]->day = (char*)malloc(sizeof(char) * (DAY + 1));
    w[i]->hours = (char*)malloc(sizeof(char) * (HOURS + 1));
    w[i]->start = (char*)malloc(sizeof(char) * (START + 1));
    w[i]->out = (char*)malloc(sizeof(char) * (OUT + 1));
    fscanf(workers, "%u %s %s %s %s %s", &(w[i]->pin), w[i]->name, w[i]->day,w[i]->hours, w[i]->start, w[i]->out);    
  }
  
  
  fclose(workers);
  for (i = 0; i < count; i++) {
    printf("Worker %u %s works %s hours at %s to %s, on %s\n", w[i]->pin, w[i]->name, w[i]->hours, w[i]->start, w[i]->out, w[i]->day);
    
    free(w[i]->name);
    free(w[i]->hours);
    free(w[i]->start);
    free(w[i]->out);
    free(w[i]->day);
    free(w[i]);
  }
  free(w);
 }
/*this program was made with the help of the teacher's repo, the help of my classmates as pedroHC, and the book "the c programming language by Brian W. Kernighan and Dennis M. Ritchie"*/
