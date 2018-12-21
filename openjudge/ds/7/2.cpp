/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-12-01 10:00:55
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

int n;
std::string w[MAXN], a, b;
std::map<std::string, int> M;
int m;
int dis[233][233];
int pre[233][233];
int ww;
print() {
  
}
void upd() {
  int aa = M[a], bb = M[b];
  // pre[aa][bb] = aa;
  // pre[bb][aa] = bb;
  dis[aa][bb] = ww;
  dis[bb][aa] = ww;
}
void print(int s, int t) {
  // if (pre[])
  int ss = pre[s][t];
  if (s == t) {
    std::cout << w[s];
    return;
  }
  // if (ss == t) {
  //   std::cout << w[ss];
  //   return;
  // }
  // if (ss == 0) {
  //   std::cout << w[s] << "->(" << dis[s][t] << ")"
  //             << "->";
  //   return;
  // } 
  print(s, ss);
  // print(ss, t);
  std::cout << "->(" << dis[ss][t] << ")->" << w[t];

}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  std::cin >> n;
  memset(dis, 0x1f, sizeof dis);
  g(i, 0, n) dis[i][i] = 0;
  f(i, 0, n) f(j, 0, n) pre[i][j] = i;
  f(i, 0, n) {
    std::cin >> w[i];
    M[w[i]] = i;
  }
  std::cin >> m;
  // scanf("%d", &m);
  f(i, 0, m) {
    std::cin >> a >> b >> ww;
    upd();
  }
  f(k, 0, n) {
    f(i, 0, n) f(j, 0, n) {
      if (dis[i][j] > dis[i][k] + dis[k][j]) {
        pre[i][j] = k;
        dis[i][j] = dis[i][k] + dis[k][j];
      }
    }
  }
  // f(i, 0, n) {
  //   f(j, 0, n) printf("%d ", pre[i][j]);
  //   puts("");
  // }
  std::cin >> m;
  f(i, 0, m) {
    std::cin >> a >> b;
    int aa = M[a], bb = M[b];
    // if (aa == bb) {
    //   std::cout << a << '\n';
    // } else {
      print(aa, bb);
      // std::cout << b << '\n';
      std::cout << '\n';
    // }
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

