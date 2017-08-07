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

int pri[MAXN], cnt;
bool vis[1000033];
void init() {
  vis[1] = 1;
  g(i, 2, 1000000) {
    if (!vis[i]) pri[cnt++] = i;
    f(j, 0, cnt) {
      if (i * pri[j] > 1000000) break;
      vis[i * pri[j]] = 1;
      if (i % pri[j] == 0) break;
    }
  }
}
int a, b, c;
int t;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  init();
  while (~scanf("%d%d%d", &a, &b, &c) && (a || b || c)) {
    for (int i = a;;i += b) {
      if (!vis[i]) --c;
      if (!c) {
        printf("%d\n", i);
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
