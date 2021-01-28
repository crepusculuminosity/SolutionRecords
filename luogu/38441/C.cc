#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
ll val, ans;
int n, k;

void dfs(int x, ll val) {
  if (x == n + 1) {
    ans += (val % k == 0);
    return;
  }
  for (int i = 1; i <= 6; i++) {
    dfs(x + 1, val * 10 + i);
  }
}

int main() {
  // freopen("data.in","r",stdin);
  scanf("%d%d", &n, &k);
  dfs(1, 0);
  printf("%d\n", ans % mod);
  return 0;
}