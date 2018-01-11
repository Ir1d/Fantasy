#pragma optimize("2")
/**
 * @author Ir1d (sirius.caffrey@gmail.com)
 * @date    2018-01-11 21:21:58
 * @copyright MIT
 */
#include <cstdio>// NOLINT
#include <cstring>// NOLINT
#include <set>// NOLINT
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
struct node {
  int x, y;
  inline node(int x = 0, int y = 0):x(x), y(y) {}
  inline bool operator < (const node& T) const {
    return x < T.x || (x == T.x && y < T.y);
  }
  inline bool operator == (const node& T) const {
    return x == T.x && y == T.y;
  }
} a[MAXN];
std::set<node> S;
int solve() {
  std::sort(a, a + n);
  S.clear();
  int ans = 0;
  int nx, ny;
  int cx, cy;
  node ss, c;
  // f(i, 0, n) S.insert(node(a[i].x, a[i].y));
  f(i, 0, n) f(j, 0, i) {
    ss = node(a[i].x + a[i].y - a[j].y, a[i].y + a[j].x - a[i].x);
    if (!(*std::lower_bound(a, a + n, ss) == ss))continue;
    // if (S.count(ss) == 0) continue;
    c = node(a[j].x + a[i].y - a[j].y, a[j].y + a[j].x - a[i].x);
    if (ss == a[i] || ss == a[j] || c == a[i] || c == a[j] || c == ss) continue; 
    if (*std::lower_bound(a, a + n, c) == c) ++ans;
  }
  return ans / 2;
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (~scanf("%d", &n) && n) {
    f(i, 0, n) scanf("%d%d", &a[i].x, &a[i].y);
    printf("%d\n", solve());
  }


#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
