/**
 * @author Ir1d (sirius.caffrey@gmail.com)
 * @date    2018-01-13 14:45:46
 * @copyright MIT
 */
#include <cstdio>// NOLINT
#include <cstring>// NOLINT
#include <queue>// NOLINT
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

int pri[MAXN];
bool vis[MAXN];
int cnt;
void init(int n) {
  memset(vis, 0, sizeof vis);
  pri[0] = pri[1] = 0;
  vis[0] = vis[1] = 1;
  g(i, 2, n) {
    if (!vis[i]) pri[cnt++] = i;
    f(j, 0, cnt) {
      if (i * pri[j] > MAXN) break;
      vis[i * pri[j]] = 1;
      if (i % pri[j] == 0) break;
    }
  }
}
int dp[MAXN];
int changeDig(int x, int d, int v) {
  switch(d) {
    case 0:
      return x / 10 * 10 + v;
    case 1:
      return x / 100 * 100 + x % 10 + v * 10;
    case 2:
      return x / 1000 * 1000 + x % 100 + v * 100;
    case 3:
      return x % 1000 + v * 1000;
  }
}
int T;
int s, t;
std::queue<int> Q;
int solve() {
  while (!Q.empty()) Q.pop();
  Q.push(s); dp[s] = 0;
  int u, v;
  while (!Q.empty()) {
    u = Q.front(); Q.pop();
    // if (u == t) return dp[u];
    f(i, 0, 4) {
      f(j, 0, 10) {
        if (i == 3 && j == 0) continue;
        v = changeDig(u, i, j);
        if (vis[v] || dp[v] <= dp[u]) continue;
        dp[v] = dp[u] + 1;
        // if (v == t) return dp[v];
        Q.push(v);
      }
    }
  }
  return dp[t];
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  init(MAXN - 1);
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &s, &t);
    memset(dp, 0x1f, sizeof dp);
    printf("%d\n", solve());
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
