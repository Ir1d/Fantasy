/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-12-10 10:57:43
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
int a[MAXN], b[MAXN];
int s[MAXN];
int st[MAXN], top;
int l[MAXN], r[MAXN];
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (~scanf("%d", &n) && n != -1) {
    g(i, 1, n) {
      scanf("%d%d", a + i, b + i);
      s[i] = (i?s[i - 1]:0) + a[i];
    }
    top = 0;

    g(i, 1, n) {
      while (top && b[ st[top - 1] ] >= b[i]) {
        --top;
      }
      l[i] = top?(st[top - 1]) : 0;
      st[top++] = i;
    }
    // g(i, 1, n) printf("%d ", l[i]); puts("");
    top = 0;
    gd(i, n, 1) {
      while (top && b[ st[top - 1] ] >= b[i]) {
        --top;
      }
      r[i] = top?(st[top - 1]):(n+1);
      st[top++] = i;
    }
    LL res = 0;
    g(i, 1, n) res = std::max(res, (LL)b[i] * (s[ r[i] - 1 ] - s[ l[i] ]));
    printf("%lld\n", res);
  }
  

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

