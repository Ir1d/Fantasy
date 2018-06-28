/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-27 08:33:42
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

char buf[12];
int n;
int ti, r, pos;
int a[523], a1;
int b[523], b1;
int c[523], c1;
void mul() {
  c1 = a1 + b1;
  // f(i, 0, b1) printf("%d", b[i]); puts("");
  f(i, 0, c1) c[i] = 0;
  int tee;
  f(i, 0, a1) {
    f(j, 0, b1) {
      tee = a[i] * b[j] + c[i + j];
      if (tee > 9) {
        c[i + j + 1] += tee / 10;
        tee %= 10;
      }
      c[i + j] = tee;
    }
  }
  while (c[c1] == 0) --c1;
  ++c1;
  f(i, 0, c1) b[i] = c[i];
  b1 = c1;
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (~scanf("%s%d", buf, &n)) {
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    memset(c, 0, sizeof c);
    r = 0; ti = 0; pos = 0;
    int len = strlen(buf);
    f(i, 0, strlen(buf)) {
      if (buf[i] == '.') {
        pos = len - 1 - i;
      } else  r = r * 10 + buf[i] - '0';
    }
    --n;
    a1 = 0; b1 = 0;
    f(i, 0, len) if (buf[len - 1 - i] != '.') a[a1++] = buf[len - 1 - i] - '0';
    a[a1] = 0;
    int cc = 0;
    // f(i, 0, a1) printf("%d", a[i]); puts("");
    // return 0;
    // while (a[a1 -  1] == 0) --a1;
    if (a[0] == 0 && pos) f(i, 0, a1) if (a[i]) {
      cc = i; break;
    }
    // printf("%d\n", cc);
    if (cc) f(i, cc, a1) a[i - cc] = a[i];
    a1 -= cc;
    pos -= cc;
    ti = pos * (n + 1);
    // printf("~%d %d\n", pos, a1);
    // printf("%d\n", a1);
    f(i, 0, a1) b[i] = a[i];
    b1 = a1;
    f(i, 0, n) {
      mul();
    }
    // printf("``%d\n", ti);
    // if (ti >= b1) {
    //   putchar('.');
    //   f(i, b1, ti) putchar('0');
    // }
    gd(i, b1 - 1, ti) {
      printf("%d", b[i]);
    }
      // if (ti == i && ti) putchar('.');
    for (cc = 0; cc <= ti && c[cc] == 0; ++cc);
    if (ti > cc) putchar('.');
    gd(i, ti - 1, cc) printf("%d", b[i]);
    puts("");
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

