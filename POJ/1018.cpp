/**
 * @author Ir1d (sirius.caffrey@gmail.com)
 * @date    2018-05-19 21:30:33
 * @copyright MIT
 */
#include <cstdio>// NOLINT
#include <cstring>// NOLINT
#include <vector>// NOLINT
#include <queue>// NOLINT
#include <utility>// NOLINT
#include <algorithm>// NOLINT
#include <iomanip>// NOLINT
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
int n;
typedef std::pair<int, int> PII;
std::vector<PII> G[233];
// std::vector<int> V;
int lb, rb;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &T);
  while (T--) {
  lb = 0; rb = oo;
    // V.clear();
    scanf("%d", &n);
    f(i, 0, n) G[i].clear();
    f(i, 0, n) {
      int t;
      scanf("%d", &t);
      int x, y;
      int ll = oo, rr = 0;
      f(j, 0, t) {
        scanf("%d%d", &x, &y);
        G[i].push_back(PII(x, y));
        // V.push_back(x);
        if (x < ll) ll = x;
        if (x > rr) rr = x;
      }
      if (ll > lb) lb = ll;
      if (rr < rb) rb = rr;
    }
    // std::sort(V.begin(), V.end());
    f(i, 0, n) std::sort(G[i].begin(), G[i].end(), std::greater<PII>());
    // int mn = V[0], mx = *V.rbegin();
    double ans = 0.0;
    g(cur, lb, rb) {
    // f(it, 0, V.size()) {
      // int cur = V[it];
      int b = 0;
      f(i, 0, n) {
        int ww = -1;
        f(j, 0, G[i].size()) if (G[i][j].first >= cur) {
          if (ww == -1 || G[i][j].second < G[i][ww].second) {
            ww = j;
          }
        } else break;
        if (ww == -1) {
          b = oo;
          break;
        }
        // a = std::min(G[i][ww].first, a);
        b += G[i][ww].second;
      }
      // printf("%d %d %lf\n", cur, b, cur * 1.0 / b);
      if (b != oo && cur * 1.0 / b > ans) ans = cur * 1.0 / b;
    }
    printf("%.03lf\n", ans);
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
