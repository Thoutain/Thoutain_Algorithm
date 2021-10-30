/*
节点与边之间的关系

前序、中序、后序遍历

二叉树-广义表

广义表-二叉树
    栈
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node *lchild, *rchild;
} Node;

typedef struct Tree  {
    Node *root;
    int length;
} Tree;

typedef struct Stack {
    Node **data;
    int top, size;
} Stack;

Node *getNewNode(char val) {
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

Stack *init_stack(int n) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (Node **)malloc(sizeof(Node *) * n);
    s->top = -1;
    s->size = n;
    return s;
}

Node *top(Stack *s) {
    return s->data[s->top];
}

int empty(Stack *s) {
    return s->top == -1;
}

int push(Stack *s, Node *val) {
    if (s == NULL) return 0;
    if (s->top == s->size - 1) return 0;
    s->data[++(s->top)] = val;
    return 1;
}

int pop(Stack *s) {
    if (s == NULL) return 0;
    if (empty(s)) return 0;
    s->top -= 1;
    return 1;
}

void clear_stack(Stack *s) {
    if (s == NULL) return;
    free(s->data);
    free(s);
    return;
}

void clear_node(Node *node) {
    if (node == NULL) return;
    clear_node(node->lchild);
    clear_node(node->rchild);
    free(node);
    return;
}

void clear_tree(Tree *tree) {
    if (tree == NULL) return;
    clear_node(tree->root);
    free(tree);
    return;
}

Node *build(const char *str, int *node_num) {
    Stack *s = init_stack(strlen(str));
    int flag = 0;
    Node *tmp = NULL, *p = NULL;
    while (str[0]) {
        switch(str[0]) {
            case '(' : {
                push(s, tmp);
                flag = 0;
            } break;
            case ')' : {
                p = top(s);
                pop(s);
            } break;
            case ',' : flag = 1; break;
            case ' ' : break;
            default : 
                tmp = getNewNode(str[0]);
                if (!empty(s) && flag == 0) {
                    top(s)->lchild = tmp;
                } else if (!empty(s) && flag == 1) {
                    top(s)->rchild = tmp;
                }
                ++(*node_num);
                break;
        } 
        str ++;
    }
    clear_stack(s);
    if (tmp && p == NULL) p = tmp;
    return p;
}

void pre_order_node(Node *root) {
    if (root == NULL) return;
    printf("%c ", root->data);
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
    printf("%c ", root->data);
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
    printf("%c ", root->data);
    return;
}

void post_order(Tree *tree) {
    if (tree == NULL) return;
    printf("post_order : ");
    post_order_node(tree->root);
    printf("\n");
    return;
}

int main() {
    char str[1000] = {0};
    int node_num = 0;
    scanf("%[^\n]s", str);
    getchar();
    Tree *tree = getNewTree();
    tree->root = build(str, &node_num);
    tree->length = node_num;
    // test build
    pre_order(tree);
    in_order(tree);
    post_order(tree);
    clear_tree(tree);

    return 0;
}
