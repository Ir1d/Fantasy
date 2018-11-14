/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-11-14 17:15:33
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
const int MAXN = 1033;

struct node {
  int t, w, x;
} e[2100000];
int head[MAXN], cnt = 1;
inline void add(int s, int t, int w) {
  e[++cnt].t = t;
  e[cnt].x = head[s];
  e[cnt].w = w;
  head[s] = cnt;
}
int dfn[MAXN], low[MAXN], scc, idx, sta[MAXN], top;
bool inSta[MAXN];
int belong[MAXN];
int ans;
void tarjan(int u, int fa) {
  int v;
  dfn[u] = low[u] = ++idx;
  inSta[u] = 1;
  sta[top++] = u;
  for (int i = head[u]; i; i = e[i].x) {
    v = e[i].t;
    if (i == (fa ^ 1)) continue;
    // if (v == fa) continue;
    if (!dfn[v]) {
      tarjan(v, i);
      // tarjan(v, u);
      if (low[v] < low[u]) low[u] = low[v];
      if (low[v] > dfn[u]) ans = std::min(ans, e[i].w);
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
int n, m, u, v, w;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (scanf("%d%d", &n, &m) == 2 && (n || m)) {
    memset(dfn, 0, sizeof dfn);
    memset(low, 0, sizeof low);
    memset(head, 0, sizeof head);
    scc = idx = top = 0;
    cnt = 1;
    ans = oo;
    g(i, 1, m) {
      scanf("%d%d%d", &u, &v, &w);
      add(u, v, w);
      add(v, u, w);
    }
    int res = 0;
    g(i, 1, n) if (!dfn[i]) {
      ++res;
      tarjan(i, -1);
    }
    // printf("``%d\n", res);
    if (res > 1) {
      puts("0");
    } else if (ans == oo) {
      puts("-1");
    } else if (ans == 0) {
      puts("1");
    } else {
      printf("%d\n", ans);
    }
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

