#include <bits/stdc++.h>
using namespace std;
int a[105];
int x, n, sum, ans;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    a[i] = a[i - 1] + x;
    sum += x;
  }
  int aver = sum / n;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      if (a[i] - aver == 0)
        continue;
    }
  }
  cout << ans << endl;
  return 0;
}
