/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-12-20 21:12:15
 * @copyright MIT
 */
#include <bits/stdc++.h>  // NOLINT
#include <cmath>          // NOLINT
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

int n;
int a[MAXN];
int partition(int ll, int rr) {
  int m = ll + (rr - ll >> 1);
  int p = ll, q = rr;
  int pivot = a[ll];
  while (p < q) {
    while (p < q && a[q] >= pivot) --q;
    std::swap(a[p], a[q]);
    while (p < q && a[p] <= pivot) ++p;
    std::swap(a[p], a[q]);
  }
  return p;
}
int find(int ll, int rr, int k) {
  if (ll == rr) {
    return a[ll];
  }
  int pid = partition(ll, rr);
  int num = pid - ll + 1;
  if (num == k) return a[ll + k - 1];
  if (num > k) return find(ll, pid - 1, k);
  return find(pid + 1, rr, k - num);
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d", &n);
  g(i, 1, n) scanf("%d", a + i);
  printf("%d\n", find(1, n, (n + 1) / 2));

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
