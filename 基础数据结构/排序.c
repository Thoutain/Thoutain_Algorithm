/*
稳定排序
    插入排序 O(n^2) 基于比较跟交换

    冒泡排序 O(n^2) 

    归并排序 O(NlogN) 分治

不稳定排序
    选择排序

    快速排序
*/
#include <stdio.h>

#define swap(a, b) {\
    a ^= b;\
    b ^= a;\
    a ^= b;\
}

void insert_sort(int *num, int len) {
    for (int i = 1; i < n; i ++) {
        for (int j = i; j > 0 && num[j] < num[j - 1]; j --)
            swap(num[j], num[j - 1]);
    }
    return;
}

void bubble_sort(int *num, int len) {
    for (int i = 1; i < n; i ++) {
        for (int j = i; j < n; j ++)
    }
}

int main() {

    return 0;
}