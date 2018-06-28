/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-27 00:42:00
 * @copyright MIT
 */
#include <bits/stdc++.h>  // NOLINT
#include <cmath>          // NOLINT
#include <cstdio>         // NOLINT
#include <cstring>        // NOLINT
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

typedef long long LL;  // NOLINT
typedef long double real;

const double INF = 1e100;
const int oo = ~0u >> 2;
const double pi = acos(-1.0);
const double EPS = 1e-8;
const int MAXN = 100033;

int n, k;
char buf[12][12];
int map[12][12];
int ans;
int cx[12], cy[12];
void dfs(int x, int y, int k) {
  if (k == 0 || x == n) {
    if (k == 0) ++ans;
    return;
  }
  if (map[x][y] == 1 && cx[x] == 0 && cy[y] == 0) {
    map[x][y] = 0;
    cx[x] = cy[y] = 1;
    if (y + 1 == n) dfs(x + 1, 0, k - 1);
    else dfs(x, y + 1, k - 1);
    map[x][y] = 1;
    cx[x] = cy[y] = 0;
    if (y + 1 == n) dfs(x + 1, 0, k);
    else dfs(x, y + 1, k);
  } else if (y + 1 == n) dfs(x + 1, 0, k);
  else dfs(x, y + 1, k);
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (~scanf("%d%d", &n, &k) && (n != -1 || k != -1)) {
    f(i, 0, n) {
      scanf("%s", buf[i]);
      f(j, 0, n) map[i][j] = (buf[i][j] == '#') ? 1 : 0;
    }
    ans = 0;
    memset(cx, 0, sizeof cx);
    memset(cy, 0, sizeof cy);
    dfs(0, 0, k);
    printf("%d\n", ans);
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
