#include <bits/stdc++.h>
using namespace std;

void permute(string s, int i) {
  if (i >= s.size()) {
    cout << s << endl;
    return;
  }
  for (int j = i; j < s.size(); j++) {
    swap(s[i], s[j]);
    permute(s, i + 1);
  }
  return;
}

int main() {
  // freopen("data.in","r",stdin);
  // freopen("data.out","w",stdout);
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  permute(s, 0);
}