/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2017-10-01 22:27:59
 * @license Star And Thank Author
 */

#include <cstdio>// NOLINT
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

char map[505][505];
int lb, rb, ub, db;
int d[505];
char s[23];
int id;
int cx, cy;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif
  rb = db = 1;
  while (~scanf("%s", s)) {
    if (s[0] == 'd') d[id] = 1;
    else if (s[0] == 'l') d[id] = 2;
    else if (s[0] == 'u') d[id] = 3;
    else d[id] = 4;
    ++id;
  }
  f(i, 0, id) {
    if (d[i] == 1) {
      ++cx;
    } else if (d[i] == 2) {
      --cy;
    } else if (d[i] == 3) {
      --cx;
    } else {
      ++cy;
    }
    if (cx > db) db = cx;
    if (cy > rb) rb = cy;
    if (cx < ub) ub = cx;
    if (cy < lb) lb = cy;
  }
  cx = 1 - ub; cy = 1 - lb;
  map[cx][cy] = 'S';
  db = cx; rb = cy;
  f(i, 0, id) {
    if (d[i] == 1) {
      ++cx;
    } else if (d[i] == 2) {
      --cy;
    } else if (d[i] == 3) {
      --cx;
    } else {
      ++cy;
    }
    if (!map[cx][cy]) map[cx][cy] = '*';
    if (cx > db) db = cx;
    if (cy > rb) rb = cy;
  }
  map[cx][cy] = 'E';
  g(i, 0, db + 1) map[i][0] = map[i][rb + 1] = '#';
  g(i, 0, rb + 1) map[0][i] = map[db + 1][i] = '#';
  g(i, 0, db) g(j, 0, rb) if (!map[i][j]) map[i][j] = ' ';
  // g(i, 0, rb + -lb) map[-ub + db][i] = map[0][i] = '#';
  // f(i, 1, -ub + db) {
  //   map[i][0] = map[i][rb + -lb] = '#';
  //   f(j, 1, rb + -lb) if (!map[i][j]) map[i][j] = ' ';
  // }
  g(i, 0, db + 1) puts(map[i]);


#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
