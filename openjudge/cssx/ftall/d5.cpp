/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-28 16:20:18
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
int a[233];
int op[233];
char s[23];
double w[233];
double dp[23][233][2];
char buf[12];
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  // scanf("%d", &T);
  int cas = 1;
  while (~scanf("%d", &n)) {
    // scanf("%d", &n);
    g(i, 0, n) scanf("%d", a + i);
    g(i, 1, n) {
      scanf("%s", buf);
      if (buf[0] == '&') op[i] = 0;
      else if (buf[0] == '|') op[i] = 1;
      else op[i] = 2;
    }
    g(i, 1, n) scanf("%lf", w + i);
    f(i, 0, 21) f(j, 0, 201) f(k, 0, 2) dp[i][j][k] = 0;
    f(i, 0, 20) dp[i][0][(a[0] & (1 << i)) >> i] = 1;
    int v;
    f(i, 0, 20) {
      g(j, 1, n) {
        f(k, 0, 2) {
          dp[i][j][k] = 0;
          f(l, 0, 2) {
            if (op[j] == 0 && (((a[j] & (1 << i)) >> i) & l) == k) {
              dp[i][j][k] += dp[i][j - 1][l] * (1 - w[j]);
            }
            if (op[j] == 1 && (((a[j] & (1 << i)) >> i) | l) == k) {
              dp[i][j][k] += dp[i][j - 1][l] * (1 - w[j]);
            }
            if (op[j] == 2 && (((a[j] & (1 << i)) >> i) ^ l) == k) {
              dp[i][j][k] += dp[i][j - 1][l] * (1 - w[j]);
            }
          }
          dp[i][j][k] += dp[i][j - 1][k] * w[j];
        }
      }
    }
    double res = 0.0;
    f(i, 0, 20) res += dp[i][n][1] * (1 << i);
    printf("Case %d:\n", cas++);
    printf("%lf\n", res);
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

