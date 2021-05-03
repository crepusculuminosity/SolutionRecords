#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e5 + 10;
char T[maxn];

int main() {
  int m;
  cin >> m >> (T + 1);
  bool f = 1;
  for (int i = 2; i <= m; i++)
    f &= (T[1] != T[i]);
  if (f)
    cout << "Correct";
  else
    cout << "Wrong Answer";
  return 0;
}