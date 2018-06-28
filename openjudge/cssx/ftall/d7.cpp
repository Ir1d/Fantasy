/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-28 22:38:37
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

int n, w;
typedef std::pair<int, int> PII;
int c[23];
PII dp[MAXN * 3];
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d%d", &n, &w);
  f(i, 0, n) scanf("%d", c + i);
  memset(dp, 0x1f, sizeof dp);
  dp[0] = PII(1, 0);
  f(s, 1, 1 << n) {
    f(i, 0, n) if (s & (1 << i)) {
      if (dp[s ^ (1 << i)].second + c[i] <= w) {
        dp[s] = std::min(dp[s], PII(dp[s ^ (1 << i)].first, dp[s ^ (1 << i)].second + c[i]));
      }
      if (dp[s ^ (1 << i)].second <= w) {
        dp[s] = std::min(dp[s], PII(dp[s ^ (1 << i)].first + 1, c[i]));
      }
    }
  }
  printf("%d\n", dp[(1 << n) - 1].first);

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

