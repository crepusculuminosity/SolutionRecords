#include <bits/stdc++.h>
using namespace std;

int main() {
  int _, kse = 1;
  cin >> _;
  while (_--) {
    int a, b;
    cin >> a >> b;
    cout << "ircus Act " << kse++ << ':' << endl;
    if (a == 1 || a * 5 <= b * 2)
      cout << "Chester can do it!";
    else
      cout << "Chester will fail!";
    cout << endl << endl;
  }
}