### BFS
#### 算法
(BFS) O(nm)O(nm)
这是一个典型的宽度优先搜索问题，我们从 (0, 0) 点开始，每次朝上下左右四个方向扩展新的节点即可。

扩展时需要注意新的节点需要满足如下条件：

之前没有遍历过，这个可以用个bool数组来判断；
没有走出边界；
横纵坐标的各位数字之和小于 kk；
最后答案就是所有遍历过的合法的节点个数。

#### 时间复杂度
每个节点最多只会入队一次，所以时间复杂度不会超过方格中的节点个数。
最坏情况下会遍历方格中的所有点，所以时间复杂度就是 O(nm)O(nm)。

#### C++代码
```C++
class Solution {
public:

    int get_sum(pair<int, int> p) {
        int s = 0;
        while (p.first) {
            s += p.first % 10;
            p.first /= 10;
        }
        while (p.second) {
            s += p.second % 10;
            p.second /= 10;
        }
        return s;
    }

    int movingCount(int threshold, int rows, int cols)
    {
        if (!rows || !cols) return 0;
        queue<pair<int,int>> q;
        vector<vector<bool>> st(rows, vector<bool>(cols, false));

        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

        int res = 0;
        q.push({0, 0});
        while (q.size()) {
            auto t = q.front();
            q.pop();
            if (st[t.first][t.second] || get_sum(t) > threshold) continue;
            res ++ ;
            st[t.first][t.second] = true;
            for (int i = 0; i < 4; i ++ ) {
                int x = t.first + dx[i], y = t.second + dy[i];
                if (x >= 0 && x < rows && y >= 0 && y < cols) q.push({x, y});
            }
        }

        return res;
    }
};

```