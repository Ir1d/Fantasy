/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-23 16:20:03
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
int n, k;
int m[233];
int p[233];
int dp[233];
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &k);
    f(i, 0, n) scanf("%d", m + i);
    f(i, 0, n) scanf("%d", p + i);
    memset(dp, 0, sizeof dp);
    f(i, 0, n)  {
      dp[i] = p[i];
      f(j, 0, i) 
      if (m[i] - m[j] > k) {
        dp[i] = std::max(dp[i], dp[j] + p[i]);
      }
    }
    f(i, 0, n) dp[0] = std::max(dp[0], dp[i]);
    printf("%d\n", dp[0]);
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

