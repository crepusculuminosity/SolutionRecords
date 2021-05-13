#include <bits/stdc++.h>
using namespace std;
int f[40];

void init() {
  f[3] = 1, f[4] = 3;
  for (int i = 5; i <= 30; i++)
    f[i] = f[i - 1] * 2 + (1 << i - 4) - f[i - 4];
}

int main() {
  init();
  int n;
  while (cin >> n && n) {
    cout << f[n] << '\n';
  }
  return 0;
}