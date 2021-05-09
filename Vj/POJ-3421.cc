#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = (1 << 19) + 10;
int num[maxn], prime[maxn];
typedef long long ll;
int cnt;
ll sum, a[30], n;

void init() {
  for (int i = 2; i < maxn; i++) {
    if (num[i] == 0)
      prime[++cnt] = i;

    for (int j = 1; j <= cnt && i * prime[j] < maxn; j++) {
      num[i * prime[j]] = 1;
      if (i % prime[j])
        break;
    }
  }
}

int main() {
  init();
  while (~scanf("%lld", &n)) {
    sum = 0;
    int tot = 0;
  }
}