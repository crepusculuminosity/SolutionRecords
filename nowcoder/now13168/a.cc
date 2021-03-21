#include <bits/stdc++.h>
using namespace std;
map<char, bool> mp;
stack<bool> s;

int main() {
  // freopen("data.in", "r", stdin);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    char c;
    cin >> c;
    if (c == 'T')
      mp[(char)(i - 1 + 'A')] = 1;
    else
      mp[(char)(i - 1 + 'A')] = 0;
  }
  getchar();
  string str;
  getline(cin, str);
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == ' ')
      continue;
    if (str[i] >= 'A' && str[i] <= 'Z')
      s.push(mp[str[i]]);
    else {
      bool x, y;
      switch (str[i]) {
      case '+':
        x = s.top();
        s.pop();
        y = s.top();
        s.pop();
        s.push(x | y);
        break;
      case '-':
        x = s.top();
        s.pop();
        s.push(!x);
        break;
      case '*':
        x = s.top();
        s.pop();
        y = s.top();
        s.pop();
        s.push(x & y);
        break;
      }
    }
  }
  if (s.top() == 1)
    cout << 'T';
  else
    cout << 'F';
  return 0;
}