/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-12-30 23:24:11
 * @copyright MIT
 */
#include <cstdio>// NOLINT
#include <cstring>// NOLINT
#include <bits/stdc++.h>// NOLINT
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

int T;
int n;
struct node {
  int l, r, md;
  int v;
  node *ls, *rs;
  inline node(int ll = 0, int rr = 0):l(ll), r(rr), md(ll + (rr - ll >> 1)) {
    if (ll == rr) {
      scanf("%d", &v);
      ls = rs = NULL;
      return;
    }
    ls = new node(ll, md);
    rs = new node(md + 1, rr);
    v = ls->v + rs->v;
  }
  inline void update(int x, int y) {
    if (l == r) {
      v += y;
      return;
    }
    if (x <= md) ls->update(x, y);
    else rs->update(x, y);
    v += y;
  }
  inline int get(int ll, int rr) {
    if (ll == l && rr == r) {
      return v;
    }
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

  scanf("%d", &T);
  g(cas, 1, T) {
    printf("Case %d:\n", cas);
    scanf("%d", &n);
    node *root = new node(1, n);
    char buf[12];
    int x, y;
    for (;;) {
      scanf("%s", buf);
      if (buf[0] == 'E') {
        break;
      }
      scanf("%d%d", &x, &y);
      if (buf[0] == 'Q') {
        printf("%d\n", root->get(x, y));
      } else if (buf[0] == 'A') {
        root->update(x, y);
      } else if (buf[0] == 'S') root->update(x, -y);
      else break;
    }
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

