/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-12-22 13:56:27
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
int t[10000003];
int cnt = 0;
inline void upd(int x) {
  if (!x) ++cnt;
  else
  for (x; x <= 10000000; x += x & -x) {
    ++t[x];
  }
}
inline int get(int x) {
  if (x < 0) return 0;
  if (x == 0) return cnt;
  int res = cnt;
  for (; x; x -= x & -x) {
    res += t[x];
  }
  return res;
}
int a[200033];
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &n);
  f(i, 0, n) scanf("%d", a + i);
  LL res = 0;
  gd(i, n - 1, 0) {
    res += get((a[i]&1)?(a[i] / 2):(a[i]/2-1)) + cnt;
    if (a[i]) upd(a[i]);
    else ++cnt;
  }
  printf("%lld\n", res);

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

