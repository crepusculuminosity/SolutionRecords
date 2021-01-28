#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100];

void dabiao() {
  a[1] = 1;
  for (int i = 2; i <= 62; i++) {
    a[i] = a[i - 1] * 2;
  }
}

int main() {
  // freopen("data.in","r",stdin);
  int t;
  scanf("%d", &t);
  while (t--) {
    bool f = 0;
    ll n;
    scanf("%lld", &n);
    for (int i = 1; i < 62; i++) {
      for (int j = 1; j < 62; j++) {
        if (a[i] + a[j] == n) {
          f = 1;
          break;
        }
      }
    }
    if (f)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}