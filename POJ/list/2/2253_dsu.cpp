/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2017-08-17 00:46:02
 * @license Star And Thank Author
 */

#include <cstdio>// NOLINT
#include <cstring>// NOLINT
#include <algorithm>// NOLINT
#include <vector>// NOLINT
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
inline double Q(double x) {
  return x * x;
}
struct stone {
  int x, y;
}  a[1033];
inline double dis(int i, int j) {
  return sqrt(Q(a[i].x - a[j].x) + Q(a[i].y - a[j].y));
}
int cas = 1;
inline void getMax(double &x, double y) {
  if (x < y) x = y;
}
struct node {
  int s, t;
  double w;
  inline bool operator < (const node& T) const {
    return w < T.w;
  }
} tee;
std::vector<node> V;
int fa[1033];
inline int get(int x) {
  int tee = fa[x], q;
  while (tee != fa[tee]) tee = fa[tee];
  while (x != tee) {
    q = fa[x]; fa[x] = tee; x = q;
  }
  return tee;
}
bool check(double x) {
  int l, r;
  g(i, 1, n) fa[i] = i;
  f(i, 0, V.size()) {
    if (V[i].w <= x) {
      l = get(V[i].s); r = get(V[i].t);
      //
      fa[l] = r;
    } else break;
  }
  return get(1) == get(2);
}
double teee;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (~scanf("%d", &n) && n) {
    g(i, 1, n) scanf("%d%d", &a[i].x, &a[i].y);
    V.clear();
    double l = 0, r = 0;
    g(i, 1, n) g(j, 1, n) if (i != j) {
      teee = dis(i, j);
      getMax(r, teee);
      tee.s = i; tee.t = j; tee.w = teee;
      V.push_back(tee);
    }
    std::sort(V.begin(), V.end());
    r += 1e-8; l -= 1e-8;
    g(i, 1, 200) {
      double md = l + (r - l) / 2.0;
      if (check(md)) r = md;
      else l = md;
    }
    printf("Scenario #%d\n", cas++);
    printf("Frog Distance = %.3lf\n\n", r + 1e-8);
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
