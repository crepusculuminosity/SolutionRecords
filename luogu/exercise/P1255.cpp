#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
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
  BigInteger operator=(const BigInteger &);
};

BigInteger::BigInteger(int n) {
  for (int i = 0; i < MAXN; i++)
    val[i] = 0;
  n = n > 0 ? n : -n;
  for (len = 1; n; len++, n /= 10)
    val[len] = n % 10;
  len--;
}

BigInteger BigInteger::operator=(const BigInteger &obj) {
  len = obj.len;
  for (int i = 1; i <= len; i++)
    val[i] = obj.val[i];
  return *this;
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

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int n;
  cin >> n;
  if (n == 0)
    cout << 0 << endl;
  else {
    BigInteger f[3];
    f[1] = 1;
    f[2] = 2;
    for (int i = 2; i <= n; i++)
      f[(i + 1) % 3] = f[i % 3] + f[(i + 2) % 3];
    cout << f[n % 3] << endl;
  }
  return 0;
}
