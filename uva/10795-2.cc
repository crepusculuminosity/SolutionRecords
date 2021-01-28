#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;
typedef long long ll;
const int N = 65;
int n;
int a[N], b[N];
ll f(int *p, int i, int final) {
  if (i == 0)
    return 0;
  if (p[i] == final)
    return f(p, i - 1, final);
  else
    return f(p, i - 1, 6 - p[i] - final) + (1LL << (i - 1));
}
int main() {
  freopen("data.in", "r", stdin);
  int Kase = 0;
  while (scanf("%d", &n) && n) {
    for (int i = 1; i <= n; i++)
      scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
      scanf("%d", &b[i]);
    int k = n;
    while (k >= 1 && a[k] == b[k])
      k--;
    ll ans = 0;
    if (k >= 1) {
      int other = 6 - a[k] - b[k];
      ans = f(a, k - 1, other) + f(b, k - 1, other) + 1;
    }
    printf("Case %d: %lld\n", ++Kase, ans);
  }
  return 0;
}