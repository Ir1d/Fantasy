/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-29 01:03:51
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

int s1[555], s2[555];
int dp[555];
int lcis(int n, int m) {
  memset(dp, 0, sizeof dp);
  int k;
  g(i, 1, n) {
    k = 0;
    g(j, 1, m) {
      if (s1[i] == s2[j]) {
        if (dp[j] <= dp[k]) {
          dp[j] = dp[k] + 1;
        }
      }
      if (s1[i] > s2[j]) {
        if (dp[k] < dp[j]) k = j;
      }
    }
  }
  int ans = 0;
  g(i, 1, m) ans = std::max(ans, dp[i]);
  return ans;
}
int T, n, m;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    g(i, 1, n) scanf("%d", s1 + i);
    scanf("%d", &m);
    g(i, 1, m) scanf("%d", s2 + i);
    printf("%d\n", lcis(n, m));
    if (T) puts("");
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

