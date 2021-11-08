#include <stdio.h>
#define MAX_EDGES 50
#define NO_EDGE -1
typedef struct {
int n, m;
int A[50][50];
} Graph;
void init_graph(Graph* G, int n, int m) {
int i, j;
G->n = n;
G->m = m;
for (i = 1; i <= n; i++)
for (j = 1; j <= m; j++)
G->A[i][j] = NO_EDGE;
}
void add_edge(Graph* G, int x, int y, int w) {
G->A[x][y] = w;
G->A[y][x] = w;
}
int mark[50];
int pi[50];
int p[50];
void Dijkstra(Graph* G, int s) {
int i, j, it;
for (i = 1; i <= G->n; i++) {
pi[i] = 999999;
mark[i] = 0;
}
pi[s] = 0;
p[s] = -1;
for (it = 1; it < G->n; it++) {
int min_pi = 999999;
for (j = 1; j <= G->n; j++)
if (mark[j] == 0 && pi[j] < min_pi) {
min_pi = pi[j];
i = j;
}
mark[i] = 1;
for (j = 1; j <= G->n; j++)
if (G->A[i][j] != NO_EDGE && mark[j] == 0) {
if (pi[i] + G->A[i][j] < pi[j]) {
pi[j] = pi[i] + G->A[i][j];
p[j] = i;
}
}
}
}
int main() {
Graph G;
int n, m, u, v, e, w, x, y;
scanf("%d%d", &n, &m);
init_graph(&G, n, m);
for (e = 1; e <= m; e++) {
scanf("%d%d%d", &u, &v, &w);
add_edge(&G,u,v,w);
}
scanf("%d%d", &x,&y);
Dijkstra(&G, x);
if(pi[y]>0){
printf("%d\n", pi[y]);
}
printf("%d %d %d", x,p[y],y);
return 0;
}

