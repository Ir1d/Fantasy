/**
 * @author SCaffrey (srius.caffrey@gmail.com)
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

bool map[6][6];
bool ctf;
int s;
const int dx[] = {-1, 1, 0, 0, 0};
const int dy[] = {0, 0, -1, 1, 0};
bool check() {
  f(i, 1, 5) f(j, 1, 5) if (map[i][j] != map[1][1]) return 0;
  return 1;
}
void flip(int x, int y) {
  f(i, 0, 5) map[x + dx[i]][y + dy[i]] ^= 1;
}
void dfs(int x, int y, int dep) {
  if (dep == s) {
    ctf = check();
    return;
  }
  if (ctf || x == 5) return;
  flip(x, y);
  if (y < 4) dfs(x, y + 1, dep + 1);
  else dfs(x + 1, 1, dep + 1);
  flip(x, y);
  if (y < 4) dfs(x, y + 1, dep);
  else dfs(x + 1, 1, dep);
}
char c;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  f(i, 1, 5) f(j, 1, 5) {
    c = getchar();
    if (c == '\n') c = getchar();
    if (c == 'b') map[i][j] = 1;
  }
  for (s = 0; s <= 16; ++s) {
    dfs(1, 1, 0);
    if (ctf) {
      printf("%d\n", s);
      return 0;
    }
  }
  puts("Impossible");

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
