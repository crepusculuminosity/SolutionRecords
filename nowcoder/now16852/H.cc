#include <bits/stdc++.h>
using namespace std;
int n, k;
constexpr int maxn = 1e7 + 10;
int a[maxn];

int main() {
  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    a[i] = a[i - 1] + x;
  }
  int ans = 0x3f3f3f3f, minl;
  int l = 1, r = 1;
  for (; l <= n; l++) {
    while (a[r] - a[l - 1] < k && r < n)
      ++r;
    //printf("%d %d\n", l, r);
    if (r == n)
      break;
    if (ans > r - l + 1)
      ans = r - l + 1, minl = l;
  }
  printf("%d %d", minl, minl + ans - 1);
  return 0;
}