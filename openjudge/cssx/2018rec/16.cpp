/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-24 13:14:47
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

int pri[MAXN], cnt;
bool vis[MAXN * 10];
void init() {
  vis[0] = vis[1] = 1;
  g(i, 2, MAXN - 33) {
    if (!vis[i]) {
      pri[cnt++] = i;
    }
    f(j, 0, cnt) {
      if (i * pri[j] > MAXN) break;
      vis[i * pri[j]] = 1;
      if (i % pri[j] == 0) break;
    }
  }
  // f(i, 0, 10) printf("%d\n", pri[i]);
}
int n, a, b;
int m;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  init();
  while (~scanf("%d%d%d", &n, &a, &b) && (n || a || b)) {
    LL mx = 0, p, q;
    f(i, 0, cnt) if (pri[i] <= n) {
      g(j, 0, i) if (pri[i] * pri[j] <= n) {
        if (a * pri[i] <= b * pri[j] && pri[i] * pri[j] > mx) {
          mx = pri[i] * pri[j];
          p = pri[j]; q = pri[i];
        }
      } else break;
    } else break;
    printf(LLD" "LLD"\n", p, q);
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

