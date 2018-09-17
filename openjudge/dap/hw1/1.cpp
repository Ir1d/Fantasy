/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-09-17 23:36:05
 * @copyright MIT
 * POJ 1182
 */
#include <cstdio>// NOLINT
#include <cstring>// NOLINT
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
const int MAXN = 150033;

int a, b, c;
int fa[MAXN * 3];
int get(int x) {
  if (x == fa[x]) return x;
  return fa[x] = get(fa[x]);
}
bool same(int x, int y) {
  return get(x) == get(y);
}
void merge(int a, int b) {
  a = get(a); b = get(b);
  if (rand() & 1) fa[a] = b;
  else fa[b] = a;
}
int n, m;
int d, x, y;
int ans;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d%d", &n, &m);
  g(i, 1, n * 3) fa[i] = i;
  while (m--) {
    scanf("%d%d%d", &d, &x, &y);
    if (x < 1 || x > n || y < 1 || y > n) {
      ++ans;
      continue;
    }
    if (d == 1) {
      if (same(x, y + n) || same(x, y + 2 * n)) {
        ++ans;
      } else {
        merge(x, y);
        merge(x + n, y + n);
        merge(x + 2 * n, y + 2 * n);
      }
    } else {
      if (same(x, y) || same(x, y + 2 * n)) {
        ++ans;
      } else {
        merge(x, y + n);
        merge(x + n, y + 2 * n);
        merge(x + 2 * n, y);
      }
    }
  }
  printf("%d\n", ans);

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
