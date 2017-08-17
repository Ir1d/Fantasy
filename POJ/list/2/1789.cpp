/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2017-08-17 10:12:31
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
int n;
char code[2033][12];
int cost[2033][2033];
int vis[2033];
int lowc[2033];
inline int calc(int a, int b) {
  int res = 0;
  f(i, 0, 7) if (code[a][i] != code[b][i]) ++res;
  return res;
}
int prim() {
  int minc, res = 0, p;
  memset(vis, 0, sizeof vis);
  vis[0] = 1;
  f(i, 1, n) lowc[i] = cost[0][i];
  f(i, 1, n) {
    minc = oo; p = -1;
    f(j, 0, n) {
      if (!vis[j] && minc > lowc[j]) {
        minc = lowc[j]; p = j;
      }
    }
    if (minc == oo) return -1;
    res += minc;
    vis[p] = 1;
    f(j, 0, n) if (!vis[j] && lowc[j] > cost[p][j]) lowc[j] = cost[p][j];
  }
  return res;
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (~scanf("%d", &n) && n) {
    memset(cost, 0, sizeof cost);
    f(i, 0, n) scanf("%s", code[i]);
    f(i, 0, n - 1) f(j, i + 1, n) cost[j][i] = cost[i][j] = calc(i, j);
    printf("The highest possible quality is 1/%d.\n", prim());
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}