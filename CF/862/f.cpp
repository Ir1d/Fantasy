/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2017-09-30 22:20:24
 * @license Star And Thank Author
 */

#include <bits/stdc++.h>// NOLINT
#include <cstdio>// NOLINT
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

typedef std::pair<int, int> PII;
std::string a[MAXN];
int lcp[MAXN], n, q;
struct node {
  int ans;
  std::vector<PII> L, R;
} T[262144];
node merge(const node& L, const node& R, int m) {
  node res;
  res.ans = std::max(L.ans, R.ans);
  res.L = L.L;
  for (auto i = L.R.end() - 1, j = R.L.end() - 1; i >= L.R.begin(); --i) {
    while (j > R.L.begin() && j->first < i->first) --j;
    if (j->first < i->first) break;
    res.ans = std::max(res.ans, (j->second - i->second + 1) * std::min(lcp[m], i->first));
  }
  for (auto i = R.L.end() - 1, j = L.R.end() - 1; i >= R.L.begin(); --i) {
    while (j > L.R.begin() && j->first < i->first) --j;
    if (j->first < i->first) break;
    res.ans = std::max(res.ans, (i->second - j->second + 1) * std::min(lcp[m], i->first));
  }
  for (auto i: R.L) {
    i.first = std::min(i.first, lcp[m]);
    if (i.first >= res.L.back().first) res.L.back().second = i.second;
    else res.L.push_back(i);
  }
  res.R = R.R;
  for (auto i: L.R) {
    i.first = std::min(i.first, lcp[m]);
    if (i.first >= res.R.back().first) res.R.back().second = i.second;
    else res.R.push_back(i);
  }
  return res;
}
void build(int p, int l, int r) {
  if (l == r) {
    T[p].ans = a[l].length();
    T[p].L = T[p].R = {{a[l].length(), l}};
    return;
  }
  int m = l + r >> 1;
  build(p << 1, l, m);
  build(p << 1|1, m + 1, r);
  T[p] = merge(T[p << 1], T[p << 1|1], m);
}
node G(int p, int l, int r, int L, int R) {
  if (L <= l && r <= R) return T[p];
  int m = l + r >> 1;
  if (R <= m) return G(p << 1, l, m, L, R);
  if (L > m) return G(p << 1|1, m + 1, r, L, R);
  return merge(G(p << 1, l, m, L, R), G(p << 1|1, m + 1, r, L, R), m);
}
void update(int p, int l, int r, int x) {
  if (l == r) {
    T[p].ans = a[l].length();
    T[p].L = T[p].R = {{a[l].length(), l}};
    return;
  }
  int m = l + r >> 1;
  if (x <= m) update(p << 1, l, m, x);
  if (x >= m) update(p << 1|1, m + 1, r, x);
  T[p] = merge(T[p << 1], T[p << 1|1], m);
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d%d", &n, &q);
  g(i, 1, n) std::cin >> a[i];
  f(i, 1, n) while (a[i][lcp[i]] == a[i + 1][lcp[i]]) ++lcp[i];
  build(1, 1, n);
  while (q--) {
    int ty;
    scanf("%d", &ty);
    if (ty == 1) {
      int l, r;
      scanf("%d%d", &l, &r);
      printf("%d\n", G(1, 1, n, l, r).ans);
    } else {
      int x;
      scanf("%d", &x);
      std::cin >> a[x];
      if (x > 1) {
        lcp[x - 1] = 0;
        while (a[x - 1][lcp[x - 1]] == a[x][lcp[x - 1]]) ++lcp[x - 1];
        update(1, 1, n, x - 1);
      }
      if (x < n) {
        lcp[x] = 0;
        while (a[x][lcp[x]] == a[x + 1][lcp[x]]) ++lcp[x];
        update(1, 1, n, x);
      }
      update(1, 1, n, x);
    }
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
