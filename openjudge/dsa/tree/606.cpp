/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-12-19 22:55:40
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
const int MAXN = 10033;

int nx[MAXN][26];
int root = 0;
int sz[MAXN];
int tail = 1;
void insert(char *s) {
  int cur = root;
  ++sz[root];
  f(i, 0, strlen(s)) {
    int &c = nx[cur][s[i] - 'a'];
    if (!c) c = tail++;
    cur = c;
    ++sz[cur];
  }
}
char ss[1033][23];
int num;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (~scanf("%s", ss[num++]));
  f(i, 0, num) insert(ss[i]);
  f(i, 0, num) {
    printf("%s ", ss[i]);
    int u = root;
    f(j, 0, strlen(ss[i])) {
      putchar(ss[i][j]);
      u = nx[u][ss[i][j] - 'a'];
      if (sz[u] == 1) break;
    }
    puts("");
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

