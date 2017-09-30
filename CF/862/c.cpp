/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2017-09-30 16:29:00
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

int n, x;
int s;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d%d", &n, &x);
  if (n == 2) {
    if (x == 0) {
      puts("NO");
      return 0;
    }
    printf("YES\n0 %d\n", x);
    return 0;
  }
  puts("YES");
  if (n == 1) {
    printf("%d\n", x);
    return 0;
  }
  g(i, 1, n - 3) {
    s ^= i;
    printf("%d ", i);
  }
  if (s ^ x) printf("%d %d %d\n", 0, 1 << 17, (1 << 17) ^  x ^ s);
  else printf("%d %d %d\n", 1 << 17, 1 << 18, (1 << 17) ^ (1 << 18));


#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
