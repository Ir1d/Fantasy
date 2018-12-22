/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-12-22 20:55:21
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
const int MAXN = 300033;

char s[MAXN];
int sa[MAXN], rank[MAXN], height[MAXN];
int t1[MAXN], t2[MAXN], r[MAXN], c[MAXN];
void hz(int *r, int n, int m) {
  int *x = t1, *y = t2, *t, p = 0;
  f(i, 0, m) c[i] = 0;
  f(i, 0, n) c[x[i]=r[i]]++;
  f(i, 1, m) c[i] += c[i - 1];
  gd(i, n - 1, 0) sa[ --c[ x[i] ] ] = i;
  for (int j = 1; j <= n && p < n; j <<= 1, m = p) {
    p = 0;
    f(i, n - j, n) y[p++] = i;
    f(i, 0, n) if (sa[i] >= j) y[p++] = sa[i] - j;
    f(i, 0, m) c[i] = 0;
    f(i, 0, n) c[ x[ y[i]]]++;
    f(i, 1, m) c[i] += c[i - 1];
    gd(i, n - 1, 0) sa[ --c[ x[ y[i] ] ] ] = y[i];
    t = x; x = y; y = t;
    p = 1; x[ sa[0] ] = 0;
    f(i, 1, n) x[ sa[i] ] = y[ sa[i] ] == y[ sa[i - 1] ] && y[ sa[i] + j] == y[ sa[i - 1] + j]?p-1:p++;
  }
}
void getHeight(int n) {
  g(i, 1, n) rank[ sa[i] ] = i;
  int k = 0, j;
  f(i, 0, n) {
    j = sa[ rank[i] - 1];
    for (k?k--:0; r[i + k] == r[j + k]; ++k);
    height[rank[i]] = k;
  }
}
int turn = 0;
int vis[MAXN];
int who[MAXN];
int ans[MAXN];
int nn;
int n;
int cnt;
bool check(int lim) {
  int i, j, k, t;
  int ss;
  bool ctf = 0;
  for (i = 2; i <= n; i = j + 1) {
    while (height[i] < lim && i <= n) ++i;
    for (j = i; height[j] >= lim && j <= n; ++j);
    if (j - i + 1 < nn) continue;
    ++turn;
    ss = 0;
    for (k = i - 1; k < j; ++k) if (t = who[sa[k]]) if (vis[t] != turn) {
      ++ss; vis[t] = turn;
    }
    if (ss >= nn) {
      if (ctf) ans[cnt++] = sa[i - 1];
      else {
        cnt = 1; ans[0] = sa[i - 1]; ctf = 1;
      }
    }
  }
  return ctf;
}
void solve() {
  memset(vis, 0, sizeof vis);
  int mn = 1, mx = n;
  if (!check(mn)) {
    puts("?");
    return;
  }
  while (mn <= mx) {
    int md = mn + (mx - mn >> 1);
    if (check(md)) mn = md + 1;
    else mx = md - 1;
  }
  // printf("%d\n", cnt);
  f(i, 0, cnt) {
    int j = ans[i];
    f(k, 0, mx) printf("%c", r[j + k] - 100);
    puts("");
  }
}
char str[1233];
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif
int num, flag = 0;
  while (~scanf("%d", &num) && num) {
    if (flag) puts("");
    else flag = 1;
    nn = num / 2 + 1;
    int l = 0;
    g(i, 1, num) {
      scanf("%s", str);
      int len = strlen(str);
      f(j, 0, len) {
        r[l + j] = str[j] + 100;
        who[l + j] = i;
      }
      r[l + len] = i; who[l + len] = 0;
      l += len + 1;
    }
    r[l] = 0;
    hz(r, l + 1, 228);
    getHeight(l);
    n = l;
    solve();
  }


#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

