#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 1e6 + 10;
int num[maxn], prime[maxn], cnt, a[maxn];

void init() {
  for (int i = 5; i < maxn; i += 4) {
    if (!num[i]) {
      prime[++cnt] = i;
      for (int j = 5; j * i < maxn; j += 4)
        num[i * j] = 1;
    }
  }
  for (int i = 2; i <= cnt; i++) {
    for (int j = 2; j <= i && prime[j] * prime[i] < maxn; j++)
      a[prime[i] * prime[j]] = 1;
  }
  for (int i = 2; i < maxn; i++)
    a[i] += a[i - 1];
}

int main() {
  init();
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
  int n;
  while (cin >> n && n) {
    cout << a[n] << '\n';
  }
  return 0;
}