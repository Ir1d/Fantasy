/**
 * @author Ir1d (sirius.caffrey@gmail.com)
 * @date    2018-01-12 20:31:47
 * @copyright MIT
 */
#include <cstdio>// NOLINT
#include <cstring>// NOLINT
#include <iostream>// NOLINT
#include <map>// NOLINT
#include <string>// NOLINT
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

char str[233];
char s1[233], s2[233];
std::map<std::string, std::string> M;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (gets(str)) {
    if (str[0] == '\0') continue;
    int pos = strchr(str, ' ') - str;
    // printf("%d\n", pos);
    // return 0;
    if (pos < 0) {
      if (M.find(std::string(str)) == M.end()) puts("eh");
      else printf("%s\n", M[std::string(str)].c_str());
      continue;
    }
    strcpy(s1, str);
    s1[pos] = '\0';
    strcpy(s2, str + pos + 1);
    // printf("%s:%s", s1, s2);
    M[std::string(s2)] = std::string(s1);
    // printf("```%s\n", str);
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
