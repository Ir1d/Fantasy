// POJ 3321
/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-10-13 16:31:15
 * @copyright MIT
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
int a[MAXN];
int m;
char buf[12];
int x;
struct node {
  int t, x;
} e[MAXN << 1];
int head[MAXN], cnt = 1;
inline void add(int s, int t) {
  e[++cnt].t = t; e[cnt].x = head[s]; head[s] = cnt;
}
int u, v;
int l[MAXN], r[MAXN], idx;
void dfs(int u) {
  l[u] = ++idx;
  for (int i = head[u]; i; i = e[i].x) {
    if (l[e[i].t]) continue;
    dfs(e[i].t);
  }
  r[u] = idx;
}
int t[MAXN];
inline void update(int x, int v) {
  for (int i = x; i <= n; i += i & -i) {
    t[i] += v;
  }
}
inline int get(int x) {
  int res = 0;
  for (;x; x -= x & -x) {
    res += t[x];
  }
  return res;
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &n);
  f(i, 1, n) {
    scanf("%d%d", &u, &v);
    add(u, v);
    add(v, u);
  }
  // idx = 1;
  dfs(1);
  // g(i, 1, n) printf("%d ", l[i]); puts("");
  // g(i, 1, n) printf("%d ", r[i]); puts("");
  g(i, 1, n) {
    update(l[i], 1);
    a[i] = 1;
    // update(r[i] + 1, -1);
  }
  scanf("%d", &m);
  f(i, 0, m) {
    scanf("%s%d", buf, &x);
    if (buf[0] == 'C') {
      update(l[x], -a[x]);
      // update(r[x] + 1, a[x]);
      a[x] = -a[x];
    } else {
      printf("%d\n", get(r[x]) - get(l[x] - 1));
    }
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

