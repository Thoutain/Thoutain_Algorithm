#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b;\
    b = __temp;\
}

// 单边递归
void quick_sort(int *num, int l, int r) {
    while (l < r) {
        int x = l, y = r, z = num[(l + r) >> 1];
        do {
            while (num[l] < z) x ++;
            while (num[r] > z) y --;
            if (x <= y) {
                swap(num[x], num[y]);
            } 
        } while (x <= y);
        quick_sort(num, l, y);
        l = x;
    }
    return;
}

// 二分查找
// 注意边界条件
// 最后一个1， 第一个0  虚拟前地址

// 三分查找
// 解决凸函数的极值点
/*
[L, R]是查找范围
m1是[L, R]的三分之一处
m2是[L，R]的三分之二处

if (f[m1] < f[m2]) l = m1;
if (f[m2] <= f[m1]) R = m2;
if (|m1 - m2| < exp) res;

练习：输入a，b，c三个整数，求解下列方程的极值点
    ax^2 + bx + c
*/

int binary_search(int *arr, int n, int x) {
    int l  = 0;
    int r = n - 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (arr[mid] < x) l = mid + 1;
        if (arr[mid] > x) r = mid - 1;
        else return mid;
    }
    return -1;
}

// 000000000000001111111111找第一个1
int binary_search1(int *arr, int n) {
    int l = 0;
    int r = n - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (arr[mid] == 1) r = mid;
        else l = mid + 1;
    }
    return l == n ? -1 : l;
}

// 111111111111111110000000000找最后一个1
int binary_search2(int *arr, int n) {
    int l = -1;
    int r = n - 1;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (arr[mid] == 1) l = mid;
        else r = mid - 1;
    }
    return l;
}

// 哈希表
// 哈希函数 冲突处理
/*
数组：int类型下标映射到任意元素

哈希表：任意类型下标映射到任意元素
    将类类型映射到整型  再由整型做下标去得到最后的值
    size  data_type
    哈希函数用来做映射
    冲突处理：1.开放定值法
             2.拉链法 加一个链表
             3.再哈希（散列）多个哈希函数
             4.建立公共溢出区  专门存储冲突的数据

    BKDRHash APHash
*/

typedef struct Node {
    char *str;
    struct Node *next;
} Node;

typedef struct HashTable {
    Node **data;
    int size;
} HashTable;

Node *init_node(char *str, Node *head) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->str = strdup(str);
    p->next = head;
    return p;
}

HashTable *init_hashtable(int n) {
    HashTable *h = (HashTable *)malloc(sizeof(HashTable));
    h->size = n << 1;
    h->data = (Node **)calloc(h->size, sizeof(Node *));
    return h;
}

int BKDRHash(char *str) {
    int seed = 31;
    int hash = 0;
    for (int i = 0; str[i]; i ++)
        hash = hash * seed + str[i];
    return hash & 0x7fffffff;
}

int insert(HashTable *h, char *str) {
    int hash = BKDRHash(str);
    int index = hash % h->size;
    h->data[index] = init_node(str, h->data[index]);
}

int search(HashTable *h, char *str) {
    int hash = BKDRHash(str);
    int index = hash % h->size;
    Node *p = h->data[index];  
    while (p && strcmp(p->str, str)) p = p->next;
    return p != NULL;
}

void clear_node(Node *node) {
    if (node == NULL) return;
    Node *p = node, *q;
    while (p) {
        q = p->next;
        free(p->str);
        free(p);
        p = q;
    }
    return;
}

void clear(HashTable *h) {
    if (h == NULL) return;
    for (int i = 0; i < h->size; i ++) {
        clear_node(h->data[i]);
    }
    free(h->data);
    free(h);
    return;
}

int main() {
    int op;
    #define MAX_N 100
    char str[MAX_N + 5] = {0};
    HashTable *h = init_hashtable(MAX_N + 5);
    while (~scanf("%d%s", &op, str)) {
        switch (op) {
            case 0:
                printf("insert %s to HashTable\n", str);
                insert(h, str);
                break;
            case 1:
                printf("search %s from HashTable result = %d\n", str, search(h, str));
                break;
        } 
    }
    #undef MAX_N
    clear(h);
    return 0;
}