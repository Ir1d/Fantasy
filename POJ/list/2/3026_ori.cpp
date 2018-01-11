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
  f(i, 0, y) {
    f(j, 0, x) {
      if (maz[i][j] == 'S') {
        sx = j; sy = i; break;
      }
    }
  }
  vis[sy][sx] = 1;
  d[0][sy][sx] = 0;
  alien[numa][0] = sy;
  alien[numa++][1] = sx;
  Q.push(PII(sy, sx));
  int nx, ny;
  while (!Q.empty()) {
    PII cur = Q.front(); Q.pop();
    f(i, 0, 4) {
      ny = cur.first + dy[i];
      nx = cur.second + dx[i];
      if (nx >= 0 && nx < x && ny >= 0 && ny < y && !vis[ny][nx] && maz[ny][nx] != '#') {
        d[0][ny][nx] = d[0][cur.first][cur.second] + 1;
        vis[ny][nx] = 1;
        Q.push(PII(ny, nx));
        if (maz[ny][nx] == 'A') {
          alien[numa][0] = ny;
          alien[numa++][1] = nx;
        }
      }
    }
  }
  f(ai, 1, numa) {
    memset(vis, 0, sizeof vis);
    int ay = alien[ai][0], ax = alien[ai][1];
    d[ai][ay][ax] = 0;
    Q.push(PII(ay, ax));
    vis[ay][ax] = 1;
    while (!Q.empty()) {
      PII cur = Q.front(); Q.pop();
      f(i, 0, 4) {
        ny = cur.first + dy[i];
        nx = cur.second + dx[i];
        if (nx >= 0 && nx < x && ny >= 0 && ny < y && !vis[ny][nx] && maz[ny][nx] != '#') {
          d[ai][ny][nx] = d[ai][cur.first][cur.second] + 1;
          vis[ny][nx] = 1;
          Q.push(PII(ny, nx));
        }
      }
    }
  }
  f(i, 0, numa) {
    f(j, 0, numa) {
      int ay1 = alien[j][0], ax1 = alien[j][1];
      e[i][j] = d[i][ay1][ax1];
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
    scanf("%d%d\n", &x, &y);
    f(i, 0, y) gets(maz[i]);
    bfs();
    printf("%d\n", prim());
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
