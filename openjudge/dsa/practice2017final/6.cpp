/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-12-22 14:23:47
 * @copyright MIT
 */
#include <cstdio>// NOLINT
#include <cstring>// NOLINT
#include <bits/stdc++.h>// NOLINT
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
  int u, k, w;
  inline bool operator < (const node& T) const {
    return w > T.w;
  }
  inline node(int a = 0, int b = 0, int c = 0) : u(a), k(b), w(c) {}
};
struct edge {
  int t, w, x;
} e[MAXN << 1];
int coco[MAXN];
int n, m, tank, st, ed;
int head[MAXN], cnt = 1;
inline void add(int s, int t, int w) {
  e[++cnt].t = t; e[cnt].x = head[s]; head[s] = cnt; e[cnt].w = w;
}
int dis[1003][103];
bool vis[1003][103];

void init() {
  memset(head, 0, sizeof head);
  cnt = 1;
}
std::priority_queue<node>Q;
void dij(int s) {
  memset(dis, 0x1f, sizeof dis);
  memset(vis, 0, sizeof vis);
  while (!Q.empty()) Q.pop();
  node tee;
  tee.u = s; tee.k = 0; tee.w = 0;
  dis[s][0] = 0;
  Q.push(tee);
  int v, cost;
  while (!Q.empty()) {
    tee = Q.top(); Q.pop();
    vis[tee.u][tee.k] = 1;
    if (tee.u == ed) {
      printf("%d\n", tee.w);
      return;
    }
    if (tee.k + 1 <= tank && !vis[tee.u][tee.k + 1] && dis[tee.u][tee.k] + coco[tee.u] < dis[tee.u][tee.k + 1]) {
      dis[tee.u][tee.k + 1] = dis[tee.u][tee.k] + coco[tee.u];
      Q.push(node(tee.u, tee.k + 1, dis[tee.u][tee.k + 1]));
    }
    for (int i = head[tee.u]; i; i = e[i].x) {
      v = e[i].t; cost = e[i].w;
      if (tee.k >= cost && !vis[v][tee.k - cost]) {
        dis[v][tee.k - cost] = tee.w;
        Q.push(node(v, tee.k - cost, tee.w));
      }
    }
  }
  puts("impossible");
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  int u, v, w;
  scanf("%d%d", &n, &m);
  init();
  f(i, 0, n) {
    scanf("%d", coco + i);
  }
  f(i, 0, m) {
    scanf("%d%d%d", &u, &v, &w);
    add(u, v, w);
    add(v, u, w);
  }
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d", &tank, &st, &ed);
    dij(st);
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

