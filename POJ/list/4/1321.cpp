/**
 * @author Ir1d (sirius.caffrey@gmail.com)
 * @date    2018-01-13 12:38:21
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

int n, k;
char map[12][12];
int vx[12];
int vy[12];
int ans;
void dfs(int dep, int num) {
  if (num == k) {
    ++ans;
    return;
  }
  if (dep >= n) {
    return;
  }
  f(i, 0, n) {
    if (map[dep][i] == '#' && vy[i] == 0 && vx[dep] == 0) {
      vy[i] = 1; vx[dep] = 1;
      dfs(dep + 1, num + 1);
      vy[i] = 0; vx[dep] = 0;
    }
  }
  dfs(dep + 1, num);
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (~scanf("%d%d", &n, &k) && (n != -1 || k != -1)) {
    f(i, 0, n) {
      scanf("%s", map[i]);
    }
    memset(vx, 0, sizeof vx);
    memset(vy, 0, sizeof vy);
    ans = 0;
    dfs(0, 0);
    printf("%d\n", ans);
  }


#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
