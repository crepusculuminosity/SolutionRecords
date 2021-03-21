#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5010;
int sum[MAXN][MAXN];
int x, y, v;

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

int main() {
  int n = read(), r = read();
  int x, y, v;
  for (int i = 1; i <= n; i++)
    x = read(), y = read(), v = read(), a[x + 1][y + 1] = v;
  for (int i = 1; i < MAXN; i++) {
    for (int j = 1; j < MAXN; j++) {
    }
  }
}