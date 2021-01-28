#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int cot = 0;
ll n[1000005][2];
ll a;

inline ll read() {
  ll x = 0, f = 1; //
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}

int main() {
  freopen("data.in", "r", stdin);
  int t = read();
  while (t--) {
    cot = 0;
    memset(n, 0, sizeof(ll));
    a = read();
    for (ll i = 2; i * i <= a; i++) {
      if (a % i == 0) {
        cot++;
        n[cot][0] = i;
        n[cot][1] = 1;
        a /= i;
        while (a % i == 0) {
          n[cot][1]++;
          a /= i;
        }
      }
    }
    if (a != 1) {
      cot++;
      n[cot][0] = a;
      n[cot][1] = 1;
    }
    ll minn = 60;
    for (int i = 1; i <= cot; i++) {
      if (n[i][1] == 0)
        continue;
      minn = min(n[i][1], minn);
    }
    printf("%lld\n", minn);
  }
}