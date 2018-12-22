/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-12-22 21:56:09
 * @copyright MIT
 */
#include <cstdio>// NOLINT
#include <cstring>// NOLINT
#include <algorithm>// NOLINT
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

char s[MAXN];
int sa[MAXN], rank[MAXN], height[MAXN];
int t1[MAXN], t2[MAXN], r[MAXN], c[MAXN];
void hz(int *r, int n, int m) {
  int *x = t1, *y = t2, *t, p = 0;
  f(i, 0, m) c[i] = 0;
  f(i, 0, n) c[x[i] = r[i]]++;
  f(i, 1, m) c[i] += c[i - 1];
  gd(i, n - 1, 0) sa[ --c[ x[i] ] ] = i;
  for (int j = 1; j <= n && p < n; j <<= 1, m = p) {
    p = 0;
    f(i, n - j, n) y[p++] = i;
    f(i, 0, n) if (sa[i] >= j) y[p++] = sa[i] - j;
    f(i, 0, m) c[i] = 0;
    f(i, 0, n) c[ x[y[i]]]++;
    f(i, 1, m) c[i] += c[i - 1];
    gd(i, n - 1, 0) sa[ --c[ x[ y[i]]]] = y[i];
    t = x; x = y; y = t;
    p = 1; x[ sa[0] ] = 0;
    f(i, 1, n) x[ sa[i] ] = y[ sa[i] ] == y[ sa[i - 1] ] && y[sa[i] + j] == y[ sa[i - 1] + j ] ? p - 1: p++;
  }
}
void getHeight(int n) {
  g(i, 1, n) rank[ sa[i] ] = i;
  int k = 0, j;
  f(i, 0, n) {
    j = sa[ rank[i] - 1 ];
    for (k?k--:0; r[i + k ] == r[j + k]; ++k);
    height[rank[i]] = k;
  }
}
int nu, K;

bool check(int v, int n) {
  int i = 2;
  while (i <= n) {
    while (i <= n && height[i] < v) ++i;
    int k = 0;
    while (i + k <= n && height[i + k] >= v && k < K - 1) ++k;
    if (K - 1 == k) return 1;
    i += k + 1;
  }
  return 0;
}
int a[MAXN];
int num;
int idx[1000005];
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (~scanf("%d%d", &num, &K)) {
    f(i, 0, num) {
      scanf("%d", a + i);
      r[i] = a[i];
    }
    std::sort(a, a + num);
    int sz = std::unique(a, a + num) - a;
    f(i, 0, sz) idx[a[i]] = i + 1;
    f(i, 0, num) r[i] = idx[r[i]];
    r[num] = 0;
    hz(r, num + 1, sz + 1);
    getHeight(num);
    int ll = 0, rr = num - K;
    do {
      int md = ll + (rr - ll >> 1);
      if (check(md, num)) ll = md + 1;
      else rr = md - 1;
    } while (ll <= rr);
    printf("%d\n", rr);
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

