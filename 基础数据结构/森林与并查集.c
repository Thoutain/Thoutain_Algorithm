/*
解决具有连通性关系的问题

quick_find算法
    联通判断O（1）
    合并操作O（n）

quick_union
    联通判断：tree-height
    合并操作：tree-height

    问题思考
        1.极端情况下会退化成一条链
        2.将节点数量多的接到少的树上面，导致了退化
        3.将树高深的接到浅的上面，导致了退化

    随堂思考
        若要改进，是按照节点数量还是按照树的高度为合并参考

weighted_quick_union
    优化：路径压缩 参考quick_find
*/