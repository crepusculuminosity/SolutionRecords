#include <bits/stdc++.h>
using namespace std;

vector<string> v;
inline int read() {
  int x = 0, f = 1; //
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}

bool hs(string &s1, string &s2) {
  int a[30], b[30];
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  for (int i = 0; i < s1.size(); i++) {
    a[s1[i] - 'a']++;
  }
  for (int i = 0; i < s2.size(); i++) {
    b[s2[i] - 'a']++;
  }
  for (int i = 0; i < 25; i++) {
    if (a[i] && b[i])
      return 1;
  }
  return 0;
}

int main() {
  // freopen("data.in","r",stdin);

  int t = read();
  while (t--) {
    v.clear();
    bool f = 1;
    string str;
    int n = read();
    for (int i = 0; i < n; i++) {
      cin >> str;
      v.push_back(str);
    }
    for (int i = 0; i < n / 2; i++) {
      if (!hs(v[i], v[n - 1 - i]))
        f = 0;
    }
    if (f)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }

  return 0;
}