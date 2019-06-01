#include "stdafx.h"

CMAP::CMAP()
{
	_EmptyMap();
}

CMAP::~CMAP()
{
}

void CMAP::InitMap()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (i == 0 || i == ROW - 1 || j == 0 || j == COL - 1)
				m_MapArr[i][j] = 1;
			else
				m_MapArr[i][j] = 0;
		}
	}
}

void CMAP::ShowMap()
{
	BeginBatchDraw();
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			switch (m_MapArr[i][j])
			{
			case 0:
				//printf("  ");
				setfillcolor(RGB(0, 0, 0));
				setlinecolor(DARKGRAY);
				fillrectangle(j * 25, i * 25, (j + 1) * 25, (i + 1) * 25);
				break;
			case 1:
				setfillcolor(BROWN);
				setlinecolor(RGB(255, 255, 255));
				fillrectangle(j * 25, i * 25, (j + 1) * 25, (i + 1) * 25);
				break;
			case 2:
				setfillcolor(GREEN);
				setlinecolor(LIGHTGRAY);
				fillrectangle(j * 25, i * 25, (j + 1) * 25, (i + 1) * 25);
				break;
			}
		}
		printf("\n");
	}
	int sum = ClearBlock();
	char s[5];
	sprintf(s, "%d", sum);

	settextcolor(WHITE);
	settextstyle(15, 0, _T("ËÎÌå"));
	setbkmode(TRANSPARENT);
	outtextxy(0, 25*ROW, _T("·ÖÊý£º"));
	outtextxy(25 * 2, 25 * ROW, s);

	EndBatchDraw();
}

void CMAP::SetMapVal(int row, int col, int val)
{
	m_MapArr[row][col] = val;
}

void CMAP::_EmptyMap()
{
	memset(m_MapArr, 0, sizeof(char)*ROW*COL);
}

int CMAP::ClearBlock()
{
	int sum = 0;
	bool isClear = true;
	for (int i = ROW - 2; i >= 6; --i)
	{	
		isClear = true;
		for (int j = 1; j < COL - 1; ++j)
		{
			if (m_MapArr[i][j] != 2)
				isClear = false;
		}
		if (isClear)
		{
			sum++;
			for (int m = i; m >= 5; --m)
			{
				for (int n = 2; n < COL - 1; ++n)
				{
					m_MapArr[m][n] = m_MapArr[m - 1][n];
				}
				++i;
			}
		}
	}

	return sum;
}