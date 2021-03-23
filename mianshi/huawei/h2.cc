#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  int ans = 0;
  getline(cin, str);
  char c;
  cin >> c;
  for (int i = 0; i < str.size(); i++)
    if (str[i] == c || abs(str[i] - c) == 32)
      ++ans;
  cout << ans;
  return 0;
}