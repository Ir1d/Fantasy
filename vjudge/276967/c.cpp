/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-12-30 23:24:11
 * @copyright MIT
 */
#include <cmath>          // NOLINT
#include <cstdio>         // NOLINT
#include <cstring>        // NOLINT
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

typedef long long LL;  // NOLINT
typedef long double real;

const double INF = 1e100;
const int oo = ~0u >> 2;
const double pi = acos(-1.0);
const double EPS = 1e-8;
const int MAXN = 100033;

int T;
int n;
struct node {
  int l, r, md;
  LL v;
  LL c;
  node *ls, *rs;
  inline node(int ll = 0, int rr = 0) : l(ll), r(rr), md(ll + (rr - ll >> 1)) {
    c = 0;
    if (ll == rr) {
      scanf("%lld", &v);
      ls = rs = NULL;
      return;
    }
    ls = new node(ll, md);
    rs = new node(md + 1, rr);
    v = ls->v + rs->v;
  }
  inline void pushdown() {
    if (ls && rs) {
      ls->c += c;
      ls->v += (ls->r - ls->l + 1) * c;
      rs->c += c;
      rs->v += (rs->r - rs->l + 1) * c;
      c = 0;
    }
  }
  inline void update(int ll, int rr, LL d) {
    if (ll == l && rr == r) {
      c += d;
      v += (LL)(rr - ll + 1) * d;
      return;
    }
    if (c) pushdown();
    if (rr <= md)
      ls->update(ll, rr, d);
    else if (ll > md)
      rs->update(ll, rr, d);
    else {
      ls->update(ll, md, d);
      rs->update(md + 1, rr, d);
    }
    v = ls->v + rs->v;
  }
  inline LL get(int ll, int rr) {
    if (ll == l && rr == r) {
      return v;
    }
    if (c) pushdown();
    if (rr <= md) return ls->get(ll, rr);
    if (ll > md) return rs->get(ll, rr);
    return ls->get(ll, md) + rs->get(md + 1, rr);
  }
};

int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  // scanf("%d", &T);
  // g(cas, 1, T) {
  // printf("Case %d:\n", cas);
  int m;
  scanf("%d%d", &n, &m);
  node *root = new node(1, n);
  char buf[12];
  int x, y, z;
  while (m--) {
    scanf("%s", buf);
    scanf("%d%d", &x, &y);
    if (buf[0] == 'Q') {
      printf("%lld\n", root->get(x, y));
    } else {
      scanf("%d", &z);
      root->update(x, y, z);
    }
  }
  // }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
