/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-12-12 10:53:07
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

int bin[35];
int n, ans;
int val[MAXN], last[MAXN];
struct node {
  int t, w, x;
} e[MAXN << 1];
int head[MAXN], cnt = 1;
inline void add(int s, int t, int w) {
  e[++cnt].t = t; e[cnt].x = head[s]; head[s] = cnt; e[cnt].w = w;
}
int tail = 1;
int nx[MAXN * 31][2];
int root = 0;
void insert(int x) {
  int cur = root, t;
  gd(i, 31, 0) {
    t = x & (1 << i);
    t >>= i;
    int &r = nx[cur][t];
    if (!r) r = tail++;
    cur = r;
  }
}
int query(int x) {
  int cur = root, t, res = 0;
  gd(i, 31, 0) {
    t = x & (1 << i);
    t >>= i;
    if (nx[cur][t ^ 1]) {
      cur = nx[cur][t ^ 1];
      res += 1 << i;
    }
    else cur = nx[cur][t];
  }
  ans = std::max(ans, res);
}
void dfs(int x, int fa) {
  for (int i = head[x]; i; i = e[i].x) {
    if (e[i].t != fa) {
      val[e[i].t] = val[x] ^ e[i].w;
      dfs(e[i].t, x);
    }
  }
}
int u, v, w;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (~scanf("%d", &n)) {
    memset(head, 0, sizeof head);  
    memset(nx, 0, sizeof nx);  
    cnt = 1; ans = 0; tail = 1;
    f(i, 1, n) {
      scanf("%d%d%d", &u, &v, &w);
      ++u; ++v;
      add(u, v, w);
      add(v, u, w);
    }
    dfs(1, -1);
    g(i, 1, n) {
      insert(val[i]);
    }
    // g(i, 1, n) printf("%d ", val[i]); puts("");
    g(i, 1, n) query(val[i]);
    printf("%d\n", ans);

  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

