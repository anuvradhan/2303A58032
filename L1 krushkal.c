#include <stdio.h>
#define MAX 30

struct Edge {
    int u, v, cost;
};
int parent[MAX];
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}
void unionSet(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}
int main() {
    int n, e;
    struct Edge edges[MAX], temp;
    int i, j;
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    // L=1, H=2, C=3, B=4, A=5
    printf("Enter edges (u v cost):\n");
    for (i = 0; i < e; i++) {
        char u, v;
        int cost;
        scanf(" %c %c %d",&u,&v,&cost);
        int x,y;
        if(u == 'L') x = 1;
        if(u == 'H') x = 2;
        if(u == 'C') x = 3;
        if(u == 'B') x = 4;
        if(u == 'A') x = 5;

        if (v == 'L') y = 1;
        if (v == 'H') y = 2;
        if (v == 'C') y = 3;
        if (v == 'B') y = 4;
        if (v == 'A') y = 5;

        edges[i].u = x;
        edges[i].v = y;
        edges[i].cost = cost;
    }
    
    for (i = 0; i < e - 1; i++) {
        for (j = 0; j < e - i - 1; j++) {
            if (edges[j].cost > edges[j + 1].cost) {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
    
    for (i = 1; i <= n; i++)
        parent[i] = i;

    int totalCost = 0;
    printf("\nSelected Edges in the MST:\n");
    for (i = 0; i < e; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        if (find(u) != find(v)) {
            unionSet(u, v);
            totalCost += edges[i].cost;
            char nameU, nameV;
            if (u == 1) nameU = 'L';
            if (u == 2) nameU = 'H';
            if (u == 3) nameU = 'C';
            if (u == 4) nameU = 'B';
            if (u == 5) nameU = 'A';
            if (v == 1) nameV = 'L';
            if (v == 2) nameV = 'H';
            if (v == 3) nameV = 'C';
            if (v == 4) nameV = 'B';
            if (v == 5) nameV = 'A';
            printf("%c - %c : %d\n", nameU, nameV, edges[i].cost);
        }
    }
    printf("\nTotal Minimum Cost = %d\n", totalCost);
    
    
    return 0;
}

