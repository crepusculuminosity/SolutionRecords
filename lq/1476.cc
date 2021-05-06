#include <bits/stdc++.h>
using namespace std;
char ch[] = "LANQIAO";
typedef long long ll;
int main() {
  ll res = 0;
  int len = strlen(ch);
  for (int i = 0; i < len; i++) {
    int t = ch[i] - 'A' + 1;
    res = res * 26 + t;
  }
  cout << res;
  return 0;
}
