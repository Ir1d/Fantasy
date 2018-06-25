/**
 * @author Ir1d(sirius.caffrey@gmail.com)
 * @date    2018-06-25 00:48:13
 * @copyright MIT
 * = = 没过
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

int n, k;
int map[5][55];
int pos[55];
int pos2[55];
struct node {
  int a, b, c;
};
std::vector<node> V;
typedef std::pair<int, int> PII;
std::queue<PII> Q;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
int vis[5][55];
PII pre[5][55];
int ti;
int curID;
void print(int x, int y) {
  if (x != -1 || y != -1) {
    print(pre[x][y].first, pre[x][y].second);
  }
  V.push_back((node){curID, x + 1, y + 1});
}
bool solve(int a, int b, int c, int d) {
  ++ti;
  // (a, b) -> (c, d)
  while (!Q.empty()) Q.pop();
  curID = map[a][b];
  Q.push(PII(a, b));
  PII tee;
  int nx, ny;
  pre[a][b] = PII(-1, -1);
  while (!Q.empty()) {
    tee = Q.front(); Q.pop();
    f(i, 0, 4) {
      nx = tee.first + dx[i]; ny = tee.second + dy[i];
      if (nx < 1 || nx > 2 || ny < 0 || ny >= n) continue;
      if (vis[nx][ny] == ti) continue;
      pre[nx][ny] = tee;
      if (nx == c && ny == d) {
        print(nx, ny);
        V.push_back((node){curID, (c == 1)?1:4, d + 1});
        return 1;
      }
      vis[nx][ny] = ti;
      Q.push(PII(nx, ny));
    }
  }
  return 0;
}
bool done[55];
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  scanf("%d%d", &n, &k);
  f(i, 0, 4) f(j, 0, n) scanf("%d", &map[i][j]);
  memset(pos, -1, sizeof pos);
  memset(pos2, -1, sizeof pos2);
  f(i, 0, n) {
    if (map[0][i]) pos[ map[0][i] ] = i;
  }
  bool c = 0;
  f(i, 0, n) if (map[1][i]) {
    if (pos[ map[1][i] ] == -1) continue;
    if (pos[ map[1][i] ] <= i) {
      c = 1;
      g(j, pos[ map[1][i] ], i) {
        if (map[1][j] != 0 && map[1][j] != map[1][i]) {
          c = 0; break;
        }
      }
      if (c) {
        fd(j, i, pos[ map[1][i] ])
          V.push_back((node){map[1][i], 2, j});
        V.push_back((node){map[1][i], 1, pos[ map[1][i] ] + 1});
        map[1][i] = 0;
      }
    } else {
      c = 1;
      g(j, i, pos[ map[1][i] ]) {
        if (map[1][j] != 0 && map[1][j] != map[1][i]) {
          c = 0; break;
        }
      }
      if (c) {
        f(j, i, pos[ map[1][i] ])
          V.push_back((node){map[1][i], 2, j + 2});
        V.push_back((node){map[1][i], 1, pos[ map[1][i] ] + 1});
        map[1][i] = 0;
      }
    }
  }
  bool can = 0;
  int posx = 0, posy = 0;
  f(i, 0, n) if (map[1][i] == 0 || map[2][i] == 0) {
    can = 1; break;
    posx = (map[1][i] == 0) ? 1 : 2;
    posy = i;
  }
  if (!can) {
    puts("-1");
    return 0;
  }
  int left = 0;
  f(i, 0, n) {
    if (map[1][i]) ++left;
    if (map[2][i]) ++left;
  }
  // printf("%d\n", left);
  bool met;
  while (left) {
    posx = -1; posy = -1;
    f(i, 0, n) if (map[1][i] == 0) {
      posx = 1; posy = i;
      break;
    }
    // f(j, 0, 4) {
    //   f(i, 0, n) {
    //     printf("%d ", map[j][i]);
    //   }
    //   puts("");
    // }
    // puts("`");
    // return 0;
    // met = 0;
    if (posx != -1) {
      gd(i, posy - 1, 0) if (map[1][i]) {
        V.push_back((node){map[1][i], 2, i + 2});
        std::swap(map[1][i], map[1][i + 1]);

      }
      if (map[2][0]) {
        V.push_back((node){map[2][0], 2, 1});
        std::swap(map[1][0], map[2][0]);
      } 
      f(i, 1, n) if (map[2][i]) {
        V.push_back((node){map[2][i], 3, i});
        std::swap(map[2][i], map[2][i - 1]);
      }
      if (map[1][n - 1]) {
        V.push_back((node){map[1][n - 1], 3, n});
        std::swap(map[1][n - 1], map[2][n - 1]);
      }
      gd(i, n - 1, posy + 1) if (map[1][i]) {
        V.push_back((node){map[1][i], 2, i + 2});
        std::swap(map[1][i], map[1][i + 1]);
      }
      f(i, 0, n) {
        if (map[1][i] && map[0][i] == map[1][i]) {
          V.push_back((node){map[1][i], 1, i + 1});
          map[1][i] = 0;
          --left;
        }
        if (map[2][i] && map[2][i] == map[3][i]) {
          V.push_back((node){map[2][i], 4, i + 1});
          map[2][i] = 0;
          --left;
        }
      }
    }
    // f(j, 0, 4) {
    //   f(i, 0, n) { printf("%d ", map[j][i]); }
    //   puts("");
    // }
    // puts("`");
    if (!left) break;
    posx = -1;
    posy = -1;
    f(i, 0, n) if (map[2][i] == 0) {
      posx = 2;
      posy = i;
      break;
    }
    if (posx != -1) {
      f(i, posy + 1, n) if (map[2][i]) {
        V.push_back((node){map[2][i], 3, i});
        std::swap(map[2][i], map[2][i - 1]);
      }
      if (map[1][n - 1]) {
        V.push_back((node){map[1][n - 1], 3, n});
        std::swap(map[1][n - 1], map[2][n - 1]);
      }
      gd(i, n - 2, 0) if (map[1][i]) {
        V.push_back((node){map[1][i], 2, i + 2});
        std::swap(map[1][i], map[1][i + 1]);
      }
      if (map[2][0]) {
        V.push_back((node){map[2][0], 2, 1});
        std::swap(map[1][0], map[2][0]);
      }
      g(i, 1, posy - 1) if (map[2][i]) {
        V.push_back((node){map[2][i], 3, i});
        std::swap(map[2][i], map[2][i - 1]);
      }
      f(i, 0, n) {
        if (map[1][i] && map[0][i] == map[1][i]) {
          V.push_back((node){map[1][i], 1, i + 1});
          map[1][i] = 0;
          --left;
        }
        if (map[2][i] && map[2][i] == map[3][i]) {
          V.push_back((node){map[2][i], 4, i + 1});
          map[2][i] = 0;
          --left;
        }
      }
    }
    // f(j, 0, 4) {
    //   f(i, 0, n) { printf("%d ", map[j][i]); }
    //   puts("");
    // }
    // puts("`");
    // printf("%d\n", left);
    // return 0;
  }
  // f(i, 0, 4) {
  //   f(j, 0, n) printf("%d ", map[i][j]); puts("");
  // }
  // f(i, 0, n) {
  //   if (map[3][i]) pos2[ map[3][i] ] = i;
  // }
  // f(i, 0, n) if (map[2][i]) {
  //   if (pos2[ map[2][i] ] == -1) continue;
  //   if (pos2[ map[2][i] ] <= i) {
  //     c = 1;
  //     g(j, pos2[ map[2][i] ], i) {
  //       if (map[2][j] != 0 && map[2][j] != map[2][i]) {
  //         c = 0; break;
  //       }
  //     }
  //     if (c) {
  //       fd(j, i, pos2[ map[2][i] ])
  //         V.push_back((node){map[2][i], 3, j});
  //       V.push_back((node){map[2][i], 4, pos2[ map[2][i] ] + 1});
  //       map[2][i] = 0;
  //     }
  //   } else {
  //     c = 1;
  //     g(j, i, pos2[ map[2][i] ]) {
  //       if (map[2][j] != 0 && map[2][j] != map[2][i]) {
  //         c = 0; break;
  //       }
  //     }
  //     if (c) {
  //       f(j, i, pos2[ map[2][i] ])
  //         V.push_back((node){map[2][i], 3, j + 2});
  //       V.push_back((node){map[2][i], 4, pos2[ map[2][i] ] + 1});
  //       map[2][i] = 0;
  //     }
  //   }
  // }
  // int left = 0;
  // f(i, 0, n) {
  //   if (map[1][i]) ++left;
  //   if (map[2][i]) ++left;
  // }
  // // f(i, 0, 4) {
  // //   f(j, 0, n) printf("%d ", map[i][j]); puts("");
  // // }
  // bool ctf;
  // bool can;
  // while (left) {
  //   can = 0;
  //   f(i, 0, n) {
  //     if (map[1][i]) {
  //       ctf = 0;
  //       if (pos[ map[1][i] ] != -1) ctf = solve(1, i, 0, pos[ map[1][i] ]);
  //       else ctf = solve(1, i, 3, pos2[ map[1][i] ]);
  //       if (ctf) {
  //         --left;
  //         can = 1;
  //       }
  //     }
  //     if (map[2][i]) {
  //       ctf = 0;
  //       if (pos[ map[2][i] ] != -1) ctf = solve(1, i, 0, pos[ map[2][i] ]);
  //       else ctf = solve(1, i, 3, pos2[ map[2][i] ]);
  //       if (ctf) {
  //         --left;
  //         can = 1;
  //       }
  //     }
  //   }
  //   if (!can) {
  //     bool has = 0;
  //     f(i, 0, n) if (map[1][i] && !map[2][i] && !done[i]) {
  //       has = 1;
  //       V.push_back((node){map[1][i], 2, i});
  //       std::swap(map[1][i], map[2][i]);
  //       done[i] = 1;
  //       break;
  //     } else if (!map[1][i] && map[2][i] && !done[i]) {
  //       done[i] = 1;
  //       has = 1;
  //       V.push_back((node){map[2][i], 1, i});
  //       std::swap(map[1][i], map[2][i]);
  //       break;
  //     }
  //     if (!has) {
  //       puts("-1");
  //       return 0;
  //     }
  //   }
  // }
  printf("%d\n", V.size());
  f(i, 0, V.size()) printf("%d %d %d\n", V[i].a, V[i].b, V[i].c);


#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

