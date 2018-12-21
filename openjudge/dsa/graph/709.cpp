/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-12-20 00:59:52
 * @copyright MIT
 */
#include <cstdio>// NOLINT
#include <cstring>// NOLINT
#include <algorithm>// NOLINT
#include <queue>// NOLINT
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
int x[233], y[233];
inline double qq(double x) {
  return x * x;
}
inline double D(int a, int b) {
  return sqrt(qq(x[a] - x[b]) + qq(y[a] - y[b]));
}
struct node {
  int t, x;
  double w;
} e[MAXN];
int head[MAXN], cnt = 1;
inline void add(int s, int t, double w) {
  // printf("``%d %d %lf\n", s, t, w);
  e[++cnt].t = t; e[cnt].x = head[s]; head[s] = cnt; e[cnt].w = w;
}
double dis[MAXN];
typedef std::pair<double, int> PI;
std::priority_queue<PI, std::vector<PI>, std::greater<PI> > Q;
int vis[MAXN], ti = 0;
double solve() {
  g(i, 1, n) dis[i] = 1e100;
  while (!Q.empty()) Q.pop();
  ++ti;
  dis[1] = 0;
  Q.push(PI(0, 1));
  PI tee;
  int u;
  while (!Q.empty()) {
    tee = Q.top(); Q.pop();
    u = tee.second;
    if (vis[u] == ti) continue;
    vis[u] = ti;
    for (int i = head[u]; i; i = e[i].x) {
      if (ti != vis[e[i].t] && dis[e[i].t] > std::max(dis[u], e[i].w)) {
        dis[e[i].t] = std::max(dis[u], e[i].w);
        Q.push(PI(dis[e[i].t], e[i].t));
      }
    }
  }
  return dis[2];
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

int cas = 1;
  while (~scanf("%d", &n) && n) {
    memset(head, 0, sizeof head); cnt = 1;
    g(i, 1, n) {
      scanf("%d%d", x + i, y + i);
    }
    g(i, 1, n) {
      f(j, 1, i) {
        double xx = D(i, j);
        add(i, j, xx);
        add(j, i, xx);
      }
    }
    printf("Scenario #%d\n", cas++);
    printf("Frog Distance = %.3f\n", solve());
    // g(i, 1, n) printf("%lf ", dis[i]); puts("");
    puts("");
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

