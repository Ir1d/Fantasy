/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2017-08-17 00:15:38
 * @license Star And Thank Author
 */

#include <cstdio>// NOLINT
#include <queue>// NOLINT
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

int n, m;
struct edge {
  int t, w, x;
} e[MAXN];
int head[233], cnt = 1;
int l[233];
int d, p, x, u, w;
int ans = oo;
bool inq[233];
int dis[233];
inline void add(int s, int t, int w) {
  e[++cnt].t = t; e[cnt].w = w; e[cnt].x = head[s]; head[s] = cnt;
}
std::queue<int> Q;
bool judge(int x) {
  return l[x] >= d && l[x] <= d + m;
}
void spfa() {
  memset(dis, 0x1f, sizeof dis);
  dis[0] = 0; Q.push(0); inq[0] = 1;
  int u, tee;
  while (!Q.empty()) {
    u = Q.front(); Q.pop();
    for (int i = head[u]; i; i = e[i].x) {
      tee = e[i].t;
      if (judge(tee) && dis[tee] - dis[u] > e[i].w) {
        dis[tee] = dis[u] + e[i].w;
        if (!inq[tee]) {
          inq[tee] = 1;
          Q.push(tee);
        }
      }
    }
    inq[u] = 0;
  }
  if (ans > dis[1]) ans = dis[1];
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d%d", &m, &n);
  g(i, 1, n) {
    scanf("%d%d%d", &p, l + i, &x);
    add(0, i, p);
    g(j, 1, x) {
      scanf("%d%d", &u, &w);
      add(u, i, w);
    }
  }
  for (d = l[1] - m; d <= l[1]; ++d) spfa();
  printf("%d", ans);

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
