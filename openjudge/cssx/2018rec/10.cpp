/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-23 14:26:19
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
int n;
int a[MAXN];
int ll[MAXN], rr[MAXN];
int x;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    f(i, 0, n) scanf("%d", a + i);
    memset(ll, 0, sizeof ll);
    memset(rr, 0, sizeof rr);
    x = a[0];
    f(i, 0, n) {
      if (a[i] < x) x = a[i];
      ll[i] = a[i] - x;
      if (i) ll[i] = std::max(ll[i], ll[i - 1]);
    }
    x = a[n - 1];
    gd(i, n - 1, 0) {
      if (a[i] > x) x = a[i];
      rr[i] = x - a[i];
      if (i + 1 < n) rr[i] = std::max(rr[i], rr[i + 1]);
    }
    x = 0;
    f(i, 0, n) x = std::max(x, ll[i] + rr[i + 1]);
    printf("%d\n", x);
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

