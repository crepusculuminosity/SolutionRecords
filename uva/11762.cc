#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e6 + 10;

bool num[maxn];
int prime[80000];
double dp[maxn];
bool vis[maxn];
int cnt;

void init() {
  // int cnt;
  for (int i = 2; i <= 1000000; i++) {
    if (num[i] == 0)
      prime[++cnt] = i;
    for (int j = 1; j <= cnt && i * prime[j] <= 1000000; j++) {
      num[i * prime[j]] = 1;
      if (i % prime[j] == 0)
        break;
    }
  }
}

double dfs(int x) {
  if (x == 1)
    return 0;
  if (vis[x])
    return dp[x];
  vis[x] = 1;
  double &ans = dp[x];
  ans = 0;
  int p = 0, q = 0;
  for (int i = 1; i <= cnt && prime[i] <= x; i++) {
    ++p;
    if (x % prime[i] == 0)
      ++q, ans += dfs(x / prime[i]);
  }
  ans = (ans + p) / q;
  return ans;
}

int main() {
  // freopen("data.in", "r", stdin);
  init();
  int _, kse = 1;
  scanf("%d", &_);
  while (_--) {
    int n;
    scanf("%d", &n);
    printf("Case %d: %lf\n", kse++, dfs(n));
  }
  return 0;
}