#pragma once
#define BLOCK_NUM 4
struct MyPos
{
	int x, y;
};
class CBlock
{
public:
	CBlock();
	~CBlock();
	void InitBlock();
	void SetBlockDown();
	void SetBlockLeft(bool isLeft = true);
	void SetBlockChange();
	MyPos const* GetBlockHead() const { return m_BlockArr; }
	int GetBlockChangeType() const { return m_BlockChangeType; }
	int GetBlockType() const { return m_BlockType; }
private:
	void _Empty();
private:
	MyPos	m_BlockArr[BLOCK_NUM];
	int		m_BlockChangeType;	//�������ת���
	int		m_BlockType;		//��������7�����ֵ�

};

