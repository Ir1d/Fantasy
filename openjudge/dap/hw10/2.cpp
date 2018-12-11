/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-12-12 00:37:59
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
const int MAXN = 200033;

char s[MAXN];
int sa[MAXN], rank[MAXN], height[MAXN];
int t1[MAXN], t2[MAXN], r[MAXN], c[MAXN];
void hz(int *r, int n, int m) {
  int *x = t1, *y = t2, *t, p = 0;
  f(i, 0, m) c[i] = 0;
  f(i, 0, n) c[ x[i] = r[i] ]++;
  f(i, 1, m) c[i] += c[i - 1];
  gd(i, n - 1, 0) sa[ --c[ x[i] ] ] = i;
  for (int j = 1; j <= n && p < n; j <<= 1, m = p) {
    p = 0;
    f(i, n - j, n) y[p++] = i;
    f(i, 0, n) if (sa[i] >= j) y[p++] = sa[i] - j;
    f(i, 0, m) c[i] = 0;
    f(i, 0, n) c[ x[y[i] ] ]++;
    f(i, 1, m) c[i] += c[i - 1];
    gd(i, n - 1, 0) sa[ --c[x[y[i]]]] = y[i];
    t = x; x = y; y = t;
    p = 1; x[ sa[0] ] = 0;
    f(i ,1, n) x[ sa[i] ] = y[ sa[i] ] == y[ sa[i - 1] ] && y[ sa[i] + j ] == y[ sa[i - 1] + j ] ? p - 1 : p++;
  }
}
void getHeight(int *r, int n) {
  g(i, 1, n) rank[ sa[i] ] = i;
  int k = 0, j;
  f(i, 0, n) {
    j = sa[ rank[i] - 1 ];
    for (k?k--:0; r[i + k] == r[j + k]; ++k);
    height[rank[i]] = k;
  }
}

int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (~scanf("%s", s)) {
    int l1 = strlen(s);
    s[l1] = 'z' + 1;
    scanf("%s", s + l1 + 1);
    int n = strlen(s);
    f(i, 0, n) r[i] = s[i] - 'a' + 1;
    r[n] = 0;
    hz(r, n + 1, 28);
    getHeight(r, n);
    int res = 0;
    g(i, 1, n) if (height[i] > res && ((sa[i] < l1) ^ (sa[i - 1] < l1))) res = height[i];
    printf("%d\n", res);
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
