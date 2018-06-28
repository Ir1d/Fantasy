/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-27 10:51:41
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
int dis[23][23];
int dp[MAXN][23];
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &n);
  f(i, 0, n) f(j, 0, n) scanf("%d", &dis[i][j]);
  memset(dp, 0x1f, sizeof dp);
  // dp[0][0] = 0;
  dp[1][0] = 0;
  dp[0][0] = 0;
  // f(i, 0, n) dp[0][i] = 0;
  f(s, 0, 1 << n) {
    f(i, 0, n) if (s & (1 << i)) {
      f(j, 0, n) if (s & (1 << j)) if (i != j) {
        dp[s][i] = std::min(dp[s][i], dp[s ^ (1 << i)][j] + dis[j][i]);
      }
    }
  }
  printf("%d\n", dp[(1 << n) - 1][n - 1]);
  // int res = oo;
  // f(i, 0, n) {
  //   res = std::min(res, dp[(1 << n) - 1][i]);
  // }
  // printf("%d\n", res);

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

