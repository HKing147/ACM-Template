/*************************************************************************
 > File Name: test.cpp
 > Author: HKing
 > Mail: 1470042308@qq.com
 > Created Time: 2021年05月23日 星期日 20时13分14秒
*************************************************************************/

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define out(n) cout << n << ' '
#define outl(n) cout << n << endl
#define sd(n) scanf("%d", &n)
#define sdd(n, m) scanf("%d%d", &n, &m)
#define sddd(n, m, k) scanf("%d%d%d", &n, &m, &k)
#define pd(n) printf("%d\n", (n))
#define pdd(n, m) printf("%d %d\n", n, m)
#define pddd(n, m, k) printf("%d %d %d\n", n, m, k)
#define sld(n) scanf("%lld", &n)
#define sldd(n, m) scanf("%lld%lld", &n, &m)
#define slddd(n, m, k) scanf("%lld%lld%lld", &n, &m, &k)
#define pld(n) printf("%lld\n", n)
#define pldd(n, m) printf("%lld %lld\n", n, m)
#define plddd(n, m, k) printf("%lld %lld %lld\n", n, m, k)
#define sf(n) scanf("%lf", &n)
#define sff(n, m) scanf("%lf%lf", &n, &m)
#define sfff(n, m, k) scanf("%lf%lf%lf", &n, &m, &k)
#define ss(str) scanf("%s", str)
#define ps(str) printf("%s", str)
#define x first
#define y second
#define pi acos(-1)
#define de(c, n)                                                               \
  for (int i = 0; i < n; ++i)                                                  \
    cout << c;                                                                 \
  cout << endl
#define debug(a) cout << #a << '=' << a << endl
#define INF_INT 0x3f3f3f3f;
#define INF_LONG 4557430888798830399
#define mem(ar, num) memset(ar, num, sizeof(ar))
#define me(ar) memset(ar, 0, sizeof(ar))
#define all(v) v.begin(), v.end()
#define max(a, b, c) max(a, max(b, c))
#define lowbit(x) (x & (-x))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) a / gcd(a, b) * b
#define qpow(a, k, p)                                                          \
  ({                                                                           \
    LL s = 1;                                                                  \
    while (k > 0) {                                                            \
      if (k & 1)                                                               \
        s = s * a % p;                                                         \
      a = a * a % p;                                                           \
      k >>= 1;                                                                 \
    }                                                                          \
    s;                                                                         \
  })
#define inv(a, p)                                                              \
  ({                                                                           \
    LL q = p - 2;                                                              \
    qpow(a, q, p);                                                             \
  })
#define W(t)                                                                   \
  cin >> t;                                                                    \
  while (t--)
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
typedef pair<LL, LL> PLL;
typedef pair<LL, PLL> PLLL;

int main() {
  IOS;

  return 0;
}
