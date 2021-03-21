#include <bits/stdc++.h>
using namespace std;
constexpr double eps = 1e-7;
double w, g, h, r;

double fun(double x) {
  return x / sqrt(g * g + x * x) + (x - w) / sqrt(h * h + (w - x) * (w - x));
}

double solve() {
  double l = 0, r = w;
  while (r - l > eps) {
    double mid = (r + l) / 2;
    if (fun(mid) >= 0)
      r = mid;
    if (fun(mid) < 0)
      l = mid;
  }
  return l;
}

int main() {
  // freopen("data.in","r",stdin);
  int _;
  cin >> _;
  while (_--) {
    cin >> w >> g >> h >> r;
    g -= r, h -= r;
    double ans1 = sqrt(w * w + (g - h) * (g - h));
    double x = solve();
    double ans2 = sqrt(g * g + x * x) + sqrt(h * h + (w - x) * (w - x));
    cout << fixed << setprecision(8) << ans1 << ' ' << ans2 << '\n';
  }
}