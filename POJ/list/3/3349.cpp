/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2017-10-30 19:33:31
 * @license Star And Thank Author
 */

// #include <bits/stdc++.h>// NOLINT
#include <cstdio>// NOLINT
#include <algorithm>// NOLINT
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

int n;
int b[12], t;
struct node {
  int a[6];
  inline void print() {
    f(i, 0, 6) printf("%d ", a[i]);
    puts("");
  }
  inline bool operator < (const node& T) const {
    f(i, 0, 6) if (a[i] != T.a[i]) return a[i] < T.a[i];
    return 0;
  }
  inline bool operator == (const node& T) const {
    f(i, 0, 6) if (a[i] != T.a[i]) return 0;
    return 1;
  }
  void hash() {
    int cur;
    f(i, 0, 6) {
      f(j, 0, 6) {
        cur = (i + j) % 6;
        b[j] = a[cur];
      }
      f(j, 0, 6) {
        if (a[j] > b[j]) {
          f(k, 0, 6) a[k] = b[k];
          break;
        } else if (a[j] < b[j]) break;
      }
    }
    f(i, 0, 6) {
      f(j, 0, 6) {
        cur = (i - j + 6) % 6;
        b[j] = a[cur];
      }
      f(j, 0, 6) {
        if (a[j] > b[j]) {
          f(k, 0, 6) a[k] = b[k];
          break;
        } else if (a[j] < b[j]) break;
      }
    }
  }
} s[MAXN];
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &n);
  f(i, 0, n) {
    f(j, 0, 6) scanf("%d", &s[i].a[j]);
    std::sort(s[i].a, s[i].a + 6);
    // s[i].hash();
  }
  std::sort(s, s + n);
  f(i, 1, n) {
    if (s[i] == s[i - 1]) {
      puts("Twin snowflakes found.");
      return 0;
    }
  }
  puts("No two snowflakes are alike.");
  // f(i, 0, n) s[i].print();

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
