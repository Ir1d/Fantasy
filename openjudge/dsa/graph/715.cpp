/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-12-13 18:30:45
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

int n, m;
int x[133], y[133];

inline double dd(int a, int b) {
  return sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]) +
              0.0);
}
struct node {
  int s, t;
  double w;
} e[MAXN];
int pre[133];
int vis[133];
int id[133];
double in[133];
int u, v;
double ans;
bool solve() {
  ans = 0;
  int u, v, root = 0;
  for (;;) {
    f(i, 0, n) in[i] = 1e100;
    f(i, 0, m) {
      u = e[i].s; v = e[i].t;
      if (u != v && e[i].w < in[v]) {
        in[v] = e[i].w;
        pre[v] = u;
      }
    }
    f(i, 0, m) {
      if (i != root && in[i] != 1e50) return 0;
    }
    int tn = 0;
    memset(id, -1, sizeof id);
    memset(vis, -1, sizeof vis);
    in[root] = 0;
    f(i, 0, n) {
      ans += in[i];
      v = i;
      while (vis[v] != i && id[v] == -1 && v != root) {
        vis[v] = i;
        v = pre[v];
      }
      if (v != root && id[v] == -1) {
        for (int u = pre[v]; u != v; u = pre[u]) {
          id[u] = tn;
        }
        id[v] = tn++;
      }
    }
    if (tn == 0) break;
    f(i, 0, n) {
      if (id[i] == -1) id[i] = tn++;
    }
    f(i, 0, m) {
      u = e[i].s; v = e[i].t;
      e[i].s = id[u];
      e[i].t = id[v];
      if (e[i].s != e[i].t) {
        e[i].w -= in[v];
      }
    }
  }
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (~scanf("%d%d", &n, &m)) {
    f(i, 0, n) { scanf("%d%d", x + i, y + i); }
    f(i, 0, m) {
      scanf("%d%d", &u, &v);
      u--;
      v--;
      e[i] = (node){u, v, dd(u, v)};
    }
    if (solve()) {
      printf("%.2lf\n", ans);
    } else {
      puts("NO");
    }
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

