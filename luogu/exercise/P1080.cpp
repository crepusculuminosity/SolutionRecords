#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;

struct Minister {
  int left;
  int right;
  int pro;
} mini[1005];

bool cmp(Minister &a, Minister &b) { return a.pro < b.pro; }

inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}

class BigInteger {
public:
  int val[MAXN];
  short len;
  BigInteger();
  BigInteger(int n);
  void clean();
  friend ostream &operator<<(ostream &, const BigInteger &);
  friend istream &operator>>(istream &, BigInteger &);
  friend BigInteger operator+(const BigInteger &a, const BigInteger &b);
  friend BigInteger operator*(const BigInteger &a, const BigInteger &b);
  // friend BigInteger operator/(const BigInteger& a, const BigInteger& b);
};

BigInteger::BigInteger(int n) {
  for (int i = 0; i < MAXN; i++)
    val[i] = 0;
  n = n > 0 ? n : -n;
  for (len = 1; n; len++, n /= 10)
    val[len] = n % 10;
  len--;
}

BigInteger::BigInteger() {
  for (int i = 0; i < MAXN; i++)
    val[i] = 0;
  len = 0;
}

ostream &operator<<(ostream &out, const BigInteger &obj) {
  if (obj.len == 0) {
    cout << 0;
    return out;
  }
  for (int i = obj.len; i > 0; i--)
    out << obj.val[i];
  return out;
}

istream &operator>>(istream &in, BigInteger &obj) {
  string s;
  in >> s;
  int i = s.length(), j = 0;
  obj.len = s.length();
  for (; i > 0; i--, j++)
    obj.val[i] = s[j] - '0';
  return in;
}

BigInteger operator+(const BigInteger &a, const BigInteger &b) {
  BigInteger c;
  int max = a.len > b.len ? a.len : b.len;
  for (int i = 1; i <= max; i++) {
    c.val[i] += a.val[i] + b.val[i];
    c.val[i + 1] = c.val[i] / 10;
    c.val[i] %= 10;
  }
  if (c.val[max + 1] == 0)
    c.len = max;
  else
    c.len = max + 1;
  return c;
}

BigInteger operator*(const BigInteger &a, const BigInteger &b) {
  BigInteger c;
  c.len = a.len + b.len;
  for (int i = 1; i <= a.len; i++)
    for (int j = 1; j <= b.len; j++)
      c.val[i + j - 1] += a.val[i] * b.val[j];
  for (int i = 1; i <= c.len; i++) {
    c.val[i + 1] += c.val[i] / 10;
    c.val[i] %= 10;
  }
  c.clean();
  return c;
}

void BigInteger::clean() {
  while (len > 0 && !val[len])
    len--;
}

BigInteger divide(BigInteger &a, int b) {
  BigInteger c;
  c.len = a.len;
  int q = 0;
  for (int i = a.len; i > 0; i--) {
    int dividend = 10 * q + a.val[i];
    c.val[i] = dividend / b;
    q = dividend % b;
  }
  c.clean();
  return c;
}

bool comp(const BigInteger &a, const BigInteger &b) { // a<=b返回1
  if (a.len != b.len)
    return a.len < b.len;
  for (int i = a.len; i > 0; i--) {
    if (a.val[i] != b.val[i])
      return a.val[i] < b.val[i];
  }
  return true;
}

int main() {
  int n = read();
  for (int i = 0; i <= n; i++) {
    mini[i].left = read();
    mini[i].right = read();
    mini[i].pro = mini[i].left * mini[i].right;
  }
  BigInteger product(mini[0].left);
  BigInteger ans(0);
  sort(mini + 1, mini + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    if (comp(ans, divide(product, mini[i].right)))
      ans = divide(product, mini[i].right);
    product = product * mini[i].left;
  }
  cout << ans << endl;
  return 0;
}
