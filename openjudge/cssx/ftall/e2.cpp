/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-28 09:57:26
 * @copyright MIT
 */
#include <cmath>          // NOLINT
#include <algorithm>          // NOLINT
#include <queue>          // NOLINT
#include <map>          // NOLINT
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

char buf[12];
int a[12];
std::map<int, bool> M;
std::map<int, int> pre;
std::map<int, int> dir;
inline int hash() {
  int res = 0;
  f(i, 0, 9) res = res * 9 + a[i];
  return res;
}
inline void unhash(int x) {
  gd(i, 8, 0) {
    a[i] = x % 9;
    x /= 9;
  }
}
int magic = 54481005;
// 54481005
struct node {
  int v, p, d;
  // d for dir
  // 0, 1, 2, 3
  // u, r, d, l
} tee;
std::queue<node> Q;
node te;
const char ww[] = {'u', 'r', 'd', 'l'};
int cur;
void print(int x) {
  if (x != cur) {
    print(pre[x]);
    putchar(ww[ dir[x] ]);
  }
}
void bfs() {
  cur = hash();
  M[cur] = 1;
  tee.v = cur; tee.p = -1;
  pre[cur] = -1;
  Q.push(tee);
  int pos;
  while (!Q.empty()) {
    tee = Q.front(); Q.pop();
    unhash(tee.v);
    // f(i, 0, 9) printf("%d ", a[i]); puts("");
    // return;
    f(i, 0, 9) if (a[i] == 0) {
      pos = i; break;
    }
    te.p = tee.v;
    if (pos + 3 < 9) {
      std::swap(a[pos], a[pos + 3]);
      te.v = hash();
      bool &cc = M[te.v];
      if (cc == 0) {
        te.d = 2;
        cc = 1;
        dir[te.v] = te.d;
        pre[te.v] = tee.v;
        if (te.v == magic) {
          print(te.v);
          return;
        }
        Q.push(te);
      }
      std::swap(a[pos], a[pos + 3]);
    }
    if (pos - 3 >= 0) {
      std::swap(a[pos], a[pos - 3]);
      te.v = hash();
      bool &cc = M[te.v];
      if (cc == 0) {
        te.d = 0;
        cc = 1;
        dir[te.v] = te.d;
        pre[te.v] = tee.v;
        if (te.v == magic) {
          print(te.v);
          return;
        }
        Q.push(te);
      }
      std::swap(a[pos], a[pos - 3]);
    }
    if (pos > 0 && (pos / 3 == (pos - 1) / 3)) {
      std::swap(a[pos], a[pos - 1]);
      te.v = hash();
      bool &cc = M[te.v];
      if (cc == 0) {
        te.d = 3;
        cc = 1;
        dir[te.v] = te.d;
        pre[te.v] = tee.v;
        if (te.v == magic) {
          print(te.v);
          return;
        }
        Q.push(te);
      }
      std::swap(a[pos], a[pos - 1]);
    }
    if (pos < 8 && (pos / 3 == (pos + 1) / 3)) {
      std::swap(a[pos], a[pos + 1]);
      te.v = hash();
      bool &cc = M[te.v];
      if (cc == 0) {
        te.d = 1;
        cc = 1;
        dir[te.v] = te.d;
        pre[te.v] = tee.v;
        if (te.v == magic) {
          print(te.v);
          return;
        }
        Q.push(te);
      }
      std::swap(a[pos], a[pos + 1]);
    }
  }
  puts("unsolvable");
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif
  f(i, 0, 8) a[i] = i + 1;
  // std::swap(a[2], a[4]);
  // unhash(hash());
  // f(i, 0, 9) printf("%d ", a[i]); puts("");
  // return 0;
  // printf("%d\n", magic = hash());
  magic = hash();
  f(i, 0, 9) {
    scanf("%s", buf);
    if (buf[0] == 'x') a[i] = 0;
    else a[i] = buf[0] - '0';
  }
  int cnt = 0;
  f(i, 0, 9) {
    f(j, 0, i) if (a[i] && a[j] > a[i]) ++cnt;
  }
  // printf("%d\n", cnt);
  // return 0;
  if (cnt % 2 == 0) bfs();
  else
    puts("unsolvable");

#ifdef LOCAL
        fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
