/**
 * @author Ir1d (sirius.caffrey@gmail.com)
 * @date    2018-01-14 11:25:19
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

int n;
char s[33];
int map[33][33];
int u, v;
int c[33];
bool ok(int x) {
  f(i, 0, n) if (i != x && map[i][x]) {
    if (c[x] == c[i]) return 0;
  }
  return 1;
}
bool dfs(int x, int cNum) {
  if (x >= n) return 1;
  g(i, 1, cNum) {
    c[x] = i;
    if (ok(x)) {
      if (dfs(x + 1, cNum)) return 1;
    }
    c[x] = 0;
  }
  return 0;
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (~scanf("%d", &n) && n) {
    memset(map, 0, sizeof map);
    f(i, 0, n) {
      scanf("%s", s);
      u = s[0] - 'A';
      f(j, 2, strlen(s)) {
        v = s[j] - 'A';
        map[v][u] = map[u][v] = 1;
      }
    }
    memset(c, 0, sizeof c);
    g(i, 1, n) {
      if (dfs(0, i)) {
        if (i == 1) {
          puts("1 channel needed.");
        } else {
          printf("%d channels needed.\n", i);
        }
        break;
      }
    }
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
