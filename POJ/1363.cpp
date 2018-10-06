/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-09-30 22:11:07
 * @copyright MIT
 */
#include <cstdio>// NOLINT
#include <cstring>// NOLINT
#include <vector>// NOLINT
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
bool function(std::vector<int> & seq) {
  // if legal return 1; else return 0;
  std::vector<int> v;
  int n = seq.size();
  int cur = 1;
  for (int i = 0; i < n; ++i) {
    if (v.size() && v.back() == seq[i]) {
      v.pop_back();
    } else {
      while (cur < seq[i]) {
        v.push_back(cur);
        ++cur;
      }
      if (cur > seq[i]) {
        return 0;
      }
      ++cur;
    }
    // for (auto x:v) printf("%d ", x); puts("");
  }
  return 1;
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

// std::vector<int> a = {4, 3, 2, 1};
// std::vector<int> a = {3, 1, 2, 4};
// std::vector<int> a = {3, 4, 2, 1};
// printf("%d\n", function(a));

  std::vector<int> v;
  int x, n;
  while (~scanf("%d", &n) && n) {
    while (~scanf("%d", &x) && x) {
      v.clear();
      v.push_back(x);
      f(i, 1, n) {
        scanf("%d", &x);
        v.push_back(x);
      }
      if (function(v)) puts("Yes");
      else puts("No");
    }
    puts("");
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

