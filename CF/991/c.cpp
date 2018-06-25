/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-23 23:52:21
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

LL n;
bool c(LL k) {
  LL x = n;
  LL a = 0, b = 0, c;
  while (x) {
    c = std::min(k, x);
    x -= c; a += c;
    c = x / 10;
    b += c; x = x - c;
  }
  // printf(LLD" "LLD, a, b);
  return a >= b;
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  // for (n = 1; n <= 1000; ++n) {
  scanf(LLD, &n);
  // c(3);
  LL lb = 1, rb = std::min(n / 2 + 2, n), md, ans;
  while (lb <= rb) {
  // f(k, 0, 1024) {
    md = lb + (rb - lb >> 1);
    if (c(md)) {
      rb = md - 1;
      ans = md;
    } else {
      lb = md + 1;
    }
  }
  lb = std::max(1LL, ans - 5);
  rb = std::max(std::min(ans + 5, n / 2), 1LL);
  // printf(LLD, rb);
  // if (c(1)) puts("??");
  for (LL x = lb; x <= rb; ++x) if (c(x)) {
    printf(LLD"\n", x);
    break;
  }
  // g(i, 1, n) if (c(i)) {
  //   printf("%d\n", i);
  //   assert(i == ans);
  //   break;
  // }
  // }
#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
