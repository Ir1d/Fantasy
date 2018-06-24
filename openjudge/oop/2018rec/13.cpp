/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-24 19:06:22
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
int a[MAXN][3];
int dp[MAXN][2][2];
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &n);
  f(j, 0, 3) f(i, 0, n) scanf("%d", &a[i][j]);
  memset(dp, 0, sizeof dp);
  dp[0][0][0] = a[0][0];
  dp[0][0][1] = a[0][1];
  f(i, 1, n) f(j, 0, 2) f(k, 0, 2) f(t, 0, 2) {
    dp[i][k][t] = std::max(dp[i][k][t], dp[i - 1][j][k ^ 1] + a[i][k + t]);
  }
  printf("%d\n", std::max(dp[n - 1][0][0], dp[n - 1][1][0]));

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

