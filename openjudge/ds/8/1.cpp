/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-12-01 22:31:05
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

int a[MAXN];
int t[MAXN];
long long ans;
void solve(int ll, int rr) {
  if (rr - ll > 1) {
    int p = ll, md = ll + (rr - ll >> 1);
    int q = md, r = ll;
    solve(ll, md);
    solve(md, rr);
    f(i, ll, rr) t[i] = a[i];
    while (p < md || q < rr) {
      if ((p >= md) || (q < rr && t[q] < t[p])) {
        ans += md - p;
        a[r++] = t[q++];
      } else {
        a[r++] = t[p++];
      }
    }
    // f(i, ll, rr) a[i] = t[i];
  }
}
int n;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (~scanf("%d", &n) && n) {
    g(i, 1, n) scanf("%d", a + i);
    ans = 0;
    solve(1, n + 1);
    printf("%lld\n", ans);
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
