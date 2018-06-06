#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int n, k, p, m, ans;
int a[200010], b[200010], c[200010];

int main() {
  scanf("%d%d%d", &n, &k, &p);
  for (int i = 1; i <= n; i++) {
    int k, q, res = 0;
    scanf("%d%d", &k, &q);
    if (q <= p)  //找最近的消费≤p的咖啡店
      m = i;
    if (m >= a[k])
      res = b[k];  //更新位置，当前的客栈可以和上一次色调为k的客栈组合成一种方案
    a[k] = i;
    ans += res;
    b[k]++;
  }
  printf("%d", ans);

  return 0;
}