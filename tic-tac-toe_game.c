#include<stdio.h>

char board[3][3];


void pintboard()
{
    printf("\b");
    printf(" %c | %c | %c \n",board[0][0],board[0][1],board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n",board[1][0],board[1][1],board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n",board[2][0],board[2][1],board[2][2]);
    printf("\n");
}

void resetboard()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            board[i][j]=' ';
        }
    }
}

int checkfreespace()
{
    int freespace=9;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j]!=' ')
            freespace--;
        }
    }
    return freespace;
}

char checkwinner()
{
    for(int i=0;i<3;i++)
    {
        if(board[i][0]==board[i][1] && board[i][0]==board[i][2] && board[i][0]!=' ')
        {
            return board[i][0];
        }
    }

    for(int i=0;i<3;i++)
    {
        if(board[0][i]==board[1][i] && board[0][i]==board[2][i] && board[0][i]!=' ')
        {
            return board[0][i];
        }
    }

    if(board[0][0]==board[1][1] && board[0][0]==board[2][2] && board[0][0]!=' ')
    {
        return board[0][0];
    }

    if(board[0][2]==board[1][1] && board[0][2]==board[2][0] && board[0][2]!=' ')
    {
        return board[0][2];
    }

    return ' ';


}


int main()
{
    int row,col;
    char winner=' ';
    char currentplayer='X';

    resetboard();

    printf("tic-tac-toe game: ");
    printf("player 1:X & player 2:O\n");

    while(winner==' ' && checkfreespace()!=0)
    {
        pintboard();

        printf("player %c, enter move(row(1-3) & col(1-3)): ",currentplayer);
        scanf("%d%d",&row,&col);
    
       row--;
       col--;

       if(row>=0&&row<3&&col>=0&&col<3&&board[row][col]==' ')
       {
        board[row][col]=currentplayer;
        winner=checkwinner();
       
       
       if(winner==' ')
       {
        currentplayer=(currentplayer=='X') ? 'O' : 'X';
       }
    }
    else
    {
        printf("invalid move! try again\n");
    }
       
    }
    
    pintboard();
    if(winner!=' ')
    {
        printf("winner is %c\n",winner);
    }
    else
    {
        printf("its a draw\n");
    }

    return 0;
}