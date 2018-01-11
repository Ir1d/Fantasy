/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2017-08-17 01:04:10
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
const int MAXN = 10033;

int n;
inline double Q(double x) {
  return x * x;
}
struct node {
  int x, y;
  inline node(int ll = 0, int rr = 0):x(ll), y(rr) {}
} a[MAXN];
double dis[MAXN];
inline double Dis(int i, int j) {
  return sqrt(Q(a[i].x - a[j].x) + Q(a[i].y - a[j].y));
}
struct edge {
  int t, x;
  double w;
} e[MAXN * 8];
int head[MAXN], cnt = 1;
inline void add(int s, int t, double w) {
  e[++cnt].t = t; e[cnt].x = head[s]; head[s] = cnt; e[cnt].w = w;
  e[++cnt].t = s; e[cnt].x = head[t]; head[t] = cnt; e[cnt].w = w;
}
bool vis[MAXN];
inline double maxx(double x, double y) {
  if (x < y) return y;
  return x;
}
void get() {
  g(i, 0, n) dis[i] = 1e125;
  memset(vis, 0, sizeof vis);
  double mx;
  int pos;
  dis[1] = 0;
  f(i, 1, n) {
    mx = 1e125; pos = 0;
    g(j, 1, n) if (!vis[j] && dis[j] < mx) {
      mx = dis[j]; pos = j;
    }
    vis[pos] = 1;
    for (int j = head[pos]; j; j = e[j].x) {
      if (!vis[e[j].t] && maxx(dis[pos], e[j].w) < dis[e[j].t]) {
        dis[e[j].t] = maxx(dis[pos], e[j].w);
      }
    }
  }
}
int cas = 1;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (~scanf("%d", &n) && n) {
    g(i, 1, n) scanf("%d%d", &a[i].x, &a[i].y);
    g(i, 1, n) head[i] = 0;
    cnt = 1;
    g(i, 1, n) f(j, 1, i) {
      add(i, j, Dis(i, j));
    }
    get();
    printf("Scenario #%d\n", cas++);
    printf("Frog Distance = %.3lf\n\n", dis[2] + 1e-8);
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
