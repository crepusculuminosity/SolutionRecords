#include <bits/stdc++.h>
using namespace std;
int main() {
  // freopen("data.out","w",stdout);
  double x = 1.0;
  int n;
  cin >> n;

  if (n > 25)
    cout << "0.61803399";
  else {
    for (int i = 2; i <= n; i++)
      x = 1.0 / (1 + x);

    cout << fixed << setprecision(8) << x;
  }

  return 0;
}
