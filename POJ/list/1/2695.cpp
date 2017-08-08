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

bool c[4][4];
char s[4][4];
int cx[16], cy[16];
int ans = 0;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  memset(c, 0, sizeof c);
  f(i, 0, 4) scanf("%s", s[i]);
  f(i, 0, 4) f(j, 0, 4) {
    if (s[i][j] == '+') {
      c[i][j] ^= 1;
      f(k, 0, 4) {
        c[i][k] ^= 1;
        c[k][j] ^= 1;
      }
    }
  }
  f(i, 0, 4) f(j, 0, 4) if (c[i][j]) {
    cx[ans] = i + 1;
    cy[ans] = j + 1;
    ++ans;
  }
  printf("%d\n", ans);
  f(i, 0, ans) printf("%d %d\n", cx[i], cy[i]);

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
