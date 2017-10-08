/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2017-10-04 15:51:01
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

int w, p;
int a[233];
int vis[233];
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d%d", &w, &p);
  f(i, 0, p) scanf("%d", a + i);
  f(i, 0, p) f(j, 0, i) {
    vis[int(std::abs(a[i] - a[j]))] = 1;
  }
  f(i, 0, w) {
    vis[a[i]] = 1;
    vis[w - a[i]] = 1;
  }
  g(i, 1, w) if (vis[i]) printf("%d ", i);

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
