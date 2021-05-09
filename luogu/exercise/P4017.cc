#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 5010;
int n, m;
vector<int> G[maxn];
int dp[maxn], in[maxn], chu[maxn];
constexpr int mod = 80112002;

int main() {
  // freopen("data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  cin >> n >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    ++in[v], ++chu[u];
  }
  // memset(dp,-1,sizeof(dp));
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (!in[i]) {
      dp[i] = 1;
      q.push(i);
    }
  }
  int cnt = 0;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    // d[++cnt]=x;
    for (int i = 0; i < G[x].size(); i++) {
      --in[G[x][i]];
      dp[G[x][i]] = (dp[G[x][i]] + dp[x]) % mod;
      if (!in[G[x][i]])
        q.push(G[x][i]);
    }
  }
  int ans = 0;

  for (int i = 1; i <= n; i++) //最高营养级生物不仅仅只有一个
    if (chu[i] == 0)
      ans = (ans + dp[i]) % mod;
  cout << ans;
  return 0;
}