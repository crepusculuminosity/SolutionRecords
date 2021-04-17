#include <bits/stdc++.h>
using namespace std;

int main()
{
	int arr[11];
	arr[5] = arr[7] = 0;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	arr[4] = 8;
	for (int i = 6; i <= 10; ++i){
		if (i != 7)arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3] + arr[i - 4];
	}
	cout << arr[10] << endl;
	return 0;
}
