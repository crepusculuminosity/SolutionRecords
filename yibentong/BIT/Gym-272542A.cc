#define lb(x) ((x) & (-x))
#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 2e5 + 10;
using ll = long long;
ll tr[maxn];
ll a[maxn];
int n, q;
void build() {
  for (int i = 1; i <= n; i++) {
    tr[i] += a[i];
    if (i + lb(i) <= n)
      tr[i + lb(i)] += tr[i];
  }
}

void update(int x, int k) {
  while (x <= n) {
    tr[x] += k;
    x += lb(x);
  }
}

ll query(int x) {
  ll res = 0;
  while (x) {
    res += tr[x];
    x -= lb(x);
  }
  return res;
}

int main() {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  cin >> n >> q;
  for (int i = 1, now = 0; i <= n; i++) {
    int x;
    cin >> x;
    a[i] = x - now, now = x;
  }
  build();
  while (q--) {
    int a, b, c;
    cin >> a >> b >> c;
    update(a, c);
    update(b + 1, -c);
  }
  for (int i = 1; i <= n; i++)
    cout << query(i) << ' ';
  return 0;
}