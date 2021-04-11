#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

vector<int> arr;
vector<vector<int>> G;

void dfs(int u, int p) {
  if (arr[u])
    return;
  arr[u] = p;
  for (auto v : G[u])
    dfs(v, 3 - p);
}

int main() {
  int n, m;
  cin >> n >> m;
  arr.assign(n, 0);
  G.resize(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(0, 1);
  int x = 0, y = 0;
  for (auto e : arr) {
    if (e == 1)
      ++x;
    if (e == 2)
      ++y;
  }
  if (x + y == n and x * y == m)
    cout << y / 2 + x / 2;
  else
    cout << n / 2;
}
