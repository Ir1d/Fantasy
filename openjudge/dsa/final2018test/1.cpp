/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-12-12 10:53:41
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

int n, k;
int a[MAXN];
int q[MAXN], ll, rr;
int pos[MAXN];
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d%d", &n, &k);
  g(i, 1, n) scanf("%d", a + i);
  q[rr++] = a[1]; pos[rr - 1] = 1;
  g(i, 2, k) {
    while (rr > ll && q[rr - 1] > a[i]) --rr;
    q[rr++] = a[i]; pos[rr - 1] = i;
  }
  printf("%d ", q[ll]); 
  g(i, k + 1, n) {
    // ++ll;
    while (rr > ll && q[rr - 1] > a[i]) --rr;
    q[rr++] = a[i]; pos[rr - 1] = i;
    if (pos[ll] < i - k + 1) ++ll;
    printf("%d ", q[ll]);
  }
  puts("");
  ll = rr = 0;
  q[rr++] = a[1]; pos[rr - 1] = 1;
  g(i, 2, k) {
    while (rr > ll && q[rr - 1] < a[i]) --rr;
    q[rr++] = a[i]; pos[rr - 1] = i;
  }
  printf("%d ", q[ll]);
  g(i, k + 1, n) {
    while (rr > ll && q[rr - 1] < a[i]) --rr;
    q[rr++] = a[i]; pos[rr - 1] = i;
    if (pos[ll] < i - k + 1) ++ll;
    printf("%d ", q[ll]);
  }
  puts("");

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

