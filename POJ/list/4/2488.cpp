/**
 * @author Ir1d (sirius.caffrey@gmail.com)
 * @date    2018-01-12 22:42:39
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

int T;
int n, m;
bool ctf = 0;
int rx[233];
int ry[233];
int vis[50][50];
const int dx[] = {-1, 1, -2, 2, -2, 2, -1, 1};
const int dy[] = {-2, -2, -1, -1, 1, 1, 2, 2};
void print(int ti) {
  f(i, 0, ti) {
    putchar(ry[i] + 'A' - 1);
    putchar(rx[i] + '0');
  }
  puts("");
  puts("");
}
void dfs(int x, int y, int ti) {
  if (ti == n * m) {
    print(ti);
    ctf = 1;
    return;
  }
  int nx, ny;
  f(i, 0, 8) {
    if (ctf) return;
    nx = x + dx[i]; ny = y + dy[i];
    if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
    if (vis[nx][ny]) continue;
    vis[nx][ny] = 1;
    rx[ti] = nx; ry[ti] = ny;
    dfs(nx, ny, ti + 1);
    vis[nx][ny] = 0;
  }
}
void solve(int n, int m) {
  memset(vis, 0, sizeof vis);
  ctf = 0;
  g(i, 1, n) {
    g(j, 1, m) {
      rx[0] = i; ry[0] = j;
      vis[i][j] = 1;
      dfs(i, j, 1);
      vis[i][j] = 0;
      if (ctf) return;
    }
  }
  puts("impossible\n");
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &T);
  g(i, 1, T) {
    scanf("%d%d", &n, &m);
    printf("Scenario #%d:\n", i);
    solve(n, m);
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
