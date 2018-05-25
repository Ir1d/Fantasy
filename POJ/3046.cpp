/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2018-05-25 23:05:21
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

int cnt[1033], sum[1033], dp[2][MAXN], sd[MAXN];
int ans, n, m, a, b, x, y;
const int MOD = 1000000;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d%d%d%d", &n, &m, &a, &b);
  g(i, 1, m) {
    scanf("%d", &x);
    ++cnt[x];
  }
  g(i, 1, n) sum[i] = sum[i - 1] + cnt[i];
  dp[0][0] = 1;
  g(i, 0, m) sd[i] = 1;
  g(i, 1, n) {
    y = i & 1;
    g(j, 0, sum[i]) {
      dp[y][j] = ((sd[j] - sd[j - std::min(cnt[i], j) - 1]) % MOD + MOD) % MOD;
    }
    sd[0] = dp[y][0];
    g(j, 1, m) sd[j] = (sd[j - 1] + dp[y][j]) % MOD;
  }
  ans = 0;
  g(i, a ,b) ans = (ans + dp[n & 1][i]) % MOD;
  printf("%d\n", ans);

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
