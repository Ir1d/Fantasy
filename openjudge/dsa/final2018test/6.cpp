/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-12-12 10:34:38
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

int n;
int x, y, z;
std::map<int, int> M;
std::priority_queue<int> Q;
std::priority_queue<int, std::vector<int>, std::greater<int> > q;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  // scanf("%d", &n);
  // f(i, 0, n) {
  for(;;) {
    scanf("%d", &x);
    if (x == 0) break;
    if (x == 1) {
      scanf("%d%d", &y, &z);
      M[z] = y;
      Q.push(z);
      q.push(z);
    } else if (x == 2) {
      if (Q.empty()) {
        puts("0");
        continue;
      }
      int c = Q.top(); Q.pop();
      while (M.find(c) == M.end() && !Q.empty()) {
        c = Q.top(); Q.pop();
      }
      if (Q.empty()) {
        puts("0");
        continue;
      }
      printf("%d\n", M[c]);
      M.erase(c);
    } else {
      if (q.empty()) {
        puts("0");
        continue;
      }
      int c = q.top();
      q.pop();
      while (M.find(c) == M.end() && !q.empty()) {
        c = q.top();
        q.pop();
      }
      if (q.empty()) {
        puts("0");
        continue;
      }

      printf("%d\n", M[c]);
      M.erase(c);
    }
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

