#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 2e5 + 10;
vector<int> G[maxn];
int dp[maxn];
bool cmp(int x, int y) { return x > y; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int _;
  cin >> _;
  while (_--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
      G[i].clear();
    for (int i = 1; i <= n; i++) {
      int u, v;
      cin >> u >> v;
      G[u].push_back(v);
    }
    int cnt;
    for (cnt = 1; cnt <= n; cnt++) {
      if (G[cnt].empty())
        break;
      sort(G[cnt].begin(), G[cnt].end(), cmp);
    }
    for (int k = 1; k <= n; k++) {
      
      for (int i = 1; i <= cnt - 1; i++) {
        if (G[i].size() >= k)
          dp[k] += G[i][k - 1];
      }
    }
  }
}