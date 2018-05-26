/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2018-05-26 14:20:34
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

int T;
int n;
int dp[133][133];
int a[133];
int s[133];
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &T);
  while (T--) {
    memset(dp, 0, sizeof dp);
    scanf("%d", &n);
    s[0] = 0;
    g(i, 1, n) {
      scanf("%d", a + i);
      s[i] = s[i - 1] + a[i];
    }
    int j;
    g(len, 1, n) {
      g(i, 1, n - len + 1) {
        j = i + len - 1;
        dp[i][j] = oo;
        g(k, i, j) {
          dp[i][j] = std::min(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + (s[j] - s[k]) * (k - i) + a[k] * (len - 1));
        }
      }
    }
    printf("%d\n", dp[1][n]);
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
