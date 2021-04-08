#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e5;
int main() {
  freopen("data.in", "w", stdout);
  srand((unsigned)time(NULL));
  for (int i = 1; i <= maxn; i++)
    cout << rand() % 10;
  return 0;
}