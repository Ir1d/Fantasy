/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-28 11:20:36
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

const int MOD = 1e9 + 7;
int n;
int a[MAXN];
std::vector<int> V;
int h[MAXN];
int dp[MAXN];
const int MX = 5e4 + 10;
void get(int pos, int &x, int &y) {
  x = y = 0;
  for (; pos; pos -= pos & -pos) {
    if (x < h[pos]) {
      x = h[pos]; y = dp[pos];
    } else if (x == h[pos]) {
      y += dp[pos];
      if (y >= MOD) y %= MOD;
    }
  }
}
void update(int pos, int x, int y) {
  for (; pos <= MX; pos += pos & -pos) {
    if (h[pos] < x) {
      h[pos] = x; dp[pos] = y;
    } else if (h[pos] == x) {
      dp[pos] += y;
      if (dp[pos] >= MOD) dp[pos] %= MOD;
    }
  }
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &n);
  g(i, 1, n) {
    scanf("%d", a + i);
    V.push_back(a[i]);
  }
  std::sort(V.begin(), V.end());
  V.erase(std::unique(V.begin(), V.end()), V.end());
  g(i, 1, n) a[i] = std::lower_bound(V.begin(), V.end(), a[i]) - V.begin() + 1;
  // g(i, 1, n) printf("%d ", a[i]); puts("");
  int x, y;
  g(i, 1, n) {
    get(a[i] - 1, x, y);
    ++x;
    update(a[i], x, (x == 1) ? 1 : y);
  }
  int ans;
  get(n, x, ans);
  printf("%d\n", ans);

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

