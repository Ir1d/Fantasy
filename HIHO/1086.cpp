/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-29 09:59:27
 * @copyright MIT
 */
#include <cstdio>// NOLINT
#include <cstring>// NOLINT
#include <bits/stdc++.h>// NOLINT
#include <cmath>// NOLINT
#define x1 x11
#define y1 y11

#define f(x, y, z) for (int x = (y), __ = (z); x < __; ++x)
#define g(x, y, z) for (int x = (y), __ = (z); x <= __; ++x)
#define fd(x, y, z) for (int x = (y), __ = (z); x > __; --x)
#define gd(x, y, z) for (int x = (y), __ = (z); x >= __; --x)

#ifdef WIN32
  #define LLD "%I64d"
  #define LLU "%I64u"
#else
  #define LLD "%lld"
  #define LLU "%llu"
#endif

typedef long long LL;// NOLINT
typedef long double real;

const double INF = 1e100;
const int oo = ~0u >> 2;
const double pi = acos(-1.0);
const double EPS = 1e-8;
const int MAXN = 100033;

int n;
int w;
int a[133], b[133], c[133];
LL dp[MAXN];
void complete(int v, int ww) {
  g(i, v, w) dp[i] = std::max(dp[i], dp[i - v] + ww);
}
void zeroOne(int v, int ww) {
  gd(i, w, v) dp[i] = std::max(dp[i], dp[i - v] + ww);
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d%d", &n, &w);
  f(i, 0, n) {
    scanf("%d%d%d", a + i, b + i, c + i);
    if (a[i] * c[i] >= w) {
      complete(a[i], b[i]);
    } else {
      int cc = c[i], k = 1;
      while (cc >= k) {
        zeroOne(a[i] * k, b[i] * k);
        cc -= k;
        k <<= 1;
      }
      zeroOne(a[i] * cc, b[i] * cc);
    }
  }
  g(i, 1, w) dp[0] = std::max(dp[9], dp[i]);
  printf(LLD"\n", dp[0]);

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

