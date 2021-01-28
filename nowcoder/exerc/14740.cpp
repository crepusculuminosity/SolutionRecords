#include <bits/stdc++.h>
using namespace std;
double x, y, v;
int main() {
  int _;
  scanf("%d", &_);
  while (_--) {
    scanf("%lf%lf%lf", &x, &y, &v);
    double a = 9.8 * x * x / 2.0 / v / v;
    double b = -x;
    double c = y + 9.8 * x * x / 2.0 / v / v;
    double delta = b * b - 4 * a * c;
    if (delta < 0)
      printf("NO SOLUTION.\n");
    else {
      double tan1 = (-b - sqrt(delta)) / (2.0 * a);
      double tan2 = (-b + sqrt(delta)) / (2.0 * a);
      double jg1 = atan(tan1);
      double jg2 = atan(tan2);
      if (jg2 - jg1 >= 1e-5)
        printf("%.5lf %.5lf\n", jg1, jg2);
      else
        printf("%.5lf\n", jg1);
    }
  }
  return 0;
}