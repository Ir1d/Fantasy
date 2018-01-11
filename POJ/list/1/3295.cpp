/**
 * @author SCaffrey (srius.caffrey@gmail.com)
 * @copyright MIT
 */
#include <cstdio>// NOLINT
#include <cstring>// NOLINT
#include <iostream>// NOLINT
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

bool val[12];
std::string str;
int s;
bool solve() {
  char c = str[s++];
  while (c) {
    if (c >= 'a' && c <= 'z') return val[c - 'p'];
    if (c == 'N') return !solve();
    bool f1 = solve(), f2 = solve();
    if (c == 'K') return f1 & f2;
    if (c == 'A') return f1 | f2;
    if (c == 'E') return f1 == f2;
    if (c == 'C') return !f1 | f2;
  }
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (std::cin >> str && str[0] != '0') {
    bool ctf = 1;
    f(idx, 0, 32) {
      f(i, 0, 5) {
        val[i] = idx & (1 << i);
      }
      s = 0;
      ctf = solve();
      if (!ctf) break;
    }
    if (ctf) std::cout << "tautology\n";
    else std::cout << "not\n";
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
