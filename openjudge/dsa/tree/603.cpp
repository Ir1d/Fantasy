/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-12-19 21:12:23
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
const int MAXN = 200033;

int fa[MAXN];
int a, b;
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
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  int T;
  scanf("%d", &T);
  int n, m;
  while (T--) {
    scanf("%d%d", &n, &m);
    g(i, 1, 2 * n) fa[i] = i;
    int x, y;
    char buf[12];
    f(i, 0, m) {
      scanf("%s%d%d", buf, &x, &y);
      if (buf[0] == 'D') {
        unite(x, y + n);
        unite(x + n, y);
      } else {
        bool c1 = same(x, y);
        bool c2 = same(x + n, y + n);
        if (c1 || c2) {
          puts("In the same gang.");
        } else if (same(x, y + n) || same(y, x + n)) {
          puts("In different gangs.");
        } else {
          puts("Not sure yet.");
        }
      }
    }
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

