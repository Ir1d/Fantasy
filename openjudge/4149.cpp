/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2018-06-06 23:50:56
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

int T;
int dp[33000];
int pre[33000];
int n;
int ti;
struct node {
  char buf[60];
  int d, c;
  inline void read() {
    scanf("%s%d%d", buf, &d, &c);
    ti += c;
  }
} a[100];
void print(int ti, int state) {
  if (ti <= 0) return;
  int s = state ^ pre[state];
  // printf("%d ", s)
  int c = 0;
  while (s) {
    s >>= 1; ++c;
  }
  printf("%s\n", a[c - 1].buf);
  print(ti - a[c - 1].c, pre[state]);
}
typedef std::pair<int, int> PII;
std::map<PII, int> M;
int solve(int sum, int state) {
  if (sum == 0) return 0;
  int cur, &mn = M[PII(sum, state)], pos;
  if (mn) return mn;
  mn = oo;
  f(i, 0, n) if (a[i].c <= sum && (state & (1 << i))) {
    cur = (ti - sum + a[i].c <= a[i].d) ? 0 : (ti - sum + a[i].c - a[i].d);
    cur += solve(sum - a[i].c, state ^ (1 << i));
    if (mn == oo || mn > cur) {
      mn = cur;
      pos = i;
    }
  }
  pre[state] = state ^ (1 << pos);
  return mn;
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &T);
  while (T--) {
    M.clear();
    scanf("%d", &n);
    ti = 0;
    f(i, 0, n) a[i].read();
    // memset(dp, 0x1f, sizeof dp);
    // printf("%d\n", 2 * dp[0][0]);
    // f(s, 0, 1 << n)
    dp[0] = 0;
    int tee;
    printf("%d\n", solve(ti, (1 << n) - 1));
    print(ti, (1 << n) - 1);
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
