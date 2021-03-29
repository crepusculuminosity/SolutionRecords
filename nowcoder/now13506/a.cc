#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 5e3 + 10;
vector<int> G[maxn];
int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
}