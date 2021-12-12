class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> heap; // 小根堆
    int kk;
    KthLargest(int k, vector<int>& nums) {
        kk = k;
        for (int x : nums) {
            heap.push(x);
            if (heap.size() > k) heap.pop();
        }
    }
    
    int add(int val) {
        heap.push(val);
        if (heap.size() > k) heap.pop();
        return heap.top();
    }
};