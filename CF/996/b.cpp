/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-25 00:36:31
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
int a[MAXN];
int mn;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &n);
  f(i, 0, n) { 
    scanf("%d", a + i);
    if (a[i] < a[mn]) mn = i;
  }
  int pos = a[mn] % n;
  if (a[pos] == a[mn]) {
    printf("%d\n", pos + 1);
    return 0;
  }
  int cur = a[mn];
  f(i, pos, n) {
    if (a[i] <= cur) {
      printf("%d\n", i + 1);
      return 0;
    }
    ++cur;
  }
  f(i, 0, pos) {
    if (a[i] <= cur) {
      printf("%d\n", i + 1);
      return 0;
    }
    ++cur;
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
