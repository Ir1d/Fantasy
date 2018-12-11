/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-12-11 23:21:15
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
const int MAXN = 805033;

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
    f(i, 1, n) x[ sa[i] ] = y[sa[i]] == y[ sa[i - 1] ] && y[sa[i] + j] == y[sa[i - 1] + j] ? p - 1 : p++;
  }
}
void getHeight(int *r, int n) {
  g(i, 1, n) rank[ sa[i] ] = i;
  int k = 0, j;
  f(i, 0, n) {
    j = sa[ rank[i] - 1];
    for (k?k--:0; r[i + k] == r[j + k]; ++k);
    height[rank[i]] = k;
  }
}
int mn;
void solve() {
  int n = strlen(s);
  f(i, 0, n) r[i] = s[i] - 'a' + 1;
  hz(r, n + 1, 27);
  // getHeight(n);
  g(i, 1, n) printf("%d ", sa[i] + 1);
  puts("");
  g(i, 2, n) printf("%d ", height[i]);
  puts("");
}
int n;
int vis[MAXN], ti;
char ans[MAXN];
int id[MAXN];
int a[MAXN];
int res, len;
bool check(int k) {
  int cnt = 0;
  memset(vis, 0, sizeof vis);
  ti = 1;
  g(i, 2, res) {
    if (height[i] < k) {
      ++ti;
      cnt = 0;
      continue;
    }
    if (vis[id[sa[i - 1]]] != ti) {
      vis[id[sa[i - 1]]] = ti;
      ++cnt;
    }
    if (vis[id[sa[i]]] != ti) {
      vis[id[sa[i]]] = ti;
      ++cnt;
    }
    if (cnt == n) {
      f(j, 0, k) ans[j] = a[ sa[i] + j ];
      ans[k] = 0;
      // printf("\n%d: %s???\n", k, ans);
      return 1;
    }
  }
  return 0;
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (~scanf("%d", &n) && n) {
    memset(sa, 0, sizeof sa);
    memset(rank, 0, sizeof rank);
    memset(height, 0, sizeof height);
    res = 0;
    f(i, 0, n) {
      scanf("%s", s);
      len = strlen(s);
      f(j, 0, len) {
        a[res] = s[j];
        id[res++] = i;
      }
      a[res] = '#' + i;
      id[res++] = '#' + i;
    }
    a[res] = 0;
    hz(a, res + 1, 5000);
    // g(i, 0, res) printf("%d ", sa[i]); puts("");
    getHeight(a, res);
    // g(i, 0, res) printf("%d ", height[i]); puts("");
    int ll = 1, rr = strlen(s), ctf = 0, md;
    while (ll <= rr) {
      // printf("::%d %d: ", ll, rr);
      md = ll + (rr - ll >> 1);
      if (check(md)) {
        // printf("%d\n", md);
        ctf = 1;
        ll = md + 1;
      } else {
        // puts("");
        rr = md - 1;
      }
    }
    if (ctf) printf("%s\n", ans);
    else puts("IDENTITY LOST");
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
