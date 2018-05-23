/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2018-05-23 10:06:26
 * @copyright MIT
 */
#include <cstdio>// NOLINT
#include <cstring>// NOLINT
#include <algorithm>// NOLINT
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
double w[1033];
int l[1033], r[1033];
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &n);
  f(i, 0, n) scanf("%lf", w + i);
  f(i, 0, n) l[i] = r[i] = 1;
  f(i, 0, n) {
    f(j, 0, i) if (w[i] > w[j]) {
      l[i] = std::max(l[i], l[j] + 1);
    }
  }
  f(i, 1, n) l[i] = std::max(l[i], l[i - 1]);
  gd(i, n - 1, 0) {
    fd(j, n - 1, i) if (w[i] > w[j]) {
      r[i] = std::max(r[i], r[j] + 1);
    }
  }
  gd(i, n - 1, 0) r[i] = std::max(r[i], r[i + 1]);
  int res = 0;
  f(i, 0, n) {
    res = std::max(res, l[i] + r[i + 1]);
  }
  printf("%d\n", n - res);

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
