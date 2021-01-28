#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[10010];

void init() {
  dp[0] = 1ll;
  for (int i = 1; i * i * i <= 10000; i++) {
    for (int j = 0; j <= 10000; j++) {
      if (j >= i * i * i)
        dp[j] += dp[j - i * i * i];
    }
  }
}

int main() {
  int m;
  init();
  while (~scanf("%d", &m)) {
    printf("%lld\n", dp[m]);
  }
  return 0;
}