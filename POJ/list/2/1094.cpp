/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2017-08-19 23:57:19
 * @license Star And Thank Author
 */

#include <cstdio>// NOLINT
#include <cstring>// NOLINT
#include <algorithm>// NOLINT
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

int n, m;
bool smaller[33][33];
const int inconsistent = 1;
const int determined = 2;
const int undetermined = 3;
inline bool cmp(int a, int b) {
  return smaller[a][b];
}
inline int getId(char c) {
  return c - 'A';
}
int work(int a, int b) {
  if (smaller[b][a]) return inconsistent;
  smaller[a][b] = 1;
  f(i, 0, n) if (smaller[i][a]) smaller[i][b] = 1;
  f(i, 0, n) if (smaller[b][i]) smaller[a][i] = 1;
  f(i, 0, n) f(j, i + 1, n) if (!(smaller[i][j] || smaller[j][i])) return undetermined;
  return determined;
}
char buf[12];
inline void input(int x) {
  f(i, x + 1, m) gets(buf);
}
int f[33];
inline void output() {
  f(i, 0, n) f[i] = i;
  std::sort(f, f + n, cmp);
  f(i, 0, n) putchar(f[i] + 'A');
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (~scanf("%d%d\n", &n, &m) && (n || m)) {
    memset(smaller, 0, sizeof smaller);
    int ans = undetermined;
    f(i, 0, m) {
      char a, b, opt;
      a = getchar(); opt = getchar(); b = getchar(); getchar();
      if (opt == '<') ans = work(getId(a), getId(b));
      else ans = work(getId(b), getId(a));
      if (ans == inconsistent) {
        printf("Inconsistency found after %d relations.\n", i + 1);
        input(i);
        break;
      } else if (ans == determined){
        printf("Sorted sequence determined after %d relations: ", i + 1);
        input(i);
        output();
        puts(".");
        break;
      }
    }
    if (ans == undetermined) puts("Sorted sequence cannot be determined.");
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
