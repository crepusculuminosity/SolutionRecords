#include <bits/stdc++.h>
using namespace std;
int a[1005], b[1005];
int d;
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    if (a[i] != b[i])
      d++;
  }
  cout << n - abs(d - k) << endl;
  return 0;
}