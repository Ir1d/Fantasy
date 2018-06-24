/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-24 20:27:01
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
int n, m, x, y;
int cnt = 0;
int ti;
const int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
const int dy[] = {-2, -1, 1, 2, -2, -1, 1, 2};
int vis[23][23];
void dfs(int x, int y, int s) {
  if (s == 0) {
    ++cnt;
    return;
  }
  int nx, ny;
  f(i, 0, 8) {
    nx = x + dx[i]; ny = y + dy[i];
    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
    if (vis[nx][ny] == ti) continue;
    vis[nx][ny] = ti;
    dfs(nx, ny, s - 1);
    vis[nx][ny] = 0;
  }
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d%d", &n, &m, &x, &y);
    cnt = 0;
    ++ti;
    vis[x][y] = ti;
    dfs(x, y, n * m - 1);
    printf("%d\n", cnt);
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

