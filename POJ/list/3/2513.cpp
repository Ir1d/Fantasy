/**
 * @author Ir1d (sirius.caffrey@gmail.com)
 * @date    2018-01-12 21:12:17
 * @copyright MIT
 */
#include <cstdio>// NOLINT
#include <cstring>// NOLINT
#include <string>// NOLINT
#include <map>// NOLINT
// #include <bits/stdc++.h>// NOLINT
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


int n, m;
struct node {
  int cnt;
  node* ch[27];
  inline node() {
    cnt = -1; memset(ch, 0, sizeof ch);
  }
} *root;
int get(char *s) {
  node *tee = root;
  f(j, 0, strlen(s)) {
    if (tee->ch[ s[j] - 'a' ] == NULL) {
      return -1;
      // tee->ch[ s[j] - 'a' ] = new node();
    }
    tee = tee->ch[ s[j] - 'a' ];
  }
  return tee->cnt;
}
void insert(char* s, int v) {
  node *tee = root;
  f(j, 0, strlen(s)) {
    if (tee->ch[ s[j] - 'a' ] == NULL) {
      tee->ch[ s[j] - 'a' ] = new node();
    }
    tee = tee->ch[ s[j] - 'a' ];
  }
  tee->cnt = v;
  // ++tee->cnt;
}
char s1[23], s2[23];
int deg[500005], fa[500005], cnt = 1;
inline int find(int x) {
  // if (fa[x] == -1) return x;
  if (fa[x] == x) return fa[x];
  return fa[x] = find(fa[x]);
}
inline int insert(char *s) {
  int tee = get(s);
  if (~tee) return tee;
  insert(s, cnt++);
  fa[cnt - 1] = cnt - 1;
  return cnt - 1;
}
bool ok() {
  int num = 0;
  f(i, 2, cnt) if (find(i) != find(1)) return 0;
  f(i, 1, cnt) if (deg[i] & 1) ++num;
  // printf("%d\n", num);
  // return num <= 2;
  return num == 0 || num == 2;
}
// std::map<std::string, int> M;
// std::string a, b;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  root = new node();
  int x, y;
  // memset(fa, -1, sizeof fa);
  while (~scanf("%s%s", s1, s2)) {
    // a = std::string(s1);
    // b = std::string(s2);
    // if (M.find(a) == M.end()) M[a] = x = cnt++;
    // else x = M[a];
    // if (M.find(b) == M.end()) M[b] = y = cnt++;
    // else y = M[b];
    x = insert(s1), y = insert(s2);
    ++deg[x], ++deg[y];
    if (find(x) != find(y)) fa[find(x)] = find(y);
  }
  if (ok()) puts("Possible");
  else puts("Impossible");


#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
