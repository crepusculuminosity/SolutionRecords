#include <bits/stdc++.h>
using namespace std;
int n;

inline int pow3(int n) {
  int res = 1;
  for (int i = 1; i <= n; i++)
    res *= 3;
  return res;
}
int main() {
  while (cin >> n)
    cout << pow3(n) - 1 << endl;
  return 0;
}