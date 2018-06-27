/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-27 14:40:54
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
int l[MAXN * 3];
int ll[MAXN * 3];
int r[MAXN * 3];
int rr[MAXN * 3];
char buf[MAXN * 3];
int len;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &n);
  f(idx, 0, n) {
    scanf("%s", buf);
    r[idx] = l[idx] = 0;
    len = strlen(buf);
    f(i, 0, len) if (buf[i] == '(') {
      f(j, i, len) if (buf[j] == '(') {
        ++r[idx];
      } else {
        if (r[idx]) --r[idx];
      }
      break;
    }
    gd(i, len - 1, 0) if (buf[i] == ')') {
      gd(j, i, 0) if (buf[j] == ')') ++l[idx];
      else if (l[idx]) --l[idx];
      break;
    }
  }
  f(i, 0, n) {
    if (l[i] < 0) l[i] = 0;
    if (r[i] < 0) r[i] = 0;
  }
  // f(i, 0, n) printf("%d %d\n", l[i], r[i]);
  LL res = 0;
  f(i, 0, n) {
    if (l[i] == 0) {
      res += ll[ r[i] ];
    }
    if (r[i] == 0) {
      res += rr[ l[i]]; 
    }
    if (!l[i]) ++rr[ r[i] ];
    if (!r[i]) ++ll[ l[i] ];
  }
  // printf(LLD"\n", res);
  // f(i, 0, n) printf("%d %d\n", ll[i], rr[i]);
  f(i, 0, n) {
    if (l[i] == 0 && r[i] == 0) ++res;
  }
  printf(LLD, res);

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

