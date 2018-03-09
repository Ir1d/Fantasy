/**
 * @author Ir1d (sirius.caffrey@gmail.com)
 * @date    2018-03-09 16:20:40
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
// std::set<LL> S;
LL a[MAXN], b[MAXN];
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d%d", &n, &m);
  g(i, 1, n) scanf(LLD, a + i);
  g(i, 1, m) scanf(LLD, b + i);
  g(i, 1, n) a[i] += a[i - 1];
  int ans = 0;
  LL *pos;
  LL delta = 0, cur = 0;
  g(i, 1, m) {
    cur += b[i];
    pos = std::lower_bound(a + 1, a + n + 1, cur + delta);
    if (*pos == cur + delta) {
      ++ans;
      delta += cur;
      cur = 0;
    }
  }
  printf("%d\n", ans);

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
