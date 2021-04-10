#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long ll;
ll a[N];

inline ll read()
{
    ll x = 0;
    char ch = getchar();
    while (!isdigit(ch))
        ch = getchar();
    while (isdigit(ch))
        x = x * 10 + ch - 48, ch = getchar();
    return x;
}
int main()
{
    ll n = read();
    for (ll i = 1; i <= n; i++)
        a[i] = read();
    sort(a + 1, a + 1 + n);
    ll ans = -1;
    int i = 1;
    while (i <= n) {
        int j = i;
        while (a[j] == a[j + 1])
            ++j;
        ans = max(ans, (j - i + 1) * a[i]);
        i = ++j;
    }
    printf("%lld", ans);
    return 0;
}