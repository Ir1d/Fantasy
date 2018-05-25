/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2018-05-25 20:14:28
 * @copyright MIT
 */
#include <algorithm>  // NOLINT
#include <cmath>          // NOLINT
#include <cstdio>         // NOLINT
#include <cstring>        // NOLINT
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

typedef long long LL;  // NOLINT
typedef long double real;

const double INF = 1e100;
const int oo = ~0u >> 2;
const double pi = acos(-1.0);
const double EPS = 1e-8;
const int MAXN = 633;

int n, m;
int a[MAXN], b[MAXN];
int dp[MAXN][MAXN];
int pre[MAXN][MAXN];
int st[MAXN];
void solve() {
  g(i, 1, n) scanf("%d", a + i);
  scanf("%d", &m);
  g(j, 1, m) scanf("%d", b + j);
  memset(dp, 0, sizeof dp);
  dp[0][0] = 0;
  int mx, pos;
  g(i, 1, n) {
    mx = pos = 0;
    g(j, 1, m) {
      if (a[i] == b[j]) {
        dp[i][j] = mx + 1;
        pre[i][j] = pos;
      } else {
        dp[i][j] = std::max(dp[i][j], dp[i - 1][j]);
      }
      if (b[j] < a[i] && mx < dp[i - 1][j]) {
        mx = dp[i - 1][j];
        pos = j;
      }
    }
  }
  int ans = -1, x = n, y, p = 0;
  g(i, 1, n) g(j, 1, m) {
    if (ans < dp[i][j]) {
      ans = dp[i][j];
      y = j;
    }
  }
  printf("%d\n", ans);
  while (ans--) {
    st[++p] = b[y];
    while (a[x] != b[y]) --x;
    y = pre[x][y];
    --x;
  }
  gd(i, p, 1) printf("%d ", st[i]); puts("");
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (~scanf("%d", &n)) solve();

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
