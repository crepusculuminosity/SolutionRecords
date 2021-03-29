#include <bits/stdc++.h>
using namespace std;

#define MAXN 10004

int N;
int A[MAXN];

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
    scanf("%*d%d", A + i);
  for (int i = 1; i <= N; i++)
    printf("%d ", A[i] == A[i + 1] ? N - i + 1 : 1);
  puts("");
}