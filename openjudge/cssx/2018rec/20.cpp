/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-24 11:54:56
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
char s[233], t[233], w[500];
int dp[233][233];
int n, m;
void solve() {
  memset(dp, 0, sizeof dp);
  dp[0][0] = 1;
  g(i, 0, n) g(j, 0, m) if (i + j) {
    if (w[i + j] == s[i]) dp[i][j] |= dp[i - 1][j];
    if (w[i + j] == t[j]) dp[i][j] |= dp[i][j - 1];
  }
  // g(i, 1, n) {
  //   g(j, 1, m) printf("%d ", dp[i][j]);
  //   puts("");
  // }
  if (dp[n][m]) puts("yes");
  else puts("no");
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &T);
  g(cas, 1, T) {
    scanf("%s%s%s", s + 1, t + 1, w + 1);
    n = strlen(s + 1);
    m = strlen(t + 1);
    printf("Data set %d: ", cas);
    solve();
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

