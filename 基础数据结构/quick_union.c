/*
题目描述
​   所谓一个朋友圈子，不一定其中的人都互相直接认识。

​   例如：小张的朋友是小李，小李的朋友是小王，那么他们三个人属于一个朋友圈。

​   现在给出一些人的朋友关系，人按照从 1 到 n 编号在这中间会进行询问某两个人是否属于一个朋友圈，请你编写程序，实现这个过程。

输入
    第一行输入两个整数 n,m(1≤n≤10000，3≤m≤100000)，分别代表人数和操作数。

    接下来 m 行，每行三个整 a,b,c（a∈[1,2], 1≤b,c≤n）
    当 a=1 时，代表新增一条已知信息，b,c 是朋友
    当 a=2 时，代表根据以上信息，询问 b,c 是否是朋友
输出
    对于每个 a=2 的操作，输出『Yes』或『No』代表询问的两个人是否是朋友关系。

6 5
1 1 2
2 1 3
1 2 4
1 4 3
2 1 3

No
Yes
*/
// 实际中直接路径压缩就好了  不用按秩压缩
#include <stdio.h>
#include <stdlib.h>

typedef struct UnionSet {
    int *father, *size;
    int n;
} UnionSet;

UnionSet *init(int n) {
    UnionSet *u = (UnionSet *)malloc(sizeof(UnionSet));
    u->father = (int *)malloc(sizeof(int *) * (n + 1));
    u->size = (int *)malloc(sizeof(int *) * (n + 1));
    u->n = n;
    for (int i = 1; i <= n; i ++) {
        u->father[i] = i;
        u->size[i] = 1;
    }
    return u;
}

// 路径压缩
int find(UnionSet *u, int x) {
    if (u->father[x] == x) return x;
    return u->father[x] = find(u, u->father[x]);
}

// 将颜色为a的点与改为颜色b  使a、b相连
int merge(UnionSet *u, int a, int b) {
    int fa = find(u, a);
    int fb = find(u, b);
    if (fa == fb) return 0;
    if (u->size[fa] < u->size[fb]) {
        int tmp = fa;
        fa = fb;
        fb = tmp;
    }
    u->father[fb] = fa;
    u->size[fa] += u->size[fb];
    return 1;
}

void clear(UnionSet *u) {
    if (u == NULL) return;
    free(u->father);
    free(u->size);
    free(u);
    return;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    UnionSet *u = init(n);
    for (int i = 0; i < m; i ++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        switch(a) {
            case 1: merge(u, b, c); break;
            case 2: printf("%s\n", find(u, b) == find(u, c) ? "Yes" : "No"); break;
        }
    }
    clear(u);
    return 0;
}