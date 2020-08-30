#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<cstdlib>

using namespace std;
char b[3][3]={{'.','.','.'},{'.','.','.'},{'.','.','.'}};
void display();
int islocationempty(int);
int isempty();
int insertval();
void replaceval(int,int);
int iswinner(int);
int FLAG = 1;
int IW = 0;
char str1[25],str2[25];
int score=0;
#define WINDOWS 1
void clrscr()
{
    system("cls");
}
int main()
{
    cout<<"*******************************************************************************"<<endl;
    cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
    cout<<endl;
    cout<<"------------------------------------WELCOME-----------------------------------"<<endl;
    cout<<"******************************************************************************"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-TIC TAC TOE-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Press ENTER to continue. ";
    getch();
    clrscr();
    cout<<endl;
    cout<<"-----------------****************INTRODUCTION*****************-----------------"<<endl;
    cout<<"You probably know how to play TIC-TAC-TOE,right.Quite simple, isn't it?But if you really wrap your brain around it,you would realize its not so simple as you think."<<endl;
    cout<<"TIC-TAC-TOE involves looking ahead and trying to figure out what the person playing against you might do next."<<endl;
    cout<<endl;
    cout<<" SO LET'S HAVE A LOOK AT THE RULES FOR PLAYING TIC TAC TOE!!!"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Press ENTER to continue. "<<endl;
    getch();
    clrscr();
    cout<<"-----------------****************INSTRUCTIONS*****************-----------------"<<endl;
    cout<<endl;
    cout<<"There are two players-- User 1 and User 2."<<endl;
    cout<<"The user 1 places 'X' and user 2 places 'O' in the spaces alotted."<<endl;
    cout<<"The playing grid is numbered from 1 to 9."<<endl;
    cout<<"Players have to enter the number corresponding to the place they want to put their 'X' or 'O' in."<<endl;
    cout<<"NO PLAYER IS ALLOWED TO ENTER ANY NUMBER WHICH HAS ALREADY BEEN FILLED OR IS NOT AMONG 1-9."<<endl;
    cout<<"The individual scores will be alotted as per the game rules-- +2 for winning, 0 for losing and +1 for a draw."<<endl;
    cout<<"-------------------------------------------------------------------------------"<<endl;
    cout<<"SO NOW LETS PLAY!!!"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Press ENTER to continue. "<<endl;
    getch();
    clrscr();
    cout<<"ENTER THE NAME OF USER 1."<<endl;
    gets(str1);
    cout<<"ENTER THE NAME OF USER 2."<<endl;
    gets(str2);
    cout<<"GREAT!!  "<< str1 <<" AND "<<str2 <<" -- HERE YOU ARE!!!"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Press ENTER to continue. "<<endl;
    getch();
    clrscr();
    for(;;)
    {
        display();
        if(isempty()){
            int val = insertval();
            int locempt = islocationempty(val);
            if(locempt == 1){
                replaceval(val,FLAG);
                display();
                IW = iswinner(FLAG);
                if(IW){
                    if(FLAG){
                        cout<<"CONGRATULATIONS!!!  "<<str1<<" IS WINNER!! "<<endl;
                        cout<<str1<<", YOUR SCORE IS: "<<(score+2)<<endl;
                        cout<<str2<<", YOUR SCORE IS: "<<score<<endl;
                        getch();
                        clrscr();
                        cout<<endl;
                        cout<<endl;
                        cout<<endl;
                        cout<<endl;
                        cout<<"******THE END******";

                    }
                    else{
                        cout<<"CONGRATULATIONS!!!  "<<str2<<" IS WINNER!! "<<endl;;
                        cout<<str2<<", YOUR SCORE IS: "<<(score+2)<<endl;
                        cout<<str1<<", YOUR SCORE IS: "<<score<<endl;
                        getch();
                        clrscr();
                        cout<<endl;
                        cout<<endl;
                        cout<<endl;
                        cout<<endl;
                        cout<<"******THE END******";
                    }
                    getch();
                    break;
                }
            }
            else if(locempt == -1){
                cout<<"YOU CAN'T ENTER THIS NUMBER. GAME INTERRUPTED DUE TO ILLEGAL INPUT!! ENTER AGAIN!!";
                getch();
                break;
            }
            else{
                cout<<"YOU CAN'T ENTER THIS NUMBER. GAME INTERRUPTED DUE TO ILLEGAL INPUT!! ENTER AGAIN!!";
                getch();
                continue;
            }
        }
        else{
            if(IW == 0){
                cout<<"MATCH DRAW!!"<<endl;
                getch();
                clrscr();
                cout<<str1<<", YOUR SCORE IS: "<<(score+1)<<endl;
                cout<<str2<<", YOUR SCORE IS: "<<(score+1);
                getch();
                break;
            }
        }
        if(FLAG)FLAG = 0;
        else FLAG = 1;
    }
    getch();
    return 0;
}
void display()
{
    int i,j,k=1;
    clrscr();
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<k++<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<b[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
}
int islocationempty(int n)
{
    int i,j,fg = 0;
    if(n >= 1 && n <= 9){
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(i*3 + j == n-1)
            {
                if(b[i][j]=='.'){
                    fg = 1;
                    break;
                }
            }
        }
        if(fg)break;
    }
    return fg;
    }else{
        return -1;
    }
}
int isempty()
{
    int i,j,f=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(b[i][j]=='.'){
                f = 1;
                break;
            }
        }
        if(f)break;
    }
    return f;
}
int insertval()
{
    int x;
    cout<<"Enter Location : ";
    fflush(stdout);
    cin>>x;
    return x;
}
//replaceval is uded to insert input to board.
void replaceval(int x,int y)
{
    int i,j,F = 0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(i*3 + j == x-1)
            {
                if(y == 0)
                {
                    b[i][j]='O';
                }
                else
                {
                    b[i][j]='X';
                }
                F = 1;
                break;
            }
        }
        if(F)break;
    }
}
int iswinner(int F)
{
    int flag = 0;
    if(F){
        if(b[0][0]=='X' && b[0][1]=='X' && b[0][2]=='X')
            {flag = 1;}
        else if(b[1][0]=='X' && b[1][1]=='X' && b[1][2]=='X')
            {flag = 1;}
        else if(b[2][0]=='X' && b[2][1]=='X' && b[2][2]=='X')
            {flag = 1;}
        else if(b[0][0]=='X' && b[1][0]=='X' && b[2][0]=='X')
            {flag = 1;}
        else if(b[0][1]=='X' && b[1][1]=='X' && b[2][1]=='X')
            {flag = 1;}
        else if(b[0][2]=='X' && b[1][2]=='X' && b[2][2]=='X')
            {flag = 1;}
        else if(b[0][0]=='X' && b[1][1]=='X' && b[2][2]=='X')
            {flag = 1;}
        else if(b[0][2]=='X' && b[1][1]=='X' && b[2][0]=='X')
            {flag = 1;}
    }
    else{
    if(b[0][0]=='O' && b[0][1]=='O' && b[0][2]=='O')
        {flag = 1;}
    else if(b[1][0]=='O' && b[1][1]=='O' && b[1][2]=='O')
        {flag = 1;}
    else if(b[2][0]=='O' && b[2][1]=='O' && b[2][2]=='O')
        {flag = 1;}
    else if(b[0][0]=='O' && b[1][0]=='O' && b[2][0]=='O')
        {flag = 1;}
    else if(b[0][1]=='O' && b[1][1]=='O' && b[2][1]=='0')
        {flag = 1;}
    else if(b[0][2]=='O' && b[1][2]=='O' && b[2][2]=='O')
        {flag = 1;}
    else if(b[0][0]=='O' && b[1][1]=='O' && b[2][2]=='O')
        {flag = 1;}
    else if(b[0][2]=='O' && b[1][1]=='O' && b[2][0]=='O')
        {flag = 1;}
    }
    return flag;
}
