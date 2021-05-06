#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 1e6 + 10;
int num[maxn], prime1[100000], prime2[100000];

typedef long long ll;
ll L, R;
int cnt;

void init() {
  for (ll i = 2; i < maxn; i++) {
    if (num[i] == 0)
      prime1[++cnt] = i;
    // for (ll j = i * i; j < maxn; j += i)
    // num[j] = 1;
    for (int j = 1; j <= cnt && prime1[j] * i < maxn; j++) {
      num[i * prime1[j]] = 1;
      if (i % prime1[j] == 0)
        break;
    }
    // cout<<i<<endl;
  }
}
void solve(ll L, ll R) {
  memset(num, 0, sizeof(num));
  for (ll i = 1; i <= cnt; i++) {
    // ll p = max(L / prime1[i], (ll)2);
    ll p = L / prime1[i];
    if (p < 2)
      p = 2;
    // while(p<=1) ++p;
    for (ll j = prime1[i] * p; j <= R; j += prime1[i]) {
      if (!num[j - L] && j >= L)
        num[j - L] = 1;
      // if(j>=L) num[j-L]=1;
    }
  }
  // cout<<endl;
  if (L == 1)
    num[0] = 1;
}

int main() {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0), cout.tie(0);
  init();
  while (~scanf("%lld%lld", &L, &R)) {
    ll MINN = 0x3f3f3f3f, MAXN = -0x3f3f3f3f;
    ll maxl, maxr, minl, minr;
    solve(L, R);
    int tot = 0;
    for (int i = 0; i <= R - L; i++)
      if (num[i] == 0)
        prime2[++tot] = i + L;
    // cout<<endl;
    if (tot <= 1) {
      puts("There are no adjacent primes.");
    } else {
      for (int i = 1; i < tot; i++) {
        if (prime2[i + 1] - prime2[i] > MAXN) {
          MAXN = prime2[i + 1] - prime2[i];
          maxl = prime2[i], maxr = prime2[i + 1];
        }
        if (prime2[i + 1] - prime2[i] < MINN) {
          MINN = prime2[i + 1] - prime2[i];
          minl = prime2[i], minr = prime2[i + 1];
        }
      }
      printf("%lld,%lld are closest, %lld,%lld are most distant.\n", minl, minr,
             maxl, maxr);
    }
  }
  return 0;
}