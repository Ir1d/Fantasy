/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-25 14:32:49
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
int r, c;
char map[555][555];
bool vis[555][555];
typedef std::pair<int, int> PII;
std::queue<PII> Q;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};
void bfs() {
  PII tee;
  while (!Q.empty()) {
    int nx, ny;
    tee = Q.front(); Q.pop();
    vis[tee.first][tee.second] = 1;
    f(i, 0, 4) {
      nx = tee.first + dx[i]; ny = tee.second + dy[i];
      if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
      if (map[nx][ny] == 'X') continue;
      if (vis[nx][ny]) continue;
      // vis[nx][ny] = 1;
      Q.push(PII(nx, ny));
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
    while (!Q.empty()) Q.pop();
    memset(vis, 0, sizeof vis);
    scanf("%d%d", &r, &c);
    f(i, 0, r) {
      scanf("%s", map[i]);
      if (i == 0 || i == r - 1) {
        f(j, 0, c) if (map[i][j] == 'O') Q.push(PII(i, j));
      } else {
        if (map[i][0] == 'O') Q.push(PII(i, 0));
        if (map[i][c - 1] == 'O') Q.push(PII(i, c - 1));
      }
    }
    bfs();
    f(i, 0, r) {
      f(j, 0, c) if (map[i][j] == 'O' && !vis[i][j]) map[i][j] = 'X';
      printf("%s\n", map[i]);
    }
    if (T) puts("");
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

