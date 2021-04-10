#include <bits/stdc++.h>
using namespace std;
int a[30];
char ch;
FILE *fd;
void work() {
  memset(a, 0, sizeof(a));
  int sum = 0;
  while ((ch = fgetc(fd)) != EOF) {
    ch = tolower(ch);
    if (ch >= 'a' && ch <= 'z')
      ++a[ch - 'a'], ++sum;
  }
  fclose(fd);
  double en = 0.0;
  for (int i = 0; i < 26; i++) {
    if (!a[i])
      continue;
    double p = a[i] * 1.0 / sum;
    en += p * log2(p);
  }
  for (int i = 0; i < 26; i++) {
    cout << (char)i + 'a' << " 出现的次数为：" << a[i] << '\n';
  }
  cout << "信息熵为：";
  cout << fixed << setprecision(8) << -en << '\n';
}
int main() {
  freopen("data.out", "w", stdout);
  fd = fopen("./data1.in", "r"); // Robinson
  if (fd == NULL)
    cout << "failed\n";
  work();
  fd = fopen("./data2.in", "r"); // Jane Eyre
  if (fd == NULL)
    cout << "failed\n";
  work();
  return 0;
}
