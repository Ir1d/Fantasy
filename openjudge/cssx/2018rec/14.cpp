/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-24 15:23:02
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
int n;
char s[12][23];
int dis[23][23];
int len[12];
int c(int a, int b) {
  int res = std::min(len[a], len[b]);
  while (res) {
    if (strstr(s[b], s[a] + len[a] - res) == s[b]) break;
    --res;
  }
  return res;
  bool ctf = 0;
  gd(i, std::min(len[a], len[b]), 1) {
    ctf = 1;
    f(j, 0, i) if (s[a][len[a] - 1 - j] != s[b][j]) {
      ctf = 0;
      break;
    }
    if (ctf) return i;
  }
  return 0;
}
bool check(int a, int b) {
  // b in a
  bool cc = 0;
  f(i, 0, len[a]) if (s[a][i] == s[b][0] && i + len[b] <= len[a]) {
    cc = 1;
    f(j, 0, len[b]) {
      if (s[a][i + j] != s[b][j]) {
        cc = 0; break;
      }
    }
    if (cc) return 1;
  }
  return 0;
}
int r[12];
int dp[1 << 9][12];
int solve(int st, int x) {
  // st is used strings
  // x is the last one of them
  int &res = dp[st][x];
  if (res) return res;
  res = oo;
  f(j, 0, n) {
    if (x != j && (st & (1 << j))) {
      res = std::min(res, solve(st ^ (1 << j), j) + len[x] - dis[j][x]);
    }
  }
  return res;
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &T);
  bool cc = 0;
  while (T--) {
    scanf("%d", &n);
    memset(dis, 0, sizeof dis);
    for (int i = 0; i < n; ++i) {
      scanf("%s", s[i]);
      cc = 0;
      len[i] = strlen(s[i]);
      f(j, 0, i) if (check(j, i)) {
        // puts("????");
        cc = 1; break;
      }
      if (cc) {
        --i; --n;
        continue;
      }
      f(j, 0, i) {
        dis[i][j] = c(i, j);
        dis[j][i] = c(j, i);
      }
    }
    // printf("%d\n", n);
    // f(i, 0, n) {
    //   f(j, 0, n) printf("%d ", dis[i][j]);
    //   puts("");
    // }
    f(i, 0, n) r[i] = i;
    f(i, 0, n) dis[i][i] = len[i];
    int ans = 0, tee;
    f(i, 0, n) ans += len[i];
    memset(dp, 0, sizeof dp);
    f(i, 0, n) dp[0][i] = len[i];
    f(i, 0, n) {
      ans = std::min(solve((1 << n) - (1 << i) - 1, i), ans);
    }
    // do {
    //   tee = len[r[0]];
    //   f(i, 1, n) {
    //     // tee -= len[r[i - 1]];
    //     tee -= dis[r[i - 1]][r[i]];
    //     tee += len[r[i]];
    //   }
    //   if (tee < ans) ans = tee;
    // } while (std::next_permutation(r, r + n));
    printf("%d\n", ans);
  }


#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
