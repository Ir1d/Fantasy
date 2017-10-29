/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2017-08-28 16:33:41
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

char dic[10033][23];
int idx;
int cnt;
char str[23];
int n, len;
bool check(char *a) {
  int r = 0, p = 0;
  len = strlen(a);
  if (len != n && len != n - 1 && len != n + 1) return 0;
  if (len == n - 1) {
    f(i, 0, len) {
      if (a[i] != str[p]) {
        if (r) return 0;
        ++r; ++p;
        if (a[i] != str[p]) return 0;
      }
      ++p;
    }
    return 1;
  }
  if (len == n) {
    f(i, 0, n) {
      if (a[i] != str[p]) {
        if (r) return 0;
        ++r;
      }
      ++p;
    }
    return 1;
  }
  f(i, 0, len) {
    if (a[i] != str[p]) {
      if (r) return 0;
      ++r;
      ++i;
      if (a[i] != str[p]) return 0;
    }
    ++p;
  }
  return 1;
}
void solve() {
  n = strlen(str);
  f(i, 0, idx) if (!strcmp(dic[i], str)) {
    printf("%s is correct\n", str);
    return;
  }
  printf("%s:", str);
  f(i, 0, idx) if (check(dic[i])) printf(" %s", dic[i]);
  puts("");
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (~scanf("%s", dic[idx])) {
    if (dic[idx][0] == '#') break;
    ++idx;
  }
  while (~scanf("%s", str) && str[0] != '#') solve();

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
