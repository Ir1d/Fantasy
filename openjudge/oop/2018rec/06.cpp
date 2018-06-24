/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-23 13:35:15
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
int n, m;
int met[33][33];
int ti;
typedef std::pair<int, int> PII;
PII pre[33][33];
void print(int x, int y) {
  if (x == -1 && y == -1) return;
  print(pre[x][y].first, pre[x][y].second);
  printf("%c%d", 'A' + y, x + 1);
}
const int dx[] = {-1, 1, -2, 2, -2, 2, -1, 1};
const int dy[] = {-2, -2, -1, -1, 1, 1, 2, 2};
bool dfs(int x, int y, int c) {
  bool ctf = 0;
  if (c == n * m) {
    print(x, y);
    puts("");
    return 1;
  }
  int nx, ny;
  f(i, 0, 8) {
    nx = x + dx[i]; ny = y + dy[i];
    if (nx < 0 || nx >= n || ny < 0 || ny >= m || met[nx][ny] == ti) continue;
    met[nx][ny] = ti;
    pre[nx][ny] = PII(x, y);
    if (dfs(nx, ny, c + 1)) return 1;
    met[nx][ny] = 0;
  }
  return 0;
}
void solve() {
  // ti = 1;
  f(j, 0, m) {
    f(i, 0, n) {
      ++ti;
      pre[i][j] = PII(-1, -1);
      met[i][j] = ti;
      if (dfs(i, j, 1)) return;
    }
  }
  puts("impossible");
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &T);
  g(it, 1, T) {
    if (it > 1) puts("");
    scanf("%d%d", &n, &m);
    printf("Scenario #%d:\n", it);
    solve();
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

