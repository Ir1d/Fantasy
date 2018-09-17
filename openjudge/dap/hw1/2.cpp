/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-09-17 23:46:57
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

int T;
int fa[4000];
int get(int x) {
  if (x == fa[x]) return x;
  return fa[x] = get(fa[x]);
}
bool same(int x, int y) { return get(x) == get(y); }
void merge(int a, int b) {
  a = get(a);
  b = get(b);
  if (rand() & 1)
    fa[a] = b;
  else
    fa[b] = a;
}
int n, m;
bool c() {
  int x, y;
  while (m--) {
    scanf("%d%d", &x, &y);
    if (same(x, y) || same(x + n, y + n)) return 1;
    merge(x, y + n);
    merge(y, x + n);
  }
  return 0;
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &T);
  g(cas, 1, T) {
    if (cas != 1) puts("");
    scanf("%d%d", &n, &m);
    g(i, 1, n * 2) fa[i] = i;
    printf("Scenario #%d:\n", cas);
    if (c()) puts("Suspicious bugs found!");
    else puts("No suspicious bugs found!");
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
