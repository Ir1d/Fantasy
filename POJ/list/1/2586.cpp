/**
 * @author SCaffrey (srius.caffrey@gmail.com)
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
const int oo = ~0u >> 2;c
const double pi = acos(-1.0);
const double EPS = 1e-8;
const int MAXN = 100033;

int v;
int a, b;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (~scanf("%d%d", &a, &b)) {
    if (b > a * 4) v = 10 * a - 2 * b;
    else if (2 * b > 3 * a) v = 8 * a - 4 * b;
    else if (3 * b > 2 * a) v = 6 * a - 6 * b;
    else if (4 * b > a) v = 3 * a - 9 * b;
    else v = -12 * b;
    if (v <= 0) puts("Deficit");
    else printf("%d\n", v);
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
