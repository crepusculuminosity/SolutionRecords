#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 110;
const int mod = 10000;
struct Matrix {
  ll a[maxn][maxn];
  int n;
  Matrix(int n) {
    this->n = n;
    for (int i = 1; i <= n; i++)
      a[i][i] = 0;
  }
  void clear() {
    memset(a, 0, sizeof(a));
    return;
  }
  void unit() {
    clear();
    for (int i = 1; i <= n; i++)
      a[i][i] = 1;
  }
  friend Matrix operator*(const Matrix &o1, const Matrix &o2) {
    int n = o1.n;
    Matrix res(n);
    res.clear();
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        for (int k = 1; k <= n; k++) {
          res.a[i][j] = (res.a[i][j] + o1.a[i][k] * o2.a[k][j]) % mod;
        }
    return res;
  }
  friend Matrix operator+(const Matrix &o1, const Matrix &o2) {
    int n = o1.n;
    Matrix res(n);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        res.a[i][j] = (o1.a[i][j] + o2.a[i][j]) % mod;
    return res;
  }
  void print() {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++)
        cout << a[i][j] << ' ';
      cout << '\n';
    }
  }
  void scan() {
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        cin >> a[i][j];
  }
};

inline Matrix ksm(Matrix &o, ll k) {
  Matrix res(o.n);
  res.unit();
  while (k) {
    if (k & 1)
      res = (res * o);
    o = o * o;
    k >>= 1;
  }
  return res;
}
ll n;
int main() {
  freopen("data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  Matrix res(2);
  //r.a[2][2] = r.a[1][2] = r.a[2][1] = 1, r.a[1][1] = 0;
  while (cin >> n && ~n) {
    res.a[1][1] = 0, res.a[1][2] = 1, res.a[2][1] = 1, res.a[2][2] = 1;
  // res.scan();
    res = ksm(res, n);
    cout << res.a[2][1] <<'\n';
  }
  return 0;
}