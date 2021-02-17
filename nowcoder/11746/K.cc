#include <bits/stdc++.h>
using namespace std;

char tb[50];
int ftb(char c) {
  int i = 0;
  for (; i < 50; i++)
    if (tb[i] == c)
      return i;
}

int main() {
  freopen("data.in", "r", stdin);
  for (int i = 0; i < 25; i++)
    tb[i] = 'b' + i;
  for (int i = 25; i < 50; i++)
    tb[i] = 'B' + i - 25;
  string s;
  vector<int> a, b;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] >= '0' && s[i] <= '9')
      a.push_back(s[i] - '0');
    else
      b.push_back(ftb(s[i]));
  }
  for (int i = 0; i < b.size(); i++)
    b[i] = (b[i] + a[i]) % 50;
  for (int i = 0; i < 4; i++) {
    swap(b[i + 0], b[i + 3]);
    swap(b[i + 1], b[i + 2]);
  }
  for (auto x : b)
    cout << tb[x];
  return 0;
}