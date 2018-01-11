/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2017-09-30 17:59:33
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

char s[1023];
int ans, pos0, pos1, n;
void send() {
  printf("? %s\n", s);
  fflush(stdout);
  scanf("%d", &ans);
  ans = n - ans;
}
int mx;
int ll, rr, md;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &n);
  f(i, 0, n) s[i] ='1';
  send();
  mx = ans;
  s[0] = '0';
  send();
  if (mx > ans) pos1 = 1;
  else pos0 = 1;
  s[0] = '1';
  ll = 1; rr = n;
  while (ll != rr) {
    md = ll + (rr - ll >> 1);
    g(i, 1, md) s[i] = '0';
    send();
    if ((mx - ans) * (pos1?1:-1) == md) ll = md + 1;
    else rr = md;
    g(i, 1, md) s[i] = '1';
  }
  if (!pos0) pos0 = ll + 1;
  else pos1 = ll + 1;
  printf("! %d %d", pos0, pos1);
  fflush(stdout);

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
