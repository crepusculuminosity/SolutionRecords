#include <bits/stdc++.h>
using namespace std;
set<char> s;
int main() {
  string str;
  cin >> str;
  for (auto iter = str.begin(); iter != str.end(); iter++)
    s.insert(*iter);
  cout << s.size() << endl;
  return 0;
}