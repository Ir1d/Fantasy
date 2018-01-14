/**
 * @author Ir1d (sirius.caffrey@gmail.com)
 * @date    2018-01-14 10:36:41
 * @copyright MIT
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

int target, num;
char s[8];
bool rej, err;
int ans[8], sz, sum;
int tee[8], cur, tot;
void dfs(int x, int pos) {
  if (x == 0) {
    cur = pos;
    if (sum < tot && tot <= target) {
      sum = tot;
      sz = cur;
      err = rej = 0;
      f(i, 0, sz) ans[i] = tee[i];
    } else if (sum == tot && tot <= target) {
      rej = 1;
    }
    return;
  }
  if (x + tot < sum) return;
  for (int dec = 10; dec <= x * 10; dec *= 10) {
    tot += x % dec;
    tee[pos] = x % dec;
    dfs(x / dec, pos + 1);
    tot -= x % dec;
  }
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (~scanf("%d%d", &target, &num) && (target || num)) {
    rej = 0; err = 1;
    sum = tot = 0;
    dfs(num, 0);
    if (rej && !err) {
      puts("rejected");
    } else if (err) {
      puts("error");
    } else {
      printf("%d", sum);
      gd(i, sz - 1, 0) printf(" %d", ans[i]);
      puts("");
    }
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
