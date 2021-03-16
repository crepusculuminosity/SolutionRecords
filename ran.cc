#include <bits/stdc++.h>
using namespace std;
constexpr int n = 1e7;

int main() {
  freopen("data.in", "w", stdout);
  srand((unsigned)time(NULL));
  int n = rand() % 20 + 1;
  cout << n << endl;
  for (int i = 0; i < n; i++)
    printf("%d %d\n", rand() % 1007, rand() & 1007);
  return 0;
}