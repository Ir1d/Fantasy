/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-12-07 14:43:23
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
const int MAXN = 200033;

int root[MAXN];
int ls[MAXN * 40], rs[MAXN * 40], lis[MAXN * 40], lds[MAXN * 40];

int ncnt, n, ans;
int ret = 0;
std::vector<int> v[MAXN];
int val[MAXN];
int sx[MAXN];
int icnt = 0;

void merge(int &x, int y) {
  // y into x
  if (!x || !y) {
    x = x + y;
    return;
  }
  lis[x] = std::max(lis[x], lis[y]);
  lds[x] = std::max(lds[x], lds[y]);
  ret = std::max(ret, std::max(lis[ls[x]] + lds[rs[y]], lds[rs[x]] + lis[ls[y]]));
  merge(ls[x], ls[y]);
  merge(rs[x], rs[y]);
}
void modify(int &x, int l, int r, int t, int v, int *a) {
  if (!x) x = ++ncnt;
  a[x] = std::max(a[x], v);
  if (l == r) return;
  int md = l + (r - l >> 1);
  if (t <= md) modify(ls[x], l, md, t, v, a);
  else modify(rs[x], md + 1, r, t, v, a);
}
int query(int x, int l, int r, int ql, int qr, int *a) {
  if (l > r) return 0;
  if (!x) return 0;
  if (ql <= l && r <= qr) return a[x];
  int ret = 0, md = l + (r - l >> 1);
  if (ql <= md) ret = std::max(ret, query(ls[x], l, md, ql, qr, a));
  if (qr > md) ret = std::max(ret, query(rs[x], md + 1, r, ql, qr, a));
  return ret;
}
void dfs(int x, int fa) {
  for (auto u: v[x]) {
    if (u == fa) continue;
    dfs(u, x);
  }
  ret = 0;
  int nlis = 0, nlds = 0, ilis, ilds;
  for (auto u: v[x]) {
    if (u == fa) continue;
    ilis = query(root[u], 1, icnt, 1, val[x] - 1, lis);
    ilds = query(root[u], 1, icnt, val[x] + 1, icnt, lds);
    merge(root[x], root[u]);
    ans = std::max(ans, ilis + nlds + 1);
    ans = std::max(ans, ilds + nlis + 1);
    nlis = std::max(nlis, ilis);
    nlds = std::max(nlds, ilds);
  }
  ans = std::max(ans, ret);
  modify(root[x], 1, icnt, val[x], nlis + 1, lis);
  modify(root[x], 1, icnt, val[x], nlds + 1, lds);
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &n);
  g(i, 1, n) {
    scanf("%d", val + i);
    sx[++icnt] = val[i];
  }
  std::sort(sx + 1, sx + icnt + 1);
  icnt = std::unique(sx + 1, sx + icnt + 1) - sx - 1;
  g(i, 1, n) val[i] = std::lower_bound(sx + 1, sx + icnt + 1, val[i]) - sx;
  int x, y;
  g(i, 2, n) {
    scanf("%d%d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  dfs(1, 0);
  printf("%d\n", ans);

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
