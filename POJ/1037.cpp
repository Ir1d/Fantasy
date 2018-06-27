/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-27 20:56:50
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

LL c[25][25][2];
// 0 for up
// 1 for down
int n;
void init() {
  int n = 20;
  memset(c, 0, sizeof c);
  c[1][1][0] = c[1][1][1] = 1;
  g(i, 2, n) {
    g(k, 1, i)  {
      f(r, k, i) c[i][k][0] += c[i - 1][r][1];
      f(r, 1, k) c[i][k][1] += c[i - 1][r][0];
    }
  }
}
int a[25], used[25];
void print(int n, LL idx) {
  LL skipped = 0;
  memset(used, 0, sizeof used);
  int num;
  g(i, 1, n) {
    LL oldVal = skipped;
    num = 0;
    g(k, 1, n) {
      oldVal = skipped;
      if (!used[k]) {
        ++num;
        if (i == 1) skipped += c[n][num][0] + c[n][num][1];
        else {
          if (k > a[i - 1] && (i == 2 || a[i - 2] > a[i - 1])) {
            skipped += c[n - i + 1][num][1];
          } else if (k < a[i - 1] && (i == 2 || a[i - 2] < a[i - 1])) {
            skipped += c[n - i + 1][num][0];
          }
        }
        if (skipped >= idx) {
          a[i] = k;
          used[k] = 1;
          skipped = oldVal;
          break;
        }
      }
    }
  }
  g(i, 1, n) printf("%d ", a[i]);
  puts("");
}
int T;
LL idx;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  init();
  scanf("%d", &T);
  while (T--) {
    scanf("%d"LLD, &n, &idx);
    print(n, idx);
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

