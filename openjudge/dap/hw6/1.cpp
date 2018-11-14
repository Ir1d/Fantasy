/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-11-14 16:07:11
 * @copyright MIT
 */
#include <cmath>          // NOLINT
#include <cstdio>         // NOLINT
#include <cstring>        // NOLINT
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

typedef long long LL;  // NOLINT
typedef long double real;

const double INF = 1e100;
const int oo = ~0u >> 2;
const double pi = acos(-1.0);
const double EPS = 1e-8;
const int MAXN = 100033;

struct node {
  int t, x;
} e[MAXN];
int head[MAXN], cnt = 1;
inline void add(int s, int t) {
  e[++cnt].t = t;
  e[cnt].x = head[s];
  head[s] = cnt;
}
int dfn[MAXN], low[MAXN], scc, idx, sta[MAXN], top;
bool inSta[MAXN];
int belong[MAXN];
int has[MAXN], w[MAXN];
void tarjan(int u) {
  int v;
  dfn[u] = low[u] = ++idx;
  inSta[u] = 1;
  sta[top++] = u;
  for (int i = head[u]; i; i = e[i].x) {
    v = e[i].t;
    if (!dfn[v]) {
      tarjan(v);
      if (low[v] < low[u]) low[u] = low[v];
    } else if (inSta[v] && dfn[v] < low[u]) {
      low[u] = dfn[v];
    }
  }
  if (low[u] == dfn[u]) {
    ++scc;
    do {
      v = sta[--top];
      belong[v] = scc;
      inSta[v] = 0;
    } while (u != v);
  }
}
int n, m;
int u, v;
int num[MAXN];
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (~scanf("%d%d", &n, &m)) {
    memset(dfn, 0, sizeof dfn);
    memset(low, 0, sizeof low);
    memset(num, 0, sizeof num);
    memset(head, 0, sizeof head);
    scc = idx = top = 0; cnt = 1;
    f(i, 0, m) {
      scanf("%d%d", &u, &v);
      add(u, v);
    }
    g(i, 1, n) if (!dfn[i]) tarjan(i);
    g(i, 1, n) {
      for (int j = head[i]; j; j = e[j].x) {
        if (belong[i] != belong[e[j].t]) {
          ++num[ belong[i] ];
        }
      }
    }
    // g(i, 1, n) printf("%d ", belong[i]); puts("");
    // g(i, 1, scc) printf("%d ", num[i]); puts("");
    int res, sum = 0;
    g(i, 1, scc) {
      if (!num[i]) {
        ++sum; res = i;
      }
    }
    if (sum == 1) {
      sum = 0;
      g(i, 1, n) if (belong[i] == res) {
        ++sum;
        // printf("``%d\n", i);
      }
      printf("%d\n", sum);
    } else puts("0");
  }
  

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
