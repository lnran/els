#pragma once
#define ROW 22
#define COL 12
class CMAP
{
public:
	CMAP();
	~CMAP();
	void InitMap();
	void ShowMap();
	void SetMapVal(int row, int col, int val);
	int ClearBlock();
public:
	int GetMapVal(int row, int col)const { return m_MapArr[row][col]; }
private:
	void _EmptyMap();
private:
	char m_MapArr[ROW][COL];

};

