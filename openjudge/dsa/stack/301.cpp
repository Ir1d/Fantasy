/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-12-10 11:36:54
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
const int MAXN = 1000033;

int n, k, a[MAXN], q[MAXN], ft, rr;
int pos[MAXN];
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (~scanf("%d%d", &n, &k)) {
    g(i, 1, n) scanf("%d", a + i);
    // min
    ft = rr = 0; memset(pos, 0, sizeof pos);
    q[rr++] = a[1]; pos[rr - 1] = 1;
    g(i, 2, k) {
      while (rr > ft && q[rr - 1] > a[i]) --rr;
      q[rr++] = a[i]; pos[rr - 1] = i;
    }
    printf("%d ", q[ft]);
    g(i, k + 1, n) {
      while (rr > ft && q[rr - 1] > a[i]) --rr;
      q[rr++] = a[i]; pos[rr - 1] = i;
      if (pos[ft] < i - k + 1) ++ft;
      printf("%d ", q[ft]);
    }
    puts("");
    // max
    ft = rr = 0;
    memset(pos, 0, sizeof pos);
    q[rr++] = a[1], pos[rr - 1] = 1;
    g(i, 2, k) {
      while (rr > ft && q[rr - 1] < a[i]) --rr;
      q[rr++] = a[i]; pos[rr - 1] = i;
    }
    printf("%d ", q[ft]);
    g(i, k + 1, n) {
      while (rr > ft && q[rr - 1] < a[i]) --rr;
      q[rr++] = a[i]; pos[rr - 1] = i;
      if (pos[ft] < i - k + 1) ++ft;
      printf("%d ", q[ft]);
    }
    puts("");
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

