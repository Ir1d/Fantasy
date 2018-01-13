/**
 * @author Ir1d (sirius.caffrey@gmail.com)
 * @date    2018-01-13 13:02:05
 * @copyright MIT
 */
#include <cstdio>// NOLINT
#include <cstring>// NOLINT
#include <queue>// NOLINT
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

int n, k;
int vis[MAXN];
std::queue<int> Q;
int a[3];
int x;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d%d", &n, &k);
  Q.push(n);
  vis[n] = 1;
  if (n == k) {
    puts("0");
    return 0;
  }
  while (!Q.empty()) {
    x = Q.front(); Q.pop();
    a[0] = x * 2; a[1] = x + 1; a[2] =  x - 1;
    f(i, 0, 3) {
      if (a[i] > MAXN || a[i] < 0 || vis[a[i]]) continue;
      Q.push(a[i]);
      vis[a[i]] = vis[x] + 1;
      if (a[i] == k) {
        printf("%d\n", vis[a[i]] - 1);
        return 0;
      }
    }
  }
  puts("-1");

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
