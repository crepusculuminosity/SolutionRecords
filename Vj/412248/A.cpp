#include <bits/stdc++.h>
using namespace std;

bool ispd(string str) {
  if (str.size() % 2 == 1)
    return 0;
  int len = str.size();
  string s = str;
  reverse(s.begin(), s.end());
  if (s.substr(0, len / 2) == str.substr(0, len / 2))
    return 1;
  return 0;
}

int main() {
  // freopen("data.in","r",stdin);
  // freopen("data.out","w",stdout);
  string s;
  cin >> s;
  while (s.size() % 2 == 0) {
    if (ispd(s))
      s = s.substr(0, s.size() / 2);
    else
      break;
  }
  cout << s.size() << endl;

  return 0;
}