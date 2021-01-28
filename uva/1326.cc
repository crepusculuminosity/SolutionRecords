#include <bits/stdc++.h>
#define _rep(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
int n;
char ch[1000];
int a[30];

int main() {
  while (scanf("%d", &n) == 1) {
    _rep(i, 1, n) {
      scanf("%s", ch);
      a[i] = 0;
      int len = strlen(ch);
      _rep(j, 0, len - 1) { a[i] ^= 1 << (ch[j] - 'A'); }
    }
  }
}