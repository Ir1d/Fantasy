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

struct node {
  double l, r;
  inline bool operator < (const node& T) const {
    return l < T.l;
  }
} a[1033];
int n, d, cases;
int x, y;
double tee;
int ctf;
int ans;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (~scanf("%d%d", &n, &d) && (n || d)) {
    ctf = 0;
    f(i, 0, n) {
      scanf("%d%d", &x, &y);
      tee = sqrt((double)d * d - y * y);
      a[i].l = x - tee;
      a[i].r = x + tee;
      if (y > d) ctf = 1;
    }
    std::sort(a, a + n);
    printf("Case %d: ", ++cases);
    if (ctf) {
      puts("-1");
      continue;
    }
    ans = 1;
    node pos = a[0];
    f(i, 1, n) {
      if (pos.r < a[i].l) {
        ++ans;
        pos = a[i];
      } else if (pos.r >= a[i].r) pos = a[i];
    }
    printf("%d\n", ans);
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
