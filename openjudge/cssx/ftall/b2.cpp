/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-25 14:01:55
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

int n, m, k;
int vis[23][23];
int can[123];
int map[23][23];
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
int res;
void dfs(int x, int y, int num) {
  if (num > res) res = num;
  bool ctf = 0;
  int nx, ny;
  f(i, 0, 4) {
    nx = x + dx[i]; ny = y + dy[i];
    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
    if (vis[nx][ny]) continue;
    if (!can[map[nx][ny]]) continue;
    can[ map[nx][ny] ] = 0;
    vis[nx][ny] = num + 1;
    dfs(nx, ny, num + 1);
    vis[nx][ny] = 0;
    can[ map[nx][ny] ] = 1;
  }
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d%d%d", &n, &m, &k);
  g(i, 1, k) can[i] = 1;
  f(i, 0, n) f(j, 0, m) scanf("%d", &map[i][j]);
  vis[0][0] = 1; can[ map[0][0] ] = 0;
  dfs(0, 0, 1);
  printf("%d\n", res);

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

