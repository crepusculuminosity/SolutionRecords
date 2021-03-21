#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Poi {
  ll x, y;
} p[100005];
Poi niu, zhi;
ll dis(Poi a, Poi b) { return abs(a.x - b.x) + abs(a.y - b.y); }
ll minn = 1e10;
int main() {
  ll n;
  scanf("%lld", &n);
  for (ll i = 1; i <= n; i++) {
    scanf("%lld", &p[i].x);
  }
  ll t;
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld%lld%lld%lld", &niu.x, &niu.y, &zhi.x, &zhi.y);

    if (niu.y * zhi.y > 0)
      printf("%lld\n", dis(niu, zhi));
    else {
      for (ll i = 1; i <= n; i++) {
        ll m = dis(niu, p[i]) + dis(p[i], zhi);
        minn = min(m, minn);
      }
      printf("%d\n", minn);
    }
  }

  return 0;
}