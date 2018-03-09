/**
 * @author Ir1d (sirius.caffrey@gmail.com)
 * @date    2018-03-09 16:46:22
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

int a[MAXN];
int b[MAXN];
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  int n;
  scanf("%d", &n);
  g(i, 1, n) a[2 * i - 1] = i;
  fd(i, 2 * n - 1, n) {
    if (a[i]) {
      int j = i - 1;
      while (a[j]) --j;
      a[j] = a[i];
    }
  }
  g(i, 1, n) printf("%d ", a[i]);
  g(i, 1, n) b[a[i]] = i;
  puts("");
  g(i, 1, n) printf("%d ", b[i]);

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
