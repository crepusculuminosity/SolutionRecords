#include <bits/stdc++.h>
using namespace std;
int l, m;
int a, b, ans, bs;
int tr[10005];

int main() {
  cin >> l >> m;
  while (m--) {
    cin >> a >> b;
    for (int i = a; i <= b; i++)
      tr[i] = 1;
  }
  for (int i = 0; i <= l; i++) {
    if (!tr[i])
      ans++;
  }
  cout << ans << endl;
  return 0;
}