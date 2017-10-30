/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2017-10-30 21:03:50
 * @license Star And Thank Author
 */

// #include <bits/stdc++.h>// NOLINT
#include <stdio.h>// NOLINT
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
// const double pi = acos(-1.0);
const double EPS = 1e-8;
const int MAXN = 100033;

int a[5];
short M[25000003];
// std::unordered_map<int, int> M;
int cur;
int ans;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  g(i, 1, 5) scanf("%d", a + i);
  g(x1, -50, 50) {
    if (!x1) continue;
    g(x2, -50, 50) {
      if (!x2) continue;
      cur = a[4] * x1 * x1 * x1 + a[5] * x2 * x2 * x2;
      cur = -cur;
      if (cur < 0) cur += 25000000;
      ++M[cur];
    }
  }
  g(x1, -50, 50) {
    if (!x1) continue;
    g(x2, -50, 50) {
      if (!x2) continue;
      g(x3, -50, 50) {
        if (x3) {
          cur = a[1] * x1 * x1 * x1 + a[2] * x2 * x2 * x2 + a[3] * x3 * x3 * x3;
          if (cur < 0) cur += 25000000;
          ans += M[cur];
        }
      }
    }
  }
  printf("%d\n", ans);

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
