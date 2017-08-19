/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2017-08-18 20:48:40
 * @license Star And Thank Author
 */

#include <cstdio>// NOLINT
#include <queue>// NOLINT
#include <algorithm>// NOLINT
#include <cstring>// NOLINT
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
char maz[233][233];
bool vis[233][233];
int d[233][233][233];
int alien[233][2];
int numa;
int x, y, sx, sy;
int e[233][233];
std::queue<PII> Q;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};
bool used[233];
void bfs() {
  sx = sy = -1;
  numa = 0;
  memset(vis, 0, sizeof vis);
  f(i, 0, x) f(j, 0, y) {
    if (maz[i][j] == 'S') {
      sx = i; sy = j; break;
    }
  }
  vis[sx][sy] = 1;
  d[0][sx][sy] = 0;
  alien[numa][0] = sx;
  alien[numa++][1] = sy;
  Q.push(PII(sx, sy));
  int nx, ny;
  while (!Q.empty()) {
    PII cur = Q.front(); Q.pop();
    f(i, 0, 4) {
      nx = cur.first + dx[i];
      ny = cur.second + dy[i];
      if (nx >= 0 && nx < x && ny >= 0 && ny < y && !vis[nx][ny] && maz[nx][ny] != '#') {
        d[0][nx][ny] = d[0][cur.first][cur.second] + 1;
        vis[nx][ny] = 1;
        Q.push(PII(nx, ny));
        if (maz[nx][ny] == 'A') {
          alien[numa][0] = nx;
          alien[numa++][1] = ny;
        }
      }
    }
  }
  f(ai, 1, numa) {
    memset(vis, 0, sizeof vis);
    int ax = alien[ai][0], ay = alien[ai][1];
    d[ai][ax][ay] = 0;
    Q.push(PII(ax, ay));
    vis[ax][ay] = 1;
    while (!Q.empty()) {
      PII cur = Q.front(); Q.pop();
      f(i, 0, 4) {
        nx = cur.first + dx[i];
        ny = cur.second + dy[i];
        if (nx >= 0 && nx < x && ny >= 0 && ny < y && !vis[nx][ny] && maz[nx][ny] != '#') {
          d[ai][nx][ny] = d[ai][cur.first][cur.second] + 1;
          vis[nx][ny] = 1;
          Q.push(PII(nx, ny));
        }
      }
    }
  }
  f(i, 0, numa) {
    f(j, 0, numa) {
      int ax1 = alien[j][0], ay1 = alien[j][1];
      e[i][j] = d[i][ax1][ay1];
    }
  }
}
std::priority_queue<PII, std::vector<PII>, std::greater<PII> > PQ;
int prim() {
  memset(used, 0, sizeof used);
  used[0] = 1;
  int unum = 1;
  f(i, 1, numa) {
    PQ.push(PII(e[0][i], i));
  }
  int ans = 0;
  while (unum < numa) {
    PII cur = PQ.top(); PQ.pop();
    int t = cur.second, td = cur.first;
    if (used[t]) continue;
    ans += td; used[t] = 1; ++unum;
    f(i, 0, numa) {
      if (!used[i]) PQ.push(PII(e[t][i], i));
    }
  }
  while (!PQ.empty()) PQ.pop();
  return ans;
}
int T;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &T);
  while (T--) {
    scanf("%d%d\n", &y, &x);
    // NOTE THIS!!!!!
    f(i, 0, x) gets(maz[i]);
    bfs();
    printf("%d\n", prim());
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
