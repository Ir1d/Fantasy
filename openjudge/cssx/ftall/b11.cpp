/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-25 17:25:16
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

int T;
int s;
std::vector<int> res;
bool ctf;
void dfs(double x, int pre, int sum) {
  if (fabs(x) <= 1e-6 && sum == 0) {
    ctf = 1; return;
  }
  g(i, pre, sum) {
    if (x < 1. / i - 1e-6) continue;
    res.push_back(i);
    dfs(x - 1. / i, i, sum - i);
    if (!ctf) {
      res.pop_back();
    } else break;
  }
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &T);
  while (T--) {
    scanf("%d", &s);
    res.clear();
    ctf = 0;
    dfs(1, 1, s);
    if (res.size() == 0) puts("-1");
    else {
      printf("%d\n", res.size());
      f(i, 0, res.size()) printf("%d ", res[i]);
      puts("");
    }
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

