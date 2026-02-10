#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 6
#define INF INT_MAX

int minDistance(int dist[], bool visited[]) {
    int min = INF, minIdx;
    for (int v = 0; v < V; v++)
        if (!visited[v] && dist[v] < min)
            min = dist[v], minIdx = v;
    return minIdx;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool visited[V] = {false};
    
    for (int i = 0; i < V; i++) dist[i] = INF;
    dist[src] = 0;
    
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = true;
        
        for (int v = 0; v < V; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    
    printf("Shortest distances from vertex %d:\n", src);
    for (int i = 0; i < V; i++)
        printf("To %d: %d\n", i, dist[i]);
}

int main() {
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0},
        {4, 0, 8, 0, 0, 0},
        {0, 8, 0, 7, 0, 4},
        {0, 0, 7, 0, 9, 14},
        {0, 0, 0, 9, 0, 10},
        {0, 0, 4, 14, 10, 0}
    };
    
    printf("Dijkstra's Shortest Path\n\n");
    dijkstra(graph, 0);
    
    return 0;
}