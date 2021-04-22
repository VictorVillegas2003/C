/*First you have to include the library "File.h" in the "Homework_5.c"file, after that you make another file with the name "File.h" and you put the code that is in the homework5 file, then you run and compile the code and finally you start playing*/

#include "File.h" 

int NearMines(int row, int column, char table[ROWS][COLUMNS]) {
  int count = 0, startingRow, endingRow, startingColumn, endingColumn;
  if (row <= 0) {
    startingRow = 0;
  } else {
    startingRow = row - 1;
  }

  if (row + 1 >= ROWS) {
    endingRow = ROWS - 1;
  } else {
    endingRow = row + 1;
  }

  if (column <= 0) {
    startingColumn = 0;
  } else {
    startingColumn = column - 1;
  }
  if (column + 1 >= COLUMNS) {
    endingColumn = COLUMNS - 1;
  } else {
    endingColumn = column + 1;
  }
  int m;
  for (m = startingRow; m <= endingRow; m++) {
    int l;
    for (l = startingColumn; l <= endingColumn; l++) {
      if (table[m][l] == MINE) {
        count++;
      }
    }
  }
  return count;
}

int Random(int min, int max) {
  return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

void startingTable(char table[ROWS][COLUMNS]) {
  int l;
  for (l = 0; l < ROWS; l++) {
    int m;
    for (m = 0; m < COLUMNS; m++) {
      table[l][m] = UNSTOPEED_SPACE;
    }
  }
}

void putMine(int row, int column, char table[ROWS][COLUMNS]) {
  table[row][column] = MINE;
}

void randomMines(char table[ROWS][COLUMNS]) {
  int l;
  for (l = 0; l < NUMBER_OF_MINES; l++) {
    int row = Random(0, ROWS - 1);
    int column = Random(0, COLUMNS - 1);
    putMine(row, column, table);
  }
}

void separatorHeader() {
  int m;
  for (m = 0; m <= COLUMNS; m++) {
    printf("----");
    if (m + 2 == COLUMNS) {
      printf("-");
    }
  }
  printf("\n");
}

void rowsSeparator() {
  int m;
  for (m = 0; m <= COLUMNS; m++) {
    printf("+---");
    if (m == COLUMNS) {
      printf("+");
    }
  }
  printf("\n");
}

void Header() {
  separatorHeader();
  printf("|   ");
  int l;
  for (l = 0; l < COLUMNS; l++) {
    printf("| %d ", l + 1);
    if (l + 1 == COLUMNS) {
      printf("|");
    }
  }
  printf("\n");
}

char IntToChar(int number) {
  return number + '0';
}

void printTable(char table[ROWS][COLUMNS], int showMines) {
  Header();
  separatorHeader();
  char letter = 'A';
  int l;
  for (l = 0; l < ROWS; l++) {
    int m;
    
    printf("| %c ", letter);
    letter++;
    for (m = 0; m < COLUMNS; m++) {
        
      char trueLetter = UNSTOPEED_SPACE;
      char actualLetter = table[l][m];
      if (actualLetter == MINE) {
        trueLetter = UNSTOPEED_SPACE;
      } else if (actualLetter == CHOSEN_SPACE) {
      
        int closeMines = NearMines(l, m, table);
        trueLetter = IntToChar(closeMines);
      }
      printf("| %c ", trueLetter);
      if (m + 1 == COLUMNS) {
        printf("|");
      }
    }
    printf("\n");
    rowsSeparator();
  }
}

int openBox(char letterRow, int column, char table[ROWS][COLUMNS]) {

  letterRow = toupper(letterRow);

  column--;

  int row = letterRow - 'A';
  assert(column < COLUMNS && column >= 0);
  assert(row < ROWS && row >= 0);
  if (table[row][column] == MINE) {
    return MISTAKE_MINE_FOUND;
  }
  if (table[row][column] == CHOSEN_SPACE) {
    return MISTAKE_CHOSEN_SPACE;
  }

  table[row][column] = CHOSEN_SPACE;
  return NO_MISTAKES;
}

int noChosenBoxes(char table[ROWS][COLUMNS]) {
  int l;
  for (l = 0; l < ROWS; l++) {
    int m;
    for (m = 0; m < COLUMNS; m++) {
      char actual = table[l][m];
      if (actual == UNSTOPEED_SPACE) {
        return 0;
      }
    }
  }
  return 1;
}

int main() {
  char table[ROWS][COLUMNS];
  int showMines = 0;
 
  srand(getpid());
  startingTable(table);
  randomMines(table);
 
  while (1) {
    printTable(table, showMines);
    if (showMines) {
      break;
    }
    int column;
    char row;
    printf("Enter the row: ");
    scanf(" %c", &row);
    printf("Enter the column: ");
    scanf("%d", &column);
    int status = openBox(row, column, table);
    if (noChosenBoxes(table)) {
      printf("You win\n");
      showMines = 1;
    } else if (status == MISTAKE_CHOSEN_SPACE) {
      printf("This box is opened\n");
    } else if (status == MISTAKE_MINE_FOUND) {
      printf("You lose\n");
      showMines = 1;
    }
  }
  return 0;
}
/*This code was made with the help of the teacher's repo and the youtube video of Luis Cabrera Benito*/
