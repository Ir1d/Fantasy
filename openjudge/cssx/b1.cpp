/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-24 21:06:43
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
char map[5][5];
typedef std::pair<int, int> PII;
std::vector<PII> V;
int a[5];
int calc() {
  f(i, 0, 4) a[i] = 0;
  f(i, 0, 4) f(j, 0, i) if (map[i][j] == 'W') {
    ++a[i];
  } else ++a[j];
  int res = 1;
  f(i, 1, 4) if (a[i] > a[0]) ++res;
  return res;
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &T);
  while (T--) {
    f(i, 0, 4) scanf("%s", map[i]);
    V.clear();
    f(i, 0, 4) f(j, 0, i) if (map[i][j] == '?') V.push_back(PII(i, j));
    int n = V.size();
    int res = 4;
    f(i, 0, 1 << n) {
      f(j, 0, n) if (i & (1 << j)) {
        map[V[j].first][V[j].second] = 'W';
      } else map[V[j].first][V[j].second] ='L';
      res = std::min(calc(), res);
    }
    printf("%d\n", res);
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

