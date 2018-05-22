/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2018-05-22 21:43:09
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
const int MAXN = 100033;

int n, m;
char str[633][333];
char buf[333];
int dp[333];
int tee;
int match(const char *s, const char *t) {
  if (s[0] != t[0]) return 0;
  int len = strlen(t);
  int j = 0;
  f(i, 0, len) {
    while (s[j] != '\0' && s[j] != t[i]) ++j;
    if (s[j] == '\0') return 0;
    ++j;
  }
  return j;
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d%d", &n, &m);
  scanf("%s", buf);
  f(i, 0, n) scanf("%s", str[i]);
  dp[m] = 0;
  gd(i, m - 1, 0) {
    dp[i] = dp[i + 1] + 1;
    f(j, 0, n) {
      if (tee = match(&buf[i], str[j])) {
        dp[i] = std::min(dp[i], int(tee - strlen(str[j]) + dp[i + tee]));
      }
    }
  }
  printf("%d\n", dp[0]);

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
