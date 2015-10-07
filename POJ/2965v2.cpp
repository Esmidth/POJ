/*����һ��DFS+Enum*/



//Memory Time 
//240K  641MS 

//��������Ҫ���ÿ�η�ת�����ӣ���˲�������BFS��Ӧ��ʹ��DFS�������·��
#include"stdafx.h"
#include<iostream>
using namespace std;

bool lock[10][10] = { false };
bool flag;
int step;
int ri[16], cj[16];

bool isopen(void)
{
	for (int i = 3; i<7; i++)
		for (int j = 3; j<7; j++)
			if (lock[i][j] != true)
				return false;
	return true;
}

void flip(int row, int col)               //��ʵ�ο�POJ1753�ķ��巽��Ҳ�ǿ����������ģ����ǻᳬʱ��ͨ��
{                                        //��ʱ��ԭ����Ƿ���ʱ��̫�����Ĳ���
	lock[row][col] = !lock[row][col];      //POJ1753ʹ��6x6���Σ��������ֻ����Χ�ġ�һȦ�����壡
	for (int i = 3; i <= 6; i++)                //����ʹ��10x10���Σ���������С���Ȧ�����壡
		lock[i][col] = !lock[i][col];      //��ʵ��λ����Ϳ���ֻʹ��4x4���Σ���󽵵�ʱ�临�Ӷȣ�����û�ж�����������ǳ����ܸ��ӣ����ÿ�
	for (int j = 3; j <= 6; j++)
		lock[row][j] = !lock[row][j];
	return;
}

void dfs(int row, int col, int deep)
{
	if (deep == step)
	{
		flag = isopen();
		return;
	}

	if (flag || row == 7)return;

	flip(row, col);
	ri[deep] = row;
	cj[deep] = col;

	if (col<6)
		dfs(row, col + 1, deep + 1);
	else
		dfs(row + 1, 3, deep + 1);

	flip(row, col);
	if (col<6)
		dfs(row, col + 1, deep);
	else
		dfs(row + 1, 3, deep);
	return;
}

int main(void)
{
	char temp;
	int i, j;
	for (i = 3; i<7; i++)
		for (j = 3; j<7; j++)
		{
			cin >> temp;
			if (temp == '-')
				lock[i][j] = true;
		}

	for (step = 0; step <= 16; step++)
	{
		dfs(3, 3, 0);
		if (flag)break;
	}

	cout << step << endl;
	for (i = 0; i<step; i++)
		cout << ri[i] - 2 << ' ' << cj[i] - 2 << endl;
	return 0;
}