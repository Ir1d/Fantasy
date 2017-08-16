/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2017-08-16 17:08:02
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

int a[25], b[25], c[233];
int t, n, p, num;
int idx, sta[233];
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &t);
  while (t--) {
    num = 0;
    scanf("%d", &n);
    a[0] = 0; p = 0;
    g(i, 1, n) {
      scanf("%d", a + i);
      f(j, p, p + a[i] - a[i - 1]) c[j] = j + 1;
      c[p + a[i] - a[i - 1]] = -(p + a[i] - a[i - 1] + 1);
      p = p + a[i] - a[i - 1] + 1;
    }
    int j = 0;
    f(i, 0, p) {
      if (c[i] > 0) sta[idx++] = c[i];
      else {
        num = sta[--idx];
        num = (-c[i] - num) / 2 + 1;
        b[j] = num; ++j;
      }
    }
    f(i, 0, j - 1) printf("%d ", b[i]);
    printf("%d\n", b[j - 1]);
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
