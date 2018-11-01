/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-11-02 00:30:58
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

char a, b, c;
bool ctf = 0, str = 0;
char buf[1033];
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  // for (;;) putchar(0);
  while (c = getchar()) {
    if (c == -1) break;
    a = b; b = c;
    if (ctf == 0 && (b == '"' && a != '\\')) {
      str ^= 1;
    }
    if (str) {
      if (a) putchar(a);
      continue;
    }
    if (ctf == 1) {
      if (a == '*' && b == '/') {
        a = b = 0;
        ctf = 0;
      }
    } else {
      if (a == '/' && b == '*') {
        ctf = 1;
        b = 0;
      }
      else if (a) putchar(a);
    }
  }
  if (b) putchar(b);

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

