// 顺序表：依靠连续的空间存储数据 一个元素挨着一个元素
// 链表：
    // 程序内部：依靠头指针记录一条完整的链表
    // 内存内部：数据区+指针域  结点的定义

// 插入操作
    // 注意要将插入点后面的部分连接起来  否则会发生内存泄漏

// 删除操作
    // 同样需要注意内存泄漏

// 单向链表
// 单向循环链表：把head看作整个单向循环链表的尾结点 尾部插入的时候注意调head
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct List {
    Node head; // 虚拟头结点
    int length;
} List;

Node *getNewNode(int val);
List *init_list();
int insert(List *l, int index, int val);
int erase(List *l, int index);
void clear_node(Node *node);
void clear(List *l);
void output(List *l);

Node *getNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->next = NULL;
    return p;
}

List *init_list() {
    List *l = (List *)malloc(sizeof(List));
    l->head.next = NULL;
    l->length = 0;
    return l;
}

int insert(List *l, int index, int val) {
    if (l == NULL) return 0;
    if (index < 0 || index > l->length) return 0;
    Node *p = (&l->head), *node = getNewNode(val);
    while (index --) p = p->next;
    // 此时指针p的位置在待插入的位置前一个位置
    node->next = p->next;
    p->next = node;
    l->length += 1;
    return 1;
}

int erase(List *l, int index) {
    if (l == NULL) return 0;
    if (index < 0 || index > l->length) return 0;
    Node *p = (&l->head), *q;
    while (index --) p = p->next;
    q = p->next;
    p->next = q->next;
    clear_node(q);
    l->length -= 1;
    return 1;
}

// 封装的原因是为了方便添加其他操作  结构复杂之后单单free满足不了需求
void clear_node(Node *node) {
    if (node == NULL)
        return;
    free(node);
    return;
}

void clear(List *l) {
    if (l == NULL)
        return;
    Node *p = l->head.next, *q;
    while (p != NULL) {
        q = p->next;
        clear_node(p);
        p = q;
    }
    free(l);
    return;
}

// 头插法reverse  需要虚拟头
void reverse(List *l) {
    if (l == NULL) return;
    Node *p = l->head.next, *q;
    l->head.next = NULL;
    while (p != NULL) {
        q = p->next;
        p->next = l->head.next;
        l->head.next = p;
        p = q;
    }
    return;
}

void output(List *l) {
    if (l == NULL) return;
    printf("List(%d) : ", l->length);
    for (Node *p = l->head.next; p != NULL; p = p->next) {
        printf("%d->", p->data);
    }
    printf("NULL\n");
}

int main() {
    srand(time(0));
    #define MAX_OP 20
    List *l = init_list();
    for (int i = 0; i < MAX_OP; i ++) {
        int op = rand() % 4;
        int val = rand() % 100;
        int index = rand() % (l->length + 3) - 1; 
        switch (op) {
            case 0 :
            case 1 : {
                printf("insert %d at %d to List = %d\n",val, index, insert(l, index, val));
            } break;
            case 2 : {
                printf("reverse the List!\n");
                reverse(l);
            } break;
            case 3 : {
                printf("erase an item at %d from Vector = %d\n", index, erase(l, index));
            } break;
        }
        output(l), printf("\n");
    }
    #undef MAX_OP
    clear(l);
    return 0;
}

// 思考
// http://oj.haizeix.com/problem/272
/*
题目描述
给定一个长度为 n 的序列 A，A 中的数各不相同。对于 A 中的每一个数 Ai，求：

min(1≤j<i)  |Ai−Aj|
以及令上式取到最小值的 j（记为 Pi）。若最小值点不唯一，则选择使 Aj 较小的那个。

输入
​ 第一行一个整数 n，第二行 n 个数 A1至An。

输出
​ n−1 行，每行 2 个用空格隔开的整数。分别表示当 i∈[2,n] 时，对应的 min(1≤j<i)  |Ai−Aj| 和 Pi 的值。

样例输入
3
1 5 3
样例输出
4 1
2 1
数据规模与约定
​ 时间限制：1 s

​ 内存限制：256 M

​ 100% 的数据保证 n≤105
*/