#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e5 + 10;
vector<int> G[maxn];
int n, m;
int a[maxn];

void dfs(int x, int c) {
  if (a[x])
    return;
  a[x] = c;
  for (int i = 0; i < G[x].size(); i++)
    dfs(G[x][i], c);
}

int main() {
  // freopen("data.in", "r", stdin);
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    G[v].push_back(u);
  }
  for (int i = n; i; i--)
    dfs(i, i);
  for (int i = 1; i <= n; i++)
    cout << a[i] << ' ';
  return 0;
}