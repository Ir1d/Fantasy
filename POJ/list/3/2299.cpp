/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2017-10-29 22:10:44
 * @license Star And Thank Author
 */

// #include <bits/stdc++.h>// NOLINT
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
const int MAXN = 500033;

int n;
int a[MAXN], t[MAXN];
LL ans;
void merge(int ll, int rr) {
  if (rr - ll < 2) return;
  int md = ll + (rr - ll >> 1);
  merge(ll, md); merge(md, rr);
  int p = ll, q = md, id = ll;
  while (p < md || q < rr) {
    if (p >= md || (q < rr && a[q] < a[p])) {
      ans += md - p;
      t[id++] = a[q++];
    } else {
      t[id++] = a[p++];
    }
  }
  f(i, ll, rr) a[i] = t[i];
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (~scanf("%d", &n) && n) {
    f(i, 0, n) scanf("%d", a + i);
    ans = 0;
    merge(0, n);
    printf("%lld\n", ans);
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
