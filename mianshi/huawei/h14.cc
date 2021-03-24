#include <bits/stdc++.h>
using namespace std;

vector<string> v;
int main() {
  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    v.push_back(s);
  }
  sort(v.begin(), v.end());
  for (auto i : v)
    cout << i << endl;
  return 0;
}