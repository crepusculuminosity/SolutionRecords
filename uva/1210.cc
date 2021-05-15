#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
const int maxn = 100010;
int num[maxn], prime[maxn], cnt, sum[maxn];
map<int, int> mp;
void init() {
  for (int i = 2; i < maxn; i++) {
    if (!num[i])
      prime[++cnt] = i;
    for (int j = 1; j <= cnt && i * prime[j] < maxn; j++) {
      num[i * prime[j]] = 1;
      if (i % prime[j] == 0)
        break;
    }
  }
  for (int i = 1; i <= cnt; i++)
    prime[i] += prime[i - 1], mp[prime[i]] = 1;
  // mp[0] = 1;
}
int main() {
  // freopen("data.in", "r", stdin);
  /// reopen("data.out", "w", stdout);
  init();
  int n;
  while (~scanf("%d", &n) && n) {
    int ans = 0;
    for (int i = 0; i <= cnt; i++)
      ans += mp[prime[i] + n];
    printf("%d\n", ans);
  }
  return 0;
}