/*
计算机里的树和现实中的树方向相反

节点 + 边
节点：可以表示为集合
边：关系，集合与集合的关系
根节点：全集
……子集
一对多
树的深度(高度)是根节点开始向下遍历，最长路径的节点个数就是树的深度(高度)
节点的深度：从根节点到该节点
节点的高度：从该节点向下遍历最长路径的节点数
节点的度：从该节点向外有多少边的指向
节点数量 = 边数 + 1  // 等式很重要

二叉树：
    每个节点度最多为2
    度为0的节点比度为2的节点多一个（节点数量 = 边数 + 1）

    
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    // struct Node *next[3]; 三叉树
    struct Node *left;
    struct Node *right;
} Node, *Tree;