#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 1010;
typedef long long ll;
ll num[maxn], prime[maxn], phi[maxn], cnt;

void init() {
  for (ll i = 2; i < maxn; i++) {
    if (num[i] == 0)
      prime[++cnt] = i, phi[i] = i - 1;
    for (ll j = 1; j <= cnt && i * prime[j] < maxn; j++) {
      num[i * prime[j]] = 1;
      if (i % prime[j] == 0) {
        phi[i * prime[j]] = phi[i] * prime[j];
      } else
        phi[i * prime[j]] = phi[i] * (prime[j] - 1);
    }
  }
  for (int i = 2; i < maxn; i++)
    phi[i] += phi[i - 1];
}

int main() {
  init();
  int n, _, kse = 1;
  scanf("%d", &_);
  while (_--) {
    scanf("%d", &n);
    printf("%d %d %lld\n", kse++, n, 2 * phi[n] + 3);
  }
  return 0;
}