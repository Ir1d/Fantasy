/**
 * POJ 1195
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-10-13 17:04:16
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

int tp, s, x, y, a;
int l, b, r, t;
int w[1025][1025];
inline int get(int x, int y) {
  int res = 0;
  for (; x; x -= x & -x) {
    for (int j = y; j; j -= j & -j) {
      res += w[x][j];
    }
  }
  return res;
}
inline void update(int x, int y, int v) {
  for (; x <= s; x += x & -x) {
    for (int j = y; j <= s; j += j & -j) {
      w[x][j] += v;
    }
  }
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (~scanf("%d", &tp) && tp != 3) {
    if (tp == 0) {
      scanf("%d", &s);
    } else if (tp == 1) {
      scanf("%d%d%d", &x, &y, &a);
      ++x; ++y;
      update(x, y, a);
    } else if (tp == 2) {
      scanf("%d%d%d%d", &l, &b, &r, &t);
      ++l; ++b; ++r; ++t;
      printf("%d\n", get(r, t) + get(l - 1, b - 1) - get(l - 1, t) - get(r, b - 1));
    }
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

