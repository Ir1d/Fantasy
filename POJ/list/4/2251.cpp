#include <cstdio>
#include <queue>
#include <cstring>

#define f(x, y, z) for (int x = (y), __ = (z); x < __; ++x)
#define g(x, y, z) for (int x = (y), __ = (z); x <= __; ++x)
#define fd(x, y, z) for (int x = (y), __ = (z); x > __; --x)
#define gd(x, y, z) for (int x = (y), __ = (z); x >= __; --x)

typedef long long LL;
typedef long double real;

struct node {
  int x, y, z;
  int ti;
  inline node(int x = 0, int y = 0, int z = 0, int ti = 0):x(x), y(y), z(z), ti(ti) {}
} tee;
int vis[33][33][33];
char map[33][33][33];

int l, r, c;
int sx, sy, sz, ex, ey, ez;

const int dx[33] = {-1,0,0,0,0,1};
const int dy[33] = {0,-1,0,0,1,0};
const int dz[33] = {0,0,-1,1,0,0};

int nx, ny, nz;
int ans;
std::queue<node> Q;
bool solve() {
  ans = 0;
  while (!Q.empty()) Q.pop();
  memset(vis, -1, sizeof vis);
  Q.push(node(sx, sy, sz, 0));
  vis[sx][sy][sz] = 0;
  while (!Q.empty()) {
    tee = Q.front(); Q.pop();
    for (int i = 0; i < 6; ++i) {
      nx = tee.x + dx[i]; ny = tee.y + dy[i]; nz = tee.z + dz[i];
      if (nx < 0 || nx >= l || ny < 0 || ny >= r || nz < 0 || nz >= c) continue;
      if (map[nx][ny][nz] == '#' || (vis[nx][ny][nz] != -1/* && vis[nx][ny][nz] <= tee.ti*/)) continue;
      if (map[nx][ny][nz] == 'E') {
        ans = tee.ti + 1;
        return 1;
      }
      vis[nx][ny][nz] = tee.ti + 1;
      Q.push(node(nx, ny, nz, tee.ti + 1));
    }
  }
  return 0;
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (~scanf("%d%d%d", &l, &r, &c) && (l || r || c)) {
    f(i, 0, l) {
      f(j, 0, r) {
        scanf("%s", map[i][j]);
        f(k, 0, c) if (map[i][j][k] == 'S') {
          sx = i; sy = j; sz = k;
        } else if (map[i][j][k] == 'E') {
          ex = i; ey = j; ez = k;
        }
      }
    }
    if (solve()) printf("Escaped in %d minute(s).\n", ans);
    else puts("Trapped!");
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
