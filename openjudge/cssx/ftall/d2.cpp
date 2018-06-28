/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-28 15:02:10
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

int T;
char buf[1033];
int a[1033];
int c[2], v;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &T);
  while (T--) {
    scanf("%s", buf + 1);
    int ans = oo;
    // buf[0] -= '0';
    int n = strlen(buf + 1);
    g(i, 1, n) {
      a[i] = (buf[i] - '0');
      a[i] += a[i - 1];
      
    }
    g(i, 1, n) {
      ans = std::min(ans, (a[i] + (n - i - (a[n] - a[i]))));
    }
    printf("%d\n", ans);
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

