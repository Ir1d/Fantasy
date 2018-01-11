/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2017-08-28 09:11:15
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

int p, n, num, q;
struct node {
  int s, t, w, x, c;
} e[MAXN];
int head[123], cnt = 1;
inline void add(int s, int t, int w) {
  e[++cnt].t = t; e[cnt].x = head[s]; head[s] = cnt; e[cnt].w = e[cnt].c = w; e[cnt].s = s;
  e[++cnt].t = s; e[cnt].x = head[t]; head[t] = cnt; e[cnt].w = e[cnt].c = 0; e[cnt].s = t;
}
int dis[123];
#include <queue>
std::queue<int> Q;
int S, T;
bool bfs() {
  while (!Q.empty()) Q.pop();
  int u;
  memset(dis, -1, sizeof dis);
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
int st[233][12];
bool ctf;
void check(int id) {
  ctf = 1;
  f(i, 0, p) {
    if (st[id][i + 1] == 1) {
      ctf = 0;
      break;
    }
  }
  if (ctf) add(S, 2 * id - 1, oo);
  ctf = 1;
  f(i, 0, p) {
    if (st[id][i + p + 1] == 0) {
      ctf = 0;
      break;
    }
  }
  if (ctf) add(2 * id, T, oo);
}
int idx;
int res[233][3];
void print() {
  idx = 0;
  g(i, 1, n) {
    for (int j = head[2 * i]; j; j = e[j].x) {
      if (((e[j].t + 1) / 2 <= n) && (e[j].t & 1) && (e[j].c > e[j].w)) {
        res[idx][0] = i; res[idx][1] = (e[j].t + 1) / 2; res[idx][2] = e[j].c - e[j].w;
        idx++;
      }
    }
  }
  printf("%d\n", idx);
  f(i, 0, idx) printf("%d %d %d\n", res[i][0], res[i][1], res[i][2]);
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d%d", &p, &n);
  g(i, 1, n) {
    f(j, 0, 2 * p + 1) scanf("%d", &st[i][j]);
  }
  g(i, 1, n) add(2 * i - 1, 2 * i, st[i][0]);
  S = 0; T = 2 * n + 1;
  g(i, 1, n) {
    check(i);
    g(j, 1, n) if (i != j) {
      ctf = 1;
      f(k, 0, p) {
        if ((st[i][k + p + 1] == 0 && st[j][k + 1] == 1) ||
         (st[i][k + p + 1] == 1 && st[j][k + 1] == 0)) {
          ctf = 0;
          break;
        }
      }
      if (ctf) add(2 * i, 2 * j - 1, std::min(st[i][0], st[j][0]));
    }
  }
  printf("%d ", dinic());
  print();

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
