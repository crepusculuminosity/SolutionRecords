#include <bits/stdc++.h>
using namespace std;

string str;
int main() {
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
  while (cin >> str) {
    int a = find(str.begin(), str.end(), 'z') - str.begin();
    int b = find(str.begin(), str.end(), 'j') - str.begin();
    if (a == 7 || b == 7)
      cout << "Wrong Answer\n";
    else {
      int x = a, y = b - a - 1, z = str.size() - b - 1;
      if (z == x * y)
        cout << "Accepted\n";
      else
        cout << "Wrong Answer\n";
    }
  }
  return 0;
}