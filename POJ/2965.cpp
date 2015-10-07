//The Pilots Brothers' refrigerator
#include "stdafx.h"
#include <iostream>
#include <queue>
#include <sstream>
//Time Start: 14:42 10.2.2015
using namespace std;
struct Node
{
	vector<vector<int>> ve;
	string log = "";
	int times;
	int lasti;
	int lastj;
	bool operator==(Node a)
	{
		return ve == a.ve;
	}
	bool operator!=(Node a)
	{
		return !(ve == a.ve);
	}
};
void display(vector<vector<int>> & a)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << a[i][j];
		}
		cout << endl;
	}
}

Node opera(Node a,int i,int j)
{
	//i--;
	//j--;
	a.ve[i][j] = !a.ve[i][j];
	for (int ii = 0; ii < 4;ii++)
	{
		a.ve[ii][j] = !a.ve[ii][j];
	}
	for (int jj = 0; jj < 4;jj++)
	{
		a.ve[i][jj] = !a.ve[i][jj];
	}
	stringstream ss;
	ss << i << " " << j << "\n";
	a.log += ss.str();
	a.lasti = i;
	a.lastj = j;
	a.times++;
	return a;
}

int main()
{
	Node start, end;
	start.ve = { { 0,1,0,0 },{ 0,0,0,0 },{ 0,0,0,0 },{ 0,1,0,0 } };
	start.times = 0;
	start.lasti = 99;
	start.lastj = 99;
	end.ve = { { 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } };
	//display(start.ve);
	//display(opera(start.ve, 0, 1));
	queue<Node> qu;
	qu.push(start);
	cout << !(qu.front() == end);
	while(qu.front() != end)
	{
		for (int i = 0; i < 4;i++)
		{
			for (int j = 0; j < 4;j++)
			{
				if(i == qu.front().lasti && j == qu.front().lastj)
				{
					
				}
				else {
					qu.push(opera(qu.front(), i, j));
				}
			}
		}
		qu.pop();
	}
	cout << qu.front().times << endl;
	cout << qu.front().log << endl;
	int pause;
	cin >> pause;
}