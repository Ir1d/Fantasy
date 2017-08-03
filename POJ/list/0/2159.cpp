/**
 * @author SCaffrey (srius.caffrey@gmail.com)
 * @copyright MIT
 */
#include <algorithm>// NOLINT
#include <cstdio>// NOLINT
#include <cstring>// NOLINT
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

char s[233], t[233];
int c1[33], c2[33];
bool check() {
  f(i, 0, 26) if (c1[i] != c2[i]) return 0;
  return 1;
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (~scanf("%s%s", s, t)) {
    memset(c1, 0, sizeof c1);
    memset(c2, 0, sizeof c2);
    f(i, 0, strlen(s)) ++c1[s[i] - 'A'];
    f(i, 0, strlen(t)) ++c2[t[i] - 'A'];
    std::sort(c1, c1 + 26);
    std::sort(c2, c2 + 26);
    if (check()) puts("YES");
    else puts("NO");
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
