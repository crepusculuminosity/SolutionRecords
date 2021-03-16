#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 110;
int vis[maxn];

int main() {
  freopen("data.in", "r", stdin);
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n, m;
  while (cin >> n >> m && n) {
    vector<int> G[maxn];
    while (m--) {
      int u, v;
      cin >> u >> v;
      G[u].push_back(v);
    }

    cout << '\n';
  }
  return 0;
}