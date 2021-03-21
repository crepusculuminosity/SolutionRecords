#include <bits/stdc++.h>

using namespace std;
#define pi acos(-1.0)

int main() {
  int n;
  cin >> n;
  while (n--) {
    double a, b;
    scanf("%lf%lf", &a, &b);
    a = a * pi / 180;
    b = b * pi / 180;
    double k = sin(pi / 3 - a) * sin(pi / 3 - b) / sin(a) / sin(b);
    double x = sqrt(3) / 2 / (0.5 + 1 / k);
    printf("%.2f\n", atan(x) * 180 / pi);
  }
  return 0;
}