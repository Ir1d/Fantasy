/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-12-22 12:11:05
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

int dp[10033][501];
int n, m;
int d[10033];
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (~scanf("%d%d", &n, &m)) {
    // memset(dp, 0, sizeof dp);
    g(i, 1, n) scanf("%d", d + i);
    g(i, 1, n) {
      dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1]);
      // f(j, 1, i) dp[i][0] = std::max(dp[i][0], dp[i - j][j]);
      g(j, 1, m) {
        dp[i][j] = std::max(dp[i][j], std::max(0, dp[i - 1][j - 1] + d[i]));
        if (i > j) dp[i][0] = std::max(dp[i][0], dp[i - j][j]);
      }
    }
    printf("%d\n", dp[n][0]);
    // break;
  } 


#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

