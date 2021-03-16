#include <bits/stdc++.h>
using namespace std;
int n, m, k, x;

int qsm(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1)
      res = res * a % n;
    a = a * a % n;
    b >>= 1;
  }
  return res % n;
}

int main() {
  cin >> n >> m >> k >> x;
  cout << (x + m * qsm(10, k) % n) % n;
  return 0;
}