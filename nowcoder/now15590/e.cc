#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<string> a(n);
  for (string &s : a)
    cin >> s;

  int best = m, bi = -1, bj = -1;
  vector<int> pos(n - 1, m);
  for (int i = m - 1; i >= 0; i--) {
    for (int k = 0; k + 1 < n; k++) {
      if (a[k][i] < a[k + 1][i])
        pos[k] = i;
      if (a[k][i] > a[k + 1][i])
        pos[k] = m;
    }
    int j = *max_element(begin(pos), end(pos));
    if (j < m && j - i < best)
      best = j - i, bi = i, bj = j;
  }
  cout << bi + 1 << " " << bj + 1;
}
