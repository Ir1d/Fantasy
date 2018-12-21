/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-12-21 09:46:20
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

int T;
int nx[MAXN][11];
int sz[MAXN];
int tail = 1;
char buf[MAXN][12];
int root = 0;
inline bool insert(char *s, int idx) {
  int u = root;
  f(i, 0, strlen(s)) {
    int &r = nx[u][s[i] - '0'];
    if (!r) r = tail++;
    if (sz[r] && sz[r] != idx) return 1;
    u = r;
  }
  // printf("%d, %d\n", u, sz[u]);
  // if (sz[u] && sz[u] != idx) return 1;
  sz[u] = idx;
  return 0;
}
int n;
bool solve() {
  f(i, 0, n) {
    scanf("%s", buf[i]);
    if (insert(buf[i], i + 1)) {
      f(j, i + 1, n) scanf("%s", buf[j]);
      return 0;
    }
  }
  f(i, 0, n) {
    if (insert(buf[i], i + 1)) return 0;
  }
  return 1;
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    tail = 1;
    memset(nx, 0, sizeof nx);
    memset(sz, 0, sizeof sz);
    if (solve()) puts("YES");
    else puts("NO");
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

