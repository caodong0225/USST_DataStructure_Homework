#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// 定义二叉树节点结构
typedef struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 定义邻接表节点结构
typedef struct AdjListNode {
    int child;
    struct AdjListNode* next;
} AdjListNode;

// 定义邻接表结构
typedef struct AdjList {
    AdjListNode* head;
} AdjList;

// 定义二叉树结构
typedef struct Tree {
    int numNodes;
    TreeNode* nodes[MAX_NODES];
    AdjList adjLists[MAX_NODES];
} Tree;

// 创建新二叉树节点
TreeNode* createTreeNode(char data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 创建新邻接表节点
AdjListNode* createAdjListNode(int child) {
    AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    newNode->child = child;
    newNode->next = NULL;
    return newNode;
}

// 初始化二叉树
void initTree(Tree* tree) {
    tree->numNodes = 0;
    for (int i = 0; i < MAX_NODES; i++) {
        tree->nodes[i] = NULL;
        tree->adjLists[i].head = NULL;
    }
}

// 添加边到邻接表
void addEdge(Tree* tree, int parent, int child) {
    AdjListNode* newNode = createAdjListNode(child);
    newNode->next = tree->adjLists[parent].head;
    tree->adjLists[parent].head = newNode;
}

// 创建二叉树
void createBinaryTree(Tree* tree) {
    printf("Total number of input nodes:");
    int n;
    scanf("%d", &n);
    tree->numNodes = n;

    for (int i = 0; i < n; i++) {
        char data;
        printf("Input node %d data:", i);
        scanf(" %c", &data);
        tree->nodes[i] = createTreeNode(data);
    }

    for (int i = 0; i < n; i++) {
        int left, right;
        printf("Input left child node index for node %d (-1 indicates no left child nodes):", i);
        scanf("%d", &left);
        printf("Input right child node index for node %d (-1 indicates no right child nodes):", i);
        scanf("%d", &right);

        if (left != -1) {
            addEdge(tree, i, left);
        }
        if (right != -1) {
            addEdge(tree, i, right);
        }
    }
}

// 按邻接表构建二叉树
void buildTreeFromAdjList(Tree* tree) {
    for (int i = 0; i < tree->numNodes; i++) {
        AdjListNode* current = tree->adjLists[i].head;
        if (current != NULL) {
            tree->nodes[i]->left = tree->nodes[current->child];
            current = current->next;
        }
        if (current != NULL) {
            tree->nodes[i]->right = tree->nodes[current->child];
        }
    }
}

// 先序遍历并将结果存入栈中
void preOrderTraversal(TreeNode* root, char* stack, int* top) {
    if (root == NULL) {
        return;
    }
    stack[(*top)++] = root->data;
    preOrderTraversal(root->left, stack, top);
    preOrderTraversal(root->right, stack, top);
}

// 逆序显示先序遍历结果
void displayReversePreOrder(char* stack, int top) {
    while (top > 0) {
        printf("%c ", stack[--top]);
    }
    printf("\n");
}

int main() {
    Tree tree;
    initTree(&tree);

    createBinaryTree(&tree);
    buildTreeFromAdjList(&tree);

    // 栈来保存先序遍历结果
    char stack[100];
    int top = 0;

    // 先序遍历
    preOrderTraversal(tree.nodes[0], stack, &top);

    // 逆序显示
    printf("The reverse result of pre order traversal is: \n");
    displayReversePreOrder(stack, top);

    return 0;
}
