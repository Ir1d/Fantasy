/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-11-02 00:53:03
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
int a[1033];
int b[1033];
char buf[1033];
int c = 0;
void solve(int pos, int ll, int rr) {
  // printf("%d %d\n", ll, rr);
  // [ll, rr]
  if (ll == rr) {
    if (c) putchar(' ');
    printf("%d", a[ll]);
    c = 1;
    return;
  }
  g(i, ll, rr) {
    if (a[i] == b[pos]) {
      if (c) putchar(' ');
      printf("%d", a[i]);
      c = 1;
      solve(pos - 1 - (rr - i), ll, i - 1);
      solve(pos - 1, i + 1, rr);
      return;
    }
  }
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (~scanf("%d", &a[n++]));
  f(i, 0, n / 2) b[i] = a[i + n / 2];
  solve(n / 2 - 1, 0, n / 2 - 1);
  puts("");

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

