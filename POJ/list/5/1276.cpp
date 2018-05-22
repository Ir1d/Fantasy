/**
 * @author Ir1d (sirius.caffrey@gmail.com)
 * @date    2018-03-08 19:49:37
 * @copyright MIT
 */
#include <cstdio>// NOLINT
#include <cstring>// NOLINT
#include <algorithm>// NOLINT
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

int n, m;
int dp[100033];
int c[23], num[23];
void zeroOne(int c, int w) {
  gd(i, m, c) dp[i] = std::max(dp[i], dp[i - c] + w);
}
void complete(int c, int w) {
  g(i, c, m) dp[i] = std::max(dp[i], dp[i - c] + w);
}
#include <cassert>
void solve() {
  g(i, 1, n) {
    if (num[i] * c[i] > m) {
      complete(c[i], c[i]);
    } else {
      int k = 1;
      while (k < num[i]) {
        // if (num[i] & k) {
          zeroOne(k * c[i], k * c[i]);
          // num[i] -= k;
        // }
        k <<= 1;
      }
      // printf("`%d\n", k);
      // assert(num[i] == 0);
      zeroOne(num[i] * c[i], num[i] * c[i]);
    }
  }
  printf("%d\n", dp[m]);
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (~scanf("%d%d", &m, &n)) {
    g(i, 1, n) {
      scanf("%d%d", num + i, c + i);
    }
    memset(dp, 0, sizeof dp);
    solve();
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
