/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2018-05-25 12:59:18
 * @copyright MIT
 */
#include <bits/stdc++.h>  // NOLINT
#include <cmath>          // NOLINT
#include <cstdio>         // NOLINT
#include <cstring>        // NOLINT
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

typedef long long LL;  // NOLINT
typedef long double real;

const double INF = 1e100;
const int oo = ~0u >> 2;
const double pi = acos(-1.0);
const double EPS = 1e-8;
const int MAXN = 100033;

int n;
void dfs(int x) {
  if (x == 0) {
    printf("0");
    return;
  }
  int k = 0;
  while (x >= (1 << k)) ++k;
  --k;
  if (k == 1) {
    printf("2");
  } else {
    printf("2(");
    dfs(k);
    printf(")");
  }
  x -= 1 << k;
  while (x) {
    k = 0;
    while (x >= (1 << k)) ++k;
    --k;
    if (k == 1) {
      printf("+2");
    } else {
      printf("+2(");
      dfs(k);
      printf(")");
    }
    x -= 1 << k;
  }
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &n);
  dfs(n);

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
