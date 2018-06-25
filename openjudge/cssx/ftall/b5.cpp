/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-25 14:41:03
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

int n;
char map[1050][1050];
int h[12];
void print(int sz, int x, int y) {
  if (sz == 1) {
    map[x][y] = 'X';
    return;
  }
  print(sz - 1, x, y);
  print(sz - 1, x + h[sz - 1] * 2, y);
  print(sz - 1, x + h[sz - 1], y + h[sz - 1]);
  print(sz - 1, x, y + h[sz - 1] * 2);
  print(sz - 1, x + h[sz - 1] * 2, y + h[sz - 1] * 2);
}
int ss;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (~scanf("%d", &n) && ~n) {
    h[1] = 1;
    g(i, 2, n) h[i] = h[i - 1] * 3;
    ss = h[n];
    f(i, 0, ss) {
      f(j, 0, ss) map[i][j] = ' ';
      map[i][ss] = '\0';
    }
    print(n, 0, 0);
    f(i, 0, ss) printf("%s\n", map[i]);
    puts("-");
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

