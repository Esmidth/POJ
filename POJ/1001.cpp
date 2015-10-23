#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;


int main()
{
	double R;
	int n;
	long double result;
	while (std::cin >> R >> n && R != 0){
		result = R;
		/*
		for (int i = 0; i < n-1; i++)
			result = result * R;
			*/
		result = pow(R, n);
		printf("%lf", result);
	}
	system("pause");
	return 0;
}