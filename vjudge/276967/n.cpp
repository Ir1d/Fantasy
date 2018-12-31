/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-12-31 23:48:47
 * @copyright MIT
 */
#include <bits/stdc++.h>  // NOLINT
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

struct seg {
  int l, r, h, d;
  inline seg(int l, int r, int h, int d) : l(l), r(r), h(h), d(d) {}
  inline seg() {}
  inline bool operator<(const seg &T) const { return h < T.h; }
} a[MAXN];
struct node {
  int l, r, md;
  node *ls, *rs;
  int sum, cnt;
  int c;
  int lbd, rbd;
  inline node(int ll = 0, int rr = 0) : l(ll), r(rr), md(ll + (rr - ll >> 1)) {
    sum = 0;
    cnt = 0;
    c = 0;
    lbd = rbd = 0;
    if (ll == rr) {
      ls = rs = NULL;
      return;
    }
    ls = new node(ll, md);
    rs = new node(md + 1, rr);
  }
  void update(int ll, int rr, int v) {
    if (l == ll && r == rr) {
      c += v;
      if (c) {
        lbd = rbd = 1;
        sum = r - l + 1;
        cnt = 2;
      } else if (l == r) {
        sum = cnt = lbd = rbd = 0;
      } else {
        // throw 233;
        lbd = ls->lbd;
        rbd = rs->rbd;
        sum = ls->sum + rs->sum;
        cnt = ls->cnt + rs->cnt;
        if (ls->rbd && rs->lbd) cnt -= 2;
      }
      return;
    }
    if (rr <= md)
      ls->update(ll, rr, v);
    else if (ll > md)
      rs->update(ll, rr, v);
    else {
      ls->update(ll, md, v);
      rs->update(md + 1, rr, v);
    }
    if (c) {
      lbd = rbd = 1;
      sum = r - l + 1;
      cnt = 2;
    } else {
      lbd = ls->lbd;
      rbd = rs->rbd;
      sum = ls->sum + rs->sum;
      cnt = ls->cnt + rs->cnt;
      if (ls->rbd && rs->lbd) cnt -= 2;
    }
  }
} * root;
int n;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (~scanf("%d", &n)) {
    int mn = 1e4, mx = -1e4;
    int x1, x2, y1, y2;
    g(i, 1, n) {
      scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
      mn = std::min(mn, x1);
      mx = std::max(mx, x2);
      a[i] = seg(x1, x2, y1, 1);
      a[i + n] = seg(x1, x2, y2, -1);
    }
    // printf("%d %d\n", mn, mx);
    node *root = new node(1, mx - mn + 1);
    n <<= 1;
    std::sort(a + 1, a + n + 1);
    int ans = 0, last = 0;
    g(i, 1, n) {
      if (a[i].l < a[i].r)
        root->update(a[i].l - mn + 1, a[i].r - 1 - mn + 1, a[i].d);
      ans += root->cnt * (a[i + 1].h - a[i].h);
      ans += abs(root->sum - last);
      last = root->sum;
    }
    printf("%d\n", ans);
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
