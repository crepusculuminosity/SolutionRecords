#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e6 + 10;
int fa[maxn], vis[maxn];

int find(int x) {
  if (fa[x] == x)
    return x;
  return fa[x] = find(fa[x]);
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= 20000; i++)
    fa[i] = i;
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    x = find(x), y = find(y);
    if (x == y)
      vis[x] = 1;
    else {
      if (x > y)
        swap(x, y);
      fa[x] = y;
      vis[x] = 1;
    }
  }
  for (int i = 1; i <= 20000; i++)
    if (!vis[i]) {
      cout << i - 1;
      break;
    }
  return 0;
}