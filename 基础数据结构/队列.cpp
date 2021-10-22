// FIFO first in first out
// 线性结构
// length head tail data_type
// 设计的时候队尾是指向最后一个元素还是其下一个位置？
// 队列的假溢出 tail指针不能往后走了但队列没满
    // 循环队列 取余运算 滑动数组\滚动数组
    // 这时候加一个count作计数器  记录实际元素的数量 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define GREEN(a) COLOR(a, 32)

typedef struct Queue {
    int *data; // storage
    int length;
    int head, tail; 
    int count;
} Queue;

Queue *init(int n) {
    // 两次申请空间
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (int *)malloc(sizeof(int) * n); 
    q->length = n;
    q->head = q->tail = 0;
    q->count = 0;
    return q;
}

int empty(Queue *q) {
    return q->count == 0;
}

int front(Queue *q) {
    return q->data[q->head];
}

int expand(Queue *q) {
    int *p = NULL;
    int _size = q->length;
    while (_size) { // 循环扩容
        p = (int *)malloc(sizeof(int) * (q->length + _size));
        if (p != NULL) break;
        _size >>= 1;
    }
    if (p == NULL) return 0;
    for (int i = q->head, j = 0; j < q->count; j ++)
        p[j] = q->data[(i + j) % q->length];
    free(q->data);
    q->data = p;
    q->head = 0, q->tail = q->count;
    q->length += _size;
    return 1;
}

int push(Queue *q, int val) {
    if (q == NULL) return 0;
    if (q->count == q->length) {
        if (expand(q) == 0)
            return 0;
        printf(GREEN("succeed in expanding to %d\n"), q->length);
    }
    q->data[q->tail ++] = val;
    if (q->tail == q->length) q->tail = 0;
    q->count += 1;
    return 1;
}

int pop(Queue *q) { 
    if (q == NULL) return 0;
    if (empty(q)) return 0;
    q->head ++;
    if (q->head == q->length) q->head = 0;
    q->count --;
    return 1;
}

void clear(Queue *q) {
    if (q == NULL) return;
    free(q->data);
    free(q);
    return;
}

void output(Queue *q) {
    printf("Queue : [");
    for (int i = q->head, j = 0; j < q->count; j ++) {
        j != 0 && printf(" ");
        printf("%d", q->data[(i + j) % q->length]);
    }
    printf("]\n");
    return;
}

int main() {
    srand(time(0));
    #define MAX_OP 20
    Queue *q = init(5);
    for (int i = 0; i < MAX_OP; i ++) {
        int op = rand() % 4;
        int val = rand() % 100;
        // int index = rand() % (v->length + 1); 
        int index = rand() % (q->length + 3) - 1; // index的范围更全面
        switch (op) { // 提高插入命中率
            case 0 :
            case 1 :
            case 2 : {
                printf("push %d to Queue = %d\n",val, push(q, val));
            } break;
            case 3 : {
                if (empty(q)) {
                    printf("fail to pop an item!\n");
                } else {
                    printf("success to pop an item : %d\n", front(q));
                    pop(q);
                }
            } break;
        }
        output(q), printf("\n");
    }
    #undef MAX_OP
    clear(q); 
    return 0;
}