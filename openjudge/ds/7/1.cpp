/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-12-01 09:51:04
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
char buf[12];
int k, w;
int u, v, ans;
struct node {
  int s, t, w;
  inline bool operator < (const node& T) const {
    return w < T.w;
  }
} e[MAXN];
int fa[MAXN];
inline int get(int x) {
  if (x == fa[x]) return fa[x];
  return fa[x] = get(fa[x]);
}
void unite(int x, int y) {
  x = get(x);
  y = get(y);
  fa[x] = y;
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &n);
  int tot = 0;
  g(i, 0, n) fa[i] = i;
  f(i, 0, n - 1) {
    scanf("%s%d", buf, &k);
    u = buf[0] - 'A';
    f(j, 0, k) {
      scanf("%s%d", buf, &w);
      e[tot++] = (node){u, buf[0] - 'A', w};
      // e[tot++] = (node){buf[0] - 'A', u, w};
    }
  }
  std::sort(e, e + tot);
  f(i, 0, tot) {
    u = e[i].s; v = e[i].t;
    if (get(u) == get(v)) continue;
    ans += e[i].w;
    unite(u, v);
  }
  printf("%d\n", ans);

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

