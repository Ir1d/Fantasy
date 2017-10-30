/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2017-10-30 20:44:54
 * @license Star And Thank Author
 */

// #include <bits/stdc++.h>// NOLINT
#include <cstdio>// NOLINT
#include <cstring>// NOLINT
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

int n, t, m;
double f[1033][35];
double g[1033][35][35];
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (~scanf("%d%d%d", &n, &t, &m) && (n || m || t)) {
    double ans = 1;
    f(i, 0, t) {
      g(j, 1, n) scanf("%lf", &f[i][j]);
    }
    memset(g, 0, sizeof g);
    f(i, 0, t) {
      g[i][0][0] = 1;
      g(j, 1, n) {
        g[i][j][0] = g[i][j - 1][0] * (1 - f[i][j]);
        g(k, 1, j) {
          g[i][j][k] = g[i][j - 1][k - 1] * (f[i][j]) + g[i][j - 1][k] * (1 - f[i][j]);
        }
      }
    }
    f(i, 0, t) ans *= 1 - g[i][n][0];
    double temp = 1;
    f(i, 0, t) {
      double sum = 0;
      f(j, 1, m) sum += g[i][n][j];
      temp *= sum;
    }
    ans -= temp;
    printf("%.3f\n", ans);
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
