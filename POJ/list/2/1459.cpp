/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2017-08-28 07:54:40
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

int n, np, nc, m, a, b, c;
char ch;
int id;
struct node {
  int t, w, x;
} e[MAXN];
int head[533], cnt = 1;
inline void add(int s, int t, int w) {
  e[++cnt].t = t; e[cnt].x = head[s]; head[s] = cnt; e[cnt].w = w;
  e[++cnt].t = s; e[cnt].x = head[t]; head[t] = cnt; e[cnt].w = 0;
}
int dis[533];
#include <queue>
std::queue<int> Q;
int S, T;
bool bfs() {
  while (!Q.empty()) Q.pop();
  memset(dis, -1, sizeof dis);
  int u;
  dis[S] = 0; Q.push(S);
  while (!Q.empty()) {
    u = Q.front(); Q.pop();
    for (int i = head[u]; i; i = e[i].x) {
      if (e[i].w && dis[e[i].t] == -1) {
        dis[e[i].t] = dis[u] + 1;
        Q.push(e[i].t);
      }
    }
  }
  return dis[T] != -1;
}
int dfs(int x, int fl) {
  if (x == T) return fl;
  int w, used = 0;
  for (int i = head[x]; i; i = e[i].x) {
    if (e[i].w && dis[e[i].t] == dis[x] + 1) {
      w = dfs(e[i].t, std::min(e[i].w, fl - used));
      e[i].w -= w; e[i ^ 1].w += w; used += w;
      if (used == fl) return fl;
    }
  }
  if (!used) dis[x] = -1;
  return used;
}
int dinic() {
  int ans = 0;
  while (bfs()) ans += dfs(S, oo);
  return ans;
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (~scanf("%d%d%d%d", &n, &np, &nc, &m)) {
    id = 0;
    memset(head, 0, sizeof head);
    cnt = 1;
    S = 0; T = n + 2;
    f(i, 0, m) {
      ch = getchar();
      while (ch != '(') ch = getchar();
      scanf("%d,%d)%d", &a, &b, &c);
      add(a + 1, b + 1, c);
    }
    f(i, 0, np) {
      ch = getchar();
      while (ch != '(') ch = getchar();
      scanf("%d)%d", &a, &b);
      add(S, a + 1, b);
    }
    f(i, 0, nc) {
      ch = getchar();
      while (ch != '(') ch = getchar();
      scanf("%d)%d", &a, &b);
      add(a + 1, T, b);
    }
    printf("%d\n", dinic());
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
