#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e5 + 10;
using ll = long long;
int st[maxn][20];
int n, m, a[maxn];
int Logn[maxn];
map<int, ll> mp;

void pre() {
  Logn[1] = 0, Logn[2] = 1;
  for (int i = 3; i < maxn; i++)
    Logn[i] = Logn[i / 2] + 1;
}

void stinit() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> st[i][0];
  for (int j = 1; j <= 18; j++) {
    for (int i = 1; i + (1 << j) - 1 <= n; i++)
      st[i][j] = __gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
  }
}

inline int query(int l, int r) {
  int k = Logn[r - l + 1];
  return __gcd(st[l][k], st[r - (1 << k) + 1][k]);
}

void solve() {
  mp.clear();
  int left, right;
  for (int i = 1; i <= n; i++) {
    int x = st[i][0], j = i;
    while (j <= n) {
      left = j, right = n + 1;
      while (right - left > 1) {
        int mid = (right + left) >> 1;
        if (query(i, mid) == x)
          left = mid;
        else
          right = mid;
      }
      mp[x] += (left - j + 1);
      j = left + 1;
      x = query(i, j);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  int kse = 1;
  pre();
  int _;
  cin >> _;
  while (_--) {
    cout << "Case #" << kse++ << ":" << '\n';
    stinit();
    cin >> m;
    solve();
    while (m--) {
      int a, b;
      cin >> a >> b;
      int k = query(a, b);
      ll re = mp[k];
      cout << k << ' ' << re << '\n';
    }
  }
  return 0;
}