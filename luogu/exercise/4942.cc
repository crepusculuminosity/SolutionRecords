#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll r, l;
const int mod = 9;
inline void sum(ll a, ll b) {
  printf("%lld\n", ((b - a + 1) % 9 * (b + a) % 9 * 5) % 9);
}

int main() {
  // freopen("data.in","r",stdin);
  int q;
  scanf("%d", &q);
  while (q--) {
    scanf("%lld %lld", &r, &l);
    sum(r, l);
  }
  return 0;
}