
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#define lowbit(x) (x & (-x))
#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 1
#define ll long long
#define pii pair<int, int>
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e3 + 111;

struct P {
  int x, y;
  bool operator<(const P &t) const {
    if (x == t.x) return y < t.y;
    return x < t.x;
  }
} p[MAXN], temp;

bool binary(int l, int r) {
  if (l > r) return 0;
  int m = (l + r) / 2;
  if (p[m].x == temp.x && p[m].y == temp.y)
    return 1;
  else if (temp < p[m])
    return binary(l, m - 1);
  else
    return binary(m + 1, r);
}

int main() {
#ifdef LOCAL
  freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
#endif
  int n;
  while (~scanf("%d", &n) && n) {
    for (int i = 0; i < n; ++i) scanf("%d%d", &p[i].x, &p[i].y);
    sort(p, p + n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        temp.x = p[i].x + (p[i].y - p[j].y);
        temp.y = p[i].y + (p[j].x - p[i].x);
        // cout << 1 << ':' << temp.x << ' ' << temp.y << '\n';
        if (!binary(0, n - 1)) continue;
        temp.x = p[j].x + (p[i].y - p[j].y);
        temp.y = p[j].y + (p[j].x - p[i].x);
        // cout << 2 << ':' << temp.x << ' ' << temp.y << '\n';
        if (!binary(0, n - 1)) continue;
        ++ans;
      }
    }
    printf("%d\n", ans / 2);
  }
  return 0;
}
