#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, sum;
  while (scanf("%d%d", &a, &b) == 2 && a && b) {
    sum = 0;
    for (int i = 0; i <= 99; i++) {
      if ((a * 100 + i) % b == 0) {
        sum++;
        if (sum > 1)
          printf(" %02d", i);
        else
          printf("%02d", i);
      }
    }
    printf("\n");
  }
}