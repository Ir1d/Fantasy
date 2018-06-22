/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-22 15:09:22
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

int a, b, c;
typedef std::pair<int, int> PII;
PII pre[233][233];
const char* str[] = {"FILL(1)", "FILL(2)",
"DROP(1)", "DROP(2)", "POUR(1,2)", "POUR(2,1)"};
int res[233][233];
int dis[233][233];
void print(int x, int y) {
  if (!x && !y) return;
  PII tee = pre[x][y];
  print(tee.first, tee.second);
  puts(str[res[x][y]]);
}
std::queue<PII> Q;
PII tee;
int cnt = 0;
void upd(int x, int y) {
  ++cnt;
  if (res[x][y] != -1) return;
  pre[x][y] = tee;
  res[x][y] = cnt - 1;
  dis[x][y] = dis[tee.first][tee.second] + 1;
  Q.push(PII(x, y));
}
void solve() {
  memset(res, -1, sizeof res);
  res[0][0] = dis[0][0] = 0;
  while (!Q.empty()) Q.pop();
  Q.push(PII(0, 0));
  while (!Q.empty()) {
    tee = Q.front(); Q.pop();
    if (tee.first == c || tee.second == c) {
      printf("%d\n", dis[tee.first][tee.second]);
      print(tee.first, tee.second);
      return;
    }
    cnt = 0;
    upd(a, tee.second);
    upd(tee.first, b);
    upd(0, tee.second);
    upd(tee.first, 0);
    upd(tee.first - std::min(b - tee.second, tee.first),
        tee.second + std::min(b - tee.second, tee.first));
    upd(tee.first + std::min(a - tee.first, tee.second),
        tee.second - std::min(a - tee.first, tee.second));
  }
  puts("impossible");
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d%d%d", &a, &b, &c);
  solve();

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

