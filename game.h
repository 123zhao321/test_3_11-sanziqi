#pragma once
#include <time.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
//棋盘的行数 默认为 3 ，可以修改数字，有其他的玩法哦
#define row 10
//棋盘的列数 默认为 3
#define col 10
//打印菜单
void menu();
//进入游戏
void game();
//玩家是 * 棋
//电脑是 # 棋
//win * 玩家赢了
//win # 电脑赢了
//win Q 平局
//win 0 游戏继续