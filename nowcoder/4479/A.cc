#include <bits/stdc++.h>
using namespace std;
set<char> s;
int main() {
  // freopen("data.in","r",stdin);
  string str;
  cin >> str;
  for (int i = 0; i < str.size(); i++) {
    s.insert(str[i]);
  }
  cout << s.size();
  return 0;
}