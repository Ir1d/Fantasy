/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2017-08-17 09:36:22
 * @license Star And Thank Author
 */

#include <cstdio>// NOLINT
#include <cstring>// NOLINT
#include <algorithm>// NOLINT
#include <queue>// NOLINT
#include <map>// NOLINT
#include <string>// NOLINT
#include <iostream>// NOLINT
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

struct edge {
  int t, x;
  double w;
} e[5033];
int head[123], cnt = 1;
inline void add(int s, int t, double w) {
  e[++cnt].t = t; e[cnt].x = head[s]; head[s] = cnt; e[cnt].w = w;
}
double dis[123];
bool inq[123];
std::queue<int> Q;
int ti[123];
int n, m;
bool spfa() {
  while (!Q.empty()) Q.pop();
  memset(ti, 0, sizeof ti);
  memset(dis, 0, sizeof dis);
  memset(inq, 0, sizeof inq);
  Q.push(1); inq[1] = 1; dis[1] = 1; ti[1] = 1;
  int u, tee;
  while (!Q.empty()) {
    u = Q.front(); Q.pop();
    inq[u] = 0;
    for (int i = head[u]; i; i = e[i].x) {
      tee = e[i].t;
      if (dis[tee] < dis[u] * e[i].w) {
        dis[tee] = dis[u] * e[i].w;
        if (++ti[tee] > n) return 1;
        if (!inq[tee]) {
          inq[tee] = 1; Q.push(tee);
        }
      }
    }
  }
  return 0;
}
std::map<std::string, int> M;
std::string s1, s2;
int cas = 1;
double tee;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  std::ios::sync_with_stdio(0); std::cin.tie(0);
  while (std::cin >> n && n) {
    M.clear();
    g(i, 1, n) {
      std::cin >> s1; M[s1] = i;
    }
    std::cin >> m;
    memset(head, 0, sizeof head); cnt = 1;
    while (m--) {
      std::cin >> s1 >> tee >> s2;
      add(M[s1], M[s2], tee);
    }
    std::cout << "Case " << cas++ << ": ";
    if (spfa()) std::cout << "Yes\n";
    else std::cout << "No\n";
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
