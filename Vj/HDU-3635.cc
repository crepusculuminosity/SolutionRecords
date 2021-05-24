#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e4 + 10;
int fa[maxn], d[maxn], sz[maxn];
int n, m;

int find(int x) {
  if (x == fa[x])
    return x;
  int root = find(fa[x]);
  d[x] += d[fa[x]];
  return fa[x] = root;
}

void merge(int x, int y) {
  x = find(x), y = find(y);
  fa[x] = y;
  sz[y] += sz[x];
  d[x]++;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _, kse = 1;
  cin >> _;
  while (_--) {
    cout << "Case " << kse++ << ":\n";
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
      fa[i] = i, d[i] = 0, sz[i] = 1;
    while (m--) {
      char ch[5];
      cin >> ch;
      if (ch[0] == 'T') {
        int a, b;
        cin >> a >> b;
        merge(a, b);
      } else {
        int a;
        cin >> a;
        int x = find(a);
        cout << x << ' ' << sz[x] << ' ' << d[a] << '\n';
      }
    }
  }
  return 0;
}