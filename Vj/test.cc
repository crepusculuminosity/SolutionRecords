#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;
const int MOD = 1e9 + 7;
int f[N + 1];

void init() {
  f[0] = 1;
  f[1] = 1;
  for (int i = 2; i <= N; i++)
    if (i % 2)
      f[i] = f[i - 1];
    else
      f[i] = (f[i - 1] + f[i >> 1]) % MOD;
}

int main() {
  init();

  int n;
  while (~scanf("%d", &n))
    printf("%d\n", f[n]);

  return 0;
}