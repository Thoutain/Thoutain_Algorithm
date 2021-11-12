/*
完全二叉树
    
    左孩子2i 从1开始
    右孩子2i+1
    可以用连续空间存储（数组）

堆==优先队列 （数组实现，逻辑上看成一个堆）
    本质就是一棵完全二叉树
    大顶堆：根节点为所有节点的最大值
    小顶堆：根节点为所有节点的最小值
    任意三元组根节点都是极值
    第一大在根节点，第二在第二层，第三不确定  不适合解决top-k

    尾部插入
    头部弹出  弹出后从堆的尾部拿一个值作为新的根
    类似队列

堆排序
    利用堆每次头部弹出的都是极值
    将堆的根与尾结点交换即可（也是堆的头部弹出）
    大顶堆得出的是从小到大排序
    小顶堆得出的是从大到小排序
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b;\
    b = __temp;\
}

typedef struct priority_queue {
    int *data;
    int cnt; // 优先队列里面已经存在的元素的个数
    int size; // 当前优先队列的容量
} priority_queue;

priority_queue *init(int n) {
    priority_queue *q = (priority_queue *)malloc(sizeof(priority_queue));
    q->data = (int *)malloc(sizeof(int) * (n + 1));
    q->cnt = 0;
    q->size = n;
    return q;
}

int empty(priority_queue *q) {
    return q->cnt == 0;
}

int top(priority_queue *q) {
    return q->data[1];
}

int push(priority_queue *q, int val) {
    if (q == NULL) return 0;
    if (q->cnt == q->size) return 0;
    q->cnt += 1;
    q->data[q->cnt] = val;
    int index = q->cnt;
    while (index >> 1 && q->data[index] > q->data[index >> 1]) {
        swap(q->data[index], q->data[index >> 1]);
        index >>= 1;
    }
}

int pop(priority_queue *q) {
    if (q == NULL) return 0;
    if (empty(q)) return 0;
    q->data[1] = q->data[q->cnt --];
    int index = 1;
    while ((index << 1) <= q->cnt) {
        int tmp = index, l = index << 1, r = index << 1 | 1; // 偶数或上1就相当于加上1
        if (q->data[l] > q->data[tmp]) tmp = l;
        if (r <= q->cnt && q->data[r] > q->data[tmp]) tmp = r;
        if (tmp == index) break; // 不需要更新了
        swap(q->data[index], q->data[tmp]);
        index = tmp;
    }
    return 1;
}

void clear(priority_queue *q) {
    if (q == NULL) return;
    free(q->data);
    free(q);
    return;
}

// 线性建堆法  

void DownUpdate(int *arr, int n, int index) {
    while ((index << 1) <= n) {
        int tmp = index, l = index << 1, r = index << 1 | 1;
        if (arr[l] > arr[tmp]) tmp = l;
        if (r <= n && arr[r] > arr[tmp]) tmp = r;
        if (tmp == index) break; // 不需要更新了
        swap(arr[index], arr[tmp]);
        index = tmp;
    }
    return;
}

void heap_sort(int *arr, int n) {
    arr -= 1; // 技巧
    for (int i = n >> 1; i >= 1; i --) DownUpdate(arr, n, i);
    for (int i = n; i > 1; i --) {
        swap(arr[i], arr[1]);
        DownUpdate(arr, i - 1, 1);
    }
    return;
}

void output(int *arr, int n) {
    printf("[");
    for(int i = 0; i < 20; i ++) {
        i && printf (" ");
        printf("%d", arr[i]);
    }
    printf("]\n");
    return;
}

int main() {
    srand(time(0));
    #define MAX_OP 20
    priority_queue *q = init(MAX_OP);
    for (int i = 0; i < MAX_OP; i ++) {
        int val = rand() % 100;
        push(q, val);
        printf("insert %d to the priority_queue\n", val);
    }
    for (int i = 0; i < MAX_OP; i ++) {
        printf("%d ", top(q));
        pop(q);
    }
    printf("\n");
    #undef MAX_OP
    clear(q);

    int *arr = (int *)malloc(sizeof(int) * 20);
    for (int i = 0; i < 20; i ++) arr[i] = rand() % 100;
    output(arr, 20);
    printf ("\n");
    heap_sort(arr, 20);
    output(arr, 20);
    return 0;
}
// oj 284 287