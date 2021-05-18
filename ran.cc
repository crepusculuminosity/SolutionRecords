#pragma GCC target("avx,avx2")
#include <cstdio>
#include <immintrin.h>

int n, m, num, x[5], opt, p, q, k;
__m256i a[25010];

inline void add(int l, int r, int v) {
  while (((l - 1) & 3) && l <= r)
    ((long long *)(a + (l >> 2) + 1))[(l & 3) - 1] += v, ++l;
  if (l == r + 1)
    return;
  while ((r & 3) && l <= r)
    ((long long *)(a + (r >> 2) + 1))[(r & 3) - 1] += v, --r;
  if (l == r + 1)
    return;
  l = (l >> 2) + 1, r >>= 2;
  __m256i s = _mm256_set_epi64x(v, v, v, v);
  while (l <= r)
    a[l] = _mm256_add_epi64(a[l], s), ++l;
}

inline long long query(int l, int r) {
  long long ans(0);
  while (((l - 1) & 3) && l <= r)
    ans += ((long long *)(a + (l >> 2) + 1))[(l & 3) - 1], ++l;
  if (l == r + 1)
    return ans;
  while ((r & 3) && l <= r)
    ans += ((long long *)(a + (r >> 2) + 1))[(r & 3) - 1], --r;
  if (l == r + 1)
    return ans;
  l = (l >> 2) + 1, r >>= 2;
  __m256i s = _mm256_set_epi64x(0, 0, 0, 0);
  while (l <= r)
    s = _mm256_add_epi64(a[l], s), ++l;
  for (int i = 0; i < 4; ++i)
    ans += ((long long *)&s)[i];
  return ans;
}

int main() {
  scanf("%d%d", &n, &m);
  num = n >> 2;
  for (int i = 1; i <= num; ++i) {
    for (int j = 1; j <= 4; ++j)
      scanf("%d", x + j);
    a[i] = _mm256_set_epi64x(x[4], x[3], x[2], x[1]);
  }
  for (int i = 1; i <= (n & 3); ++i)
    scanf("%d", x + i);
  a[++num] = _mm256_set_epi64x(x[4], x[3], x[2], x[1]);

  while (m--) {
    scanf("%d%d%d", &opt, &p, &q);
    if (opt == 1)
      scanf("%d", &k), add(p, q, k);
    else
      printf("%lld\n", query(p, q));
  }
  return 0;
}
