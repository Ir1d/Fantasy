/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-25 01:13:47
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
typedef std::pair<LL, LL> P;
P a[MAXN];
inline P operator + (const P &a, const P &b) {
  return P(a.first + b.first, a.second + b.second);
}
inline P operator - (const P &a, const P &b) {
  return P(a.first - b.first, a.second - b.second);
}
inline LL Q(P x) {
  return x.first * x.first + x.second * x.second;
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &n);
  f(i, 0, n) scanf(LLD""LLD, &a[i].first, &a[i].second);
  P w = a[0];
  printf("1");
  f(i, 1, n) {
    if (Q(w + a[i]) < Q(w - a[i])) {
      printf(" 1");
      w = w + a[i];
    } else {
      printf(" -1");
      w = w - a[i];
    }
  }
  // printf("\n"LLD"\n", Q(w));

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

