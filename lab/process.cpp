/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2017-10-08 00:51:47
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


char s[2333];
int main(int argc, char *argv[]) {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  strcpy(s, argv[1]);
  // s = argv[1];
  for (int i = 5; i <= 200; i += 5) {
    printf("cat %d.data | grep %s >> %s.out\n", i, s, s);
  }


#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
