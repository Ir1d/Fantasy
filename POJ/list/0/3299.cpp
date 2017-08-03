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
const int oo = ~0u >> 2;
const double pi = acos(-1.0);
const double EPS = 1e-8;
const int MAXN = 100033;

char s[2];
double t, d, h;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif
  for (;;) {
    t = d = h = -1;
    f(i, 0, 2) {
      scanf("%s", s);
      if (s[0] == 'E') return 0;
      if (s[0] == 'T') scanf("%lf", &t);
      if (s[0] == 'D') scanf("%lf", &d);
      if (s[0] == 'H') scanf("%lf", &h);
    }
    if (fabs(t + 1) <= 1e-6) t = h - 0.5555 * (6.11 * exp(5417.7530 * ((1 / 273.16) - (1 / (d + 273.16)))) - 10);
    if (fabs(d + 1) <= 1e-6) d = 1 / ((1 / 273.16) - log(((h - t) / 0.5555 + 10.0) / 6.11) / 5417.7530) - 273.16;
    if (fabs(h + 1) <= 1e-6) h = t + 0.5555 * (6.11 * exp(5417.7530 * ((1 / 273.16) - (1 / (d + 273.16)))) - 10.0);
    // h = 0.5555 * (h - 10.0) + t;
    printf("T %.01lf D %.01lf H %.01lf\n", t, d, h);
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
