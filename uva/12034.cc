#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1010;
constexpr int mod = 10056;
int f[maxn];
int C[maxn][maxn];

void init() {
  C[1][1] = C[1][0] = 1;

  for (int i = 2; i < maxn; i++)
    for (int j = 0; j <= i; j++)
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;

  f[0] = 1, f[1] = 1, f[2] = 3;
  for (int i = 3; i < maxn; i++) {
    for (int j = 1; j <= i; j++)
      f[i] = (f[i] + C[i][j] * f[i - j] % mod) % mod;
  }
}

int main() {
  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  init();
  int _, kse = 1;
  scanf("%d", &_);
  while (_--) {
    int n;
    scanf("%d", &n);
    printf("Case %d: %d\n", kse++, f[n]);
  }
  return 0;
}