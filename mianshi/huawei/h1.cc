#include <bits/stdc++.h>
using namespace std;

int main() {
  // freopen("data.in", "r", stdin);
  string str;
  getline(cin, str);
  int ans = 0;
  int i;
  for (i = str.size(); str[i] != ' ' && i >= 0; --i)
    ++ans;
  cout << ans;
  return 0;
}