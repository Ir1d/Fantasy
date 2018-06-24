/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-24 00:55:30
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

LL n;
LL cnt[12];
int used[12];
char s[23], ti;
inline int hash() {
  int s = 0;
  g(i, 0, 9) if (used[i]) s |= 1 << i;
  return s;
}
inline int hash1() {
  int s = 0;
  g(i, 0, 9) s = s * 19 + cnt[i] - used[i];
  // returns;
  // g(i, 0, 9) if (used[i]) s |= 1 << i;
  // g(i, 0, 9) if (used[i] < cnt[i]) s |= 1 << i;
}
std::set<LL> S;
LL dp[20][1025];
LL dfs(int x, int t, LL w) {
  LL &res = dp[x][hash()];
  if (res) return res;
  if (t == 0) {
    res += 1;
    // S.insert(w);
    // return;
  }
  if (x == ti) return res;
  int st = 1;
  if (x) --st;
  g(i, st, 9) if (used[i] < cnt[i]) {
    used[i]++;
    res += dfs(x + 1, t - (used[i] == 1), w * 10LL + i);
    used[i]--;
  }
  return res;
}
LL fac[23];
LL solve(std::vector<LL> now, LL sum) {
  LL res = 0;
  LL resa = 0;
  if (now.size() == 10) {
    res = fac[sum];
    f(i, 1, now.size()) res /= fac[ now[i] ];
    resa = fac[ sum - 1 + now[0] ];
    resa /= fac[sum - 1];
    resa /= fac[now[0]];
    return res * resa;
  }
  LL len = now.size();
  now.push_back(0);
  if (cnt[len] == 0) return solve(now, sum);
  // for (int i = 1; i <= cnt[len]; ++i) {
  g(i, 1, cnt[len]) {
    now[len] = i;
    if (len == 0) res += solve(now, sum);
    else res += solve(now, sum + i);
  }
  return res;
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  fac[0] = 1;
  g(i, 1, 20) fac[i] = fac[i - 1] * i;
  scanf("%s", s);
  f(i, 0, strlen(s)) ++cnt[s[i] - '0'];
  std::vector<LL> now;
  printf(LLD"\n", solve(now, 0));

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}