/**
 * @author Ir1d (sirius.caffrey@gmail.com)
 * @date    2018-01-14 07:04:45
 * @copyright MIT
 */
#include <cstdio>// NOLINT
#include <cstring>// NOLINT
#include <string>// NOLINT
#include <iostream>// NOLINT
#include <map>// NOLINT
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

int n, ans, cnt;
std::string c;
std::map<std::string, int> M;
bool vis[5005][5005], ctf;
void dfs(std::string a, std::string b, int dep) {
  if (M.find(a) == M.end()) M[a] = cnt++;
  if (M.find(b) == M.end()) M[b] = cnt++;
  if (vis[M[a]][M[b]]) return;
  vis[M[a]][M[b]] = 1;
  std::string s;
  f(i, 0, n) {
    s.push_back(b[i]);
    s.push_back(a[i]);
  }
  if (s == c) {
    if (dep < ans) ans = dep;
    ctf = 1;
    return;
  }
  a.clear();
  b.clear();
  f(i, 0 ,n) a.push_back(s[i]);
  f(i, n, 2 * n) b.push_back(s[i]);
  dfs(a, b, dep + 1);
}
int T;
std::string a, b;
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  // scanf("%d", &T);
  std::cin >> T;
  g(cas, 1, T) {
    std::cin >> n >> a >> b >> c;
    ans = ~0u >> 2; cnt = 0;
    memset(vis, 0, sizeof vis);
    ctf = 0;
    M.clear();
    dfs(a, b, 1);
    std::cout << cas << " ";
    if (ctf) std::cout << ans << "\n";
    else std::cout << "-1\n";
  }

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
