#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef double db;
typedef pair<int, int> PII;
typedef vector<int> VI;

constexpr int N = 3e5 + 10, mod = 998244353;
inline int add(int x, int y, int m = mod) { return (x += y) >= m ? x - m : x; }
inline int sub(int x, int y, int m = mod) { return (x -= y) < 0 ? x + m : x; }
inline int powmod(int x, int y = mod - 2, int m = mod) {
  int ans = 1;
  for (; y; y >>= 1, x = 1ll * x * x % m)
    if (y & 1)
      ans = 1ll * ans * x % m;
  return ans;
}
const int gn = 3, ign = powmod(gn);

namespace Polynomial {
int rev[N];
void init(int n) {
  rep(i, 0, n) rev[i] = rev[i >> 1] >> 1 | ((i & 1) ? n >> 1 : 0);
}
int glim(int n) {
  int lim = 1;
  while (lim <= n)
    lim <<= 1;
  return lim;
}

void NTT(int *f, int n, int flg) {
  rep(i, 0, n) if (rev[i] < i) swap(f[i], f[rev[i]]);
  for (int len = 2, k = 1; len <= n; len <<= 1, k <<= 1) {
    int wn = powmod(flg == 1 ? gn : ign, (mod + 1) / len);
    for (int i = 0; i < n; i += len)
      for (int j = i, w = 1; j < i + k; j++, w = 1ll * w * wn % mod) {
        int tmp = 1ll * f[j + k] * w % mod;
        f[j + k] = sub(f[j], tmp), f[j] = add(f[j], tmp);
      }
  }
  if (flg == -1) {
    int inv = powmod(n);
    rep(i, 0, n) f[i] = 1ll * f[i] * inv % mod;
  }
}

void Inv(int *f, int n, int *g) {
  if (n == 1) {
    g[0] = powmod(f[0]);
    return;
  }
  Inv(f, (n + 1) >> 1, g);
  static int tf[N];
  int lim = glim((n - 1) << 1);
  init(lim);
  rep(i, 0, lim) tf[i] = i < n ? f[i] : 0, g[i] = i < n ? g[i] : 0;
  NTT(tf, lim, 1), NTT(g, lim, 1);
  rep(i, 0, lim) g[i] = 1ll * g[i] * sub(2, 1ll * tf[i] * g[i] % mod) % mod;
  NTT(g, lim, -1);
  rep(i, n, lim) g[i] = 0;
}

struct poly {
  VI a;
  int size() const { return a.size(); }
  int deg() const { return size() - 1; }
  int &operator[](int i) {
    assert(i < size());
    return a[i];
  }
  int operator[](int i) const { return i < size() ? a[i] : 0; }
  void reverse() { ::reverse(all(a)); }
  void resize(int n) { a.resize(n); }
  poly(int n = 0) { a = VI(n, 0); }

  void print() {
    printf("#debug: ");
    puts("");
    for (auto v : a)
      printf("%d ", v);
    puts("\n-----------------");
  }

  poly inv(int n) const {
    static int f[N], invf[N];
    rep(i, 0, n) f[i] = a[i];
    Inv(f, n, invf);
    poly ans(n);
    rep(i, 0, n) ans[i] = invf[i];
    return ans;
  }
};

poly operator+(const poly &a, const poly &b) {
  poly c(max(a.size(), b.size()));
  rep(i, 0, c.size()) c[i] = add(a[i], b[i]);
  return c;
}
poly operator-(const poly &a, const poly &b) {
  poly c(max(a.size(), b.size()));
  rep(i, 0, c.size()) c[i] = sub(a[i], b[i]);
  return c;
}

poly operator*(const poly &a, const poly &b) {
  int n = a.deg(), m = b.deg(), lim = glim(n + m);
  poly c(n + m + 1);
  static int ta[N], tb[N];
  rep(i, 0, lim) ta[i] = tb[i] = 0;
  rep(i, 0, n + 1) ta[i] = a[i];
  rep(i, 0, m + 1) tb[i] = b[i];
  init(lim);
  NTT(ta, lim, 1), NTT(tb, lim, 1);
  rep(i, 0, lim) ta[i] = 1ll * ta[i] * tb[i] % mod;
  NTT(ta, lim, -1);
  rep(i, 0, n + m + 1) c[i] = ta[i];
  return c;
}

pair<poly, poly> divmod(const poly &a, const poly &b) {
  if (a.deg() < b.deg())
    return mp(poly(0), a);
  int n = a.deg(), m = b.deg();
  poly ra = a, rb = b;
  ra.reverse(), rb.reverse();
  poly q = ra * rb.inv(n - m + 1), r;
  q.resize(n - m + 1), q.reverse();
  r = a - q * b, r.resize(m);
  return mp(q, r);
}

poly operator/(const poly &a, const poly &b) { return divmod(a, b).fi; }
poly operator%(const poly &a, const poly &b) { return divmod(a, b).se; }
} // namespace Polynomial
using Polynomial::poly;

poly p[N], a[N];

void build(int x, int l, int r) {
  if (l == r) {
    p[x] = a[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(x << 1, l, mid), build(x << 1 | 1, mid + 1, r);
  p[x] = p[x << 1] * p[x << 1 | 1];
}

int ans[N], n, m;
poly A;

void solve(int x, int l, int r, const poly &f) {
  if (l == r) {
    ans[l] = f[0];
    return;
  }
  int mid = (l + r) >> 1, lc = x << 1, rc = x << 1 | 1;
  solve(lc, l, mid, f % p[lc]);
  solve(rc, mid + 1, r, f % p[rc]);
}

namespace FakeIO {
const int SZ = 233333;
char buf[SZ], *p1 = buf, *p2 = buf;
inline char nc() {
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, SZ, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline int gi() {
  int x = 0, f = 1;
  char ch;
  while (!isdigit(ch = nc()))
    if (ch == '-')
      f = -f;
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = nc();
  }
  return x * f;
}
} // namespace FakeIO
using FakeIO::gi;

int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
#endif
  n = gi();
  A = poly(n + 1);
  rep(i, 0, n + 1) {
    int x = gi();
    A[i] = x;
  }
  m = gi();
  rep(i, 1, m + 1) {
    int x = gi();
    a[i] = poly(2);
    a[i][0] = mod - x, a[i][1] = 1;
  }
  build(1, 1, m);
  solve(1, 1, m, A % p[1]);
  rep(i, 1, m + 1) printf("%d ", ans[i]);
  return 0;
}