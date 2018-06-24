/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-24 16:52:50
 * @copyright MIT
 */
#include <cmath>          // NOLINT
#include <algorithm>          // NOLINT
#include <cstdio>         // NOLINT
#include <cstring>        // NOLINT
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

typedef long long LL;  // NOLINT
typedef long double real;

const double INF = 1e100;
const int oo = ~0u >> 2;
const double pi = acos(-1.0);
const double EPS = 1e-8;
const int MAXN = 100033;

int T;
int n;
int x[55], y[55];
inline int Q(int x) {
  return x * x;
}
inline double w(int a, int b) {
  return sqrt(1.0 * Q(x[a] - x[b]) + Q(y[a] - y[b]));
}
double dp[55][55];
double dis[55][55];
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (~scanf("%d", &n)) {
    f(i, 0, n) scanf("%d%d", x + i, y + i);
    f(i, 0, n) {
      f(j, 0, i) {
        dp[i][j] = dp[j][i] = 1e100;
        dis[i][j] = dis[j][i] = w(i, j);
      }
      dis[i][i] = 0;
      dp[i][i] = 1e100;
    }
    dp[0][1] = dp[1][0] = dis[0][1];
    f(i, 1, n) f(j, 0, i) {
      dp[i][j] = std::min(dp[i][j], dp[i - 1][j] + dis[i - 1][i]);
      dp[i][i - 1] = std::min(dp[i][i - 1], dp[i - 1][j] + dis[j][i]);
      // dp[i][i - 1] = std::min(dp[i][i - 1], dp[i][j] + dis[j][i - 1]);
    }
    double res = 1e100;
    f(i, 0, n - 1) {
      res = std::min(res, dp[n - 1][i] + dis[i][n - 1]);
    }
    printf("%.2lf\n", res);
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
