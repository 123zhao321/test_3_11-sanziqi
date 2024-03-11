#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

char board[row][col];
char ch;
//菜单
void menu()
{
	printf("############################\n");
	printf("####### 1 开始游戏  ########\n");
	printf("####### 0 退出游戏  ########\n");
	printf("############################\n");
	printf("请输入数字开始游戏：\n");
}
//清理棋盘
void clean_board()
{
	int i;
	for (i = 0; i < row; i++)
	{
		int j;
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
//画棋盘
void draw_board()
{
	int i;
	int j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j != row - 1)
				printf("|");
		}
		printf("\n");
		for (j = 0; j < col && i != row - 1; j++)
		{
			printf("---");
			if (j != row - 1)
				printf("|");
		}
		printf("\n");
	}
}
//将玩家信息输入到棋盘
void play1(int i, int j)
{
	while (1)
	{
		if (board[i][j] != ' ')
		{
			printf("坐标非法，请重新输入>");
			scanf("%d %d", &i, &j);
			i--;
			j--;
		}
		else
		{
			board[i][j] = '*';
			break;
		}
	}
}
//电脑下棋
void play2()
{
	while (1)
	{
		int i = rand() % row;
		int j = rand() % row;
		if (board[i][j] == ' ')
		{
			board[i][j] = '#';
			break;
		}
	}
}
//游戏状态
char win()
{
	int i, j;
	int count = 0;
	//行判断
	for (i = 0; i < row; i++)
	{
		int count1 = 0;
		int count2 = 0;
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == '*')
			{
				count1++;
				count++;
			}
			if (board[i][j] == '#')
			{
				count2++;
				count++;
			}
		}
		if (count1 == row)
		{
			return '*';
		}
		else if (count2 == row)
		{
			return '#';
		}
	}
	if (count == row * col)
	{
		return 'Q';
	}
	//列判断
	count = 0;
	for (i = 0; i < row; i++)
	{
		int count1 = 0;
		int count2 = 0;
		for (j = 0; j < col; j++)
		{
			if (board[j][i] == '*')
			{
				count1++;
				count++;
			}
			if (board[j][i] == '#')
			{
				count2++;
				count++;
			}
		}
		if (count1 == row)
		{
			return '*';
		}
		else if (count2 == row)
		{
			return '#';
		}
	}
	if (count == row * col)
	{
		return 'Q';
	}
	//对角判断
	int count1 = 0;
	int count2 = 0;
	for (i = 0; i < row; i++)// "\"
	{
		if (board[i][i] == '*')
		{
			count1++;
		}
		if (board[i][i] == '#')
		{
			count2++;
		}
		if (count1 == row)
		{
			return '*';
		}
		else if (count2 == row)
		{
			return '#';
		}
	}
	count1 = 0;
	count2 = 0;
	for (i = 0; i < row; i++)// "/"
	{
		if (board[i][row - 1 - i] == '*')
		{
			count1++;
		}
		if (board[i][row - 1 - i] == '#')
		{
			count2++;
		}
		if (count1 == row)
		{
			return '*';
		}
		else if (count2 == row)
		{
			return '#';
		}
	}
	return 0;
}
//游戏核心
void game()
{
	//先清理棋盘
	clean_board();
	//打印棋盘
	draw_board();
	//开始下棋
	while (1)
	{
		//玩家下棋
		printf("请玩家输入下棋的坐标> ");
		int i, j;
		scanf("%d %d", &i, &j);
		//将坐标传给棋盘
		play1( i - 1, j - 1);
		draw_board();
		ch = win();
		if (ch == '*')
		{
			printf("玩家赢了！\n");
			break;
		}
		else if (ch == '#')
		{
			printf("电脑赢了！\n");
			break;
		}
		else if (ch == 'Q')
		{
			printf("--平局--\n");
			break;
		}
		//电脑下棋
		printf("电脑下棋>\n");
		play2();
		draw_board();
		ch = win();
		if (ch == '*')
		{
			printf("玩家赢了！\n");
			break;
		}
		else if (ch == '#')
		{
			printf("电脑赢了！\n");
			break;
		}
		else if (ch == 'Q')
		{
			printf("--平局--\n");
			break;
		}
	}
}