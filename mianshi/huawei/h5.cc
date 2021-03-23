#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  while (cin >> str) {
    int x = 0;
    for (int i = 2; i < str.size(); i++) {
      int s;
      if (str[i] <= '9' && str[i] >= '0')
        s = str[i] - 48;
      else
        s = str[i] - 'A' + 10;
      x = x * 16 + s;
    }
    cout << x << endl;
  }
  return 0;
}