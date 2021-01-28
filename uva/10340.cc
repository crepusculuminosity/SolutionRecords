#define RF freopen("data.in", "r", stdin);
#define WF freopen("data.out", "w", stdout);
#include <bits/stdc++.h>
using namespace std;

int main() {
  RF string s, t;
  while (cin >> s >> t) {
    queue<char> q;
    for (char &ch : s)
      q.push(ch);
    for (char &ch : t) {
      if (ch == q.front())
        q.pop();
    }
    if (q.empty())
      cout << "YES";
    else
      cout << "NO";
    cout << endl;
  }
  return 0;
}