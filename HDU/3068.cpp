/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-26 15:06:20
 * @copyright MIT
 */
#include <bits/stdc++.h>  // NOLINT
#include <cmath>          // NOLINT
#include <cstdio>         // NOLINT
#include <cstring>        // NOLINT
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

typedef long long LL;  // NOLINT
typedef long double real;

const double INF = 1e100;
const int oo = ~0u >> 2;
const double pi = acos(-1.0);
const double EPS = 1e-8;
const int MAXN = 120033;

char buf[MAXN];
char s[MAXN * 2];
int p[MAXN * 2];
int n, ans, T;
void init() {
  int mx = 0, id;
  f(i, 1, n) {
    if (mx > i) p[i] = std::min(p[2 * id - i], p[id] + id - i);
    else p[i] = 1;
    while (s[ i + p[i] ] == s[ i - p[i] ]) ++p[i];
    if (p[i] + i > mx) {
      mx = p[i] + i; id = i;
    }
  }
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (~scanf("%s", buf)) {
    n = strlen(buf);
    s[0] = '$'; s[1] = '#';
    f(i, 0, n) {
      s[i * 2 + 2] = buf[i];
      s[i * 2 + 3] = '#';
    }
    n = n * 2 + 2;
    s[n] = '\0';
    init();
    ans = 0;
    f(i, 0, n) if (ans < p[i]) ans = p[i];
    printf("%d\n", ans - 1);
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
