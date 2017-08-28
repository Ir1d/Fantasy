/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2017-08-28 07:25:13
 * @license Star And Thank Author
 */

#include <cstdio>// NOLINT
#include <cstring>// NOLINT
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

struct node {
  int t, w, x;
} e[MAXN];
int head[833], cnt = 1;
inline void add(int s, int t) {
  e[++cnt].t = t; e[cnt].x = head[s]; head[s] = cnt; e[cnt].w = 1;
  e[++cnt].t = s; e[cnt].x = head[t]; head[t] = cnt; e[cnt].w = 0;
}
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
int idx;
int map[555][555];
int n, m;
char tee[2];
int nx, ny;
void init() {
  memset(head, 0, sizeof head);
  cnt = 1;
  idx = 0;
  memset(map, 0, sizeof map);
  scanf("%d%d", &n, &m);
  g(i, 1, n) {
    scanf("%s", tee);
    f(j, 0, m) if (tee[j] == '*') {
      map[i][j + 1] = ++idx;
    }
  }
  g(i, 1, n) g(j, 1, m) if (map[i][j]) {
    f(k, 0, 4) {
      nx = i + dx[k];
      ny = j + dy[k];
      if (map[nx][ny]) {
        add(map[i][j], map[nx][ny] + idx);
      }
    }
  }
}
int S, T;
std::queue<int> Q;
int dis[833];
bool bfs() {
  while (!Q.empty()) Q.pop();
  memset(dis, -1, sizeof dis);
  int u;
  Q.push(S); dis[S] = 0;
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
int cas;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif
  scanf("%d", &cas);
  while (cas--) {
    init();
    S = 0; T = 2 * idx + 1;
    g(i, 1, idx) {
      add(S, i);
      add(i + idx, T);
    }
    printf("%d\n", idx - dinic() / 2);
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
