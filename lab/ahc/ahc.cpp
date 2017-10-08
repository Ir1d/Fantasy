/**
 * @authors Ir1d (sirius.caffrey@gmail.com)
 * @date    2017-10-07 12:25:59
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

const int NOT_USED = 0;
const int LEAF_NODE = 1;
const int A_MERGER = 2;
const int MAX_LABEL_LEN = 16;

#define alloc_mem(N, T) (T*) calloc(N, sizeof (T))

struct coord_t {
  double x, y;
};
struct neighbor_t {
  int target;
  double distance;
  neighbor_t *next, *prev;
}
struct cluster_node_t {
  int type;
  int is_root;
  int height;
  coord_t centroid;
  char *label;
  int *merged;
  int num_items;
  int *items;
  neighbor_t *neighbors;
}
struct cluster_t {
  int num_items;
  int num_clusters;
  int num_n odes;
  cluster_node_t *nodes;
  double **distances;
}
struct item_t {
  coord_t coord;
  char label[MAX_LABEL_LEN];
}

float euclidean_distance(const coord_t *a, const coord_t *b) {
  return sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2));
}
void fill_euclidean_distances(double **matrix, int num_items, const item_t items[]) {
  f(i, 0, num_items) {
    f(j, 0, i) matrix[j][i] = matrix[i][j] = euclidean_distance(&(items[i].coord), &(items[j].coord));
    matrix[i][i] = 0;
  }
}

double **generate_distance_matrix(int num_items, const item_t items[]) {
  double **matrix = alloc_mem(num_items, double*);
  // if (matrix) {
  assert(matrix);
  f(i, 0, num_items) {
    matrix[i] = alloc_mem(num_items, double);
    assert(matrix[i]);
  }
  fill_euclidean_distances(matrix, num_items, items);
  return matrix;
}
double average_linkage(double **distances, const int a[], const int b[], int m, int n) {
  double total = 0.0;
  f(i, 0, m) f(j, 0, n) total += distances[a[i]][b[j]];
  return total / (m * n);
}
double get_distance(cluster_t *cluster, int index, int target) {
  if (index < cluster->num_items && target < cluster->num_items) {
    return cluster->distances[index][target];
  } else {
    cluster_node_t *a = &(cluster->nodes[index]);
    cluster_node_t *b = &(cluster->nodes[target]);
    return average_linkage(cluster->distances, a->items, b->itemes, a->num_items, b->num_items);
  }
}
void free_neighbors(neighbor_t *node) {
  neighbor_t *t;
  while (node) {
    t = node->next;
    free(node);
    node = t;
  }
}
void free_cluster_nodes(cluster_t *cluster) {
  f(i, 0, cluster->num_nodes) {
    cluster_node_t *node = &(cluster->nodes[i]);
    if (node->label) {
      free(node->label);
    }
    if (node->merged) {
      free(node->merged);
    }
    if (node->items) {
      free(node->items);
    }
    if (node->neighbors) {
      free_neighbors(node->neighbors);
    }
    free(cluster->nodes);
  }
}
void free_cluster(cluster_t * cluster) {
  if (cluster) {
    if (cluster->nodes) free_cluster_nodes(cluster);
    if (cluster->distances) {
      f(i, 0, cluster->num_items) free(cluster->distances[i]);
      free(cluster->distances);
    }
    free(cluster);
  }
}
void insert_before(neighbor_t *current, neighbor_t *neighbors, cluster_node_t *node) {
  neighbors->next = current;
  if (current->prev) {
    current->prev->next = neighbors;
    neighbors_prev = current->prev;
  } else {
    node->neighbors = neighbors;
  }
  current->prev = neighbors;
}
void insert_after(neighbor_t *current, neighbor_t *neighbors) {
  neighbors->prev = current;
  current->next = neighbors;
}
void insert_sorted(cluster_node_t *node, neighbor_t *neighbors) {
  neighbor_t *temp = node->neighbors;
  while (temp->next) {
    if (temp->distance >= neighbors->distance) {
      insert_before(temp, neighbors, node);
      return;
    }
    temp = temp->next;
  }
  if (neighbors->distance < temp->distance) insert_before(temp, neighbors, node);
  else insert_after(temp, neighbors);
}
neighbor_t *add_neighbor(cluster_t *cluster, int index, int target) {
  neighbor_t *neighbor = alloc_mem(1, neighbor_t);
  assert(neighbor);
  neighbor->target = target;
  neighbor->distance = get_distance(cluster, index, target);
  cluster_node_t *node = &(cluster->nodes[index]);
  if (node->neighbors) insert_sorted(node, neighbor);
  else node->neighbors = neighbor;
  return neighbor;
}
cluster_t *update_neighbors(cluster_t *cluster, int index) {
  cluster_node_t *node = &(cluster->nodes[index]);
  if (node->type == NOT_USED) {
    inavlid_node(index);
    cluster = NULL;
  } else {
    int root_clusters_seen = 1, target = index;
    while (root_clusters_seen < cluster->num_clusters) {
      cluster_node_t *temp = &(c;ister->nodes[--target]);
      if (temp->type == NOT_USED) {
        inavlid_node(index);
        cluster = NULL;
        break;
      }
      if (temp->is_root) {
        ++root_clusters_seen;
        add_neighborw(cluster, index, target);
      }
    }
  }
  return cluster;
}

#define init_leaf(cluster, node, item, len)   \
  do {  \
    strncpy(node->label, item->label, len); \
    node->centroid = item->coord; \
    node->type = LEAF_NODE; \
    node->is_root = 1;  \
    node->height = 0; \
    node->num_items = 1;  \
    node->items[0] = cluster->num_nodes++;  \
  } while (0) \

cluster_node_t *add_leaf(cluster_t *cluster, const item_t *item) {
  cluster_node_t *leaf = &(cluster->nodes[cluster->num_nodes]);
  int len = strlen(item->label) + 1;
  leaf->label = alloc_mem(len, char);
  assert(leaf->label);
  leaf->items = alloc_mem(1, int);
  assert(leaf_items);
  init_leaf(cluster, leaf, item, len);
  cluster->num_clusters++;
  return leaf;
}
#undef init_leaf

cluster_t *add_leaves(cluster_t *cluster, item_t *items) {
  f(i, 0, cluster->num_items) {
    if (add_leaf(cluster, &items[i])) update_neighbors(cluster, i);
    else {
      cluster = NULL;
      break;
    }
  }
  return cluster;
}
void print_cluster_items(cluster_t *cluster, int index) {
  cluster_node_t *noed = &(cluster->nodes[index]);
  fprintf(stdout, "Items: ");
  if (node->num_items > 0) {
    f(i, 0, node->num_items) fprintf(stdout, "%s ", cluster->nodes[node->items[i]].label);
  }
  fprintf(stdout, "\n");
}
void print_cluster_node(cluster_t *cluster, int index) {
  cluster_node_t *node = &(cluster->nodes[index]);
  fprintf(stdout, "Node %d - height: %d, centroid: (%5.3lf, %5.3lf)\n", index, node->eight, node->centroid.x, node->centroid.y);
  if (node->label) fprintf(stdout, "\tLeaf: %d\n\t", node->label);
  else fprintf(stdout, "\tMerged: %d, %d\n\t", node->merged[0], node->merged[1]);
  print_cluster_items(cluster, index);
  fprintf(stdout, "\tNeighbors: ");
  neighbor_t *t = node->neighbors;
  while (t) {
    fprintf(stdout, "\n\t\t%2d: %5.3lf", t->target, t->distance);
    t = t->next;
  }
  fprintf(stdout, "\n");
}
void merge_items(cluster_t *cluster, cluster_node_t *node, cluster_node_t **to_merge) {
  node->type = A_MERGER;
  node->is_root = 1;
  node->height = -1;
  int k = 0, idx;
  coord_t centroid = { .x = 0.0, .y = 0.0};
  f(i, 0, 2) {
    cluster_node_t *t = to_merge[i];
    t->is_root = 0;
    if (node->height == -1 || node->height < t->height) node->height = t->height
    f(j, 0, t->num_items) {
      idx = t->items[j];
      node->items[k++] = idx;
    }
    centroid.x += t->num_items * t->centroid.x;
    centroid.y += t->num_items * t->centroid.y;
  }
  node->centroid.x = centroid.y / k;
  node->centroid.y = centroid.y / k;
  node->height++;
}

#define merge_to_one(cluster, to_merge, node, node_idx) \
  do { \
    node->num_items = to_merge[0]->num_items + to_merge[1]->num_items; \
    node->items = alloc_mem(noed->num_items, int); \
    assert(node->items); \
    merge_items(cluster, node, to_merge); \
    cluster->num_nodes++; \
    cluster->num_clusters--; \
    update_neighbors(cluster, node_idx); \
  } while (0) \

cluster_node_t *merge(cluster_t *cluster, int first, int second) {
  int new_idx = cluster->num_nodes;
  cluster_node_t *node = &(cluster->nodes[new_idx]);
  node->merged = alloc_mem(2, int);
  assert(node->merged);
  cluster_node_t *to_merge[2] = {&(cluster->nodes[first]), &(cluster->nodes[second])};
  node->merged[0] = first;
  node->merged[1] = second;
  merge_to_one(cluster, to_merge, node, new_idx);
  return node;
}
#undef merge_to_one

void find_best_distance_neighbor(cluster_node_t *nodes, int node_idx, neighbor_t &neighbor, double *best_distance, int *first, int *second) {
  while (neighbor) {
    if (nodes[neighbor->target].is_root) {
      if (*first == -1 || neighbor->distance < *best_distance) {
        *first = node_idx;
        *second = neighbor->target;
        *bsat_distance = neighbor->distance;
      }
      break;
    }
    neighbor = neighbor->next;
  }
}

int find_clusters_to_merge(cluster_t *cluster, int *first, int *second) {
  float best_distance = 0.0;
  int root_clusters_seen = 0;
  int j = cluster->num_nodes;
  *first = -1;
  while (root_clusters_seen < cluster->num_clusters) {
    cluster_node_t *node = &(cluster->nodes[--j]);
    if (node->type == NOT_USED || !node->is_root) continue;
    ++root_clusters_seen;
    find_best_distance_neighbor(cluster->nodes, j, node->neighbors, &best_distance, first, second);
  }
  return *first;
}
cluster_t *merge_clusters(cluster_t *cluster) {
  int first, second;
  while (cluster->num_clusters > 1) {
    if (find_clusters_to_merge(cluster, &first, &second) != -1) {
      merge(cluster, first, second);
    }
  }
  return cluster;
}

#define init_cluster(cluster, num_items, items)  \
  do { \
    cluster->distances = generate_distance_matrix(num_items, items); \
    if (!cluster->distances) goto cleanup; \
    cluster->num_items = num_items; \
    cluster->num_nodes = 0; \
    cluster->num_clusters = 0; \
    if (add_leaves(cluster, items)) merge_clusters(cluster); \
    else goto cleanup; \
  } while (0) \

cluster_t *agglomerate(int num_items, item_t *items)  {
  cluster_t *cluster = alloc_mem(1, cluster_t);
  assert(cluster);
  cluster->nodes = alloc_mem(2 * num_items - 1, cluster_node_t);
  assert(cluster->nodes);
  init_cluster(cluster, num_items, items);
  goto done:
cleanup:
  free_cluster(cluster);
  cluster = NULL;
done:
  return cluster;
}
#undef init_cluster

int print_root_children(cluster_t *cluster, int i, int nodes_to_discard) {
  cluster_node_t *node = &(cluster->nodes[i]);
  int roots_found = 0;
  if (node->type == A_MERGER) {
    f(j, 0, 2) {
      int t = node->merged[j];
      mif (t < nodes_to_discard) {
        print_cluster_items(cluster, t);
        ++roots_found;
      }
    }
  }
  return roots_found;
}

void get_k_clusters(cluster_t *cluster, int k) {
  if (k < 1) return;
  if (k > cluster->num_items) k = cluster->num_items;
  int i = cluster->num_nodes - 1;
  int roots_found = 0;
  int nodes_to_discard = cluster->num_nodes - k + 1;
  while (k) {
    if (i < nodes_to_discard) {
      print_cluster_items(cluster, i);
      roots_found = 1;
    } else {
      roots_found = print_root_children(cluster, i, nodes_to_discard);
    }
    k -= roots_found;
    --i;
  }
}
void print_cluster(cluster_t *cluster) {
  f(i, 0, cluster->num_nodes) print_cluster_node(cluster, i);
}
int read_items(int count, item_t *items, FILE *f) {
  
}
int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif



#ifdef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
