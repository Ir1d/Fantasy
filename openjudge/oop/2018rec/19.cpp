/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-24 12:02:28
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

int n, k, p;
LL res;
int pre;
int pos[233];
int cnt[233];
int can[233];
int x, y;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d%d%d", &n, &k, &p);
  g(i, 1, n) {
    scanf("%d%d", &x, &y);
    if (y <= p) pre = i;
    if (pos[x] <= pre) {
      can[x] = cnt[x];
    }
    res += can[x];
    // printf("%d %d\n", i, can[x]);
    pos[x] = i;
    ++cnt[x];
  }
  printf(LLD, res);

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

