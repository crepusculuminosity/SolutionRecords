#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int n, m;

int main() {
  // freopen("data.in","r",stdin);
  while (scanf("%d%d", &n, &m) == 2) {
    scanf("%d%d", &n, &m);
    double ans = 0.0;
    for (int i = 1; i < n; i++) {
      double pos = (double)i / n * (n + m);
      ans += fabs(pos - floor(0.5 + pos)) / (n + m);
    }
    printf("%.4f\n", ans * 10000);
  }
  return 0;
}