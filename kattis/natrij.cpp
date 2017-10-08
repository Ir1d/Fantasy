/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2017-10-01 22:08:40
 * @license Star And Thank Author
 */

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

struct node {
  int v[3];
  inline void read() {
    scanf("%d:%d:%d", v, v + 1, v + 2);
  }
  inline bool operator < (const node& T) const {
    return v[0] < T.v[0] || (v[0] == T.v[0] && v[1] < T.v[1])
     || (v[0] == T.v[0] && v[1] == T.v[1] && v[2] < T.v[2]);
  }
  inline node operator - (const node& T) const {
    node res;
    f(i, 0, 3) res.v[i] = v[i];
    res.v[2] -= T.v[2];
    if (res.v[2] < 0) {
      res.v[2] += 60; --res.v[1];
    }
    res.v[1] -= T.v[1];
    if (res.v[1] < 0) {
      res.v[1] += 60; --res.v[0];
    }
    res.v[0] -= T.v[0];
    return res;
  }
  inline void print() {
    printf("%02d:%02d:%02d\n", v[0], v[1], v[2]);
  }
} a, b;
int res;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  a.read();
  b.read();
  if (!(a < b)) b.v[0] += 24;
  a = b - a;
  a.print();

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
