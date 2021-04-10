#include <bits/stdc++.h>

#include <ctime>
using namespace std;
constexpr int MAXN = 100005;
constexpr int mod = 1e9 + 7;
using ll = long long;
class BigInteger {
public:
  int val[MAXN];
  int len;
  BigInteger();
  BigInteger(int n);
  void clean();
  friend ostream &operator<<(ostream &, const BigInteger &);
  friend istream &operator>>(istream &, BigInteger &);
  friend BigInteger operator/(const BigInteger &, int);
  friend BigInteger operator+(const BigInteger &a, const BigInteger &b);
  friend BigInteger operator*(const BigInteger &a, const BigInteger &b);
  friend BigInteger operator%(const BigInteger &a, int b);
  // friend BigInteger operator-(const BigInteger &a, const BigInteger &b);
  friend bool operator>(const BigInteger &, const BigInteger &);
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

void minus1(BigInteger &a) {
  int i = 1;
  while (a.val[i] == 0)
    ++i;
  --a.val[i];
  for (int j = 1; j <= i - 1; j++)
    a.val[j] = 9;
  a.clean();
}

BigInteger operator/(const BigInteger &a, int b) {
  BigInteger c;
  c.len = a.len;
  int q = 0;
  for (int i = a.len; i > 0; i--) {
    int di = 10 * q + a.val[i];
    c.val[i] = di / b;
    q = di % b;
  }
  c.clean();
  return c;
}

bool operator>(const BigInteger &a, const BigInteger &b) {
  if (a.len > b.len)
    return 1;
  int i = a.len;
  while (a.val[i] == b.val[i] && i)
    --i;
  return a.val[i] > b.val[i];
}

void BigInteger::clean() {
  while (len > 0 && !val[len])
    --len;
}

int getmo(BigInteger &a) {
  ll res = 0, len = a.len;
  for (int i = len; i >= 1; i--) {
    res = (res * 10 + a.val[i]) % mod;
  }
  return res;
}
int main() {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  clock_t s = clock();
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  BigInteger n;
  cin >> n;
  BigInteger ans(0);
  int cnt = 1;
  while (n > 0) {
    if (cnt == 1) {
      ans = n;
      minus1(ans);
    } else
      ans = ans + cnt * n;
    if (cnt == 7)
      cnt = 9;
    if (cnt == 1)
      cnt = 7;
    n = n / 10;
  }
  // minus1(ans);
  cout << getmo(ans) << '\n';
  clock_t e = clock();
  cout << (double)(e - s) / CLOCKS_PER_SEC;
  return 0;
}