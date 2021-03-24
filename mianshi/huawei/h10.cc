#include <bits/stdc++.h>
using namespace std;
int a[128];
int main() {
  string s;
  getline(cin, s);
  int ans = 0;
  for (int i = 0; i < s.size(); i++)
    ++a[s[i] - (char)0];
  for (int i = 0; i < 128; i++)
    if (a[i])
      ++ans;
  cout << ans;
  return 0;
}