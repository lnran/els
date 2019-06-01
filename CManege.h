#pragma once
class CManage
{
public:
	CManage();
	~CManage();
	void InitGame();
	void UpdateGame();
	void ShowGame();
public:
	void SetGameSpeed();
	bool isMove(int row0xff, int col0xff);
private:
	void _GetKey();
private:
	CMAP	m_MapDate;
	CBlock	m_BlockDate;
private:
	float	m_fSpeed;
	float	m_begTime;
	float	m_endTime;
	int		m_Gamelv;
	char	key;
};

