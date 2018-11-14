/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-11-14 17:09:11
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
void tarjan(int u) {
  int v;
  dfn[u] = low[u] = ++idx;
  inSta[u] = 1; sta[top++] = u;
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

  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    memset(head, 0, sizeof head);
    memset(dfn, 0, sizeof dfn);
    memset(low, 0, sizeof low);
    memset(belong, 0, sizeof belong);
    memset(inSta, 0, sizeof inSta);
    cnt = 1;
    scc = idx = top = 0;
    f(i, 0, m) {
      scanf("%d%d", &u, &v);
      add(u, v);
    }
    g(i, 1, n) if (!dfn[i]) tarjan(i);
    if (scc == 1) puts("Yes");
    else puts("No");
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

