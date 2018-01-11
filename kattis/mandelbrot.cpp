/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2017-10-01 19:54:17
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

struct complex {
  double r, i;
  inline complex (double r = 0, double i = 0):r(r), i(i) {}
  complex operator + (const complex& T) const {
    return complex(r + T.r, i + T.i);
  }
  complex operator * (const complex& T) const {
    return complex(r * T.r - i * T.i, r * T.i + i * T.r);
  }
} z, c;
double x, y;
int r;
int ti = 0;
void solve() {
  printf("Case %d: ", ++ti);
  z.r = z.i = 0;
  f(i, 0, r) {
    z = z * z + c;
    if ((z.r * z.r + z.i * z.i) > 4) {
      puts("OUT");
      return;
    }
  }
  puts("IN");
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (~scanf("%lf%lf%d", &c.r, &c.i, &r)) {
    solve();
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
