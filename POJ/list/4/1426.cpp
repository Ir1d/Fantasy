/**
 * @author Ir1d (sirius.caffrey@gmail.com)
 * @date    2018-01-13 13:46:12
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
char s[MAXN];
bool ctf;
void dfs(int x, int r) {
  if (x > 100) return;
  if (r == 0) {
    f(i, 0, x) putchar(s[i]);
    puts("");
    ctf = 1;
    return;
  }
  s[x] = '0';
  if (ctf) return;
  dfs(x + 1, r * 10 % n);
  if (ctf) return;
  s[x] = '1';
  dfs(x + 1, (r * 10 + 1) % n);
}
void solve() {
  ctf = 0;
  s[0] = '1';
  dfs(1, 1);
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (~scanf("%d", &n) && n) {
    solve();
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
