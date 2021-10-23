// 顺序表
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define GREEN(a) COLOR(a, 32)

// vector容量是size   已经有的最后一个元素的后一个下标，就是元素数量
typedef struct Vector {
    int *data;
    int size, length;
} Vector;

// 初始化
Vector *init(int n) {
    Vector *v = (Vector *)malloc(sizeof(Vector));
    v->data = (int *)malloc(sizeof(int) * n);
    v->size = n;
    v->length = 0;
    return v;
}

// 扩容
// malloc 申请
// calloc 申请并初始化为0
// realloc 重新分配内存 先看能不能在原有空间后面加，可以的话返回的是原地址
                        // 否则重新申请空间 并将原来空间的数据拷贝到新空间 并销毁原空间
                        // 失败返回空地址
int expand(Vector *v) {
    // 直接这么写会有内存泄漏的问题
    // v->data = (int *)realloc(v->data, sizeof(int) * (v->size * 2));
    // v->size <<= 1;
    int extr_size = v->size;
    int *p = NULL;
    while (extr_size) {
        p = (int *)realloc(v->data, sizeof(int) * (v->size + extr_size));
        if (p != NULL)  // 扩容成功
            break;
        // 申请失败的话试着申请少一点
        extr_size >>= 1; 
    }
    if (p == NULL) return 0; // 不确定是怎么跳出循环的
    v->data = p;
    v->size += extr_size;
    return 1;
}

// 插入元素
int insert(Vector *v, int index, int val) {
    if (v == NULL) return 0;
    if (v->length == v->size - 1) { // 扩容
        if (!expand(v))
            return 0;
        printf(GREEN("success to expand! the size = %d\n"), v->size);
    }
    if (index < 0 || index > v->length) return 0;
    for (int i = v->length; i > index; i --) {
        v->data[i] = v->data[i - 1];
    }
    v->data[index] = val;
    v->length += 1;
    return 1;
}

// 删除
int erase(Vector *v, int index) {
    if (v == NULL) return 0;
    if (index < 0 || index >= v->length) return 0;
    for (int i = index + 1; i < v->length; i ++) {
        // 避免访问越界
        v->data[i - 1] = v->data[i];
    }
    v->length -= 1;
    return 1;
}

// 清空
void clear(Vector *v) {
    if (v == NULL) return;
    free(v->data);
    free(v);
    return;
}

// 输出
void output(Vector * v) {
    if (v == NULL) return;
    printf("Vector : [");
    for (int i = 0; i < v->length; i ++) {
        i && printf(" ");
        printf("%d", v->data[i]);
    }
    printf("]\n");
}

int main() {
    srand(time(0));
    #define MAX_OP 20
    Vector *v = init(1);
    for (int i = 0; i < MAX_OP; i ++) {
        int op = rand() % 4;
        int val = rand() % 100;
        // int index = rand() % (v->length + 1); 
        int index = rand() % (v->length + 3) - 1; // index的范围更全面
        switch (op) { // 提高插入命中率
            case 0 :
            case 1 :
            case 2 : {
                printf("insert %d at %d to Vector = %d\n",val, index, insert(v, index, val));
            } break;
            case 3 : {
                printf("erase an item at %d from Vector = %d\n", index, erase(v, index));
            } break;
        }
        output(v), printf("\n");
    }
    #undef MAX_OP
    clear(v); 
    return 0;
}

// 顺序表存满之后怎么删  所谓的删除是逻辑上的  实际上可能并没有删除或者覆盖
// 内存泄漏是怎样的？？ 用不了，操作系统还不能回收
    // 析构  虚析构
    // 程序运行是内部要主动free
// realloc只有申请成功后才会释放原来的数据