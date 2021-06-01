#include <bits/stdc++.h>
using namespace std;
int n;


void work() {
  double ans = 0.0;
  for (int i = 0; i <= n; i++) {
    ans = max(ans, pow(1.1, i) * (100 * i + 200 * (n - i)));
  }
  cout << fixed << setprecision(15) << ans;
}
int main() {
  cin>>n;
  work();

  return 0;
}