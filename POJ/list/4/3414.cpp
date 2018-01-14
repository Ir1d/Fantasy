/**
 * @author Ir1d (sirius.caffrey@gmail.com)
 * @date    2018-01-14 09:03:26
 * @copyright MIT
 */
#include <cstdio>// NOLINT
#include <cstring>// NOLINT
#include <queue>// NOLINT
#include <string>// NOLINT
#include <iostream>// NOLINT
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

struct node {
  int a, b, ti;
  inline node(int a = 0, int b = 0, int t = 0):a(a), b(b), ti(t) {}
} pre[205][205];
int vis[205][205];
std::queue<node> Q;
std::string s[205];
int a, b, c;
void printAns(node ans) {
  std::cout << ans.ti << "\n";
  int k = 0;
  for (;;) {
    if (ans.a == 0 && ans.b == 0) break;
    node p = pre[ans.a][ans.b];
    // printf("%d %d\n", ans.a, ans.b);
    if (ans.b == p.b) {
      if (ans.a == 0) s[k++] = "DROP(1)";
      else s[k++] = "FILL(1)";
    } else if (ans.a == p.a) {
      if (ans.b == 0) s[k++] = "DROP(2)";
      else s[k++] = "FILL(2)";
    } else if ((ans.a == 0 && ans.b != p.b) || (ans.b == b && ans.a != p.a)) {
      s[k++] = "POUR(1,2)";
    } else {
      s[k++] = "POUR(2,1)";
    }
    ans.a = p.a;
    ans.b = p.b;
  }
  gd(i, k - 1, 0) std::cout << s[i] << "\n";
}
node tee;
void solve() {
    node zero(0, 0, 0);
  Q.push(zero);
  vis[0][0] = 1;
  while (!Q.empty()) {
    tee = Q.front(); Q.pop();
    if (tee.a == c || tee.b == c) {
      printAns(tee);
      return;
    }
    if (tee.a && !vis[0][tee.b]) {
      Q.push(node(0, tee.b, tee.ti + 1));
      vis[0][tee.b] = 1;
      pre[0][tee.b] = tee;
    }
    if (tee.b && !vis[tee.a][0]) {
      Q.push(node(tee.a, 0, tee.ti + 1));
      vis[tee.a][0] = 1;
      pre[tee.a][0] = tee;
    }
    if (tee.a != a && !vis[a][tee.b]) {
      Q.push(node(a, tee.b, tee.ti + 1));
      vis[a][tee.b] = 1;
      pre[a][tee.b] = tee;
    }
    if (tee.b != b && !vis[tee.a][b]) {
      Q.push(node(tee.a, b, tee.ti + 1));
      vis[tee.a][b] = 1;
      pre[tee.a][b] = tee;
    }
    if (tee.a && tee.b < b) {
      int delta = b - tee.b;
      if (tee.a > delta && !vis[tee.a - delta][b]) {
        Q.push(node(tee.a - delta, b, tee.ti + 1));
        vis[tee.a - delta][b] = 1;
        pre[tee.a - delta][b] = tee;
      } else if (!vis[0][tee.a + tee.b]) {
        Q.push(node(0, tee.a + tee.b, tee.ti + 1));
        vis[0][tee.a + tee.b] = 1;
        pre[0][tee.a + tee.b] = tee;
      }
    }
    if (tee.b && tee.a < a) {
      int delta = a - tee.a;
      if (tee.b > delta && !vis[a][tee.b - delta]) {
        Q.push(node(a, tee.b - delta, tee.ti + 1));
        vis[a][tee.b - delta] = 1;
        pre[a][tee.b - delta] = tee;
      } else if (!vis[tee.a + tee.b][0]) {
        Q.push(node(tee.a + tee.b, 0, tee.ti + 1));
        vis[tee.a + tee.b][0] = 1;
        pre[tee.a + tee.b][0] = tee;
      }
    }
  }
  std::cout << "impossible\n";
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  while (std::cin >> a >> b >> c) {
    while (!Q.empty()) Q.pop();
    memset(vis, 0, sizeof vis);
    memset(pre, 0, sizeof pre);
    solve();
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
