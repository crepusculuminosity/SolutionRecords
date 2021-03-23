#include <bits/stdc++.h>
using namespace std;

void fun(string s) {
  if (s.size() <= 8) {
    cout << s;
    for (int i = 0; i < 8 - s.size(); i++)
      putchar('0');
    puts("");
  } else {
    string s1(s, 0, 8);
    cout << s1 << endl;
    s.erase(s.begin(), s.begin() + 8);
    fun(s);
  }
}
int main() {
  string str;
  while (cin >> str)
    fun(str);
  return 0;
}