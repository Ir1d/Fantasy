/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-24 00:21:31
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
char s[233];
char t[233];
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%s%s", s, t);
  n = strlen(s);
  int res = 0;
  int cnt = 0;
  f(i, 0, n) {
    // printf("%d %d\n", i, cnt);
    if (s[i] == '0' && t[i] == '0') {
      if (cnt == 0 && i && (s[i - 1] == '0' || t[i - 1] == '0')) {
        t[i] = s[i] = '1';
        ++res;
      } else {
        ++cnt;
        if (cnt == 3) {
          res += 2;
          cnt = 0;
          s[i] = '1';
          t[i] = '1';
        }
      }
    } else if (s[i] == '0') {
      if (cnt == 1) {
        ++res; cnt = 0;
        s[i] = '1';
      } else if (cnt == 2) {
        ++res; cnt = 0;
      }
    } else if (t[i] == '0') {
      if (cnt == 1) {
        ++res; cnt = 0;
        t[i] = '1';
      } else if (cnt == 2) {
        ++res; cnt = 0;
      }
    } else {
      if (cnt == 2) ++res;
      cnt = 0;
    }
  }
  // printf("%d\n", cnt);
  if (cnt == 2) ++res;
  printf("%d\n", res);
  // printf("%s\n", s);
  // printf("%s\n", t);

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

