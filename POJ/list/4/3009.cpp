/**
 * @author Ir1d (sirius.caffrey@gmail.com)
 * @date    2018-01-13 11:05:32
 * @copyright MIT
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

int n, m;
int map[23][23];
int ans;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
int sx, sy;
void dfs(int x, int y, int ti) {
  if (ti > ans) return;
  int nx, ny;
  f(i, 0, 4) {
    nx = x; ny = y;
    while (nx >= 0 && nx < n && ny >= 0 && ny < m) {
      switch(map[nx][ny]) {
        case 0:
          nx += dx[i]; ny += dy[i];
          break;
        case 3:
          if (ti + 1 < ans) {
            ans = ti + 1;
          }
          nx = -1;
          break;
        case 1:
          if (x + dx[i] != nx || y + dy[i] != ny) {
            // have gap
            map[nx][ny] = 0;
            dfs(nx - dx[i], ny - dy[i], ti + 1);
            map[nx][ny] = 1;
          }
          nx = -1;
      }
    }
  }
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (~scanf("%d%d", &m, &n) && (n || m)) {
    f(i, 0, n) f(j, 0, m) {
      scanf("%d", &map[i][j]);
      if (map[i][j] == 2) {
        sx = i; sy = j;
        // break;
      }
    }
    ans = 11;
    map[sx][sy] = 0;
    dfs(sx, sy, 0);
    if (ans == 11) ans = -1;
    printf("%d\n", ans);
    // dfs()
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
