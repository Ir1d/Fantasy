/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-25 14:59:24
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
int w[MAXN], v[MAXN];
int dp[MAXN];
int cnt;
LL s[MAXN];
int res, tot;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (~scanf("%d", &n) && ~n) {
    cnt = 1;
    while (~scanf("%d%d", w + cnt, v + cnt) && ~w[cnt]) ++cnt;
    // printf("``%d\n", w[cnt]);
    res = 0;
    s[1] = v[1]; s[0] = 0;
    f(i, 2, cnt) s[i] = s[i - 1] + v[i];
    f(i, 1, cnt) g(j, 1, i) if (s[i] - s[j - 1] <= n) {
      tot = 0;
      g(k, j, i) tot += w[k];
      if (tot > res) res = tot;
    }
    printf("%d\n", res);
    // memset(dp, 0, sizeof dp);
    // f(i, 0, cnt) {
    //   gd(j, n, v[i]) dp[j] = std::max(dp[j], dp[j - v[i]] + w[i]);
    // }
    // printf("%d\n", dp[n]);
  }
  

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

