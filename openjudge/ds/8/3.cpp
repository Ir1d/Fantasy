/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-12-06 23:32:52
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
int a[MAXN], b[MAXN], c[MAXN];
int n, m;
typedef std::pair<int, int> PII;
PII tee;
std::priority_queue<PII, std::vector<PII>, std::greater<PII> > Q;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &m, &n);
    f(i, 0, n) scanf("%d", b + i);
    std::sort(b, b + n);
    f(i, 1, m) {
      f(j, 0, n) {
        scanf("%d", a + j);
        Q.push(PII(b[0] + a[j], 0));
      }
      // f(j, 0, n) f(k, 0, n) Q.push(PII(b[j] + a[k], j));
      std::sort(a, a + n);
      f(j, 0, n) {
        tee = Q.top(); Q.pop();
        c[j] = tee.first;
        // printf("(%d %d) ", tee.first, tee.second);
        // if (tee.second + 1 < n)
          Q.push(PII(tee.first + b[tee.second + 1] - b[tee.second],
                     tee.second + 1));
      }
      // puts("");
      while (!Q.empty()) Q.pop();
      f(j, 0, n) b[j] = c[j];
      // std::sort(b, b + n);
    }
    printf("%d", b[0]); f(j, 1, n) printf(" %d", b[j]); puts("");
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

