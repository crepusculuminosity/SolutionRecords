#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 4e4 + 10;
int n, m;
char ch[maxn];

typedef unsigned long long ull;
typedef long long ll;
ull f[maxn], p[maxn];

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  p[0] = 1;
  for (int i = 1; i < maxn; i++)
    p[i] = p[i - 1] * 131;
  while (cin >> m && m) {
    cin >> (ch + 1);
    n = strlen(ch + 1);
    for (int i = 1; i <= n; i++) 
      f[i] = f[i - 1] * 131 + ch[i] - 'a' + 1;
    
  }
}