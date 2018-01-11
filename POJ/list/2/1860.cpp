/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2017-08-16 23:06:25
 * @license Star And Thank Author
 */

#include <cstdio>// NOLINT
#include <cstring>// NOLINT
#include <cmath>// NOLINT
#include <queue>// NOLINT
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

int n, m, s;
double v;
struct edge {
  int t, x;
  double r, c;
} e[MAXN];
int head[233], cnt = 1;
inline void add(int s, int t,  double r, double c) {
  e[++cnt].t = t; e[cnt].r = r; e[cnt].c = c; e[cnt].x = head[s]; head[s] = cnt;
}
int a, b;
double r, c, rr, cc;
double dis[233];
std::queue<int> Q;
bool inq[233];
int u;
int tee;
int ti[233];
bool check() {
  dis[s] = v;
  Q.push(s);
  inq[s] = 1;
  while (!Q.empty()) {
    u = Q.front(); Q.pop(); inq[u] = 0;
    for (int i = head[u]; i; i = e[i].x) {
      tee = e[i].t;
      if (dis[tee] < (dis[u] - e[i].c) * e[i].r) {
        dis[tee] = (dis[u] - e[i].c) * e[i].r;
        if (++ti[tee] > n) return 1;
        if (!inq[tee]) {
          Q.push(tee);
          inq[tee] = 1;
        }
      }
    }
  }
  return 0;
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d%d%d%lf", &n, &m, &s, &v);
  f(i, 0, m) {
    scanf("%d%d%lf%lf%lf%lf", &a, &b, &r, &c, &rr, &cc);
    add(a, b, r, c);
    add(b, a, rr, cc);
  }
  if (check()) puts("YES");
  else puts("NO");

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
