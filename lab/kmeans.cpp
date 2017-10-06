/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2017-10-05 20:24:48
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

const int K = 200;
const double RSS_THRESHOLD = 1e-8;
/*const*/ int MAX_ITERATION_NUM = 500;
const int MAXNUMCLUSTER = 500;

int article, cnt, iteration, k;
struct Word {
  // std::vector<int> feature;
  int feature[8680];
  int belong;
  std::string s;
  double norm;
  inline void calc() {
    norm = 0.0;
    f(i, 0, article) {
      norm += feature[i] * feature[i];
    }
    norm = sqrt(norm);
    assert(norm);
  }
} word[5200];
// cnt is num of word;
struct Cluster {
  int centroid[8680];
  std::vector<int> elem;
  double norm;
  inline void calc() {
    norm = 0.0;
    f(i, 0, article) {
      norm += centroid[i] * centroid[i];
    }
    norm = sqrt(norm);
    assert(norm);
  }
} clusters[233];

std::map<std::string, int> M;
std::map<int, std::string> V;

std::string s;
void read() {
  std::ios::sync_with_stdio(0);
  int num, x;
  // 8675 5168
  // freopen("vector.out", "r", stdin);
  std::cin >> article >> cnt;
  // int cur = -1;
  // while (std::cin >> s) {
  fprintf(stderr, "Starts reading----\n");
  f(cur, 0, cnt) {
    std::cin >> s;
    // if (s[0] == '-') ++cur;
    std::cin >> word[cur].s;
    // M[s] = cur; V[cur] = s;
    std::cin >> num;
    f(i, 0, num) {
      std::cin >> x;
      ++word[cur].feature[x - 1];
      // assert(x < article);
    }
    word[cur].calc();
  }
  // fprintf(stderr, )
}

int seeds[MAXNUMCLUSTER];
void selectRandomSeeds() {
  srand(time(0));
  // std::cout << "Random Seeds: ";
  // printf("Random Seeds: ");
  int *tee = new int[cnt];
  f(i, 0, cnt) tee[i] = i;
  int pos;
  int idx = cnt;
  f(i, 0, k) {
    pos = rand() % cnt;
    seeds[i] = tee[pos];
    // std::cout << seeds[i] << " ";
    // printf("%d ", seeds[i]);
    tee[pos] = tee[--idx];
  }
  // std::cout << "\n";
  delete []tee;
  // puts("");
}
double getDis(int i, int j) {
  // word[i].feature, clusters[j].centroid
  double cos = 0.0;
  f(w, 0, article) {
    cos += word[i].feature[w] * clusters[j].centroid[w];
  }
  assert(word[i].norm * clusters[j].norm);
  cos /= (word[i].norm * clusters[j].norm);
  return 2 - cos;
}
double prev_RSS;
double RSS[K];
double calculateRSS() {
  // memset(RSS, 0, sizeof RSS);
  // double *RSS = new double[K];
  double totalRSS = 0.0;
  memset(RSS, 0, sizeof (double) * k);
  int id;
  f(i, 0, cnt) {
    id = word[i].belong;
    RSS[id] += getDis(i, id);
  }
  f(i, 0, k) {
    totalRSS += RSS[i];
  }
  // delete []RSS;
  return totalRSS;
}
bool converge() {
  bool ctf = 0;
  double cur_RSS = calculateRSS();
  // std::cout << "RSS: " << cur_RSS << "\n";
  // printf("RSS: %.06lf\n", cur_RSS);
  if (fabs(cur_RSS - prev_RSS) < RSS_THRESHOLD || iteration > MAX_ITERATION_NUM) {
    ctf = 1;
  }
  prev_RSS = cur_RSS;
  return ctf;
}
void reassign() {
  f(i, 0, k) clusters[i].elem.clear();
  double mn, dis;
  f(i, 0, cnt) {
    mn = INF;
    word[i].belong = -1;
    f(j, 0, k) {
      dis = getDis(i, j);
      if (dis < mn) {
        mn = dis;
        word[i].belong = j;
      }
    }
    clusters[ word[i].belong ].elem.push_back(i);
  }
}
void update() {
  int sz;
  f(i, 0, k) {
    if (clusters[i].elem.size() == 0) break;
    memset(clusters[i].centroid, 0, sizeof (int) * (article));
    f(j, 0, sz = clusters[i].elem.size()) {
      f(w, 0, article) {
        clusters[i].centroid[w] += word[ clusters[i].elem[j] ].feature[w];
      }
    }
    assert(sz);
    f(w, 0, article) clusters[i].centroid[w] /= sz;
    clusters[i].calc();
  }
}
void kmeans() {
  int num = k, pos;
  selectRandomSeeds();
  f(i, 0, num) {
    memcpy(clusters[i].centroid, word[ seeds[i] ].feature, sizeof (int) * (article));
    clusters[i].calc();
  }
  while (!converge()) {
    fprintf(stderr, "Current iteration: %d\n", iteration++);
    // std::cout << "iteration " << iteration << "\n";
    // printf("iteration: %d\n", iteration);
    reassign();
    update();
  }
}
void printRes() {
  f(i, 0, k) {
    std::cout << "---- Cluster id #" << i + 1 << " ----\n";
    std::cout << "Size: " << clusters[i].elem.size() << "\n";
    // printf("Cluster id #%d: \n", i + 1);
    f(j, 0, clusters[i].elem.size()) {
      // std::cout << clusters[i].elem[j] << " ";
      std::cout << word[clusters[i].elem[j]].s << " ";
    }
    std::cout << "\n";
  }
}
int main(int argc, char *argv[]) {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  assert(argc > 1);
  k = atoi(argv[1]);
  // fprintf(stderr, "%d\n", k);
  // return 0;
  read();
  kmeans();
  printRes();

#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
