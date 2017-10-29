/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2017-10-04 15:57:35
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
char s[10033];
int p, len;
char map[133][133];
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &n);
  f(i, 0, n) {
    scanf("%s", s);
    len = strlen(s);
    p = 0;
    while (p * p < len) ++p;
    f(x, 0, p) {
      for (int y = p - 1; y >= 0; --y) {
        if (y * p + x < len) putchar(s[y * p + x]);
      }
    }
    puts("");
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}