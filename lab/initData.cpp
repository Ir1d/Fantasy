/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2017-10-08 13:00:35
 * @license Star And Thank Author
 */

#include <bits/stdc++.h>// NOLINT
#include <cstdio>// NOLINT
#include <cstring>// NOLINT
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

double rss[233];
double sp[233];
double db[233];
int it[233];
char s[233];
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  freopen("data.res", "r", stdin);
  f(i, 0, 40) scanf("%s%lf", s, rss + i);
  f(i, 0, 40) scanf("%s%lf", s, sp + i);
  f(i, 0, 40) scanf("%s%lf", s, db + i);
  f(i, 0, 40) scanf("%s%d", s, it + i);
  printf("rss = [ ");
  f(i, 0, 40) printf("%lf ", rss[i]);
  printf("]\n");
  printf("sp = [ ");
  f(i, 0, 40) printf("%lf ", sp[i]);
  printf("]\n");
  printf("db = [ ");
  f(i, 0, 40) printf("%lf ", db[i]);
  printf("]\n");
  printf("it = [ ");
  f(i, 0, 40) printf("%d ", it[i]);
  printf("]\n");
  printf("x = [");
  for (int i = 5; i <= 200; i += 5) printf("%d ", i);
  puts("]");

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
