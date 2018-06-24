/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-24 16:32:08
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

int t;
int n;
int w;
typedef std::pair<int, int> PII;
std::vector<PII> m[133];
std::set<int> S;
int lb, rb;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &t);
  int x, y;
  while (t--) {
    scanf("%d", &n);
    f(i, 0, n) m[i].clear();
    lb = 0; rb = oo;
    S.clear();
    f(i, 0, n) {
      scanf("%d", &w);
      int mn = oo, mx = 0;
      f(j, 0, w) {
        scanf("%d%d", &x, &y);
        if (x < mn) mn = x;
        if (x > mx) mx = x;
        S.insert(x);
        m[i].push_back(PII(x, y));
      }
      if (mn > lb) lb = mn;
      if (mx < rb) rb = mx;
    }
    int s = 0;
    double res = 0.0;
    for (auto it: S) if (it >= lb && it <= rb) {
      s = 0;
      f(i, 0, n) {
        int mn = oo;
        f(j, 0, m[i].size()) {
          if (m[i][j].first >= it && m[i][j].second < mn) mn = m[i][j].second;
        }
        // if (mn == oo) {
        //   s = oo; break;
        // }
        s += mn;
      }
      if (s != oo && it * 1.0 / s > res) res = it * 1.0 / s;
    }
    printf("%.03lf\n", res);
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

