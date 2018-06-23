/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-23 10:34:25
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
int a[12];
bool dfs(int n) {
  if (n == 1) {
    return a[0] == 42;
  }
  bool ctf = 0;
  f(i, 0, n) f(j, 0, i) {
    int x = a[i], y = a[j], z = a[n - 1];
    a[j] = a[n - 1];
    a[i] = x + y;
    ctf |= dfs(n - 1);
    a[i] = x - y; a[j] = a[n - 1];
    ctf |= dfs(n - 1);
    a[i] = y - x; a[j] = a[n - 1];
    ctf |= dfs(n - 1);
    a[i] = x * y; a[j] = a[n - 1];
    ctf |= dfs(n - 1);
    if (y && x % y == 0) {
      a[i] = x / y; a[j] = a[n - 1];
      ctf |= dfs(n - 1);
    }
    a[i] = x; a[n - 1] = z; a[j] = y;
    if (ctf) return 1;
  }
  return 0;
}
int solve() {
  if (dfs(n)) puts("YES");
  else puts("NO");
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &n);
  f(i, 0, n) scanf("%d", a + i);
  solve();
  // printf("%d\n", solve());


#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

