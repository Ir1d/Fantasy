/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2017-08-17 10:05:13
 * @license Star And Thank Author
 */

#include <cstdio>// NOLINT
#include <cstring>// NOLINT
#include <iostream>// NOLINT
#include <map>// NOLINT
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

std::string names[33];
int n, m;
double dis[33][33];
bool ctf;
std::map<std::string, int> M;
void init() {
  f(i, 0, n) {
    std::cin >> names[i];
    M[names[i]] = i;
    dis[i][i] = 1;
  }
  std::cin >> m;
  std::string s1, s2;
  double l;
  f(i, 0,m) {
    std::cin >> s1 >> l >> s2;
    dis[M[s1]][M[s2]] = l;
  }
}
bool check() {
  f(i, 0, n) if (dis[i][i] > 1) return 1;
  return 0;
}
int t = 0;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (std::cin >> n && n) {
    g(i, 0, n) g(j, 0, n) dis[i][j] = 1e100;
    init();
    f(k, 0, n) f(i, 0, n) f(j, 0, n) {
      if (dis[i][j] < dis[i][k] * dis[k][j]) dis[i][j] = dis[i][k] * dis[k][j];
    }
    std::cout << "Case " << ++t << ": ";
    if (check()) std::cout << "Yes" << "\n";
    else std::cout << "No" << "\n";
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
