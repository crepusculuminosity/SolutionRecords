#include <bits/stdc++.h>
#define register
#define IL inline
#define Fill(a, b) memset(a, b, sizeof(a))
using namespace std;
typedef long long ll;
const int Zsy(1e9 + 7);

IL ll Input() {
  ll x = 0, z = 1;
  char c = getchar();
  for (; c < '0' || c > '9'; c = getchar())
    z = c == '-' ? -1 : 1;
  for (; c >= '0' && c <= '9'; c = getchar())
    x = (x << 1) + (x << 3) + (c ^ 48);
  return x * z;
}

int k, c[16], C[80][80], f[20][80], sum[16];

IL void Prepare() {
  C[0][0] = 1;
  for (int i = 1; i <= 75; ++i) {
    C[i][0] = 1;
    for (int j = 1; j <= 75; ++j)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % Zsy;
  }
}

int main(int ac, char *av[]) {
  freopen("data.in", "r", stdin);
  Prepare();
  k = Input();
  for (int i = 1; i <= k; ++i)
    c[i] = Input(), sum[i] = sum[i - 1] + c[i];
  f[1][c[1] - 1] = 1;
  for (int i = 1; i < k; ++i)
    for (int j = 0; j < sum[i]; ++j) {
      if (!f[i][j])
        continue;
      for (int a = 1; a <= c[i + 1]; ++a)
        for (int b = 0; b <= a && b <= j; ++b) {
          int ret =
              1LL * f[i][j] * C[c[i + 1] - 1][a - 1] % Zsy * C[j][b] % Zsy;
          ret = 1LL * ret * C[sum[i] + 1 - j][a - b] % Zsy;
          (f[i + 1][j + c[i + 1] - a - b] += ret) %= Zsy;
        }
    }
  printf("%d\n", f[k][0]);
  return 0;
}
