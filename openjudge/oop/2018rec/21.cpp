/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-24 11:45:46
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
char s[1033];
int res = 0;
int dp[1033];
bool c(int ll, int rr) {
  for (int i = ll; i <= rr; ++i) {
    if (s[i] != s[rr - (i - ll)]) return 0;
    if (i > rr - (i - ll)) break;
  }
  return 1;
}
void solve() {
  memset(dp, 0x1f, sizeof dp);
  int n = strlen(s + 1);
  dp[0] = 0;
  // if (c(1, n)) printf("???");
  g(i, 1, n) {
    if (c(1, i)) dp[i] = 0;
    g(j, 2, i) if (c(j, i)) dp[i] = std::min(dp[i], dp[j - 1] + 1);
  }
  printf("%d\n", dp[n]);
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &T);
  while (T--) {
    scanf("%s", s + 1);
    solve();
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

