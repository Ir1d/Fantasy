/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2017-08-16 20:01:15
 * @license Star And Thank Author
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
const int MAXN = 100033;

char map[23][23];
int a[23][23];
int n, m, s;
void solve() {
  memset(a, 0, sizeof a);
  a[0][s - 1] = 1;
  int x = 0, y = s - 1;
  while (1) {
    int tx = x, ty = y;
    if (map[x][y] == 'N') --tx;
    else if (map[x][y] == 'S') ++tx;
    else if (map[x][y] == 'W') --ty;
    else if (map[x][y] == 'E') ++ty;
    if (tx < 0 || tx >= n || ty < 0 || ty >= m) {
      printf("%d step(s) to exit\n", a[x][y]);
      return;
    }
    if (a[tx][ty]) {
      printf("%d step(s) before a loop of %d step(s)\n",a[tx][ty] - 1, a[x][y] - a[tx][ty] + 1);
      return;
    }
    a[tx][ty] = a[x][y] + 1;
    x = tx; y = ty;
  }
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (~scanf("%d%d%d", &n, &m, &s)) {
    if (!n && !m && !s) break;
    f(i, 0, n) scanf("%s", map[i]);
    solve();
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
