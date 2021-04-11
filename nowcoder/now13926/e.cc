#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  map<string, int> b;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    b[s] = i;
  }
  string c = "suspicious";
  int m = 0;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    int d = b[s] - i;
    if (d > m) {
      m = d;
      c = s;
    }
  }
  cout << c << '\n';
  return 0;
}
