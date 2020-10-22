#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include <stdbool.h>

                    //initializing all variables all global variables.

                    char board[9]={'1','2','3','4','5','6','7','8','9'};
                    int chance1;                                        //player 1 chance
                    int chance2;                                        //player 2 chance
                    char X='x';
                    char O='o';
                    bool win=false;
                    int k=1;                                //it is number of turns
                    int count=0;


            // declaring all functions before main

void askValue(void);
void drawBoard(void);
void caseWin(void);

int main()
{

        drawBoard();            //calling both functions
        askValue();

}











//function3 checks if the player has won or match is draw
void caseWin()
{
                win=false;              //initializing the boolean win to false


                                if (((board[0]==board[1]) && (board[1]==board[2]))||((board[3]==board[4]) && (board[4]==board[5]))||((board[6]==board[7]) && (board[7]==board[8])))              //checks if 3 elements of row becomes same then player wins
                                    {
                                        win=true;
                                        system("cls");

                                          if(k % 2 !=0)                     //for player chances and who won i.e if k is odd and player wins therefore player 1 is winner
                                           {
                                            printf("\n\n\t\t \t\t\t\tplayer 1 has won.\n\n");
                                            drawBoard();                // draws the board for the last time.
                                           }
                                           else if(k % 2==0)
                                           {
                                               printf("\n\n\t\t \t\t\t\tplayer 2 has won.\n\n");
                                               drawBoard();
                                           }
                                    }

                                else if(((board[0]==board[3]) && (board[3]==board[6]))||((board[1]==board[4]) && (board[4]==board[7]))||((board[2]==board[5]) && (board[5]==board[8])))         //checks if 3 elements of columm becomes same then player wins
                                   {
                                        win=true;
                                        system("cls");

                                          if(k % 2 !=0)
                                           {
                                            printf("\n\n\t\t \t\t\t\tplayer 1 has won.\n\n");
                                            drawBoard();
                                           }
                                           else if(k % 2==0)
                                           {
                                               printf("\n\n\t\t \t\t\t\tplayer 2 has won.\n\n");
                                               drawBoard();
                                           }
                                    }

                                else if(((board[0]==board[4]) && (board[4]==board[8]))||((board[2]==board[4]) && (board[4]==board[6])))                 //checks if 3 elements of diagonal becomes same then player wins
                                      {
                                        win=true;
                                        system("cls");

                                          if(k % 2 !=0)
                                           {
                                            printf("\n\n\t\t \t\t\t\tplayer 1 has won.\n\n");
                                            drawBoard();
                                           }
                                           else if(k % 2==0)
                                           {
                                               printf("\n\n\t\t \t\t\t\tplayer 2 has won.\n\n");
                                               drawBoard();
                                           }
                                    }

                                           else  if(k==9)                       // it is for the condition of draw i.e if number of turns becomes 9 and no one is winner then draw.
                                                    {
                                                    win=true;
                                                    system("cls");
                                                    printf("\n\n\t\t \t\t\t the match is draw\n\n");
                                                    drawBoard();            // draws the board for the last time.
                                                    }

                                            else{win=false;}

                                        if(win==false)                  // if none of above is satisfied then it moves forward to ask another value.
                                            {
                                            system("cls");
                                            drawBoard();
                                            }


}





//function2             // asks value from player and checks for invalid input.
void askValue()
{


                                                                    //player 1
                                if(k % 2 !=0)                                               // if k is even then player 1 turn
                                    {
                                        printf("\nPlayer 1 enter the value:");
                                        scanf("%d",&chance1);

                                        if(chance1<=0||chance1>9|| board[chance1-1] =='o'   || board[chance1-1]=='x')     //checks for invalid input if it is invalid then it goes to last else and again asks for value.
                                          {
                                              printf("enter valid number");
                                          }
                                        else                                    //if input is valid then it assigns the value to array and converts it to x and o
                                        {
                                        int p1=chance1 - 1;
                                        board[p1]=X;
                                        system("cls");
                                        caseWin();                      //checks everytime for the condition of win or draw
                                        k++;                                 //increases k by 1 to go to next player chance
                                        }
                                        }



                                                // player 2
                               else if(k % 2==0)
                                    {
                                    printf("\nPlayer 2 enter the value:%d", chance2);
                                    scanf("%d",&chance2);



                                        if( chance2<=0|| chance2>9|| board[ chance2-1]=='x' ||   board[ chance2-1]=='o')
                                            {
                                        printf("enter valid number");
                                            }
                                        else
                                            {
                                                int p2= chance2 - 1;
                                                board[p2]=O;
                                                system("cls");
                                                caseWin();
                                                k++;
                                            }
                                    }
                                    if(k<=9 && win==false)                           // only asks value again from player if no. of turns is less than equal to 9 and win is false.
                                    {
                                    askValue();
                                    }

}

//function 1   draws the board
void drawBoard(void)
{
                            printf("\n\t\t\t\t\t\t tic tac toe\n\n");
                            printf("player(X) 1  vs player(O) 2\n\n\n");
                            count=0;
                            for (int i=0;i<9;i++)
                            {
                            for(int j=0;j<20;j++)
                                {
                                if(j==6 || j==13)
                                    {
                                    printf("|");
                                    }
                                else if(i==2 || i==5)
                                    {
                                    printf("_");
                                    }
                                else if(i==1 || i==4 || i==7)
                                    {
                                    if (j==2 || j==8 || j==14)
                                        {
                                        printf("   %c  ",board[count]);
                                        count++;
                                        }
                                    }
                                else
                                printf(" ");
                                }
                                printf("\n");
                            }
}
