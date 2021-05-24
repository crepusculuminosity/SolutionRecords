#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mst(a, b) memset((a), (b), sizeof(a))
#define rush()                                                                 \
  int T;                                                                       \
  scanf("%d", &T);                                                             \
  while (T--)
const int maxn = 200005;
const int INF = 0x3f3f3f3f;
const ll mod = 998244353;

int n;
int a[maxn];
int ans[maxn];
int pre[maxn];
int dp[maxn];
vector<int> vec[maxn];

void dfs(int u, int fa) {
  dp[u] = a[u];
  for (int i = 0; i < vec[u].size(); i++) {
    int v = vec[u][i];
    if (v == fa)
      continue;
    dfs(v, u);
    dp[u] += max(dp[v], 0);
  }
}

void dfs2(int u, int fa) {
  ans[u] = dp[u] + pre[u];
  for (int i = 0; i < vec[u].size(); i++) {
    int v = vec[u][i];
    if (v == fa)
      continue;
    pre[v] = max(0, ans[u] - max(0, dp[v]));
    dfs2(v, u);
  }
}

int main() {
  freopen("data.in","r",stdin);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i] == 0)
      a[i] = -1;
  }
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    vec[x].push_back(y);
    vec[y].push_back(x);
  }
  dfs(1, -1);
  dfs2(1, -1);
  for (int i = 1; i <= n; i++)
    printf("%d ", ans[i]);
  //printf("%d\n", ans[n]);
}