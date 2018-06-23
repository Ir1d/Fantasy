/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-22 20:11:47
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

char s[12];
int dis[100033][4][4];
struct node {
  int a[5];
  int c1, c2;
  inline int num() {
    int x = 0;
    f(i, 0, 5) x = x * 10 + a[i];
    return x;
  }
  inline bool can(int xx) {
    return dis[num()][c1][c2] == -1 || dis[num()][c1][c2] > xx;
  }
  inline void upd(int x) {
    dis[num()][c1][c2] = x;
  }
  inline bool check() {
    // f(i, 0, 5) printf("%d", a[i]);
    // puts("");
    // f(i, 0, 5) if (a[i] != s[i] - '0') return 0;
    // return 1;
    return 0;
  }
  inline int val() {
    return dis[num()][c1][c2];
  }
} te, tee;
std::queue<node> Q;
void solve() {
  int rr;
  memset(dis, -1, sizeof dis);
  while (!Q.empty()) Q.pop();
  f(i, 0, 5) {
    tee.a[i] = i + 1;
  }
  tee.upd(0);
  tee.c1 = 3; tee.c2 = 2;
  Q.push(tee);
  while (!Q.empty()) {
    tee = Q.front(); Q.pop();
    // printf("``%d\n", tee.num());
    rr = tee.val();
    if (rr == -1) rr = 0;
    // if (tee.check()) {
    //   printf("%d\n", rr + 1);
    //   return;
    // }
    f(i, 0, 4) {
      std::swap(tee.a[i], tee.a[i + 1]);
      if (tee.can(rr + 1)) {
        tee.upd(rr + 1);
        if (tee.check()) {
          printf("%d\n", rr + 1);
          return;
        }
        Q.push(tee);
      }
      std::swap(tee.a[i], tee.a[i + 1]);
    }
    if (tee.c1--) f(i, 0, 5) {
      tee.a[i] = (tee.a[i] + 1) % 10;
      if (tee.can(rr + 1)) {
        tee.upd(rr + 1);
        if (tee.check()) {
          printf("%d\n", rr + 1);
          return;
        }
        Q.push(tee);
      }
      tee.a[i] = (tee.a[i] + 9) % 10;
    }
    ++tee.c1;
    if (tee.c2--) f(i, 0, 5) {
      int x = tee.a[i];
      tee.a[i] = (tee.a[i] * 2) % 10;
      if (tee.can(rr + 1)) {
        tee.upd(rr + 1);
        if (tee.check()) {
          printf("%d\n", rr + 1);
          return;
        }
        Q.push(tee);
      }
      tee.a[i] = x;
    }
    ++tee.c2;
  }
  // puts("-1");
}
int getAns() {
  int x = 0;
  f(i, 0, 5) x = x * 10 + s[i] - '0';
  int c = -1;
  g(i, 0, 3) g(j, 0, 2) if (c == -1 || (dis[x][i][j] != -1 && c > dis[x][i][j])) c = dis[x][i][j];
  return c;
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  // while (~scanf("%s", s)) solve();
  solve();
  while (~scanf("%s", s)) printf("%d\n", getAns());

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

