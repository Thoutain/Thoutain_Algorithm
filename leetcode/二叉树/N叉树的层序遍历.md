**right answer**
```C++
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> que;
        vector<vector<int>> vec;
        if (root)
        {
            que.push(root);
        }
        while (!que.empty())
        {
            int size = que.size();
            vector<int> tmp;
            for (int i = 0; i < size; i ++)
            {
                Node *node = que.front();
                que.pop();
                tmp.push_back(node -> val);

                for (int j = 0; j < node -> children.size(); j ++)
                {
                    if (node -> children[j])
                    {
                        que.push(node -> children[j]);
                    }
                }
            }
            vec.push_back(tmp);
        }
        return vec;
    }
};
```

**wrong answer**
```C++
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    vector<vector<int>> vec;
    void travel(Node *root)
    {
        int st = 0;
        if (root)
        {
            for (int i = 0; i < root -> children.size(); i++)
            {
                vec[st].push_back(root -> val);
                travel(root -> children[i]);
            }
        }
    }
public:
    vector<vector<int>> levelOrder(Node* root) {
        travel(root);
        return vec;
    }
};
```
