#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
inline ll read() {
  ll x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n, m;
map<string, string> mp;
void AC() {
  n = read();
  string a, b;
  while (n--) {
    cin >> a;
    getchar();
    getline(cin, b);
    mp[a] = b;
  }
  m = read();
  string s;
  while (m--) {
    getline(cin, s);
    s += '\n';
    int last = 0;
    string res;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ' ' || s[i] == '\n') {
        string tmp = s.substr(last, i - last);
        if (mp.count(tmp))
          res += mp[tmp];
        else
          res += tmp;
        res += s[i];
        last = i + 1;
      }
    }
    cout << res;
  }
}
int main() {
  AC();
  return 0;
}