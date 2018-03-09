/**
 * @author Ir1d (sirius.caffrey@gmail.com)
 * @date    2018-03-09 16:30:31
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

std::vector<int> G[MAXN * 2];
int cnt;
char buf[MAXN * 2];
std::queue<int> q[2];
int c, pos;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%s", buf);
  f(i, 0, strlen(buf)) {
    c = buf[i] - 48;
    if (q[c].empty()) {
      if (c) {
        puts("-1");
        return 0;
      }
      ++cnt;
      G[cnt - 1].push_back(i);
      q[c ^ 1].push(cnt - 1);
    } else {
      pos = q[c].front(); q[c].pop();
      G[pos].push_back(i);
      q[c ^ 1].push(pos);
    }
  }
  if (cnt == 0 || !q[0].empty()) {
    puts("-1");
    return 0;
  }
  printf("%d\n", cnt);
  f(i, 0, cnt) {
    printf("%d", int(G[i].size()));
    f(j, 0, G[i].size()) printf(" %d", G[i][j] + 1);
    puts("");
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
