#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  while (1) {
    getline(cin, str);
    if (str.back() == '.')
      cout << "*Nod*" << '\n';
    else if (str.back() == '?')
      cout << "Quack!" << '\n';
    else
      break;
  }
  return 0;
}
