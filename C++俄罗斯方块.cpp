// C俄罗斯方块.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "CManege.h"

int main()
{
	initgraph(300, 575);
	CManage MyGame;
	MyGame.InitGame();
	while (1)
	{
		MyGame.UpdateGame();
		MyGame.ShowGame();
		system("cls");
	}
	closegraph();

    return 0;
}

