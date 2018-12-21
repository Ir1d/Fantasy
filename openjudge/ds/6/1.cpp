/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-11-22 22:33:53
 * @copyright MIT
 */
#include <bits/stdc++.h>  // NOLINT
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

int res = 0;
int n;
int a, b;
struct node {
  int t, x;
} e[MAXN];
int head[MAXN], cnt = 1;
inline void add(int s, int t) {
  e[++cnt].t = t; e[cnt].x = head[s]; head[s] = cnt;
}
void dfs(int x, int dep) {
  if (x == -1) return;
  if (dep > res) res = dep;
  for (int i = head[x]; i; i = e[i].x) {
    dfs(e[i].t, dep + 1);
  }
}
int u, v;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &n);
  f(i, 0, n) {
    scanf("%d%d", &u, &v);
    add(i + 1, u);
    add(i + 1, v);
  }
  dfs(1, 0);
  printf("%d\n", res + 1);


#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
