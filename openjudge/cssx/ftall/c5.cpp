/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-27 09:17:27
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

int p, e, i, d;
int extGcd(int a, int b, int &x, int &y) {
  if (b) {
    int r = extGcd(b, a % b, y, x);
    y -= a / b * x;
    return r;
  }
  x = 1; y = 0;
  return a;
}
int get(int a, int b) {
  int x, y;
  extGcd(a, b, x, y);
  return (x % b + b) % b;
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d%d%d%d", &p, &e, &i, &d);
  // int res = p * 28 * 33 + e * 23 * 33 + i * 23 * 28;
  // res %= 23 * 28 * 33;
  // while (res < d) res += 23 * 28 * 33;
  int M1 = 28 * 33;
  int M2 = 23 * 33;
  int M3 = 23 * 28;
  int t1 = get(M1, 23);
  int t2 = get(M2, 28);
  int t3 = get(M3, 33);
  int res = (p * t1 * M1 + e * t2 * M2 + i * t3 * M3 - d + 21252) % 21252;
  // res %= 21252;
  while (res <= 0) res += 21252;
  printf("%d\n", res);

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

