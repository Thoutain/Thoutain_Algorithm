// 递归 系统栈
// size top data_type
// FILO LIFO
// 单调栈 临近最值
// 单调队列 区间最值
// 栈 树的深度遍历、深度优先搜索dfs
// 队列(循环) 树的层序遍历、广度优先搜索bfs
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define GREEN(a) COLOR(a, 32)

typedef struct Stack {
    int *data;
    int top, size;
} Stack;

Stack *init(int n) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (int *)malloc(sizeof(int) * n);
    s->size = n;
    s->top = -1;
    return s;
}

int empty(Stack *s) {
    return s->top == -1;
}

int top(Stack *s) {
    return s->data[s->top];
}

int expand(Stack *s) {
    int _size = s->size;
    int *p;
    while (_size) {
        p = (int *)realloc(s->data, sizeof(int) * (s->size + _size));
        if (p != NULL) break;
        _size >>= 1;
    }

    if (p == NULL) return 0;
    s->data = p;
    s->size += _size;
    return 1;
}

int push(Stack *s, int val) {
    if (s == NULL) return 0;
    if (s->top == s->size - 1) {
        if (!expand(s)) return 0;
        printf(GREEN("success to expand the size to %d\n"), s->size);
    }
    s->data[++ (s->top)] = val;
    return 1;
}

int pop(Stack *s) {
    if (s == NULL) return 0;
    if (empty(s)) return 0;
    s->top -= 1;
    return 1;
}

void clear(Stack *s) {
    if (s == NULL) return;
    free(s->data);
    free(s);
    return;
}

void output(Stack *s) {
    if (s == NULL) return;
    printf("Stack : [");
    for (int i = 0; i <= s->top; i ++) {
        i && printf(" ");
        printf("%d", s->data[i]);
    }
    printf("]\n");
}
int main() {
    srand(time(0));
    #define MAX_OP 20
    Stack *s = init(1);
    for (int i = 0; i < MAX_OP; i ++) {
        int op = rand() % 4;
        int val = rand() % 100;
        switch (op) { // 提高插入命中率
            case 0 :
            case 1 :
            case 2 : {
                printf("push %d to Stack = %d\n",val, push(s, val));
            } break;
            case 3 : {
                if (empty(s)) {
                    printf("fail to pop an item!\n");
                } else {
                    printf("success to pop an item : %d\n", top(s));
                    pop(s);
                }
            } break;
        }
        output(s), printf("\n");
    }
    #undef MAX_OP
    clear(s); 
    return 0;
}