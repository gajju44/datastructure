#include <stdio.h>

#define V 4 // Number of vertices in the graph

void floydWarshall(int graph[V][V], int size) {
    int dist[V][V];

    // Initialize the distance matrix with the same values as the input graph
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Apply the Floyd-Warshall algorithm
    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest path distances
    printf("Shortest path distances between all pairs of vertices:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (dist[i][j] == 9999) {
                printf("INF\t");
            } else {
                printf("%d\t", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int size;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &size);

    int graph[V][V];

    printf("Enter the adjacency matrix of the graph (enter 9999 for infinity):\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    floydWarshall(graph, size);

    return 0;
}

