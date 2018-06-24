/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-24 20:49:23
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

int T;
int n, m;
int dp[23][23];
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &T);
  g(i, 1, 20) dp[0][i] = 1;
  g(i, 1, 20) {
    g(j, 1, 20) {
      if (i >= j) dp[i][j] = dp[i][j - 1] + dp[i -j][j];
      else dp[i][j] = dp[i][i];
    }
  }
  while (T--) {
    scanf("%d%d", &n, &m);
    printf("%d\n", dp[n][m]);
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

