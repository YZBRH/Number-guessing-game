#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void game(difficulty,goal)
{
	int guess = 0;//玩家猜的数
	int time = 0;//记录次数
	int key = 1;//初始化
	system("cls");//清屏

	switch (difficulty)
	{
	case 1:
	{
		key = rand() % 100 + 1;
		printf("简单模式随机数已成功生成\n");
		break;
	}
	case 2:
	{
		key = rand() % 1000 + 1;
		printf("普通模式随机数已成功生成\n");
		break;
	}
	case 3:
	{
		key = rand();
		printf("困难模式随机数已成功生成\n");
		break;
	}
	default :
	{
		printf("难度设置出错，难度自动调整至简单难度\n");
		key = rand() % 100 + 1;
		break;
	}
	}//随机数生成部分

	while (goal >= 1)
	{
		printf("当前目标为 %d 次猜出谜底\n", goal);
		break;
	}//当设置了目标时，提示玩家
	printf("游戏正式开始，请输入你所猜的数字:>>");
	while (1)
	{
		scanf("%d", &guess);
		if (guess == -1)
		{
			time++;
			printf("谜底是%d\n", key);
			continue;
		}//测试用后门
		else if (guess > key)
		{
			printf("猜大了，再试试吧:>>");
			time++;
			continue;
		}
		else if (guess < key)
		{
			printf("猜小了，再试试吧:>>");
			time++;
			continue;
		}
		else
		{
			time++;
			printf("猜对了，谜底即为%d\n你一共尝试了%d次\n", key, time);
			while (goal >= 1)
			{
				if (time <= goal)
				{
					printf("成功完成目标！！！\n");
					break;
				}
				else
				{
					printf("很遗憾没有完成目标......\n");
					break;
				}
			}//判断目标是否完成
			break;
		}
	}
}//游戏主体


int main()
{
	int a = 1;//控制循环
	srand((unsigned int)time(NULL));//随机数生成预备
	int main_mune = 0;//控制主菜单
	static int difficulty = 1;//难度控制
	int goal = 0;//目标设置

begin:
	printf("**********************\n");
	printf("*****猜数字小游戏*****\n");
	printf("**********************\n");
	printf("******1.开始游戏******\n");
	printf("******2.难度选择******\n");
	printf("******3.设置目标******\n");
	printf("******4.退出游戏******\n");
	printf("**********************\n");

	printf("请输入数字以执行相关操作:>");
	scanf("%d", &main_mune);

	do
	{
		switch (main_mune)
		{
		case 1:
		{
			printf("游戏开始，祝游戏愉快\n");
			game(difficulty, goal);

			printf("还想再玩一次吗？输入1以确认,输入2以调整难度，输入3以更改目标，输入其他数字以退出游戏:>>");
			int want = 0;
			scanf("%d", &want);
			if (want == 1)
			{
				main_mune = 1;
			}
			else if (want == 2)
			{
				main_mune = 2;
			}
			else if (want == 3)
			{
				main_mune = 3;
			}
			else
			{
				main_mune = 4;
			}//跳转指定菜单

			break;
		}//再来一次功能
		case 2:
		{
			printf("**********************\n");
			printf("*******难度选择*******\n");
			printf("**********************\n");
			printf("******1.简单难度******\n");
			printf("******2.普通难度******\n");
			printf("******3.困难难度******\n");
			printf("**********************\n");
			//难度菜单
			printf("请输入数字以执行相关操作:>");
			scanf("%d", &difficulty);
			int b = 1;//控制循环

			do
			{
				switch (difficulty)
				{
				case 1:
				{
					printf("当前为简单难度\n");
					b = 0;
					main_mune = 1;
					break;
				}
				case 2:
				{
					printf("当前为普通难度\n");
					b = 0;
					main_mune = 1;
					break;
				}
				case 3:
				{
					printf("当前为困难难度\n");
					b = 0;
					main_mune = 1;
					break;
				}
				default:
				{
					printf("难度设置无效，请重试\n");
					printf("请输入数字以执行相关操作:>");
					scanf("%d", &difficulty);
					continue;

				}
				}
			} while (b == 1);//难度选择判断
			break;
		}
		case 3:
		{
			printf("请输入所设置的目标:>>");
			scanf("%d", &goal);
			if (goal <= 0)
			{
				while (goal <= 0);
				{
					printf("无效输入，请重新输入:>>");
					scanf("%d", &goal);
				}//排除goal为负数和0的情况
			}
			printf("设置成功！当前目标为 %d 次内猜出谜底\n", goal);
			goto begin;
		}//目标设置部分

		case 4:
		{
			printf("游戏已退出，期待与您的下次相逢\n");
			a = 0;
			break;//退出游戏
		}
		default:
		{
			printf("无效输入，请重试:>>");
			scanf("%d", &main_mune);
			continue;
		}//主菜单选择判定
		}
	}
	while (a == 1);

	return 0;
}//主函数

