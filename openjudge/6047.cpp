/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2018-05-25 19:33:43
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

int dp[25][25][25];
int w, h, m;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  g(i, 1, 20) {
    g(j, 1, 20) {
      dp[i][j][1] = i * j;
      g(k, 2, 20) {
        dp[i][j][k] = oo;
        f(r, 1, i) {
          // dp[i][j][k] = std::min(dp[i][j][k], std::max(dp[r][j][k - 1], (i - r) * j));
          f(p, 1, k) {
            dp[i][j][k] = std::min(dp[i][j][k], std::max(dp[r][j][p], dp[i - r][j][k - p]));
          }
        }
        f(c, 1, j) {
          // dp[i][j][k] = std::min(dp[i][j][k], std::max(dp[i][c][k - 1], (j - c) * i));
          f(p, 1, k) {
            dp[i][j][k] = std::min(dp[i][j][k], std::max(dp[i][c][p], dp[i][j - c][k - p]));
          }
        }
      }
    }
  }
  while (~scanf("%d%d%d", &w, &h, &m) && (w || h || m)) {
    printf("%d\n", dp[w][h][m]);
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
