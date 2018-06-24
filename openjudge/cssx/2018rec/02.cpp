/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-22 16:10:31
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

char a[23], b[23];
char s[23][23];
int dis[33][33];
int id;
bool dif(int x, int y) {
  int c = 0;
  f(i, 0, strlen(s[x])) {
    if (s[x][i] != s[y][i]) {
      if (++c == 2) {
        return 0;
      }
    }
  }
  return 1;
}
std::queue<int> Q;
int vis[23];
void solve() {
  while (!Q.empty()) Q.pop();
  int u = 0;
  vis[u] = 1;
  Q.push(u);
  while (!Q.empty()) {
    u = Q.front(); Q.pop();
    f(i, 1, id) if ((dis[u][i] == 1) && (vis[i] == 0)) {
      Q.push(i);
      vis[i] = vis[u] + 1;
    }
  }
  printf("%d\n", vis[1]);
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%s%s", s[0], s[1]);
  id = 2;
  while (~scanf("%s", s[id++]));
  --id;
  memset(dis, 0x1f, sizeof dis);
  f(i, 0, id) dis[i][i] = 0;
  f(i, 0,  id) f(j, 0, i) {
    if (dif(i, j)) dis[i][j] = dis[j][i] = 1;
  }
  f(i, 2, id) if (dif(0, i)) dis[0][i] = 1;
  f(i, 2, id) if (dif(1, i)) dis[i][1] = 1;
  solve();


#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

