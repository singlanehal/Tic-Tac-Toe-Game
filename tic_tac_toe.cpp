#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 3

char** create_board()
{
	char** board=(char**)malloc(SIZE*sizeof(char*));
	for(int i=0;i<SIZE;i++)
	{
		board[i]=(char*)malloc(SIZE*sizeof(char));
		memset(board[i],'-',SIZE);
	}
	return board;
}
void print_board(char** board)
{
	for(int i=0;i<SIZE;i++)
	{
		for(int j=0;j<SIZE;j++)
		{
			printf("%c",board[i][j]);
		}
		printf("\n");
	}
}
void free_board(char** board)
{
	for(int i=0;i<SIZE;i++)
	{
		free(board[i]);
	}
	free(board);
}
int check_win(char** board,char player)
{
	for(int i=0;i<SIZE;i++)
	{
		if(board[i][0]==player && board[i][1]==player && board[i][2]==player)
		{
			return 1;
		}
		if(board[0][i]==player && board[1][i]==player && board[2][i]==player)
		{
			return 1;
		}
	}
	if(board[0][0]==player && board[1][1]==player && board[2][2]==player)
	{
		return 1;
	}
	if(board[0][2]==player && board[1][1]==player && board[2][0]==player)
	{
		return 1;
	}
	return 0;
}
int update_board(char** board, int x,int y,char player)
{
	if(x<0 || x>=SIZE || y<0  || y>=SIZE)
	{
		return -1;
	}
	if(board[x][y]!='-')
	{
		return -1;
	}
	board[x][y]=player;
	return 0;
}

int main()
{
	char** board =create_board();
	int player=1;
	int x,y;
	while(1)
	{
		print_board(board);
		printf("player %d:",player);
		scanf("%d %d",&x,&y);
		x--;y--;
		if(update_board(board, x, y,player==1?'X':'0')==-1)
		{
			printf("INVALID MOVE");
			continue;
		}
		if(check_win(board,player==1?'X':'0')){
			printf("player %d wins!\n",player);
			break;
		}
		player=player==1?2:1;
	}
	free_board(board);
	return 0;
}
