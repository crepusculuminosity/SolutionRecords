#include <bits/stdc++.h>
using namespace std;
int n, m;
constexpr int maxn = 1e6 + 10;
int a[maxn], b[maxn], v[maxn];
struct node {
  int d, v;
  bool operator<(const node &x) const { return v > x.v; }
} e[maxn];
bool cmp(int x, int y) { return x > y; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= m; i++)
    cin >> e[i].d;
  for (int i = 1; i <= m; i++)
    cin >> e[i].v;

  sort(a + 1, a + 1 + n, cmp);
  sort(e + 1, e + 1 + m);

  int now = 1, ans = 0;
  for (int i = 1; i <= n; i++) {
    while (e[now].d >= a[i])
      ++now;
    if (e[now].v < 0)
      break;
    ans += e[now].v;
  }
  cout << ans;
  return 0;
}