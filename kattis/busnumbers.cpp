/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2017-10-01 18:50:38
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
#include <algorithm>
int a[1023];
int c;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &n);
  f(i, 0, n) scanf("%d", a + i);
  std::sort(a, a + n);
  printf("%d", a[0]);
  f(i, 1, n) {
    if (a[i] == a[i - 1] + 1) ++c;
    else {
      if (c) {
        if (c > 1) printf("-%d %d", a[i - 1], a[i]);
        else printf(" %d %d", a[i - 1], a[i]);
        c = 0;
      } else printf(" %d", a[i]);
    }
  }
  if (c > 1) printf("-%d", a[n - 1]);
  else if (c) printf(" %d", a[n - 1]);

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
