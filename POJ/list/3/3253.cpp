/**
 * @author Ir1d (sirius.caffrey@gmail.com)
 * @date    2018-01-12 20:47:23
 * @copyright MIT
 */
#include <cstdio>// NOLINT
#include <cstring>// NOLINT
#include <queue>// NOLINT
#include <vector>// NOLINT
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

std::priority_queue<int, std::vector<int>, std::greater<int> > Q;
int x;
LL ans;
int n;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &n);
  f(i, 0, n) {
    scanf("%d", &x);
    Q.push(x);
  }
  f(i, 1, n) {
    int s = Q.top(); Q.pop();
    int t = Q.top(); Q.pop();
    Q.push(s + t);
    ans += s + t;
  }
  printf(LLD, ans);


#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
