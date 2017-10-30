/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2017-10-30 20:08:43
 * @license Star And Thank Author
 */

// #include <bits/stdc++.h>// NOLINT
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

int pos[MAXN];
int n, k;
struct node {
  int id;
  int s[33];
  inline bool operator < (const node & T)  const {
    f(i, 0, k) {
      if (s[i] != T.s[i]) return s[i] < T.s[i];
    }
    return id < T.id;
  }
} p[MAXN];
int x;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d%d", &n, &k);
  p[0].id = 0;
  f(i, 0, k) p[0].s[i] = 0;
  g(i, 1, n) {
    scanf("%d", &x);
    p[i].id = i;
    f(j, 0, k) {
      p[i].s[j] = p[i - 1].s[j] + (x & 1);
      x >>= 1;
    }
    // if (p[i].s[0]) {
    //   f(j, 0, k) --p[i].s[j];
    // }
  }
  std::sort(p, p + n + 1);
  f(i, 0, n) {
    f(j, 0, k) {
      printf("%d ", p[i].s[j]);
    }
    puts("");
  }
  int ans = 0;
  g(i, 1, n) {
    bool ctf = 1;
    f(j, 0, k) {
      if (p[i].s[j] != p[i - 1].s[j]) {
        ctf = 0;
        break;
      }
    }
    if (ctf) {
      if (pos[i - 1] == 0) pos[i] = i - 1;
      else pos[i] = pos[i - 1];
      ans = std::max(ans, abs(p[i].id - p[pos[i]].id));
    }
  }
  printf("%d\n", ans);

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
