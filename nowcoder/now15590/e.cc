#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1010;
int a[maxn];
int t, s, n;

int main() {
  cin >> t >> s >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int u = 0, l = s;
  for (int i = 0; i < t; i++) {
    if (a[i]) swap(u, l);
    if (u) --u, ++l;
  }
  cout << u;
  return 0;
}