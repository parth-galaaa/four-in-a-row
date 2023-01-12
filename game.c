/* ===========================================================================
Four in a Row Welcomes You!
=========================================================================== */

#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

bool make_move(char board[6][7], int column, char player);
bool make_move(char board[6][7], int column, char player) {
  int a=0;
  for (int i=0;i<6;i++) {
    for (int j=0; j<7; j++) {
      if (board[5-a][column]=='0' && column>=0 && column<7) {
        board[5-a][column]=player;
        return true;
      }
      else if (board[5-a][column]=='X' || board[5-a][column]=='O') {
        if (board[5-a-1][column]=='0') {
          board[5-a-1][column]=player;
          return true;
        }
        }
        a++;
      }
      if (a>=5) {
        printf("Invalid Input\n");
        break;
      }
      }
      return false;
  }
 

bool check_win(char board[6][7], char player);
bool check_win(char board[6][7], char player) {
  int count=0;
  // for horizontal
  for (int i=0;i<6;i++) {
    for (int j=0; j<7; j++) {
      if (board[i][j]==player) {
        count=count+1;
        if (count>=4) {
          return true;
          }
      }
      else if (board[i][j]!=player) {
        count=0;
      }

    }
  }
  for (int a=0;a<6;a++) {
    for (int b=0; b<7;b++) {
      if (board[b][a]==player) {
        count=count+1;
        if (count>=4) {
          return true;
        }
      }
      else if (board[b][a]!=player) {
        count=0;
      }
    }
  }

  for (int c=0;c<6;c++) {
    for (int d=0;d<7;d++) {
      if (board[c][d]==player) {
        if (board[c+1][d+1]==player && board[c+2][d+2]==player && board[c+3][d+3]==player) {
          count=4;
        if (count>=4) {
          return true;
        }
      }
        }
      else if (board[c][d]!=player) {
        count=0;
        }
      }
    }
  for (int c=0;c<6;c++) {
    for (int d=0;d<7;d++) {
      if (board[c][d]==player) {
        if (board[c-1][d-1]==player && board[c-2][d-2]==player && board[c-3][d-3]==player) {
          count=4;
        if (count>=4) {
          return true;
        }
      }
        }
      else if (board[c][d]!=player) {
        count=0;
        }
      }
    }
  for (int c=0;c<6;c++) {
    for (int d=0;d<7;d++) {
      if (board[c][d]==player) {
        if (board[c+1][d-1]==player && board[c+2][d-2]==player && board[c+3][d-3]==player) {
          count=4;
        if (count>=4) {
          return true;
        }
      }
        }
      else if (board[c][d]!=player) {
        count=0;
        }
      }
    }
  for (int c=0;c<6;c++) {
    for (int d=0;d<7;d++) {
      if (board[c][d]==player) {
        if (board[c-1][d+1]==player && board[c-2][d+2]==player && board[c-3][d+3]==player) {
          count=4;
        if (count>=4) {
          return true;
        }
      }
        }
      else if (board[c][d]!=player) {
        count=0;
        }
      }
    }
  
  return false;
}

char first_capital(const char str[], int n);
char first_capital(const char str[], int n) {
  char c;
  for (int i=0; i<n; i++) {
    if (isupper(str[i])) {
      c=str[i];
      return c;
    }
  }
  return 0;
}


void deepest_substring(const char str[], char out[]);
void deepest_substring(const char str[], char out[]) {
  int i=0;
  int count=0;
  int index=0;
  int length=0;
  while (str[i]!='\0') {
    if (str[i]=='(') {
      index = i+1;
      }
    i++;
    length++;
    }
  for(;index<length;index++){
    if(str[index]==')'){
      break;
      }
    out[count]=str[index];
    count++;
    }
  }


int main (void) {

  char board1[6][7]={{'0','0','0','0','0','0','0'},{'0','0','0','0','0','0','0'},{'0','0','0','0','0','0','0'},{'0','0','0','0','0','0','0'},{'0','0','0','0','0','0','0'},{'0','0','0','0','0','0','0'}};
  int column1;
  int column2;
  char player1='X';
  char player2='O';

 while (true) {
    printf("Enter the column number in which the piece has to be placed for player X\n");
  scanf("%d",&column1);
  while (column1>6 || column1<0) {
      printf("Invalid Input. Please enter again");
      scanf("%d",&column1);
    }
  make_move(board1,column1,player1);
    for (int i=0; i<6; i++) {
    for (int j=0; j<7; j++) {
      printf(" %c ",board1[i][j]);
    }
    printf("\n");
  }
  printf("Enter the column number in which the piece has to be placed for player O\n");
  scanf("%d",&column2);
    while (column2>6 || column2<0) {
      printf("Invalid Input. Please enter again");
      scanf("%d",&column2);
    }
  make_move(board1,column2,player2);
  for (int i=0; i<6; i++) {
    for (int j=0; j<7; j++) {
      printf(" %c ",board1[i][j]);
    }
    printf("\n");
  }
    
  check_win(board1,player1);
  if (check_win(board1,player1)==true) {
    printf("Player X wins\n");
    break;
  }
  check_win(board1,player2);
  if (check_win(board1,player2)==true) {
    printf("Player O wins\n");
    break;
  }
   }
  char board5[6][7]={{'0','0','0','0','0','0','0'},{'0','0','0','0','0','0','0'},{'0','0','0','0','0','0','0'},{'0','0','0','0','0','0','0'},{'O','0','0','0','0','0','0'},{'X','X','X','X','O','O','O'}};
  assert(check_win(board5,'X'));

  char board2[6][7]={{'0','0','0','0','0','0','0'},{'0','0','0','0','0','0','0'},{'O','0','0','0','0','0','0'},{'O','0','0','0','0','0','0'},{'O','0','0','0','0','0','0'},{'O','X','X','X','0','X','0'}};
  assert(check_win(board2,'O'));

  char board3[6][7]={{'0','0','0','0','0','0','0'},{'0','0','0','0','0','0','0'},{'0','0','0','O','0','0','0'},{'0','0','O','O','0','0','0'},{'0','O','X','X','0','0','0'},{'O','X','X','X','0','0','0'}};
  assert(check_win(board3,'O'));

 char board4[6][7]={{'0','0','0','0','0','0','0'},{'0','0','0','0','0','0','0'},{'X','0','0','O','0','0','0'},{'O','X','0','0','0','0','0'},{'O','O','X','0','0','0','0'},{'O','X','O','X','0','0','0'}};
  assert(check_win(board4,'X'));

  assert(first_capital("hellO",6)=='O');
  assert(first_capital("oN",3)=='N');
  assert(first_capital("abcDEF",7)=='D');
  assert(first_capital("ok",3)==0);
  assert(first_capital("whassuP",8)=='P');
  assert(first_capital("daMN",5)=='M');
  assert(first_capital("HI",3)=='H');
  
  char inp[13]="a(b+(c+e))+d";
  char out1[4]="";
  deepest_substring(inp,out1);
  assert(strcmp(out1,"c+e")==0);

  char inp1[5]="a(b)";
  char out2[2]="";
  deepest_substring(inp1,out2);
  assert(strcmp(out2,"b")==0);

  char inp2[7]="h*(ab)";
  char out3[3]="";
  deepest_substring(inp2,out3);
  assert(strcmp(out3,"ab")==0);

  char inp3[8]="(((a)))";
  char out4[2]="";
  deepest_substring(inp3,out4);
  assert(strcmp(out4,"a")==0);

  char inp4[17]="a(b+(c(d+(f))))";
  char out5[2]="";
  deepest_substring(inp4,out5);
  assert(strcmp(out5,"f")==0);

  char inp5[8]="((( )))";
  char out6[2]="";
  deepest_substring(inp5,out6);
  assert(strcmp(out6," ")==0);
  
  return 0;
}
  
