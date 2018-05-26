/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2018-05-26 14:31:55
 * @copyright MIT
 */
#include <cstdio>// NOLINT
#include <cstring>// NOLINT
#include <algorithm>// NOLINT
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

typedef std::pair<int, int> PII;
std::queue<PII> Q;
PII pre[6][6];
int map[6][6];
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};
int nx, ny;
void solve() {
  Q.push(PII(4, 4));
  map[4][4] = 1;
  pre[4][4] = PII(-1, -1);
  PII tee;
  while (!Q.empty()) {
    tee = Q.front();
    Q.pop();
    f(i, 0, 4) {
      nx = tee.first + dx[i];
      ny = tee.second + dy[i];
      if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
      if (map[nx][ny]) continue;
      map[nx][ny] = 1;
      pre[nx][ny] = tee;
      if (nx == 0 && ny == 0) return;
      Q.push(PII(nx, ny));
    }
  }
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  f(i, 0, 5) {
    f(j, 0, 5) {
      scanf("%d", &map[i][j]);
    }
  }
  solve();
  PII tee = PII(0, 0);
  while (tee.first != -1) {
    printf("(%d, %d)\n", tee.first, tee.second);
    tee = pre[tee.first][tee.second];
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
