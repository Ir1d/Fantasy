/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-23 23:42:02
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

int n;
int x;
int c[6];
int s, t;
int a[233];
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &n);
  t = 4.5 * n + 0.5;
  // printf("%d\n", t);
  f(i, 0, n) {
    scanf("%d", a + i);
    // ++c[x];
    s += a[i];
  }
  std::sort(a, a + n);
  int res = 0;
  if (s * 1.0 / n + 0.5 >= 5) {
    printf("%d\n", res);
    return 0;
  }
  f(i, 0, n) {
    s += 5 - a[i];
    ++res;
    if (s * 1.0 / n + 0.5 >= 5) {
      printf("%d\n", res);
      return 0;
    }
  }


#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

