#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
typedef unsigned long long ull;
char s[maxn];
ull h1[maxn], h2[maxn], p[maxn];

void hsh(char *s) {
  int n = strlen(s + 1);
  for (int i = 1; i <= n; i++)
    h1[i] = h1[i - 1] * 131 + (s[i] - 'a' + 1),
    h2[n - i + 1] = h2[n - i + 2] * 131 + (s[n - i + 1] - 'a' + 1);
  
}

int main() {
  int kse = 1;
  p[0] = 1;
  for (int i = 1; i <= 1000000; i++)
    p[i] = p[i - 1] * 131;
  while (cin >> (s + 1) && s[1] != 'E') {
  }
}