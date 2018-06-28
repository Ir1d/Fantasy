/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-28 21:52:19
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

int n, m, p;
int t[255], u[255], v[255];
int x[255], y[255], z[255];
int dp[MAXN];
int mn;
void zeroOne(int w, int v) {
  gd(i, 50000, w) {
    dp[i] = std::min(dp[i], dp[i - w] + v);
    if (i >= p) mn = std::min(mn, dp[i]);
  }
}
void zeroOne1(int w, int v) {
  gd(i, 50000, w) {
    dp[i] = std::max(dp[i], dp[i - w] + v);
  }
}
int T;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d", &n, &m, &p);
    g(i, 1, n) scanf("%d%d%d", t + i, u + i, v + i);
    g(i, 1, m) scanf("%d%d%d", x + i, y + i, z + i);
    g(i, 0, 50000) dp[i] = oo;
    mn = oo;
    dp[0] = 0;
    g(i, 1, n) {
      int k = 1, cc = v[i];
      while (k <= cc) {
        zeroOne(t[i] * k, u[i] * k);
        cc -= k;
        k <<= 1;
      }
      zeroOne(t[i] * cc, u[i] * cc);
    }
    memset(dp, 0, sizeof dp);
    g(i, 1, m) {
      int k = 1, cc = z[i];
      while (k <= cc) {
        zeroOne1(y[i] * k, x[i] * k);
        cc -= k;
        k <<= 1;
      }
      zeroOne1(y[i] * cc, x[i] * cc);
    }
    bool ctf = 1;
    g(i, 0, 50000) {
      if (dp[i] >= mn) {
        printf("%d\n", i);
        ctf = 0;
        break;
      }
    }
    if (ctf) puts("FAIL");
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

