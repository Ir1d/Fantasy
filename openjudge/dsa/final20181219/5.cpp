/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-12-19 17:34:14
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

struct node {
  int t, x;
} e[MAXN * 2];
int head[MAXN], cnt = 1;
inline void add(int s, int t) {
  e[++cnt].t = t; e[cnt].x = head[s]; head[s] = cnt;
}
int dp[MAXN][22];
int sz[MAXN];
int n, k;
int u, v;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d%d", &n, &k);
  f(i, 1, n) {
    scanf("%d%d", &u, &v);
    add(u, v);
    add(v, u);
    ++sz[u]; ++sz[v];
  }
  g(i, 1, n) {
    scanf("%d", &dp[i][0]);
  } 
  g(j, 1, k) {
    g(u, 1, n) {
      for(int i = head[u]; i; i = e[i].x) {
        dp[u][j] += dp[e[i].t][j - 1];
      }
      if (j > 1) dp[u][j] -= (sz[u] - 1) * dp[u][j - 2];
      else dp[u][1] += dp[u][0];
    }
  }
  g(i, 1, n) printf("%d\n", dp[i][k]);


#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

