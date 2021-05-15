#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 5e4 + 10;
int num[maxn], phi[maxn], prime[maxn], cnt;

void init() {
  for (int i = 2; i < maxn; i++) {
    if (num[i] == 0) {
      prime[++cnt] = i;
      phi[i] = i - 1;
    }
    for (int j = 1; j <= cnt & i * prime[j] < maxn; j++) {
      num[i * prime[j]] = 1;
      if (i % prime[j] == 0) {
        phi[i * prime[j]] = phi[i] * prime[j];
        break;
      } else
        phi[i * prime[j]] = phi[i] * (prime[j] - 1);
    }
  }
  for (int i = 2; i < maxn; i++)
    phi[i] += phi[i - 1];
}
int main() {
  init();
  int n;
  while (~scanf("%d", &n) && n) {
    printf("%d\n", 2 * phi[n] + 1);
  }
  return 0;
}