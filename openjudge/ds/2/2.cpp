/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-10-01 11:56:55
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

int a[233], b[233], c[555];
int na, nb;
char buf[555];
int tee;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%s", buf);
  na = strlen(buf);
  f(i, 0, na) {
    a[i] = buf[na - 1 - i] - '0';
  }
  scanf("%s", buf);
  nb = strlen(buf);
  f(i, 0, nb) {
    b[i] = buf[nb - 1 - i] - '0';
  }
  f(i, 0, na) {
    f(j, 0, nb) {
      tee = a[i] * b[j] + c[i + j];
      c[i + j + 1] += tee / 10;
      c[i + j] = tee % 10;
    }
  }
  int len = na + nb;
  while (len && c[len - 1] == 0) --len;
  // gd(i, len - 1, 0) printf("%d ", c[i]);
  gd(i, len - 1, 0) putchar(c[i] + '0');

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

