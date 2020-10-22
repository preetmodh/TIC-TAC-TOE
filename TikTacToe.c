#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include <stdbool.h>



int main(void)
{

            char board[9]={'1','2','3','4','5','6','7','8','9'};
            int chance1;                                                            //input from player 1
            int chance2;                                                           // input from player 2
            char X='x';
            char O='o';
            bool win=false;
            int k=1;                                                                  //defined to change chance of players.
            int count=0;
            int stop=1;                                                             // defined to display last e entered value of player


top:                  if(stop<=1)
                            {
                            printf("\n\t\t\t\t\t\t\t    tic tac toe\n\n");
                            printf("player(X) 1  vs player(O) 2\n\n\n");
                            }


            count=0;

                        for (int i=0;i<9;i++)                                         // for the printing of board. it will start here
                            {
                            for(int j=0;j<74;j++)
                                {
                                if(j==61 || j==67)
                                {
                                    printf("|");
                                }
                                else if((i==2 || i==5) && (j>=56 && j<=72))
                                    {
                                    printf("_");
                                    }
                                else if(i==1 || i==4 || i==7)
                                    {
                                    if (j==58 || j==64 || j==70)
                                        {
                                        printf("%c",board[count]);                //assignning value of x and o to board
                                        count++;
                                        }
                                else
                                    printf(" ");
                                    }
                                 else
                                printf(" ");
                                }
                                printf("\n");
                            }                                                                            // it will end  here.



                        if(stop<=1)                                                         // now input will be taken and conditions of win lose and draw will be check
                            {
                                                            //player 1
                                if(k % 2 !=0)                                               // if k is even then player 1 turn
                                    {
                                        system ("color 5a");                            //changes color of output screen.
                                        player1:                                                //goto of player1 will send it here
                                        printf("\nPlayer 1 enter the value:");
                                        scanf("%d",&chance1);
                                                                                                           //for taking value of players
                                if(chance1<=0||chance1>9 || (board[chance1-1] =='o'   || board[chance1-1]=='x'))    //checks for invalid number entered by user
                                    {
                                        printf("enter valid number");
                                        goto player1;
                                    }
                                else
                                    {
                                    int p1=chance1 - 1;
                                    board[p1]=X;                                                           //assignning value of x and o to board

                                if (((board[0]==board[1]) && (board[1]==board[2]))||((board[3]==board[4]) && (board[4]==board[5]))||((board[6]==board[7]) && (board[7]==board[8])))              //checks if 3 elements of row becomes same then player wins
                                    {
                                        win=true;
                                        system("cls");
                                        printf("\n\n\t\t \t\t\t\tplayer 1 has won.\n\n");
                                        stop++;
                                        goto top;
                                    }

                                else if(((board[0]==board[3]) && (board[3]==board[6]))||((board[1]==board[4]) && (board[4]==board[7]))||((board[2]==board[5]) && (board[5]==board[8])))         //checks if 3 elements of columm becomes same then player wins
                                    {
                                        win=true;
                                        system("cls");
                                        printf("\n\n\t\t \t\t\t\tplayer 1 has won.\n\n");
                                        stop++;
                                        goto top;
                                    }

                                else if(((board[0]==board[4]) && (board[4]==board[8]))||((board[2]==board[4]) && (board[4]==board[6])))                 //checks if 3 elements of diagonal becomes same then player wins
                                      {
                                        win=true;
                                        system("cls");
                                        printf("\n\n\t\t \t\t\t\tplayer 1 has won.\n\n");
                                        stop++;
                                        goto top;
                                      }

                                           else  if(k==9)   // if number of turns reaches 9 then game becomes draw.
                                                    {
                                                    win=true;
                                                    system("cls");
                                                    printf("\n\n\t\t \t\t\t the match is draw\n\n");
                                                    stop++;
                                                    goto top;
                                                    }

                                            else{win=false;}

                                if(win==false)                                  // if win is false then again the board draws and asks user for input
                                    {
                                    k++;
                                    system("cls");                                                                                   // clearing output screen
                                    goto top;
                                    }
                                }
                            }

                                                            // player 2
                                else if(k % 2==0)
                                    {
                                    system ("color 8a");                            //changes color of output screen.
                                    player2:
                                    printf("\nPlayer 2 enter the value:");
                                    scanf("%d",&chance2);

                                    if(chance2<=0||chance2>9|| board[chance2-1]=='x' ||   board[chance2-1]=='o')
                                        {
                                        printf("enter valid number");
                                        goto player2;
                                        }
                                    else
                                        {
                                        int p2=chance2 - 1;
                                        board[p2]=O;                                  //assignning value of x and o to board

                                            if (((board[0]==board[1])&&(board[1]==board[2]))||((board[3]==board[4]) && (board[4]==board[5]))||((board[6]==board[7]) && (board[7]==board[8])))
                                                {
                                                win=true;
                                                system("cls");
                                                printf("\n\n\t\t\t\t\t\tplayer 2 has won\n\n");
                                                stop++;
                                                goto top;
                                                }

                                        else if(((board[0]==board[3]) && (board[3]==board[6]))||((board[1]==board[4]) && (board[4]==board[7]))||((board[2]==board[5]) && (board[5]==board[8])))
                                            {
                                            win=true;
                                            system("cls");
                                            printf("\n\n\t\t \t\t\t\tplayer 2 has won.\n\n");
                                            stop++;
                                            goto top;
                                            }

                                        else if(((board[0]==board[4]) && (board[4]==board[8]))||((board[2]==board[4]) && (board[4]==board[6])))
                                        {
                                        win=true;
                                        system("cls");
                                        printf("\n\n\t\t \t\t\t\tplayer 2 has won.\n\n");
                                        stop++;
                                        goto top;
                                        }
                                    }
                                }


                                            else  if(k==9)   // will check until the element comes.
                                                    {
                                                    win=true;
                                                    system("cls");
                                                    printf("\n\n\t\t \t\t\t the match is draw\n\n");
                                                    stop++;
                                                    goto top;
                                                    }

                                            else{win=false;}

                                    if(win==false)
                                        {
                                         k++;
                                         system("cls");                                 // clearing output screen
                                         goto top;
                                        }
                                    }
                            }








