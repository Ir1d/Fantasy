/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-12-21 09:24:03
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

int n, m, k;
struct mat {
  LL a[133][133];
  int sz;
  inline mat(int n) {
    memset(a, 0, sizeof a);
    sz = n;
  }
  inline mat operator * (const mat &T) const {
    mat res(sz);
    LL r;
    f(k, 0, sz) {
      f(i, 0, sz) {
        r = a[i][k];
        f(j, 0, sz) {
          res.a[i][j] += r * T.a[k][j];
        }
      }
    }
    return res;
  }
};

char buf[12];
int x, y;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (~scanf("%d%d%d", &n, &m, &k) && (n || m || k)) {
    mat T(n + 1), res(n + 1);
    f(i, 0, T.sz) T.a[i][i] = 1;
    f(i, 0, res.sz) res.a[i][i] = 1;
    mat A(n + 1);
    A.a[0][0] = 1;
    f(i, 0, k) {
      scanf("%s%d", buf, &x);
      if (buf[0] == 'g') {
        ++T.a[0][x];
      } else if (buf[0] == 'e') {
        f(i, 0, T.sz) T.a[i][x] = 0;
      } else {
        scanf("%d", &y);
        f(i, 0, T.sz) std::swap(T.a[i][x], T.a[i][y]);
      }
    }
    while (m) {
      if (m & 1) res = res * T;
      T = T * T;
      m >>= 1;
    }
    A = A * res;
    // A = res * A;
    g(i, 1, n) printf("%lld ", A.a[0][i]);
    puts("");
    // g(i, 0, n) {
    //   g(j, 0, n) printf("%d ", A.a[i][j]); puts("");
    // }
    // printf("%d\n", )
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

