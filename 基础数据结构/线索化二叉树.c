/*
递归→回溯

线索化二叉树：
    不用递归完成二叉树遍历
*/
// 有点问题
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NORMAL 0
#define THREAD 1

typedef struct Node {
    char data;
    struct Node *lchild, *rchild;
    int ltag, rtag;
} Node;

Node *getNewNode(char val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->lchild = p->rchild = NULL;
    p->ltag = NORMAL;
    p->rtag = NORMAL;
    return p;
}

Node *insert(Node *root, int val) {
    if (root == NULL) return getNewNode(val);
    if (root->data == val) return root;
    if (val < root->data) root->lchild = insert(root->lchild, val);
    else root->rchild = root->lchild = insert(root->rchild, val);
    return root;
}

void build_thread(Node *root) {
    if (root == NULL) return;
    static Node *pre = NULL;
    build_thread(root->lchild);
    if (root->lchild == NULL) {
        root->lchild = pre;
        root->ltag = THREAD;
    }
    if (pre != NULL && pre->rchild == NULL) {
        pre->rchild = root;
        pre->rtag = THREAD;
    }
    pre = root;
    build_thread(root->rchild);
    return;
}

Node *most_left(Node *p) {
    while (p != NULL && p->ltag == NORMAL && p->lchild != NULL) p = p->lchild;
    return p;
}

void output(Node *root) {
    Node *p = most_left(root);
    while (p != NULL) {
        printf("%d ", p->data);
        if (p->rtag == THREAD) {
            p = p->rchild;
        } else {
            p = most_left(p->rchild);
        }
    }
    return;
}

void in_order(Node *root) {
    if (root == NULL) return;
    if (root->ltag == NORMAL) in_order(root->lchild);
    printf("%d ", root->data);
    if (root->rtag == NORMAL) in_order(root->rchild);
}

void clear(Node *root) {
    if (root == NULL) return;
    if (root->ltag == NORMAL) clear(root->lchild);
    if (root->rtag == NORMAL) clear(root->rchild);
    free(root);
    return;
}
int main() {
    srand(time(0));
    #define MAX_OP 20
    Node *root = NULL;
    for (int i = 0; i < MAX_OP; i ++) {
        int val = rand() % 100;
        root = insert(root, val);
    }

    build_thread(root);
    output(root), printf("\n");
    in_order(root), printf("\n");
    clear(root);
    return 0; 
}