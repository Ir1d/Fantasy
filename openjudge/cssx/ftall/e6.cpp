/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-27 11:24:45
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

int n, V, k;
int w[1033], v[1033];
int dp[1055][533];
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d%d%d", &n, &V, &k);
  f(i, 0, k) scanf("%d%d", w + i, v + i);
  f(i, 0, k) gd(r, n, w[i]) gd(j, V, v[i]) dp[r][j] = std::max(dp[r][j], dp[r - w[i]][j - v[i]] + 1);
  printf("%d ", dp[n][V]);
  g(i, 0, V) if (dp[n][i] == dp[n][V]) {
    printf("%d\n", V - i);
    break;
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

