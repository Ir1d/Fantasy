/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-22 16:28:00
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

char s[5][5];
int map[5][5];
int tee[5][5];
int res = oo;
void solve() {
  int x;
  f(it, 0, 1 << 4) {
    f(i, 0, 4) f(j, 0, 4) tee[i][j] = map[i][j];
    x = 0;
    f(i, 0, 4) if (it & (1 << i)) {
      x += 1;
      tee[0][i] ^= 1;
      if (i) tee[0][i - 1] ^= 1;
      if (i + 1 < 4) tee[0][i + 1] ^= 1;
      tee[1][i] ^= 1;
    }
    f(i, 1, 4) f(j, 0, 4) if (tee[i - 1][j]) {
      ++x;
      tee[i - 1][j] ^= 1;
      tee[i][j] ^= 1;
      if (i + 1 < 4) tee[i + 1][j] ^= 1;
      if (j) tee[i][j - 1] ^= 1;
      if (j + 1 < 4) tee[i][j + 1] ^= 1;
    }
    f(i, 0, 4) if (tee[3][i]) {
      x = -1;
      break;
    }
    if (x != -1 && x < res) res = x;
  }
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  f(i, 0, 4) {
    scanf("%s", s[i]);
  }
  f(i, 0, 4) f(j, 0, 4) if (s[i][j] == 'b') map[i][j] = 1;
  else map[i][j] = 0;
  solve();
  f(i, 0, 4) f(j, 0, 4) if (s[i][j] == 'b') map[i][j] = 0;
  else map[i][j] = 1;
  solve();
  if (res != oo) printf("%d\n", res);
  else puts("Impossible");

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

