/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2017-08-17 09:18:52
 * @license Star And Thank Author
 */

#include <cstdio>// NOLINT
#include <cstdlib>// NOLINT
#include <algorithm>// NOLINT
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

int map[123][123];
int dis[123][123];
int n;
int ans;
int tee;
int x, w;
int idx;
int fa[123];
inline int get(int x) {
  int tee = fa[x], q;
  while (tee != fa[tee]) tee = fa[tee];
  while (x != tee) {
    q = fa[x]; fa[x] = tee; x = q;
  }
  return tee;
}
inline void unite(int x, int y) {
  if (rand() & 1) fa[get(x)] = get(y);
  else fa[get(y)] = get(x);
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  srand(9986213);
  while (~scanf("%d", &n) && n) {
    ans = oo;
    memset(map, 0x1f, sizeof map);
    g(i, 1, n) fa[i] = i;
    g(i, 1, n) {
      scanf("%d", &tee);
      while (tee--) {
        scanf("%d%d", &x, &w);
        map[i][x] = w;
        unite(i, x);
      }
    }
    bool ctf = 0;
    g(i, 1, n) {
      if (get(1) != get(i)) {
        ctf = 1;
        break;
      }
    }
    if (ctf) {
      puts("disjoint");
      continue;
    }
    g(k, 1, n) g(i, 1, n) g(j, 1, n) map[i][j] = std::min(map[i][j], map[i][k] + map[k][j]);
    g(i, 1, n) {
      tee = 0;
      g(j, 1, n) if (i != j && map[i][j] > tee) tee = map[i][j];
      if (ans > tee) {
        ans = tee;
        idx = i;
      }
    }
    printf("%d %d\n", idx, ans);
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
