#include <bits/stdc++.h>
char s[100005];
int main() {
  int l, i;
  char c;

  while (~scanf("%s", s)) {
    l = strlen(s);
    c = 'a';
    i = 0;
    while (i < l && c <= 'z') {
      while (s[i] > c)
        i++;
      if (s[i] == c) {
        i++;
        c++;
      } else {
        s[i] = c;
        i++;
        c++;
      }
    }
    if (c > 'z')
      puts(s);
    else
      printf("-1\n");
  }

  return 0;
}