/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2017-09-30 15:31:41
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

int n;
struct edge {
  int t, w, x;
} e[MAXN * 2];
int head[MAXN], cnt = 1;
inline void add(int s, int t) {
  e[++cnt].t = t; e[cnt].x = head[s]; head[s] = cnt;
  e[++cnt].t = s; e[cnt].x = head[t]; head[t] = cnt;
}
int id[MAXN];
int sz[MAXN];
int num[2];
void dfs(int u) {
  for (int i = head[u]; i; i = e[i].x) {
    if (id[e[i].t] == 0) {
      ++sz[e[i].t];
      ++sz[u];
      id[e[i].t] = -id[u];
      if (id[e[i].t] == -1) ++num[0];
      else ++num[1];
      dfs(e[i].t);
    }
  }
}
int u, v;
int ans = 0;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &n);
  f(i, 1, n) {
    scanf("%d%d", &u, &v);
    add(u, v);
  }
  id[1] = 1; num[1] = 1;
  dfs(1);
  printf(LLD"\n", (LL)num[0] * num[1] - n + 1);
  // g(i, 1, n) printf("%d ", id[i]);
  // printf("%d %d\n", num[0], num[1]);

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
