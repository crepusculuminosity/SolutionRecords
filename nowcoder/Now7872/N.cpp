#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int main() {
  string str;
  cin >> str;
  for (auto iter = str.begin(); iter != str.end(); iter++) {
    if (*iter == 'y')
      a++;
    if (*iter == 'd')
      b++;
    if (*iter == 's')
      c++;
  }
  for (int i = 1; a || b || c; i++) {
    if (a > 0) {
      if (a >= 2) {
        cout << "yy";
        a = a - 2;
      } else {
        cout << 'y';
        a--;
      }
    }
    if (b > 0) {
      cout << 'd';
      b--;
    }
    if (c > 0) {
      cout << 's';
      c--;
    }
  }
  return 0;
}