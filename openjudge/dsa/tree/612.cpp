/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-12-20 00:09:21
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

int n, p;
struct node {
  int t, x;
} e[MAXN];
int head[MAXN], cnt = 1;
int sz[MAXN];
inline void add(int s, int t) {
  e[++cnt].t = t; e[cnt].x = head[s]; head[s] = cnt;
}
int dp[155][155];
void dfs(int x, int fa) {
  dp[x][1] = 0;
  sz[x] = 1;
  for (int i = head[x]; i; i = e[i].x) {
    int v = e[i].t;
    if (v == fa) continue;
    dfs(v, x);
    sz[x] += sz[v];
    gd(k, sz[x], 1) {
      dp[x][k] = dp[x][k] + 1;
      f(l, 1, k) {
        dp[x][k] = std::min(dp[x][k], dp[x][k - l] + dp[v][l]);
      }
    }
  }
}

int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d%d", &n, &p);
  int x, y;
  memset(dp, 0x1f, sizeof dp);
  dp[0][0] = 1;
  f(i, 1, n) {
    dp[i][0] = 1;
    scanf("%d%d", &x, &y);
    add(x, y);
    add(y, x);
  }
  dfs(1, -1);
  // f(i, 0, n) w[i] = PII(sz[i], i);
  int res = dp[1][p];
  g(i, 2, n) res = std::min(res, dp[i][p] + 1);
  printf("%d\n", res);
  

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

