/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-12-10 15:42:13
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

char p[MAXN];
int d[MAXN];
int n;
void get() {
  d[0] = d[1] = 0;
  int j;
  f(i, 1, n) {
    j = d[i];
    while (j && p[i] != p[j]) j = d[j];
    if (p[i] == p[j]) d[i + 1] = j + 1;
    else d[i + 1] = 0;
  }
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (~scanf("%s", p)) {
    if (p[0] == '.') break;
    n = strlen(p);
    get();
    if (n == d[n]) printf("%d\n", n);
    else if (n % (n - d[n])) puts("1");
    else printf("%d\n", n / (n - d[n]));
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

