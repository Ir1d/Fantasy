/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-27 11:33:42
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

int n, k;
typedef std::pair<int, int> PII;
std::queue<PII> Q;
int vis[MAXN * 2];
int bfs() {
  vis[n] = 1;
  PII tee;
  while (!Q.empty()) {
    tee = Q.front(); Q.pop();
    if (tee.first * 2 < MAXN * 2 && !vis[tee.first * 2]) {
      vis[tee.first * 2] = 1;
      if (tee.first * 2 == k) {
        return tee.second + 1;
      }
      Q.push(PII(tee.first * 2, tee.second + 1));
    }
    if (tee.first + 1 < MAXN * 2 && !vis[tee.first + 1]) {
      vis[tee.first + 1] = 1;
      if (tee.first + 1 == k) {
        return tee.second + 1;
      }
      Q.push(PII(tee.first + 1, tee.second + 1));
    }if (tee.first - 1 >= 0 && !vis[tee.first - 1]) {
      vis[tee.first - 1] = 1;
      if (tee.first - 1 == k) {
        return tee.second + 1;
      }
      Q.push(PII(tee.first - 1, tee.second + 1));
    }
  }
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d%d", &n, &k);
  Q.push(PII(n, 0));
  if (n == k) puts("0");
  else printf("%d\n", bfs());

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

