/**
 * @author SCaffrey (srius.caffrey@gmail.com)
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

int n, x, c[233], idx;
int ll, rr;
int a, b;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &n);
  while (n--) {
    memset(c, 0, sizeof c);
    idx = 0;
    scanf("%d", &x);
    f(i, 0, x) {
      scanf("%d%d", &a, &b);
      ll = a; rr = b;
      if (ll > rr) std::swap(ll, rr);
      ll = (ll - 1) / 2;
      rr = (rr - 1) / 2;
      g(j, ll, rr) {
        c[j] += 10;
      }
    }
    f(i, 0, 200) {
      idx = std::max(idx, c[i]);
    }
    printf("%d\n", idx);
  }


#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
