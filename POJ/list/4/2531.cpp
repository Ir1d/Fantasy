/**
 * @author Ir1d (sirius.caffrey@gmail.com)
 * @date    2018-01-14 10:15:42
 * @copyright MIT
 */
#include <cstdio>// NOLINT
#include <cstring>// NOLINT
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

int dis[32][32];
int n, ans;
int is[32];
void dfs(int x, int s) {
  if (x >= n) {
    if (s > ans) ans = s;
    return;
  }
  int t = 0;
  is[x] = 1;
  f(i, 0, x) if (!is[i]) t += dis[x][i];
  dfs(x + 1, s + t);

  t = 0;
  is[x] = 0;
  f(i, 0, x) if (is[i]) t += dis[i][x];
  dfs(x + 1, s + t);
}

int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &n);
  f(i, 0, n) f(j, 0, n) scanf("%d", &dis[i][j]);
  ans = 0;
  is[0] = 1;
  dfs(1, 0);
  printf("%d\n", ans);

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
