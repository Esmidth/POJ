#include "stdafx.h"
#include<iostream>
using namespace std;

int main(void)
{
	   int p[21] = { 0 };      //ʹ  p[0]=0  
	    int w[20];
	int str[40];     //���Ŵ�����0��1  
	int n;
	
int cases;
	cin >> cases;
	while (cases--)
		{
		memset(str, 0, sizeof(str));   //str����ʼ��Ϊȫ0  
		
			cin >> n;
		
			int i, j, k;
		
			/*Input P-sequence*/
			
			for (i = 1; i <= n; i++)
			cin >> p[i];
		
			/*Convert the P-sequence to the string of parenthesese*/
			
			for (j = 0, i = 1; i <= n; i++)        //��P����ת��Ϊ01��������Ϊ0������Ϊ1  
			for (k = 0;; k++)
			if (k<p[i] - p[i - 1])    //��ÿ������Ϊ�յ㣬�����Ŵ��ֳɶ��01�Ӵ����Ӵ����ȫ��0���ұ�ֻ��Ψһ��1.ÿ���Ӵ����ٺ�һ��1��  
			                    j++;              //kΪ�����Ӵ���ָ�룬jΪstr����ָ��  
		               else if (k == p[i] - p[i - 1])
			{
			str[j++] = 1;
			break;
			}
		
			const int length = j;   //str����  
		
			        /*Convert the string of parenthesese to the W-sequence*/
			
			        int count;
		       for (i = 0; i<length; i++)    //str����W����ת��  
			            if (str[i] == 1)      //��str������1���������ͻ��ݣ��ҳ����������0��������  
			            {
			                count = 2; //��������ʼ��Ϊ2����Ϊ��ǰ����Ѱ�ҵ���Ե�01���û�Ϊ����'F'  
			               for (j = i - 1;; j--)
				                {
				                   if (str[j] == 0)
					                    {
					                        str[i] = str[j] = 'F';  //01��Ժ�Ͷ���Ϊ'F'  
					                        break;
					                    }
				                   else
					                        count++; //�ڻ�����0�Ĺ����У�ÿ����һ��F����������+1  
				                }
			                cout << count / 2 << ' ';  //�������ĸ������ǵ�ǰ ���Ŷ� �������� ���Ŷ� (������ǰ���Ŷ�)����������  
			            }
		       cout << endl;
	}
	return 0;
}
