#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin >> n) {
    if (n & 1)
      cout << "Either";
    else {
      n /= 2;
      if (n & 1)
        cout << "Odd";
      else
        cout << "Even";
    }
    cout << endl;
  }
}