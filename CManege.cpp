#include "stdafx.h"

CManage::CManage()
{
	m_fSpeed = m_begTime = m_endTime = 0.0f;
	m_Gamelv = 2;
}

CManage::~CManage()
{
}

void CManage::InitGame()
{
	SetGameSpeed();
	m_MapDate.InitMap();
	m_BlockDate.InitBlock();
	m_begTime = timeGetTime() / 1000.0f;
	
}

void CManage::UpdateGame()
{
	//���㣬�ƶ�������(�䲻������)��д���·���
	_GetKey();
	MyPos const* temp = m_BlockDate.GetBlockHead();
	//����
	for (int i = 0; i < BLOCK_NUM; i++)
		m_MapDate.SetMapVal((temp + i)->x, (temp + i)->y, 0);
	m_endTime = timeGetTime() / 1000.0f;

	//�ƶ�
	switch (key)
	{
	case 'w':
	case 'W':
	{
		bool isChange = true;
		switch (m_BlockDate.GetBlockType())
		{
		case 0://����
			switch (m_BlockDate.GetBlockChangeType())
			{
			case 0:
				if (m_MapDate.GetMapVal((temp + 0)->x + 1, (temp + 0)->y) != 0
					|| m_MapDate.GetMapVal((temp + 1)->x + 1, (temp + 1)->y) != 0
					|| m_MapDate.GetMapVal((temp + 1)->x - 1, (temp + 1)->y) != 0
					|| m_MapDate.GetMapVal((temp + 1)->x - 2, (temp + 1)->y) != 0
					|| m_MapDate.GetMapVal((temp + 2)->x - 1, (temp + 2)->y) != 0
					|| m_MapDate.GetMapVal((temp + 2)->x - 2, (temp + 2)->y) != 0
					|| m_MapDate.GetMapVal((temp + 3)->x - 1, (temp + 3)->y) != 0)
					isChange = false;

				break;
			case 1:
				if (m_MapDate.GetMapVal((temp + 0)->x, (temp + 0)->y - 1) != 0
					|| m_MapDate.GetMapVal((temp + 1)->x, (temp + 1)->y - 1) != 0
					|| m_MapDate.GetMapVal((temp + 1)->x, (temp + 1)->y + 1) != 0
					|| m_MapDate.GetMapVal((temp + 1)->x, (temp + 1)->y + 2) != 0
					|| m_MapDate.GetMapVal((temp + 2)->x, (temp + 2)->y + 1) != 0
					|| m_MapDate.GetMapVal((temp + 2)->x, (temp + 2)->y + 2) != 0
					|| m_MapDate.GetMapVal((temp + 3)->x, (temp + 3)->y + 1) != 0)
					isChange = false;
				break;
			}
			break;
		case 1://����
			//����
			break;
		case 2://Z��
			switch (m_BlockDate.GetBlockChangeType())
			{
			case 0:
				if (m_MapDate.GetMapVal((temp + 0)->x + 1, (temp + 0)->y) != 0
					|| m_MapDate.GetMapVal((temp + 1)->x, (temp + 1)->y + 1) != 0
					|| m_MapDate.GetMapVal((temp + 1)->x - 1, (temp + 1)->y + 1) != 0  
					)
					isChange = false;
				break;
			case 1:
				if (m_MapDate.GetMapVal((temp + 0)->x, (temp + 0)->y - 1) != 0
					|| m_MapDate.GetMapVal((temp + 1)->x, (temp + 1)->y - 1) != 0
					|| m_MapDate.GetMapVal((temp + 2)->x + 1, (temp + 2)->y) != 0
					)
					isChange = false;
				break;
			}
			break;
		case 3://L��
			switch (m_BlockDate.GetBlockChangeType())
			{
			case 0:
				if (m_MapDate.GetMapVal((temp + 0)->x + 1, (temp + 0)->y) != 0
					|| m_MapDate.GetMapVal((temp + 1)->x, (temp + 1)->y + 1) != 0
					|| m_MapDate.GetMapVal((temp + 1)->x, (temp + 1)->y + 2) != 0
					|| m_MapDate.GetMapVal((temp + 2)->x, (temp + 2)->y + 1) != 0
					|| m_MapDate.GetMapVal((temp + 2)->x, (temp + 2)->y + 2) != 0
					|| m_MapDate.GetMapVal((temp + 3)->x, (temp + 3)->y + 1) != 0
					)
				isChange = false;
				break;
			case 1:
				if (m_MapDate.GetMapVal((temp + 0)->x, (temp + 0)->y + 1) != 0
					|| m_MapDate.GetMapVal((temp + 1)->x - 1, (temp + 1)->y) != 0
					|| m_MapDate.GetMapVal((temp + 1)->x - 2, (temp + 1)->y) != 0
					|| m_MapDate.GetMapVal((temp + 2)->x - 1, (temp + 2)->y) != 0
					|| m_MapDate.GetMapVal((temp + 2)->x - 2, (temp + 2)->y) != 0
					|| m_MapDate.GetMapVal((temp + 3)->x - 1, (temp + 3)->y) != 0
					)
					isChange = false;
				break;
			case 2:
				if (m_MapDate.GetMapVal((temp + 0)->x - 1, (temp + 0)->y) != 0
					|| m_MapDate.GetMapVal((temp + 1)->x, (temp + 1)->y - 1) != 0
					|| m_MapDate.GetMapVal((temp + 1)->x, (temp + 1)->y - 2) != 0
					|| m_MapDate.GetMapVal((temp + 2)->x, (temp + 2)->y - 1) != 0
					|| m_MapDate.GetMapVal((temp + 2)->x, (temp + 2)->y - 2) != 0
					|| m_MapDate.GetMapVal((temp + 3)->x, (temp + 3)->y - 1) != 0
					)
					isChange = false;
				break;
			case 3:
				if (m_MapDate.GetMapVal((temp + 0)->x, (temp + 0)->y - 1) != 0
					|| m_MapDate.GetMapVal((temp + 1)->x + 1, (temp + 1)->y) != 0
					|| m_MapDate.GetMapVal((temp + 1)->x + 2, (temp + 1)->y) != 0
					|| m_MapDate.GetMapVal((temp + 2)->x + 1, (temp + 2)->y) != 0
					|| m_MapDate.GetMapVal((temp + 2)->x + 2, (temp + 2)->y) != 0
					|| m_MapDate.GetMapVal((temp + 3)->x + 1, (temp + 3)->y) != 0
					)
					isChange = false;
				break;
			}
			break;
		}
		if (isChange)
			m_BlockDate.SetBlockChange();
	}
		
		key = 0;
		break;
	case 'a':
	case 'A':
		if (isMove(0, -1))
			m_BlockDate.SetBlockLeft();
		key = 0;
		break;
	case 'd':
	case 'D':
		if (isMove(0, 1))
			m_BlockDate.SetBlockLeft(false);
		key = 0;
		break;
	case 's':
	case 'S':
		for (int i = 0; i < 2; i++)
		{
			if (isMove(1, 0))
				m_BlockDate.SetBlockDown();
			else
				break;
		}
		key = 0;
		break;
	}
	
	//����
	if (m_endTime - m_begTime >= m_fSpeed)
	{
		if (isMove(1, 0))
			m_BlockDate.SetBlockDown();
		else
		{
			for (int i = 0; i < BLOCK_NUM; i++)
				m_MapDate.SetMapVal((temp + i)->x, (temp + i)->y, 2);
			//����
			m_MapDate.ClearBlock();
			////����֮ǰ����
			//setbkmode(OPAQUE);
			//settextcolor(BLACK);
			//outtextxy(25 * 2, 25 * ROW, " ");
	

			m_BlockDate.InitBlock();
		}
		m_begTime = m_endTime;
	}
	
	//д���·���
	for (int i = 0; i < BLOCK_NUM; i++)
		m_MapDate.SetMapVal((temp + i)->x, (temp + i)->y, 2);



}

void CManage::ShowGame()
{
	m_MapDate.ShowMap();
}

void CManage::SetGameSpeed()
{
	switch (m_Gamelv)
	{
	case 1:
		m_fSpeed = 1.0f;
		break;
	case 2:
		m_fSpeed = 0.6f;
		break;
	case 3:
		m_fSpeed = 0.2f;
		break;
	}

}

bool CManage::isMove(int row0xff, int col0xff)
{
	MyPos const* temp = m_BlockDate.GetBlockHead();
	bool isMove = true;
	for (int i = 0; i < BLOCK_NUM; i++)
	{
		if (m_MapDate.GetMapVal((temp + i)->x + row0xff, (temp + i)->y + col0xff) != 0)
		{
			isMove = false;
			break;
		}
	}
	return isMove;
}

void CManage::_GetKey()
{
	if (_kbhit())
		key = _getch();
}