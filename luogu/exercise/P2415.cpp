#include <bits/stdc++.h>
using namespace std;
int main() {
  long long sum = 0;
  int i, cnt = 0;
  while (cin >> i) {
    cnt++;
    sum += i;
  }
  /* code */

  cout << (sum << (cnt - 1)) << endl;
  return 0;
}