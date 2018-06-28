/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-27 10:03:26
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

int r, c, n;
typedef std::pair<int, int> PII;
PII a[MAXN];
std::set<PII> S;
int dx, dy;
PII delta;
bool check(int x, int t) {
  if (a[x].first + dx * t < 1 || a[x].first + dx * t > r) return 0;
  if (a[x].second + dy * t < 1 || a[x].second + dy * t > c) return 0;
  return 1;
}
int res = 0;
void debug() {
// puts("???");

}
inline PII operator + (const PII &a, const PII &b) {
  return PII(a.first + b.first, a.second + b.second);
}
void calc(int idx) {
  // printf("``%d %d\n", dx, dy);
  int x = a[idx].first + dx;  
  // res += 2;
  int y = a[idx].second + dy;
  // int c = oo;
  // if (dx) c = (r - x) / dx;
  // if (dy) c = std::min(c, (c - y) / dy);
  // if (res < c + 2) res = c + 2;
  // if (c != oo) res += c;
  // res += std::min((r - x) / dx, (c - y) / dy);
  int cc = 2;
  PII cur = PII(a[idx].first + dx, a[idx].second + dy);
  while (cur.first >= 1 && cur.second >= 1 && cur.first <= r && cur.second <= c) {
    if (*std::lower_bound(a, a + n, cur) == cur) ++cc;
    // if (S.find(PII(x, y)) != S.end()) ++cc;
    else return;
    // x += dx; y += dy;
    cur = cur + delta;
  }
  if (cc > res) res = cc;
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d%d%d", &r, &c, &n);
  f(i, 0, n) {
    scanf("%d%d", &a[i].first, &a[i].second);
    S.insert(a[i]);
  }
  std::sort(a, a + n);
  // f(i, 0, n) printf("``%d %d\n", a[i].first, a[i].second);
  f(i, 0, n) f(j, i + 1, n) {
    dx = a[j].first - a[i].first;
    dy = a[j].second - a[i].second;
    delta = PII(dx, dy);
    // if (dx == 0 && dy == 1) debug();
    // if (dx == 0 && dy == 1) puts("??");
    if (!check(j, 1)) continue;
    if (check(i, -1)) continue;
    if (a[j].first + (res - 3) * dx > r) break;
    if (S.find(PII(a[i].first - dx, a[i].second - dy)) != S.end()) continue;
    if (S.find(PII(a[j].first + dx, a[j].second + dy)) == S.end()) continue;
    calc(j);
  }
  printf("%d\n", res);

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

