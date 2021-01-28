#include <bits/stdc++.h>
using namespace std;

char a[15];
int n;
int main() {
  scanf("%d", &n);
  while (n--) {
    getchar();
    for (int i = 1; i <= 11; i++)
      a[i] = getchar();
    putchar('6');
    for (int i = 7; i <= 11; i++)
      putchar(a[i]);
    putchar('\n');
  }

  return 0;
}