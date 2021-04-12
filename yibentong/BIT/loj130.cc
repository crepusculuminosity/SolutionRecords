
//模板 单点修改 区间查询

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e6 + 10;
ll a[MAXN], b[MAXN];
ll n, m;

inline ll read() {
  ll x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline ll lowbit(int x) { return x & (-x); }

inline void init() {
  for (ll i = 1; i <= n; i++) {
    b[i] += a[i];
    ll j = i + lowbit(i);
    if (j <= n)
      b[j] += b[i];
  }
}

inline void add(ll x, ll k) {
  while (x <= n) {
    b[x] += k;
    x += lowbit(x);
  }
}

inline ll query(ll x) {
  ll ans = 0;
  while (x >= 1) {
    ans += b[x];
    x -= lowbit(x);
  }
  return ans;
}

int main() {
  freopen("data1.in","r",stdin);
  freopen("data2.out","w",stdout);
  n = read(), m = read();
  for (int i = 1; i <= n; i++)
    a[i] = read();
  init();
  for(int i=1;i<=n;i++)
    cout<<b[i]<<' ';
  cout<<endl;
  for (int i = 1; i <= m; i++) {
    int k = read(), x = read(), y = read();
    // int k,x,y; cin>>k>>x>>y;
    if (k == 1)
      add(x, y);
    if (k == 2)
      printf("%lld\n", query(y) - query(x - 1));
  }
  system("pause");
  return 0;
}