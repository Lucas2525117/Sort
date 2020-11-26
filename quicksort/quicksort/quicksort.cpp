// quicksort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void qSort(int* arr, int m, int n)
{
	int oldl = m;
	int oldr = n;
	bool bFlag = false;
	int tempArr = arr[oldl];

	while (m < n)
	{
		while ((m < n) && (arr[n] >= tempArr))
		{
			n--;
			bFlag = true;
		}

		arr[m] = arr[n];

		while ((m < n) && (arr[m] <= tempArr))
		{
			m++;
			bFlag = true;
		}

		arr[n] = arr[m];
	}

	arr[m] = tempArr;

	if (bFlag)
	{
		qSort(arr, oldl, m - 1);
		qSort(arr, m + 1, oldr);
	}
}

int main()
{
	int arr[]{ 23, 11, 25, 56, 17, 22, 45, 6, 78, 12, 43 };
	int iLen = sizeof(arr) / sizeof(arr[0]);
	qSort(arr, 0, iLen - 1);
	for (int i = 0; i < iLen; i++)
		cout << arr[i] << " ";

	system("pause");
    return 0;
}

