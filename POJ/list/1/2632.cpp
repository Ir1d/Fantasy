/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2017-08-16 18:04:40
 * @license Star And Thank Author
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

struct node {
  int x, y;
  char d;
} a[233];
int T;
int vis[233][233];
int ctf;
int w, b, m, t, z, x, k1, k2;
char g;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &T);
  while (T--) {
    ctf = 0;
    memset(vis, 0, sizeof vis);
    scanf("%d%d", &w, &b);
    scanf("%d%d", &m, &t);
    g(i, 1, m) {
      scanf("%d%d", &a[i].y, &a[i].x);
      getchar();
      scanf("%c", &a[i].d);
      vis[a[i].x][a[i].y] = i;
    }
    g(i, 1, t) {
      // fprintf(stderr, "a[9]: %d %d: %d\n", a[9].x, a[9].y, vis[a[9].x][a[9].y]);
      scanf("%d", &z);
      getchar();
      scanf("%c%d", &g, &x);
      g(j, 1, x) {
        if (a[z].x <= 0 || a[z].x > b || a[z].y <= 0 || a[z].y > w) break;
        if (g == 'F') {
          vis[a[z].x][a[z].y] = 0;
          if (a[z].d == 'E') {
            a[z].y += 1;
          } else if (a[z].d == 'W') {
            a[z].y -= 1;
          } else if (a[z].d == 'N') {
            a[z].x += 1;
          } else if (a[z].d == 'S') {
            a[z].x -= 1;
          }
        }
        if (g == 'L') {
          if (a[z].d == 'E') {
            a[z].d = 'N'; continue;
          } else if (a[z].d == 'S') {
            a[z].d = 'E'; continue;
          } else if (a[z].d == 'W') {
            a[z].d = 'S'; continue;
          } else if (a[z].d == 'N') {
            a[z].d = 'W'; continue;
          }
        }
        if (g == 'R') {
          if (a[z].d == 'E') {
            a[z].d = 'S'; continue;
          } else if (a[z].d == 'N') {
            a[z].d = 'E'; continue;
          } else if (a[z].d == 'W') {
            a[z].d = 'N'; continue;
          } else if (a[z].d == 'S') {
            a[z].d = 'W'; continue;
          }
        }
        if (a[z].x <= 0 || a[z].x > b || a[z].y <= 0 || a[z].y > w) {
          if (ctf) continue;
          ctf = 1;
          k1 = z;
          printf("Robot %d crashes into the wall\n", k1);
          break;
        }
        if (vis[a[z].x][a[z].y]) {
          if (ctf) continue;
          ctf = 2;
          k1 = z; k2 = vis[a[z].x][a[z].y];
          printf("Robot %d crashes into robot %d\n", k1, k2);
          break;
        }
        vis[a[z].x][a[z].y] = z;
      }
    }
    if (!ctf) puts("OK");
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
