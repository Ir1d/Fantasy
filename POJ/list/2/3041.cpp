/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2017-08-27 19:12:56
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
} e[MAXN * 12];
int head[MAXN], cnt = 1;
inline void add(int s, int t, int w) {
  e[++cnt].t = t; e[cnt].x = head[s]; head[s] = cnt; e[cnt].w = w;
  e[++cnt].t = s; e[cnt].x = head[t]; head[t] = cnt; e[cnt].w = 0;
}
int dis[MAXN];
std::queue<int> Q;
int S, T;
bool bfs() {
  
}
int dinic() {
  int ans = 0;
  while (bfs()) ans += dfs(S, oo);
  return ans;
}
int n, m;
int u, v;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d%d", &n, &m);
  S = 0; T = 2 * n + 1;
  g(i, 1, n) {
    add(S, i, 1);
    add(i + n, T, 1);
  }
  f(i, 0, m) {
    scanf("%d%d", &u, &v);
    add(u, v + n, 1);
  }
  printf("%d\n", dinic());

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
