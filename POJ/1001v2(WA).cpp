//High precision double
//Big Integer
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>

using namespace std;

struct arrays
{
	//dot == 2,after the 2nd number
	vector<int> num;
	int dot;
};

arrays input(string ori)
{
	arrays temp;
	int i = 0;
	while(ori[i] != '\0')
	{
		if(ori[i] == '.')
		{
			temp.dot = i;
		}
		else
		{
			temp.num.push_back(ori[i] - '1' + 1);
		}
		i++;
	}
	return temp;
}

void output(arrays a)
{
	bool zero = false;
	while(a.num[a.num.size()-1] == 0)
	{
		a.num.pop_back();
	}
	if(a.num[0] == 0)
	{
		zero = true;
	}
	
	for (int i = 0; i < a.num.size();i++)
	{
		if(a.dot == i)
		{
			cout << ".";
			zero = false;
		}
		if(a.num[i] == 0 && zero)
		{
		}
		else
		{
			cout << a.num[i];
			zero = false;
		}
	}
	cout << endl;
}

arrays mulitply(arrays& result,arrays &R)
{
	arrays temp;
	temp.dot = result.dot + R.dot;
	int size = result.num.size() + R.num.size();
	/*
	if((result.num[0]*10 + result.num[1])*R.num[0] > 99)
	{
		size++;
	}
	*/
	for (int i = 0; i < size;i++)
	{
		temp.num.push_back(0);
	}
	int R_size = R.num.size();
	int result_size = result.num.size();
	int k = 0;
	for (int i = R_size-1; i != -1;i--)
	{
		size = temp.num.size() - k;
		for (int j = result_size -1; j != -1;j--)
		{
			int tt = result.num[j] * R.num[i];
			/*
			if (tt > 9)
			{
				temp.num[size-1] += tt % 10;
				temp.num[size-2] += tt / 10;
			}
			else {
				temp.num[size-1] += tt;
			}
			*/
			temp.num[size - 1] += tt;
			size--;
		}
		k++;
	}
	for (int i = temp.num.size() - 1; i != -1;i--)
	{
		if(temp.num[i] > 9)
		{
			temp.num[i - 1] += temp.num[i] / 10;
			temp.num[i] = temp.num[i] % 10;
		}
	}
	return temp;
}

arrays mul(arrays a,int b)
{
	arrays re_arrays = a;
	for (int i = 0; i < b - 1;i++)
	{
		re_arrays = mulitply(re_arrays, a);
	}
	return re_arrays;
}
/*
void testOutput()
{
	arrays test_arrays;
	test_arrays.num = { 1,0,8,4,5 };
	test_arrays.dot = 2;
	output(test_arrays);

}
void testMultiply()
{
	arrays result = { {9,5,1,2,3},2 };
	arrays R = { {9,5,1,2,3},2 };
	arrays R1 = { {5,1,2,3,4},1 };
	arrays R2 = { {0,4,3,2,1},1 };
	output(R2);
	output(mul(R2, 20));
	cout << ".00000005148554641076956121994511276767154838481760200726351203835429763013462401" << endl;
}
*/
int main()
{
	cout << "V2" << endl;
	string R;
	int n;
	while(scanf("%s%n",&R,&n) != EOF)
	{
		output(mul(input(R), n));
	}
	//system("pause");
}