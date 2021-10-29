/*
计算机里的树和现实中的树方向相反

节点 + 边
节点：可以表示为集合
边：关系，集合与集合的关系
根节点：全集
……子集
一对多
树的深度(高度)是根节点开始向下遍历，最长路径的节点个数就是树的深度(高度)
节点的深度：从根节点到该节点
节点的高度：从该节点向下遍历最长路径的节点数
节点的度：从该节点向外有多少边的指向
节点数量 = 边数 + 1  // 等式很重要

二叉树：
    每个节点度最多为2
    度为0的节点比度为2的节点多一个（节点数量 = 边数 + 1）

    

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    // struct Node *next[3]; 三叉树
    struct Node *left;
    struct Node *right;
} Node, *Tree;

完全二叉树
    左孩子：2i，右孩子2i+1；
    用连续空间存储

满二叉树

二叉树-广义表
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node *lchild, *rchild;
} Node;

typedef struct Tree {
    Node *root;
    int length;
} Tree;

Node *getNewNode(int val);
Tree *getNewTree();
void clear_node(Node *node);
void clear(Tree *tree);
Node *insert_node(Node *root, int val, int *flag);
void insert(Tree *tree, int val);
void pre_order_node(Node *root);
void pre_order(Tree *tree);
void in_order_node(Node *root);
void in_order(Tree *tree);
void pre_order_node(Node *root);
void pre_order(Tree *tree);
void output_node(Node *root);
void output(Tree *tree);

Node *getNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->lchild = p->rchild = NULL;
    return p;
}

Tree *getNewTree() {
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree->root = NULL;
    tree->length = 0;
    return tree;
}

void clear_node(Node *node) {
    if (node == NULL) return;
    clear_node(node->lchild);
    clear_node(node->rchild);
    free(node);
    return;
}

void clear(Tree *tree) {
    if (tree == NULL) return;
    clear_node(tree->root);
    free(tree);
    return;
}

Node *insert_node(Node *root, int val, int *flag) {
    if (root == NULL) {
        *flag = 1;
        return getNewNode(val);
    }
    if (root->data == val) return root;
    if (root->data > val) root->lchild = insert_node(root->lchild, val, flag);
    else root->rchild = insert_node(root->rchild, val, flag);
    return root;
}

void insert(Tree *tree, int  val) {
    if (tree == NULL) return;
    int flag = 0;
    tree->root = insert_node(tree->root, val, &flag);
    tree->length += flag;
    return;
}

void pre_order_node(Node *root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    pre_order_node(root->lchild);
    pre_order_node(root->rchild);
    return;
}

void pre_order(Tree *tree) {
    if (tree == NULL) return;
    printf("pre_order : ");
    pre_order_node(tree->root);
    printf("\n");
    return;
}

void in_order_node(Node *root) {
    if (root == NULL) return;
    in_order_node(root->lchild);
    printf("%d ", root->data);
    in_order_node(root->rchild);
    return;
}

void in_order(Tree *tree) {
    if (tree == NULL) return;
    printf("in_order : ");
    in_order_node(tree->root);
    printf("\n");
    return;
}

void post_order_node(Node *root) {
    if (root == NULL) return;
    post_order_node(root->lchild);
    post_order_node(root->rchild);
    printf("%d ", root->data);
    return;
}

void post_order(Tree *tree) {
    if (tree == NULL) return;
    printf("post_order : ");
    post_order_node(tree->root);
    printf("\n");
    return;
}

void output_node(Node *root) {
    if (root == NULL) return;
    printf("%d", root->data);
    if (root->lchild == NULL && root->rchild == NULL) return;
    printf("(");
    output_node(root->lchild);
    printf(",");
    output_node(root->rchild);
    printf(")");
    return;
}

void output(Tree *tree) {
    if (tree == NULL) return;
    printf("tree(%d) : ", tree->length);
    output_node(tree->root);
    printf("\n");
    return;
}

int main() {
    srand(time(0));
    Tree *tree = getNewTree();
    #define MAX_OP 10
    for (int i = 0; i < MAX_OP; i ++) {
        int val = rand() % 100;
        insert(tree, val);
        output(tree);
    }
    pre_order(tree);
    in_order(tree);
    post_order(tree);
    clear(tree);
    return 0;
}