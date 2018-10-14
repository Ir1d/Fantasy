/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-10-14 23:08:16
 * @copyright MIT
 */
#include <cstdio>// NOLINT
#include <cstring>// NOLINT
#include <bits/stdc++.h>// NOLINT
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

char buf[1000033];
std::vector<std::string> v;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  gets(buf);
  int n = strlen(buf);
  bool ctf;
  f(i, 0, n) {
    if (buf[i] == ' ') continue;
    if (buf[i] == '<') {
      std::string s = "";
      if (buf[i + 1] == '/') {
        ++i;
        ctf = 1;
      } else ctf = 0;
      ++i;
      while (buf[i] != '>') {
        s += buf[i]; ++i;
      }
      while (i < n && buf[i + 1] != '<') ++i;
      if (ctf) {
        if (v.back() != s) {
          // std::cout << v.back() << "\n";
          // std::cout << s << "\n";
          puts("False");
          return 0;
        } else {
          v.pop_back();
        }
      } else {
        v.push_back(s);
      }
    }
  }
  puts("True");

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

