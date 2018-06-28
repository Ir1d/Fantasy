/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-27 11:39:58
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

int r, c;
int ans;
int a[133][133];
int vis[133][133];
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
int dfs(int x, int y, int st) {
  vis[x][y] = st;
  int nx, ny;
  int mx = st;
  f(i, 0, 4) {
    nx = x + dx[i]; ny = y + dy[i];
    if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
    if (a[nx][ny] >= a[x][y]) continue;
    if (st + 1 <= vis[nx][ny]) continue;
    mx = std::max(mx, dfs(nx, ny, st + 1));
  }
  return mx;
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d%d", &r, &c);
  f(i, 0, r) f(j, 0, c) scanf("%d", &a[i][j]);
  gd(i, r - 1, 0) f(j, 0, c) if (!vis[i][j]) {
    ans = std::max(ans, dfs(i, j, 1));
  }
  printf("%d\n", ans);

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

