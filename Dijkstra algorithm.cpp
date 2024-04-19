#include <stdio.h>   

#define INF 9999   
#define MAX 10   

// Function to implement Dijkstra's algorithm
void DijkstraAlgorithm(int Graph[MAX][MAX], int size, int start) {
    int cost[MAX][MAX], distance[MAX], previous[MAX];
    int visited[MAX] = {0}; // Array to track visited nodes
    int counter, minimumDistance, nextNode, i, j;

    // Initialize cost matrix
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (Graph[i][j] == 0)
                cost[i][j] = INF;
            else
                cost[i][j] = Graph[i][j];
        }
    }

    // Initialize distance and previous arrays
    for (i = 0; i < size; i++) {
        distance[i] = cost[start][i];
        previous[i] = start;
    }

    distance[start] = 0;
    visited[start] = 1;
    counter = 1;

    while (counter < size) {
        minimumDistance = INF;

        // Find the next node to visit
        for (i = 0; i < size; i++) {
            if (distance[i] < minimumDistance && !visited[i]) {
                minimumDistance = distance[i];
                nextNode = i;
            }
        }

        visited[nextNode] = 1;

        // Update distances to adjacent nodes
        for (i = 0; i < size; i++) {
            if (!visited[i] && minimumDistance + cost[nextNode][i] < distance[i]) {
                distance[i] = minimumDistance + cost[nextNode][i];
                previous[i] = nextNode;
            }
        }
        counter++;
    }

    // Print distances
    for (i = 0; i < size; i++) {
        if (i != start) {
            if (distance[i] != INF) {
                printf("\nDistance from Node %d to Node %d: %d", start, i, distance[i]);
            } else {
                printf("\nDistance from Node %d to Node %d: Not reachable", start, i);
            }
        }
    }
}

int main() {
    int Graph[MAX][MAX], size, source;

    // Input the number of nodes
    printf("Enter the number of nodes in the graph(maximum 10): ");
    scanf("%d", &size);

    // Input distances between nodes
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("Enter distance from Node %d to Node %d (enter 9999 for infinity): ", i, j);
            scanf("%d", &Graph[i][j]);
        }
    }

    // Input the source node
    printf("Enter the source node: ");
    scanf("%d", &source);

    // Run Dijkstra's algorithm
    DijkstraAlgorithm(Graph, size, source);

    return 0;
}

