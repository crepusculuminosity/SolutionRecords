

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#define rt return
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rep(i, x, n) for (int i = x; i < n; i++)
#define repd(i, x, n) for (int i = x; i <= n; i++)
#define pii pair<int, int>
#define pll pair<long long, long long>
#define gbtb ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define MS0(X) memset((X), 0, sizeof((X)))
#define MSC0(X) memset((X), '\0', sizeof((X)))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define eps 1e-6
#define gg(x) getInt(&x)
#define db(x) cout << "== [ " << x << " ] ==" << endl;
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll powmod(ll a, ll b, ll MOD) {
  ll ans = 1;
  while (b) {
    if (b % 2)
      ans = ans * a % MOD;
    a = a * a % MOD;
    b /= 2;
  }
  return ans;
}
inline void getInt(int *p);
const int maxn = 1000010;
const int inf = 0x3f3f3f3f;
/*** TEMPLATE CODE * * STARTS HERE ***/
int l[maxn];
int r[maxn];
ll sum[maxn];
int a[maxn];
int n;
int main() {
 // freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  gg(n);
  repd(i, 1, n) {
    gg(a[i]);
    sum[i] = sum[i - 1] + 1ll * a[i];
  }
  stack<int> s;
  // 1 2 3 4 5
  // 4
  while (s.size())
    s.pop();
  repd(i, 1, n) {
    while (s.size() && a[s.top()] >= a[i]) {
      s.pop();
    }
    if (s.size()) {
      l[i] = s.top() + 1;
    } else {
      l[i] = 1;
    }
    s.push(i);
  }
  while (s.size())
    s.pop();
  //  3 1 6 4 5 2
  //  4 -> 5  2
  int x;
  for (int i = n; i >= 1; i--) {
    while (s.size() && a[s.top()] >= a[i]) {
      s.pop();
    }
    if (s.size()) {
      r[i] = s.top() - 1;
    } else {
      r[i] = n;
    }
    s.push(i);
  }
  ll ans = -1;
  int lf, ri;
  repd(i, 1, n) {
    ll cnt = 1ll * a[i] * (sum[r[i]] - sum[l[i] - 1]);
    if (cnt > ans) {
      ans = cnt;
      lf = l[i];
      ri = r[i];
    }
  }
  printf("%lld\n", ans);
  printf("%d %d", lf, ri);
  return 0;
}

inline void getInt(int *p) {
  char ch;
  do {
    ch = getchar();
  } while (ch == ' ' || ch == '\n');
  if (ch == '-') {
    *p = -(getchar() - '0');
    while ((ch = getchar()) >= '0' && ch <= '9') {
      *p = *p * 10 - ch + '0';
    }
  } else {
    *p = ch - '0';
    while ((ch = getchar()) >= '0' && ch <= '9') {
      *p = *p * 10 + ch - '0';
    }
  }
}
