#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 2e5 + 10;
int a[maxn], b[maxn], c[maxn * 3];

int main() {
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++)
    cin >> b[i];

  for (int k = 1; k <= n * 3; k++) {
    for (int d = 1; 3 * d <= k; d++) {
      if (k % d == 0) {
        for (int i = 1; i <= k / d - 2; i++) {
          int j = k / d - 1 - i;
          // if (j * d <= n)
          c[k] += a[i * d] * b[j * d];
        }
      }
    }
  }

  for (int i = 1; i <= 3 * n; i++)
    cout << c[i] << ' ';
  return 0;
}