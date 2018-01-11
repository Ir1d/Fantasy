/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2017-08-17 11:00:18
 * @license Star And Thank Author
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

int dis[533][533];
int lowc[533];
bool vis[533];
int n;
int prim() {
  int s = 1, m = 1;
  memset(vis, 0, sizeof vis);
  int mn, p, ans = 0;
  memset(lowc, 0x1f, sizeof lowc);
  while (m != n) {
    mn = oo;
    g(i, 2, n) {
      if (!vis[i] && lowc[i] > dis[s][i]) lowc[i] = dis[s][i];
      if (!vis[i] && mn > lowc[i]) {
        mn = lowc[i];
        p = i;
      }
    }
    if (ans < mn) ans = mn;
    s = p;
    vis[s] = 1;
    ++m;
  }
  return ans;
}
int T;
int w;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    g(i, 1, n) g(j, 1, n) scanf("%d", &dis[i][j]);
    printf("%d\n", prim());
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
