/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2017-08-16 22:14:52
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

char map[12][33];
char s[] = "+---+---+---+---+---+---+---+---+";
void init() {
  bool white = 1;
  g(i, 1, 8) {
    for (int j = 1; j <= 24; j += 3) {
      if (white) {
        map[i][j] = map[i][j + 1] = map[i][j + 2] = '.';
      } else {
        map[i][j] = map[i][j + 1] = map[i][j + 2] = ':';
      }
      white ^= 1;
    }
    white ^= 1;
  }
}
void get(int ls) {
  char c = getchar();
  char x, y;
  if (c >= 'A' && c <= 'Z') {
    y = getchar();
    x = getchar();
    if (ls == 1) c += 32;
  } else {
    x = getchar();
    y = c;
    if (ls == 1) c = 'p';
    else c = 'P';
  }
  map[8 - (x - '0') + 1][(y - 'a' + 1) * 3 - 1] = c;
}
void print() {
  puts(s);
  g(i, 1, 8) {
    putchar('|');
    for (int j = 1; j <= 24; j += 3) {
      printf("%c%c%c|", map[i][j], map[i][j + 1], map[i][j + 2]);
    }
    puts("");
    puts(s);
  }
}
char str[23];
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (~scanf("%s", str)) {
    getchar();
    init();
    int ls = 0;
    while (1) {
      get(ls);
      char c = getchar();
      if (c == ',') continue;
      if (c == '\n') {
        if (++ls == 2) {
          print();
          break;
        } else {
          scanf("%s", str);
          getchar();
          continue;
        }
      }
    }
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
