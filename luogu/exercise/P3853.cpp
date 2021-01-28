#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int a[MAXN];
int ll, n, k;

int check(int x) {
  int num = 0;
  for (int i = 2; i <= n; i++) {
    if (a[i] - a[i - 1] >= x) {
      num += (a[i] - a[i - 1]) / x;
      if ((a[i] - a[i - 1]) % x == 0)
        num--;
    }
  }
  return num <= k;
}

int main() {
  scanf("%d%d%d", &ll, &n, &k);
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]);
  int l = 0, r = ll;
  while (l < r) {
    int mid = (r + l) >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  printf("%d\n", l);
  return 0;
}
