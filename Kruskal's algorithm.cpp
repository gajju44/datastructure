#include <stdio.h>
#include <stdlib.h>

struct Edge {
  int source, destination, weight;
};

struct Subset {
  int parent, rank; // Using rank for efficient union-find
};

// Comparison function for qsort
int compare(const void *a, const void *b) {
  struct Edge *edge1 = (struct Edge *)a;
  struct Edge *edge2 = (struct Edge *)b;
  return (edge1->weight - edge2->weight);
}

// Find operation to find the root of a subset (parent of a vertex)
int find(struct Subset subsets[], int vertex) {
  if (subsets[vertex].parent != vertex)
    subsets[vertex].parent = find(subsets, subsets[vertex].parent);
  return subsets[vertex].parent;
}

// Union operation to merge two subsets
void Union(struct Subset subsets[], int x, int y) {
  int xroot = find(subsets, x);
  int yroot = find(subsets, y);

  // Attach smaller rank tree under root of larger rank tree
  if (subsets[xroot].rank < subsets[yroot].rank)
    subsets[xroot].parent = yroot;
  else if (subsets[xroot].rank > subsets[yroot].rank)
    subsets[yroot].parent = xroot;
  else {
    subsets[yroot].parent = xroot;
    subsets[xroot].rank++; // Increment rank if ranks are same
  }
}

// Kruskal's algorithm to find Minimum Spanning Tree
void kruskalMST(struct Edge edges[], int V, int E) {
  struct Edge result[V]; // Array to store constructed MST
  int i = 0, j = 0; // Two pointers to indicate result[] index and picked edges

  // Sort edges in increasing order of weight
  qsort(edges, E, sizeof(edges[0]), compare);

  // Allocate memory for V subsets
  struct Subset *subsets = (struct Subset *)malloc(V * sizeof(struct Subset));

  // Initialize all subsets with single element
  for (int v = 0; v < V; ++v) {
    subsets[v].parent = v;
    subsets[v].rank = 0;
  }

  // Pick edges one by one
  while (i < E && j < V - 1) {
    struct Edge currentEdge = edges[i++];

    int x = find(subsets, currentEdge.source);
    int y = find(subsets, currentEdge.destination);

    // If including this edge doesn't cause a cycle
    if (x != y) {
      result[j++] = currentEdge;  // Add edge to result array
      Union(subsets, x, y);        // Merge two sets
    }
  }

  // Print MST edges
  printf("Minimum Spanning Tree Edges:\n");
  printf("S\tD\tW\n");
  int total_weight = 0;
  for (i = 0; i < j; ++i) {
    printf("%d -- %d == %d\n", result[i].source, result[i].destination, result[i].weight);
    total_weight += result[i].weight;
  }
  printf("Total Weight: %d\n", total_weight);

  // Free allocated memory
  free(subsets);
}

int main() {
  int V, E;
  printf("Enter the number of vertices: ");
  scanf("%d", &V);
  printf("Enter the number of edges: ");
  scanf("%d", &E);

  struct Edge graph[E];
  printf("Enter graph edges (source, destination, weight):\n");
  for (int i = 0; i < E; ++i) {
    scanf("%d %d %d", &graph[i].source, &graph[i].destination, &graph[i].weight);
  }

  kruskalMST(graph, V, E);

  return 0;
}

