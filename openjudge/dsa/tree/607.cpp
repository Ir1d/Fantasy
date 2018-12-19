/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-12-19 23:16:49
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
  int s;
  node *ls, *rs;
} pool[MAXN * 23], *tail, *root[MAXN];
inline node* newnode() {
  return tail++;
}
node* build(int ll, int rr) {
  if (ll == rr) {
    node *ans = newnode();
    ans->ls = ans->rs = NULL;
    return ans;
  }
    node *ans = newnode();
    int md = ll + (rr - ll >> 1);
    ans->ls = build(ll, md);
    ans->rs = build(md + 1, rr);
    return ans;
}
node *ins(node *root, int l, int r, int x) {
  if (l == r) {
    node *s = newnode();
    s->s = root->s + 1;
    return s;
  }
  int md = l + (r - l >> 1);
  node *s = newnode();
  s->s = root->s + 1;
  s->ls = root->ls; s->rs = root->rs;
  if (x <= md) {
    s->ls = ins(root->ls, l, md, x);
  } else {
    s->rs = ins(root->rs, md + 1, r, x);
  }
  return s;
}
int get(node *x, node *y, int k, int l, int r) {
  if (l == r) return l;
  int md = l + (r - l >> 1);
  if (y->ls->s - x->ls->s >= k) return get(x->ls, y->ls, k, l, md);
  return get(x->rs, y->rs, k - (y->ls->s - x->ls->s), md + 1, r);
}
int n, m;
int a[MAXN], b[MAXN];
int l, r, k;
std::vector<int> V;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d%d", &n, &m);
  tail = pool;
  g(i, 1, n) {
    scanf("%d", a + i); V.push_back(a[i]);
  }
  std::sort(V.begin(), V.end());
  g(i, 1, n) {
    b[i] = std::lower_bound(V.begin(), V.end(), a[i]) - V.begin() + 1;
  }
  root[0] = build(1, n);
  g(i, 1, n) root[i] = ins(root[i - 1], 1, n, b[i]);
  while (m--) {
    scanf("%d%d%d", &l, &r, &k);
    printf("%d\n", V[get(root[l - 1], root[r], k, 1, n) - 1]);
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

