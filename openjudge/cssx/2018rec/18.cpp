/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-24 15:37:55
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

int n, k;
bool dp[11000][111];
// int a[10003];
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d%d", &n, &k);
  dp[0][0] = 1;
  int x;
  int a, b;
  g(i, 1, n) {
    scanf("%d", &x);
    x = abs(x);
    x %= k;
    f(j, 0, k) if (dp[i - 1][j]) {
      dp[i][(j + x) % k] = 1;
      dp[i][((j - x) % k + k) % k] = 1;
    }
  }
  if (dp[n][0]) puts("Divisible");
  else puts("Not divisible");

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

