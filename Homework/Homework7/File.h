#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>

#define NAME 10
#define DAY 10
#define HOURS 4
#define START 4
#define OUT 4

int voids;
void show (void);
void activity (void);

struct worker{
 char idemp[10];
 char Day[10];
 char start[10];
 char end[10];
 
};
struct worker wRegister[100];

typedef struct {
  char* name;char* day;char* hours;char* start;char* out;
  unsigned int pin;
} worker;
