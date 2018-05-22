/**
 * @author Ir1d (sirius.caffrey@gmail.com)
 * @date    2018-01-14 18:06:16
 * @copyright MIT
 */
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

int a, b;
int c[23], d[23];
int dp[23][6500];
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d%d", &a, &b);
  g(i, 1, a) scanf("%d", c + i);
  g(i, 1, b) scanf("%d", d + i);
  dp[0][3200] = 1;
  g(i, 1, b) {
    g(j, 0, 6400) {
      if (dp[i - 1][j]) {
        g(k, 1, a) {
          dp[i][c[k] * d[i] + j] += dp[i - 1][j];
        }
      }
    }
  }
  printf("%d\n", dp[b][3200]);

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
