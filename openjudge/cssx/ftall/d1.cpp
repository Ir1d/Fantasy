/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-28 14:34:43
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
int a, b;
LL dp[55];
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &n);
  
  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;
  g(j, 3, 50) {
    dp[j] = dp[j - 1] + dp[j - 2];
  }
  f(i, 0, n) {
    scanf("%d%d", &a, &b);
    printf(LLD"\n", dp[abs(b - a)]);
    // printf("%d\n", dp[(a == b) ? 0 : 1][abs((b - 1) / 2 - (a - 1) / 2)]);
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

