#include <bits/stdc++.h>
using namespace std;

map<string, int> table;
int n;

int main() {
  freopen("data.in", "r", stdin);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    string opt;
    cin >> opt;

    if (opt[1] == 'o') {
      string fn;
      cin >> fn;
      if (table.find(fn) == table.end())
        continue;
      table.insert(pair<string, int>(fn, i));
    }

    if (opt[1] == 'm') {
      string fn;
      cin >> fn;
      if (table.find(fn) == table.end())
        continue;
      table.erase(fn);
    }

    if (opt[1] == 's') {
      vector<pair<int, string>> tmp;
      for (auto &x : table)
        cout << x.second << endl;
    }

    if (opt[1] == 'e') {
      string s1, s2;
      cin >> s1 >> s2;
      if (table.find(s1) == table.end())
        continue;
      int tmp = table[s1];
      table.erase(s1);
      table[s2] = tmp;
    }
  }
  return 0;
}