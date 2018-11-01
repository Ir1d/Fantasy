/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-11-02 00:08:13
 * @copyright MIT
 */
#include <bits/stdc++.h>  // NOLINT
#include <cmath>          // NOLINT
#include <cstdio>         // NOLINT
#include <cstring>        // NOLINT
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

typedef long long LL;  // NOLINT
typedef long double real;

const double INF = 1e100;
const int oo = ~0u >> 2;
const double pi = acos(-1.0);
const double EPS = 1e-8;
const int MAXN = 100033;

int n;
char a[233][233];
char s[233];
inline char cc(char c) {
  if (c >= 'A' && c <= 'Z') return c - 'A' + 'a';
  return c;
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &n);
  f(i, 0, n) {
    scanf("%s", a[i]);
  }
  scanf("%s", s);
  f(i, 0, n) {
    bool c = 0, ctf = 1;
    int pos = 0;
    f(j, 0, strlen(s)) {
      // if (a[i][pos] == 0) {
      //   ctf = 0;
      //   break;
      // }
      // printf("``(%c, %c)\n", s[j], a[i][pos]);
      if (cc(s[j]) != cc(a[i][pos])) {
        if (cc(s[j]) != '[') {
          ctf = 0;
          break;
        } else {
          while (cc(s[j]) != ']') {
            if (cc(s[j]) == cc(a[i][pos])) {
              // printf("``%d\n", j);
              c = 1;
            }
            ++j;
          }
          if (!c) {
            ctf = 0;
            break;
          }
          else ++pos;
        }
      } else {
        ++pos;
      }
    }
    if (ctf) {
      printf("%d %s\n", i + 1, a[i]);
    }
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
