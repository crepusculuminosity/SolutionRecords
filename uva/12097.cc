#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

const int maxn = 10005;
const double pi = acos(-1.0);
double a[maxn];
int n, f;

bool check(double area) {
  int sum = 0;
  for (int i = 1; i <= n; i++)
    sum += floor(a[i] / area);
  return sum >= f + 1;
}

int main() {
  // freopen("data.in","r",stdin);
  int _;
  scanf("%d", &_);
  while (_--) {
    double maxa = -1;
    scanf("%d%d", &n, &f);
    for (int i = 1; i <= n; i++) {
      int r;
      scanf("%d", &r);
      a[i] = pi * r * r;
      maxa = max(a[i], maxa);
    }
    double l = 0, r = maxa;
    while (r - l > 1e-6) {
      // double mid=(l+r)/2;
      double mid = l + (r - l) / 2;
      if (check(mid))
        l = mid;
      else
        r = mid;
    }
    printf("%.4lf\n", l);
  }
  return 0;
}