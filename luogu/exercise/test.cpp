#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
const int MAXN = 1e6 + 5;
int n, l;
int a[MAXN];
int maxn, minn, minx, maxx;
int main() {
  // freopen("data.in","r",stdin);
  int _;
  scanf("%d", &_);
  while (_--) {
    /* code */
    memset(a, 0, sizeof(a));
    scanf("%d%d", &l, &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
      minx = min(a[i], l - a[i]);
      maxx = l - minx;
      maxn = max(maxn, maxx);
      minn = max(minn, minx);
    }
    printf("%d %d\n", minn, maxn);
  }
  return 0;
}