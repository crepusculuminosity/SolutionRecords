#include <bits/stdc++.h>
using namespace std;

int a[10];

int main() {
  string s;
  cin >> s;
  for (int i = s.size(); i; --i) {
    if (!a[s[i] - '0'])
      cout << s[i] - '0';
    ++a[s[i] - '0'];
  }
  return 0;
}