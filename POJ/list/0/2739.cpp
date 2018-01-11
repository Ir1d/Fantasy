/**
 * @author SCaffrey (srius.caffrey@gmail.com)
 * @copyright MIT
 */
#include <cstdio>// NOLINT
#include <cstring>// NOLINT
#include <cmath>// NOLINT
#include <vector>// NOLINT
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
bool vis[MAXN];
int cnt;
std::vector<int> pri;
void init() {
  f(i, 2, 10000) {
    if (!vis[i]) {
      pri.push_back(i);
      for (int j = i * i; j < 10000; j += i) {
        vis[j] = 1;
      }
    }
  }
  cnt = pri.size();
}
void solve(int n) {
  LL s = 0;
  int l = 0, r = 0, c = 0;
  for (;;) {
    while (r < cnt && s < n) {
      s += pri[r++];
    }
    if (s < n) break;
    if (s == n) ++c;
    s -= pri[l++];
  }
  printf("%d\n", c);
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  init();
  while (~scanf("%d", &n) && n) {
    solve(n);
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
