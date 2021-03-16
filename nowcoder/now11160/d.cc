#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e6 + 10;
struct HashSet {
  struct node {
    int k, v, nex;
  } buf[maxn];
  int h[maxn], tot, mod = 1e6 + 9;
  void insert(int x) {
    int pos = x % mod;
    for (int i = h[pos]; i; i = buf[i].nex) {
      if (buf[i].k == x)
    }
  }
}