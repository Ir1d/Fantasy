/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-12-22 14:12:45
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

typedef std::pair<int, int> PII;
PII p[MAXN], tee;
std::set<PII> S;
int n, x, y;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (~scanf("%d", &n) && n) {
    f(i, 0, n) {
      scanf("%d%d", &p[i].first, &p[i].second);
    }
    int ans = 0;
    std::sort(p, p + n);
    f(i, 0, n) {
      f(j, i + 1, n) {
        tee.first = p[i].first + (p[i].second - p[j].second);
        tee.second = p[i].second + (p[j].first - p[i].first);
        // if (S.find(tee) == S.end())
        if (*std::lower_bound(p, p + n, tee) != tee) continue;
        tee.first = p[j].first + (p[i].second - p[j].second);
        tee.second = p[j].second + (p[j].first - p[i].first);
        if (*std::lower_bound(p, p + n, tee) != tee) continue;
        ++ans;
      }
    }
    printf("%d\n", ans / 2);
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

