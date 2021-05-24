#include <cstring>
#include <iostream>
const int maxn = 110;
int dp[maxn][maxn], a[maxn], n;
using namespace std;
inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9')
    ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + ch - 48, ch = getchar();
  return x;
}


int main() {
  memset(dp, -1, sizeof(dp));
  n = read();
  for (int i = 1; i <= n; i++)
    a[i] = read();
}