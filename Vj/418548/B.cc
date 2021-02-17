#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e5 + 10;
typedef long long ll;
vector<pair<int, int>> e[maxn];
ll dis[maxn];
bool vis[maxn];
int n, m, flag = 0;

int main() {
  cin >> n >> m >> flag;
  for (int i = 1; i <= m; i++) {
    int l, r, d;
    cin >> l >> r >> d;
    e[l].push_back({r, d});
    e[r].push_back({l, -d});
  }
  for (int i = 0; i < n; i++) {
    if (!vis[])
  }
}