#include <bits/stdc++.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>
using namespace std;
using ll = long long;
char *p;
ll n, k, a[20000007];

inline ll read() {
  ll re = 0;
  char ch = *p++;
  while (ch < '0' || ch > '9')
    ch = *p++;
  while (ch <= '9' && ch >= '0')
    re = re * 10 + ch - 48, ch = *p++;
  return re;
}

ll l = 1, r = 1, ans = -1, tot;
int main() {
  // freopen("data.in","r",stdin);
  // freopen("data.out","w",stdout);
  p = (char *)mmap(NULL, lseek(0, 0, SEEK_END), PROT_READ, MAP_PRIVATE, 0, 0);
  // n=_getInt(),k=_getInt();
  n = read(), k = read();
  for (ll i = 1; i <= n; i++)
    a[i] = read();

  while (r <= n) {
    while (r <= n && tot + a[r] <= k)
      tot += a[r], r++;
    if (tot == k)
      ans = max(ans, r - l);
    tot -= a[l], l++;
  }
  printf("%lld", ans);

  return 0;
}