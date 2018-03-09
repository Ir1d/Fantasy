/**
 * @author Ir1d (sirius.caffrey@gmail.com)
 * @date    2018-03-09 16:52:37
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
int q;
const LL p[] = {1LL,2LL,4LL,8LL,16LL,32LL,64LL,128LL,256LL,512LL,1024LL,2048LL,4096LL,8192LL,16384LL,32768LL,65536LL,131072LL,262144LL,524288LL,1048576LL,2097152LL,4194304LL,8388608LL,16777216LL,33554432LL,67108864LL,134217728LL,268435456LL,536870912LL,1073741824LL,2147483648LL,4294967296LL,8589934592LL,17179869184LL,34359738368LL,68719476736LL,137438953472LL,274877906944LL,549755813888LL,1099511627776LL,2199023255552LL,4398046511104LL,8796093022208LL,17592186044416LL,35184372088832LL,70368744177664LL,140737488355328LL,281474976710656LL,562949953421312LL,1125899906842624LL,2251799813685248LL,4503599627370496LL,9007199254740992LL,18014398509481984LL,36028797018963968LL,72057594037927936LL,144115188075855872LL,288230376151711744LL,576460752303423488LL,1152921504606846976LL}; // 2 ** 60
LL num[233];
LL s, v;
LL cur;
LL get(LL s) {
  if (s & 1) return (s + 1LL) / 2LL;
  LL t = (n + 1LL) / 2LL, num = 0LL;

  if (n % 2 == 0) {
    num = n / 2LL;
    if (s == n) s = 1;
    else s = s / 2LL + 1LL;
  } else {
    num = n - (n + 1LL) / 2LL;
    s >>= 1;
  }
  // if (s != num) s = (s - 1LL) / 2LL + 1LL;
  // else s = ();
  while ((s & 1) && num > 1) {
    // printf("%d %d %d\n", t, num, s);
    t += (num) / 2;
    if (num & 1) {
      if (s == num) s = 1;
      else s = (s + 1LL) / 2LL + 1LL;
    } else s = (s + 1LL) / 2LL;
    num -= (num) / 2;
  }
  if (s & 1) return t + 1;
  return t + (s) / 2LL;
}
void solve() {
  f(i, 0, q) {
    scanf(LLD, &s); v = 0LL;
    printf(LLD"\n", get(s));
  }
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf(LLD"%d", &n, &q);
  // g(i, 1, n) {
  //   num[i] = (n + p[i - 1]) / p[i];
  // }
  // g(i, 1, n) printf(LLD" ", num[i]); puts("");
  // if (n & 1) {
    solve();
    return 0;
  // }
  f(i, 0, q) {
    scanf(LLD, &s); v = 0LL;
    g(j, 1, 60) {
      if (s % p[j] == p[j - 1]) {
        cur = (s + p[j - 1]) / p[j];
        v += cur;
        printf(LLD"\n", v);
        break;
      } else {
        v += num[j];
      }
    }
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
