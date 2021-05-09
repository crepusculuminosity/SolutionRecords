#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 2e5 + 10;
typedef long long ll;
ll w[maxn];
constexpr int mod = 1e4 + 10;
vector<int> G[maxn];
ll ans;

void dfs(int u) {

  for (int i = 0; i < G[u].size(); i++) {
  }
}

int main() {

  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  for (int i = 1; i <= n; i++)
    cin >> w[i];
}