#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

int main()
{
	srand((unsigned)time(NULL));
	int choose;
	//打印菜单让用户选择
	do
	{
	menu();
	scanf("%d",&choose);//1开始游戏 0退出游戏 其他数字是无效的
		switch (choose)
		{
			//开始游戏啦
			case 1:
				printf("开始游戏啦!小Z正在画棋盘哦~\n");
				//Sleep(1000);//缓冲时间
				system("cls");
				game();
				break;
			case 0:
				printf("游戏结束~\n");
				break;
			default:
				printf("是无效数字请重新输入：\n");
				break;
		}
	} while (choose);
	
	return 0;
}