/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-10-16 18:40:42
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

int n;
int a[MAXN];
int res[MAXN];
struct node {
  node *ls, *rs;
  int l, r, md, v;
  inline node(int ll = 0, int rr = 0):l(ll), r(rr), md(l + (rr - ll >> 1)) {
    if (ll == rr) {
      v = 1;
      ls = rs = NULL;
      return;
    }
    ls = new node(ll, md);
    rs = new node(md + 1, rr);
    v = ls->v + rs->v;
  }
  int get(int x) {
    if (l == r) {
      return l;
    }
    if (x > ls->v) return rs->get(x - ls->v);
    return ls->get(x);
  }
  void upd(int x) {
    --v;
    if (l == r) {
      return;
    }
    if (x <= ls->v) ls->upd(x);
    else rs->upd(x - ls->v);
  }
};
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &n);
  g(i, 2, n) scanf("%d", a + i);
  node *root = new node(1, n);
  gd(i, n, 1) {
    res[i] = root->get(a[i] + 1);
    // for (int j = 1; j <= n; ++j) printf("%d ", root->get(j));
    // puts("");
    root->upd(a[i] + 1);
  }
  g(i, 1, n) printf("%d\n", res[i]);

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

