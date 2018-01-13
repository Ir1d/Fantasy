/**
 * @author Ir1d (sirius.caffrey@gmail.com)
 * @date    2018-01-13 08:31:26
 * @copyright MIT
 */
#include <cstdio>// NOLINT
#include <cstring>// NOLINT
#include <utility>// NOLINT
#include <queue>// NOLINT
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
char map[43][43];
int sx, sy, ex, ey;
const int dxl[] = {-1, 0, 1, 0};
const int dyl[] = {0, 1, 0, -1};
const int dxr[] = {-1, 0, 1, 0};
const int dyr[] = {0, -1, 0, 1};
bool ctf = 0;
int vis[43][43];
int ans;
int ans1;
int ans2;
int ans3;
int dfs(int x, int y, int op, const int* dx, const int* dy) {
  int nx, ny;
  if (x == ex && y == ey) {
    ctf = 1;
    return 1;
  }
  int t;
  f(i, 0, 4) {
    t = (i + op + 3) % 4;
    nx = x + dx[t]; ny = y + dy[t];
    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
    if (map[nx][ny] == '#') continue;
    // if (vis[nx][ny] || map[nx][ny] == '#') continue;
    return dfs(nx, ny, t, dx, dy) + 1;
  }
}
int dfs1() {
  ctf = 0; memset(vis, 0, sizeof vis);
  return dfs(sx, sy, 0, dxl, dyl);
}
int dfs2() {
  ctf = 0; memset(vis, 0, sizeof vis);
  return dfs(sx, sy, 0, dxr, dyr);
}
typedef std::pair<int, int> PII;
std::queue<PII> Q;
int bfs() {
  while (!Q.empty()) Q.pop();
  Q.push(PII(sx, sy));
  memset(vis, 0, sizeof vis);
  PII tee;
  int nx, ny;
  while (!Q.empty()) {
    tee = Q.front(); Q.pop();
    f(i, 0, 4) {
      nx = tee.first + dxl[i];
      ny = tee.second + dyl[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (vis[nx][ny] || map[nx][ny] == '#') continue;
      vis[nx][ny] = vis[tee.first][tee.second] + 1;
      Q.push(PII(nx, ny));
      if (nx == ex && ny == ey) return vis[nx][ny];
    }
  }
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    int t = n; n = m; m = t;
    f(i, 0, n) {
      scanf("%s", map[i]);
      f(j, 0, m) if (map[i][j] == 'E') {
        ex = i; ey = j;
      } else if (map[i][j] == 'S') {
        sx = i; sy = j;
      }
    }
    printf("%d %d %d\n", dfs1(), dfs2(), bfs() + 1);
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
