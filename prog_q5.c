#include <stdio.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int V;
    int adj[MAX][MAX];
} Graph;

void initGraph(Graph* g, int v) {
    g->V = v;
    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            g->adj[i][j] = 0;
}

void addEdge(Graph* g, int u, int v) {
    g->adj[u][v] = g->adj[v][u] = 1;
}

void BFS(Graph* g, int start) {
    bool vis[MAX] = {0};
    int q[MAX], f = 0, r = 0;
    
    vis[start] = true;
    q[r++] = start;
    printf("BFS from %d: ", start);
    
    while (f < r) {
        int u = q[f++];
        printf("%d ", u);
        for (int v = 0; v < g->V; v++)
            if (g->adj[u][v] && !vis[v]) {
                vis[v] = true;
                q[r++] = v;
            }
    }
    printf("\n");
}

void DFSUtil(Graph* g, int u, bool vis[]) {
    vis[u] = true;
    printf("%d ", u);
    for (int v = 0; v < g->V; v++)
        if (g->adj[u][v] && !vis[v])
            DFSUtil(g, v, vis);
}

void DFS(Graph* g, int start) {
    bool vis[MAX] = {0};
    printf("DFS from %d: ", start);
    DFSUtil(g, start, vis);
    printf("\n");
}

void printGraph(Graph* g) {
    printf("\nAdjacency Matrix:\n   ");
    for (int i = 0; i < g->V; i++) printf("%d ", i);
    printf("\n");
    for (int i = 0; i < g->V; i++) {
        printf("%d: ", i);
        for (int j = 0; j < g->V; j++)
            printf("%d ", g->adj[i][j]);
        printf("\n");
    }
}


int main() {
    Graph g;
    initGraph(&g, 6);
    
    printf("Graph Traversal (BFS & DFS)\n");
    addEdge(&g, 0, 1); addEdge(&g, 0, 2);
    addEdge(&g, 1, 3); addEdge(&g, 2, 3);
    addEdge(&g, 2, 4); addEdge(&g, 3, 5);
    addEdge(&g, 4, 5);
    
    printGraph(&g);
    printf("\n");
    BFS(&g, 0);
    DFS(&g, 0);
    
    return 0;
}
