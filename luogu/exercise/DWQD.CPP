#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  cin >> x;
  int tmp = x;
  int y = 0;
  while (x) {
    y *= 10;
    y += x % 10;
    x /= 10;
  }
  cout << y << endl;
  if (tmp == y)
    cout << "yes" << endl;
  else
    cout << "no" << endl;
  return 0;
}