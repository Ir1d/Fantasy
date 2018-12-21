/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-11-23 14:36:49
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

struct node {
  node *ls, *rs;
  int v;
  inline node(int v):v(v), ls(NULL), rs(NULL) {}
  void insert(int x) {
    if (x < v) {
      if (!ls) ls = new node(x);
      else ls->insert(x);
    } else if (x > v) {
      if (!rs) rs = new node(x);
      else rs->insert(x);
    }
  }
};
std::queue<node *> Q;
bool ctf;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  int x;
  scanf("%d", &x);
  node *root = new node(x);
  while (~scanf("%d", &x)) {
    root->insert(x);
  }
  Q.push(root);
  node *u;
  while (!Q.empty()) {
    u = Q.front();
    Q.pop();
    if (u->ls) Q.push(u->ls);
    if (u->rs) Q.push(u->rs);
    if (ctf) putchar(' ');
    printf("%d", u->v);
    ctf = 1;
  }
#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

