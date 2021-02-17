#define RF freopen("data.in", "r", stdin);
#define WF freopen("data.out", "w", stdout);
#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
int main() {
  double a, r;
  double area;
  cin >> a >> r;
  if (r <= sqrt(6) * a * 1.0 / 12)
    cout << 0;
  else if (r <= sqrt(2) * a / 4.0)
    cout << 3 * pi * (r * r - 1.0 * a * a / 24);
  else if (r <= sqrt(6) * a * 1.0 / 4) {
    double r1 = sqrt(r * r - 1.0 * a * a / 24.0);
    double the = asin(sqrt(3) * a / 6.0 / r1);
    cout << 3 * sqrt(3) / 2.0 * a * r1 * cos(the) + r1 * (the * 6.0 - pi);
  } else
    cout << sqrt(3);
  return 0;
}