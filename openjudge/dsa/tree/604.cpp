/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-12-19 22:39:35
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
int n, m;
int fa[MAXN];
int get(int x) {
  if (x == fa[x]) return fa[x];
  return fa[x] = get(fa[x]);
}
bool same(int x, int y) {
  return get(x) == get(y);
}
void unite(int x, int y) {
  fa[get(x)] = get(y);
}
bool solve() {
  int a, b;
    f(i, 0, m) {
      scanf("%d%d", &a, &b);
      if (same(a, b) || same(a + n, b + n)) {
        return 0;
      }
      unite(a, b + n);
      unite(a + n, b);
    }
  return 1;
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &T);
  int cas = 1;
  while (T--) {
    scanf("%d%d", &n, &m);
    g(i, 1, 2 * n) fa[i] = i;
    printf("Scenario #%d:\n", cas++);
    if (solve()) {
      puts("No suspicious bugs found!");
    } else {
      puts("Suspicious bugs found!");
    }
    puts("");
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

