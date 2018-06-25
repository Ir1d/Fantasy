/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-25 15:28:08
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
int r, c, k;
char map[123][132];
int sx, sy;
int vis[123][123][12];
struct node {
  int a, b, c;
};
std::queue<node> Q;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
void bfs() {
  while (!Q.empty()) Q.pop();
  Q.push((node){sx, sy, 0});
  memset(vis, 0, sizeof vis);
  vis[sx][sy][0] = 1;
  node w;
  int nx, ny;
  while (!Q.empty()) {
    w = Q.front(); Q.pop();
    f(i, 0, 4) {
      nx = w.a + dx[i]; ny = w.b + dy[i];
      if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
      if (map[nx][ny] == 'E') {
        printf("%d\n", w.c + 1);
        return;
      }
      if (vis[nx][ny][(w.c + 1) % k]) continue;
      if ((w.c + 1) % k == 0 || map[nx][ny] != '#') {
        vis[nx][ny][(w.c + 1) % k] = 1;
        Q.push((node){nx, ny, w.c + 1});
      }
    }
  }
  puts("Oop!");
}
void solve() {
  f(i, 0, r) f(j, 0, c) if (map[i][j] == 'S') {
    sx = i; sy = j;
    bfs();
    return;
  }
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d", &r, &c, &k);
    f(i, 0, r) scanf("%s", map[i]);
    solve();
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

