#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 5;
int sum[MAXN];

inline int read() {
  int x = 0, f = 1; //
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}

bool _isSquare(int x) {
  for (int i = 1; i <= 1000; i++) {
    if (i * i == x)
      return 1;
  }
  return 0;
}

int main() {
  int n = read();
  for (int i = 1; i <= n; i++) {
    int x = read();
    sum[i] = sum[i - 1] + x;
  }
  for ()
}