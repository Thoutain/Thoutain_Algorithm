class CQueue {
public:
    stack<int> p, q;
    CQueue() {
        while (!p.empty())
            p.pop();
        while (!q.empty())
            q.pop();
    }
    
    void appendTail(int value) {
        q.push(value);
    }
    
    int deleteHead() {
        if (p.empty()) {
            while (!q.empty()) {
                p.push(q.top());
                q.pop();
            }
        }
        if (p.empty())
            return -1;
        else {
            int t = p.top();
            p.pop();
            return t;
        }
            
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */