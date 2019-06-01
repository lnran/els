#include "stdafx.h"



CBlock::CBlock()
{
	_Empty();
	srand((unsigned)time(nullptr));
}


CBlock::~CBlock()
{
}

void CBlock::InitBlock()
{
	m_BlockType = rand() % 4;
	switch (m_BlockType)
	{
	case 0://³¤Ìõ
		m_BlockChangeType = rand() % 2;
		switch (m_BlockChangeType)
		{
		case 0:
			m_BlockArr[0].x = 3;
			m_BlockArr[0].y = 4;
			m_BlockArr[1].x = 3;
			m_BlockArr[1].y = 5;
			m_BlockArr[2].x = 3;
			m_BlockArr[2].y = 6;
			m_BlockArr[3].x = 3;
			m_BlockArr[3].y = 7;
			break;
		case 1:
			m_BlockArr[0].x = 4;
			m_BlockArr[0].y = 5;
			m_BlockArr[1].x = 3;
			m_BlockArr[1].y = 5;
			m_BlockArr[2].x = 2;
			m_BlockArr[2].y = 5;
			m_BlockArr[3].x = 1;
			m_BlockArr[3].y = 5;
			break;
		}
		break;
	case 1://Ìï×Ö
		m_BlockArr[0].x = 3;
		m_BlockArr[0].y = 5;
		m_BlockArr[1].x = 3;
		m_BlockArr[1].y = 6;
		m_BlockArr[2].x = 4;
		m_BlockArr[2].y = 5;
		m_BlockArr[3].x = 4;
		m_BlockArr[3].y = 6;
		break;
	case 2://Z×Ö
		m_BlockChangeType = rand() % 2;
		switch (m_BlockChangeType)
		{
		case 0:
			m_BlockArr[0].x = 3;
			m_BlockArr[0].y = 4;
			m_BlockArr[1].x = 3;
			m_BlockArr[1].y = 5;
			m_BlockArr[2].x = 4;
			m_BlockArr[2].y = 5;
			m_BlockArr[3].x = 4;
			m_BlockArr[3].y = 6;
			break;
		case 1:
			m_BlockArr[0].x = 4;
			m_BlockArr[0].y = 5;
			m_BlockArr[1].x = 3;
			m_BlockArr[1].y = 5;
			m_BlockArr[2].x = 3;
			m_BlockArr[2].y = 6;
			m_BlockArr[3].x = 2;
			m_BlockArr[3].y = 6;
			break;
		}
		break;
	case 3://L×Ö
		m_BlockChangeType = rand() % 4;
		switch (m_BlockChangeType)
		{
		case 0:
			m_BlockArr[0].x = 3;
			m_BlockArr[0].y = 5;
			m_BlockArr[1].x = 3;
			m_BlockArr[1].y = 6;
			m_BlockArr[2].x = 4;
			m_BlockArr[2].y = 6;
			m_BlockArr[3].x = 5;
			m_BlockArr[3].y = 6;
			break;
		case 1:
			m_BlockArr[0].x = 4;
			m_BlockArr[0].y = 6;
			m_BlockArr[1].x = 3;
			m_BlockArr[1].y = 6;
			m_BlockArr[2].x = 3;
			m_BlockArr[2].y = 7;
			m_BlockArr[3].x = 3;
			m_BlockArr[3].y = 8;
			break;
		case 2:
			m_BlockArr[0].x = 3;
			m_BlockArr[0].y = 7;
			m_BlockArr[1].x = 3;
			m_BlockArr[1].y = 6;
			m_BlockArr[2].x = 2;
			m_BlockArr[2].y = 6;
			m_BlockArr[3].x = 1;
			m_BlockArr[3].y = 6;
			break;
		case 3:
			m_BlockArr[0].x = 2;
			m_BlockArr[0].y = 6;
			m_BlockArr[1].x = 3;
			m_BlockArr[1].y = 6;
			m_BlockArr[2].x = 3;
			m_BlockArr[2].y = 5;
			m_BlockArr[3].x = 3;
			m_BlockArr[3].y = 4;
			break;
		}
		break;
	}

	
}
void CBlock::SetBlockChange()
{
	switch (m_BlockType)
	{
	case 0://³¤Ìõ
		switch (m_BlockChangeType)
		{
		case 0:
			m_BlockArr[0].x = m_BlockArr[1].x + 1;
			m_BlockArr[0].y = m_BlockArr[1].y;
			m_BlockArr[2].x = m_BlockArr[1].x - 1;
			m_BlockArr[2].y = m_BlockArr[1].y;
			m_BlockArr[3].x = m_BlockArr[1].x - 2;
			m_BlockArr[3].y = m_BlockArr[1].y;
			m_BlockChangeType = 1;
			break;
		case 1:
			m_BlockArr[0].x = m_BlockArr[1].x;
			m_BlockArr[0].y = m_BlockArr[1].y - 1;
			m_BlockArr[2].x = m_BlockArr[1].x;
			m_BlockArr[2].y = m_BlockArr[1].y + 1;
			m_BlockArr[3].x = m_BlockArr[1].x;
			m_BlockArr[3].y = m_BlockArr[1].y + 2;
			m_BlockChangeType = 0;
			break;
		}
		break;
	case 1://Ìï×Ö
		m_BlockArr[1].x = m_BlockArr[0].x;
		m_BlockArr[1].y = m_BlockArr[0].y + 1;
		m_BlockArr[2].x = m_BlockArr[0].x + 1;
		m_BlockArr[2].y = m_BlockArr[0].y;
		m_BlockArr[3].x = m_BlockArr[0].x + 1;
		m_BlockArr[3].y = m_BlockArr[0].y + 1;
		break;
	case 2://Z×Ö
		switch (m_BlockChangeType)
		{
		case 0:
			m_BlockArr[0].x = m_BlockArr[1].x + 1;
			m_BlockArr[0].y = m_BlockArr[1].y;
			m_BlockArr[2].x = m_BlockArr[1].x;
			m_BlockArr[2].y = m_BlockArr[1].y + 1;
			m_BlockArr[3].x = m_BlockArr[1].x - 1;
			m_BlockArr[3].y = m_BlockArr[1].y + 1;
			m_BlockChangeType = 1;
			break;
		case 1:
			m_BlockArr[0].x = m_BlockArr[1].x;
			m_BlockArr[0].y = m_BlockArr[1].y - 1;
			m_BlockArr[2].x = m_BlockArr[1].x + 1;
			m_BlockArr[2].y = m_BlockArr[1].y;
			m_BlockArr[3].x = m_BlockArr[1].x + 1;
			m_BlockArr[3].y = m_BlockArr[1].y + 1;
			m_BlockChangeType = 0;
			break;
		}
		break;
	case 3://L×Ö
		switch (m_BlockChangeType)
		{
		case 0:
			m_BlockArr[0].x = m_BlockArr[1].x + 1;
			m_BlockArr[0].y = m_BlockArr[1].y;
			m_BlockArr[2].x = m_BlockArr[1].x;
			m_BlockArr[2].y = m_BlockArr[1].y + 1;
			m_BlockArr[3].x = m_BlockArr[1].x;
			m_BlockArr[3].y = m_BlockArr[1].y + 2;
			m_BlockChangeType = 1;
			break;
		case 1:
			m_BlockArr[0].x = m_BlockArr[1].x;
			m_BlockArr[0].y = m_BlockArr[1].y + 1;
			m_BlockArr[2].x = m_BlockArr[1].x - 1;
			m_BlockArr[2].y = m_BlockArr[1].y;
			m_BlockArr[3].x = m_BlockArr[1].x - 2;
			m_BlockArr[3].y = m_BlockArr[1].y;
			m_BlockChangeType = 2;
			break;
		case 2:
			m_BlockArr[0].x = m_BlockArr[1].x - 1;
			m_BlockArr[0].y = m_BlockArr[1].y;
			m_BlockArr[2].x = m_BlockArr[1].x;
			m_BlockArr[2].y = m_BlockArr[1].y - 1;
			m_BlockArr[3].x = m_BlockArr[1].x;
			m_BlockArr[3].y = m_BlockArr[1].y - 2;
			m_BlockChangeType = 3;
			break;
		case 3:
			m_BlockArr[0].x = m_BlockArr[1].x;
			m_BlockArr[0].y = m_BlockArr[1].y - 1;
			m_BlockArr[2].x = m_BlockArr[1].x + 1;
			m_BlockArr[2].y = m_BlockArr[1].y;
			m_BlockArr[3].x = m_BlockArr[1].x + 2;
			m_BlockArr[3].y = m_BlockArr[1].y;
			m_BlockChangeType = 0;
			break;
		}
		break;
	}


}

void CBlock::SetBlockDown()
{
	for (int i = 0; i < BLOCK_NUM; i++)
		m_BlockArr[i].x++;
}

void CBlock::SetBlockLeft(bool isLeft)
{
	int index = 1;
	if (isLeft)
		index = -index;
	for (int i = 0; i < BLOCK_NUM; i++)
	{
		m_BlockArr[i].y += index;
	}
	//if (isLeft)
	//{
	//	for (int i = 0; i < BLOCK_NUM; i++)
	//	{
	//		m_BlockArr[i].y--;
	//	}
	//}
	//else
	//{
	//	for (int i = 0; i < BLOCK_NUM; i++)
	//	{
	//		m_BlockArr[i].y++;
	//	}
	//}
}



void CBlock::_Empty()
{
	memset(m_BlockArr, 0, sizeof(MyPos)*BLOCK_NUM);
}