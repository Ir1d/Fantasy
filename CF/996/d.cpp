/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-25 01:06:15
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

int n;
int a[MAXN];
int pos[MAXN];
int ano[MAXN];
LL ans;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &n);
  f(i, 0, 2 * n) scanf("%d", a + i);
  int w, p;
  for (int i = 0; i < n * 2; i += 2) {
    // w = a[i];
    f(j, i + 1, 2 * n) if (a[j] == a[i]) {
      p = j; break;
    }
    ans += p - (i + 1);
    gd(j, p - 1, i + 1) a[j + 1] = a[j];
    a[i + 1] = a[i];
  }
  printf(LLD"\n", ans);


#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

