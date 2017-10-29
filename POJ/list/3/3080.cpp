/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2017-10-29 21:12:50
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
const int MAXN = 100033;

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
    f(i, 0, n) c[ x[ y[i] ] ]++;
    f(i, 1, m) c[i] += c[i - 1];
    gd(i, n - 1, 0) sa[ --c[ x[ y[i] ] ] ] = y[i];
    t = x; x = y; y = t;
    p = 1; x[ sa[0] ] = 0;
    f(i, 1, n) {
      x[ sa[i] ] = (y[ sa[i] ] == y[ sa[i - 1] ] && y[ sa[i] + j ] == y[ sa[i - 1] + j ]) ? p - 1 : p++;
    }
  }
}
void getHeight(int n) {
  g(i, 1, n) rank[ sa[i] ] = i;
  int k = 0, j;
  f(i, 0, n) {
    j = sa[ rank[i] - 1 ];
    for (k?k--:0; s[i + k] == s[j + k]; ++k);
    height[ rank[i] ] = k;
  }
}

int T, n, l;
char ans[MAXN];
char t[MAXN];
int id[MAXN], vis[4005];
bool check(int md, int n, int k) {
  int cnt = 0;
  memset(vis, 0, sizeof vis);
  g(i, 1, n) {
    if (height[i] < md) {
      memset(vis, 0, sizeof vis);
      cnt = 0;
      continue;
    }
    if (!vis[id[sa[i - 1]]]) {
      ++cnt;
      vis[id[sa[i - 1]]] = 1;
    }
    if (!vis[id[sa[i]]]) {
      ++cnt;
      vis[id[sa[i]]] = 1;
    }
    if (cnt == k) {
      f(j, 0, md) {
        ans[j] = s[sa[i] + j];
      }
      ans[md] = '\0';
      return 1;
    }
  }
  return 0;
}
int lb, rb, md, ctf;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    s[0] = '\0';
    l = strlen(s);
    f(i, 0, n) {
      scanf("%s", t);
      l = strlen(s);
      if (i) s[l] = 'A' - 1;
      else --l;
      f(j, l + 1, l + 1 + strlen(t)) id[j] = i;
      strcpy(s + l + 1, t);
    }
    l = strlen(s);
    // puts(s);
    f(i, 0, l) r[i] = s[i] - 'A' + 2;
    hz(r, l + 1, 28);
    getHeight(l);
    lb = 1; rb = l; ctf = 0;
    while (lb <= rb) {
      md = lb + (rb - lb >> 1);
      if (check(md, l, n)) {
        ctf = md;
        lb = md + 1;
      } else {
        rb = md - 1;
      }
    }
    if (ctf >= 3) printf("%s\n", ans);
    else puts("no significant commonalities");
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
