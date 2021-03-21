#include <bits/stdc++.h>
using namespace std;

int main() {
  // freopen("data.in","r",stdin);
  // freopen("data.out","w",stdout);
  int n;
  cin >> n;
  while (n--) {
    string s;
    int sum = 0;
    cin >> s;
    for (char ch : s) {
      sum += (ch - 'A' + 1);
    }
    cout << sum << endl;
  }
  return 0;
}