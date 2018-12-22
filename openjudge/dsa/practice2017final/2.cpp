/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-12-22 13:08:43
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

const int MOD = 1e9 + 7;
int n;
char s[6][2033];
int h[6][2033];
int len[6];
int mn;
int power[2033];
inline int getHash(int idx, int ll, int rr) {
  // printf("%d: %d, %d: %d %d %d\n", idx, ll, rr, h[idx][rr], h[idx][ll - 1], power[rr - ll + 1]);
  return ((h[idx][rr] - (LL)h[idx][ll - 1] * (LL)power[rr - ll + 1] % MOD) % MOD + MOD) % MOD;
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &n);
  power[0] = 1;
  f(i, 1, 2033) power[i] = (LL)power[i - 1] * 31 % MOD;
  f(i, 0, n) {
    scanf("%s", s[i] + 1);
    len[i] = strlen(s[i] + 1);
    // h[i][0] = s[i][0] - 'a';/
    g(j, 1, len[i]) {
      h[i][j] = (h[i][j - 1] * 31 + s[i][j] - 'a' + 1) % MOD;
    }
    // printf("%d: ", i); g(j, 0, len[i]) printf("%d ", h[i][j]); puts("");
    if (len[i] < len[mn]) mn = i;
  }
  // printf("%d\n", len[mn]);
  int cur, rr, num;
  // printf("%d: %d, %d: %d\n", 0, 2, 3, getHash(0, 2, 3));
  // printf("%d: %d, %d: %d\n", 1, 1, 2, getHash(1, 1, 2));
  // printf("%d: %d, %d: %d\n", 2, 3, 4, getHash(2, 3, 4));
  gd(l, len[mn], 1) {
    g(ll, 1, len[mn] - l + 1) {
      rr = ll + l - 1;
      // s[mn][ll .. rr]
      num = 1;
      cur = getHash(mn, ll, rr);
      // printf("cur:: %d: %d, %d: %d\n", mn, ll, rr, cur);
      f(i, 0, n) if (i != mn) {
        g(j, 1, len[i] - l + 1) {
          if (getHash(i, j, j + l - 1) == cur) {
            ++num;
            break;
          }
        }
      }
      if (num == n) {
        printf("%d\n", l);
        // printf("%d: %d %d\n", mn, ll, rr);
        return 0;
      }
    }
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

