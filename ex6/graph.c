#include <stdio.h>
#include <stdlib.h>

// 定义邻接表的最大顶点数
#define MAX_VERTEX_NUM 20

// 定义邻接表的边节点结构
typedef struct ArcNode {
    int adjvex;
    struct ArcNode *next;
} ArcNode;

// 定义邻接表的顶点节点结构
typedef struct VNode {
    char data;
    ArcNode *first;
} VNode, AdjList[MAX_VERTEX_NUM];

// 定义图结构
typedef struct {
    AdjList vertices;
    int vexnum, arcnum;
} ALGraph;

// 查找顶点位置
int findVertexIndex(ALGraph *G, char vertex) {
    for (int i = 0; i < G->vexnum; i++) {
        if (G->vertices[i].data == vertex) {
            return i;
        }
    }
    return -1;
}

// 读取键盘输入，插入邻接表
void CreateALGraph(ALGraph *G) {
    int i, k;
    char vi, vj;
    ArcNode *p;

    printf("Please input the number of vertexes and edges:\n");
    scanf("%d%d", &G->vexnum, &G->arcnum);

    printf("Please input the vertexes:\n");
    for (i = 0; i < G->vexnum; i++) {
        scanf(" %c", &G->vertices[i].data);
        G->vertices[i].first = NULL;
    }

    printf("Please input the edges:\n");
    for (k = 0; k < G->arcnum; k++) {
        printf("Please input the edge (vi, vj):\n");
        scanf(" %c %c", &vi, &vj);
        
        int index_i = findVertexIndex(G, vi);
        int index_j = findVertexIndex(G, vj);

        if (index_i == -1 || index_j == -1) {
            printf("Invalid edge!\n");
            continue;
        }

        p = (ArcNode *)malloc(sizeof(ArcNode));
        p->adjvex = index_j;
        p->next = G->vertices[index_i].first;
        G->vertices[index_i].first = p;

        p = (ArcNode *)malloc(sizeof(ArcNode));
        p->adjvex = index_i;
        p->next = G->vertices[index_j].first;
        G->vertices[index_j].first = p;
    }
}

// 深度优先搜索（DFS）辅助函数
void DFS(ALGraph *G, int i, int visited[]) {
    int j;
    ArcNode *p;
    visited[i] = 1;
    printf("%c ", G->vertices[i].data);

    for (p = G->vertices[i].first; p; p = p->next) {
        j = p->adjvex;
        if (!visited[j]) {
            DFS(G, j, visited);
        }
    }
}

// 深度优先搜索（DFS）遍历
void DFSTraverse(ALGraph *G) {
    int i;
    int visited[MAX_VERTEX_NUM] = {0};

    for (i = 0; i < G->vexnum; i++) {
        if (!visited[i]) {
            DFS(G, i, visited);
        }
    }
    printf("\n");
}

// 广度优先搜索（BFS）遍历
void BFS(ALGraph *G) {
    int i, j;
    int visited[MAX_VERTEX_NUM] = {0};
    int queue[MAX_VERTEX_NUM], front = 0, rear = 0;
    ArcNode *p;

    for (i = 0; i < G->vexnum; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            printf("%c ", G->vertices[i].data);
            queue[rear++] = i;

            while (front != rear) {
                int v = queue[front++];
                for (p = G->vertices[v].first; p; p = p->next) {
                    j = p->adjvex;
                    if (!visited[j]) {
                        visited[j] = 1;
                        printf("%c ", G->vertices[j].data);
                        queue[rear++] = j;
                    }
                }
            }
        }
    }
    printf("\n");
}

int main() {
    ALGraph G;
    CreateALGraph(&G);

    printf("DFS:\n");
    DFSTraverse(&G);

    printf("BFS:\n");
    BFS(&G);

    return 0;
}
