/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2017-09-30 18:37:42
 * @license Star And Thank Author
 */

#include <set>// NOLINT
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

int n, m, q;
int a[MAXN], b[MAXN];
int l, r, x;
inline int sign(int x) {
  if (x & 1) return -1;
  return 1;
}
LL absLL(LL x) {
  if (x > 0) return x;
  return -x;
}
std::set<LL> S;
LL ans(LL x) {
  std::set<LL>::iterator it = S.lower_bound(x);
  if (it == S.end()) --it;
  LL res = absLL((*it) - x);
  if (it != S.begin()) --it;
  return std::min(res, absLL((*it) - x));
}
LL sa, cur;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d%d%d", &n, &m, &q);
  g(i, 1, n) {
    scanf("%d", a + i);
    sa += (a[i]) * sign(i - 1);
  }
  g(i, 1, n) {
    scanf("%d", b + i);
    cur += sign(i) * b[i];
  }
  S.insert(cur);
  g(i, n + 1, m) {
    scanf("%d", b + i);
    cur += b[i - n];
    cur = -cur;
    cur += sign(n) * b[i];
    S.insert(cur);
  }
  printf(LLD"\n", ans(-sa));
  f(i, 0, q) {
    scanf("%d%d%d", &l, &r, &x);
    if (!(r - l & 1)) {
      if (l & 1) sa += x;
      else sa -= x;
    }
    printf(LLD"\n", ans(-sa));
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
