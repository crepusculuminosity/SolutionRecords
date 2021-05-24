#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int maxn = 20000 + 10;
int fa[maxn * 2], rnk[maxn * 2];
int n, m;
struct node {
  int a, b;
  ll c;
  bool operator<(const node &x) const { return c > x.c; }
} es[100000 + 10];
int find(int x) {
  if (x == fa[x])
    return x;
  return fa[x] = find(fa[x]);
}
bool merge(int x, int y) {
  x = find(x), y = find(y);
  if (x == y)
    return 0;
  if (rnk[x] < rnk[y])
    fa[x] = y;
  else {
    fa[y] = x;
    if (rnk[x] == rnk[y])
      ++rnk[x];
  }
  return 1;
}
int main() {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  for (int i = 1; i < 2 * maxn; i++)
    fa[i] = i;
  cin >> n >> m;
  for (int i = 1; i <= m; i++)
    cin >> es[i].a >> es[i].b >> es[i].c;
  sort(es + 1, es + 1 + m); 
  for (int i = 1; i <= m; i++) {
    int x = es[i].a, y = es[i].b;
    if (find(x) == find(y) || find(x + n) == find(y + n)) {
      cout << es[i].c;
      return 0;
    }
    merge(x, y + n), merge(x + n, y);
  }
  cout << "0";
  return 0;
}