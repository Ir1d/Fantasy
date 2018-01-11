/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2017-10-07 16:51:03
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

int n;
int a[23333];
int x;
int m;
char s[233333];
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d%d", &m, &n);
  f(i, 0, n) {
    memset(a, 0, sizeof a);
    scanf("%s", s);
    scanf("%s", s);
    scanf("%d", &x);
    f(j, 0, x) {
      scanf("%d", &x);
      ++a[x - 1];
    }
    printf("%d", a[0]);
    f(i, 1, m) printf(",%d", a[i]);
    puts("");
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
