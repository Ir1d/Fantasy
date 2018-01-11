/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2017-08-16 23:36:24
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

int T;
int n, m, w;
int s, te, t;
struct edge {
  int t, w, x;
} e[MAXN];
int head[555], cnt = 1;
inline void add(int s, int t, int w) {
  e[++cnt].t = t; e[cnt].x = head[s]; head[s] = cnt; e[cnt].w = w;
}
int dis[555];
std::queue<int> Q;
int ti[555];
bool inq[555];
bool solve() {
  while (!Q.empty()) Q.pop();
  memset(dis, 0x1f, sizeof dis);
  memset(ti, 0, sizeof ti);
  memset(inq, 0, sizeof inq);
  dis[1] = 0;
  Q.push(1);
  int u, tee;
  while (!Q.empty()) {
    u = Q.front(); Q.pop();
    for (int i = head[u]; i; i = e[i].x) {
      tee = e[i].t;
      if (dis[tee] - dis[u] > e[i].w) {
        dis[tee] = dis[u] + e[i].w;
        if (!inq[tee]) {
          Q.push(tee);
          inq[tee] = 1;
          if (++ti[tee] > n) return 1;
        }
      }
    }
    inq[u] = 0;
  }
  return 0;
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &T);
  while (T--) {
    memset(head, 0, sizeof head); cnt = 1;
    scanf("%d%d%d", &n, &m, &w);
    f(i, 0, m) {
      scanf("%d%d%d", &s, &te, &t);
      add(s, te, t);
      add(te, s, t);
    }
    f(i, 0, w) {
      scanf("%d%d%d", &s, &te, &t);
      add(s, te, -t);
    }
    if (solve()) puts("YES");
    else puts("NO");
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
