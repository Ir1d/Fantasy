/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-23 13:56:08
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

int T;
int row[12][12], col[12][12];
int block[12][12];
inline int hash(int x, int y) {
  return (x / 3) * 3 + (y / 3);
}
int map[12][12];
void input() {
  memset(row, 0, sizeof row);
  memset(col, 0, sizeof col);
  memset(block, 0, sizeof block);
  f(i, 0, 9) f(j, 0, 9) {
    scanf("%1d", &map[i][j]);
    row[i][map[i][j]] = 1;
    col[j][map[i][j]] = 1;
    block[hash(i, j)][map[i][j]] = 1;
  }
}
bool ctf = 0;
void dfs(int x, int y) {
  if (ctf) return;
  int pos = hash(x, y);
  if (x == 9 && y == 0) {
    ctf = 1;
    f(xx, 0, 9) {
     f(yy, 0, 9) {
       // if (yy) putchar(' ');
       printf("%d", map[xx][yy]);
     }
     puts("");
    }
    return;
  }
  int nx = x, ny = y + 1;
  if (ny == 9) {
    ++nx; ny = 0;
  }
  while (map[nx][ny]) {
    ++ny;
    if (ny == 9) {
      ++nx; ny = 0;
    }
  }
  g(i, 1, 9) if (row[x][i] == 0 && col[y][i] == 0 && block[pos][i] == 0) {
    row[x][i] = 1; col[y][i] = 1; block[pos][i] = 1;
    map[x][y] = i;
    dfs(nx, ny);
    row[x][i] = 0; col[y][i] = 0; block[pos][i] = 0;
    map[x][y] = 0;
  }
}
void solve() {
  ctf = 0;
  f(i, 0, 9) f(j, 0, 9) if (map[i][j] == 0) {
    dfs(i, j);
    // if (ctf) {
      return;
    // }
  }
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  // f(i, 0, 9) {
  //   f(j, 0, 9) printf("%d ", hash(i, j));
  //   puts("");
  // }
  // return 0;
  scanf("%d", &T);
  while (T--) {
    input();
    solve();
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

