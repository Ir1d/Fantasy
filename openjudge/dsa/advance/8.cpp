/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-12-22 18:08:51
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
  gd(i, n - 1, 0) sa[ --c[ x[i] ] ]  = i;
  for (int j = 1; j <= n && p < n; j <<= 1, m = p) {
    p = 0;
    f(i, n - j, n) y[p++] = i;
    f(i, 0, n) if (sa[i] >= j) y[p++] = sa[i] - j;
    f(i, 0, m) c[i] = 0;
    f(i, 0, n) c[ x[y[i]] ]++;
    f(i, 1, m) c[i] += c[i - 1];
    gd(i, n - 1, 0) sa[ --c[ x[ y[i] ] ] ] = y[i];
    t = x; x = y; y = t;
    p = 1; x[ sa[0] ] = 0;
    f(i, 1, n) x[ sa[i] ] = y[sa[i]] == y[ sa[i - 1]] && y[sa[i] + j] == y[sa[i - 1] + j] ? p - 1 : p++;
  }
}
int n;
int a[MAXN];
void getHeight(int n) {
  // puts("SA:"); g(i, 1, n) printf("%d ", sa[i]); puts("");
  g(i, 1, n) rank[ sa[i] ] = i;
  int k = 0, j;
  // height[0] = 0;
  f(i, 0, n) {
    j = sa[ rank[i] - 1];
    for (k?k--:0; a[i + k] == a[j + k]; ++k);
    height[rank[i]] = k;
  }
}
bool solve(int k) {
  int mn = sa[1], mx = sa[1];
  g(i, 2, n) {
    if (height[i] >= k && i < n) {
      mn = std::min(mn, sa[i]);
      mx = std::max(mx, sa[i]);
      continue;
    }
    if (mx - mn >= k) return 1;
    mn = mx = sa[i];
  }
  return 0;
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (~scanf("%d", &n) && n) {
    f(i, 0, n) scanf("%d", a + i);
    f(i, 0, n - 1) a[i] = a[i + 1] - a[i] + 100;
    a[--n] = 0;
    // puts("begins");
    // g(i, 0, n) printf("%d ", a[i]); puts("");
    hz(a, n + 1, 200);
    getHeight(n);
    int ll = 4, rr = n >> 1;
    int md, ans = 0;
    while (ll <= rr) {
      md = ll + (rr - ll >> 1);
      if (solve(md)) {
        ans = md;
        ll = md + 1;
      } else {
        rr = md - 1;
      }
    }
    ++ans;
    // printf("ans: %d\n", ans);
    printf("%d\n", (ans) >= 5 ? ans : 0);
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

