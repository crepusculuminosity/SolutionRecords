#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 5, M = 2e4 + 5, inf = 0x3f3f3f3f, mod = 1e9 + 7;
#define mst(a) memset(a, 0, sizeof a)
#define lx x << 1
#define rx x << 1 | 1
#define PII pair<int, int>
#define fi first
#define se second
#define pb push_back
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
  freopen("data.in", "r", stdin);
  int t;
  scanf("%d", &t);
  while (t--) {
    ll n, d, w;
    scanf("%lld%lld%lld", &n, &d, &w);
    w /= gcd(d - 1, w);
    ll m = min(n, d) - 1;
    ll x = m / w, y = m % w + 1;
    printf("%lld\n", y * x + (x - 1) * x / 2 * w);
  }
  return 0;
}