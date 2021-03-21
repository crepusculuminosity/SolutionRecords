#include <bits/stdc++.h>
using namespace std;

int cnt;

int main() {
  // freopen("data.in", "r", stdin);
  int n;
  cin >> n;
  int f = 1;
  for (int i = 1; i <= n; i++) {
    ++cnt;
    int x;
    cin >> x;
    while (cnt < x) {
      f = 0;
      cout << cnt << endl;
      ++cnt;
    }
  }
  if (f)
    cout << "good job";
  return 0;
}