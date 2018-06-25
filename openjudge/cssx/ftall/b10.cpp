/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-25 16:36:05
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

int m, n, s;
int h[133], c[133], t[133], r[133];
char buf[12];
int dp[2033][2405];
void zeroOne(int c, int t, int v, int T, int C) {
  gd(i, C, c) {
    gd(j, T, t) {
      dp[i][j] = std::max(dp[i][j], dp[i - c][j - t] + v);
    }
  }
}
void complete(int c, int t, int v, int T, int C) {
  g(i, c, C) {
    g(j, t, T) {
      dp[i][j] = std::max(dp[i][j], dp[i - c][j - t] + v);
    }
  }
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d%d%d", &m, &n, &s);
  f(i, 0, n) {
    scanf("%d%d%d%s", h + i, c + i, t + i, buf);
    if (buf[0] == 'l') {
      r[i] = 1;
    } else {
      r[i] = 0;
    }
  }
  int T, C;
  int ans = 0;
  g(days, 1, m) {
    T = days * 24;
    C = s - 200 * (days / 3);
    if (days % 3) C -= (days % 3 + 1) * 50;
    if (C < 0) break;
    memset(dp, 0, sizeof dp);
    f(i, 0, n) if (r[i]) zeroOne(c[i], t[i], h[i], T, C);
    else complete(c[i], t[i], h[i], T, C);
    ans = std::max(ans, dp[C][T]);
  }
  printf("%d\n", ans);

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

