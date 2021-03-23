#include <bits/stdc++.h>
using namespace std;
int main() {
  freopen("xxx.txt", "w", stdout); //打开文件,改一下文件名
  int a, b;
  int x, y, num = 0;
  ;
  cin >> x >> y;
  for (a = x; a <= y; a++) {
    for (b = 2; b <= sqrt(a); b++) {
      if (a % b == 0)
        break;
    }
    if (b > sqrt(a)) {
      cout << a << ",";
      num++;
    }
  }
  cout << endl << num;
  return 0;
}