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

char p[233], t[233];
void dfs(int l, int r, int ll, int rr) {
  if (l > r) return;
  int ld, rd;
  char rt = p[l];
  g(i, ll, rr) {
    if (t[i] == rt) {
      ld = i - ll;
      dfs(l + 1, l + ld, ll, i - 1); //lson
      rd = rr - i;
      dfs(l + ld + 1, l + rr - ll, i + 1, rr); //rson
      break;
    }
  }
  putchar(rt);
}
int len;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (~scanf("%s%s", p, t)) {
    len = strlen(p);
    dfs(0, len - 1, 0, len - 1);
    puts("");
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
