/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-27 14:09:58
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

int n, k;
int nx[MAXN * 2];
int a[MAXN * 2];
int x;
int s[MAXN * 10];
bool v[MAXN * 10];
int c[MAXN * 2];
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d%d", &n, &k);
  s[0] = 0;
  f(i, 0, n) {
    scanf("%d", a + i);
    if (a[i] - k >= 0) ++s[ a[i] - k ];
    else ++s[0];
    --s[ a[i] ];
  }
  int res = n;
  g(i, 1, MAXN * 10 - 330) s[i] += s[i - 1];
  f(i, 0, n) if (s[ a[i] ] && !c[i]) {
    --res;
    // printf("%d ", i);
  }
  // puts("");
  printf("%d\n", res);
  // std::sort(a, a + n);


#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

