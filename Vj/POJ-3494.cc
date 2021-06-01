#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 2010;
int a[maxn][maxn];
int n;
inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9')
    ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + ch - 48, ch = getchar();
  return x;
}



int main() {
  n=read();
  for(int i=1;i<=n;i++)

}
