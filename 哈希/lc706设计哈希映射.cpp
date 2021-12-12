class MyHashMap {
public:
    const int N = 20011;

    vector<list<pair<int, int>>> hash;

    MyHashMap() {
        hash = vector<list<pair<int, int>>>(N);
    }
    
    list<pair<int, int>>::iterator find(int key) {
        int t = key % N;
        auto it = hash[t].begin();
        for (; it != hash[t].end(); it ++)
            if (it->first == key) break;
        return it;
    }

    void put(int key, int value) {
        int t = key % N;
        auto it = find(key);
        if (it == hash[t].end())
            hash[t].push_back(make_pair(key, value));
        else
            it->second = value;
    }
    
    int get(int key) {
        auto it = find(key);
        if (it == hash[key % N].end())
            return -1;
        return it->second;
    }
    
    void remove(int key) {
        int t = key % N;
        auto it = find(key);
        if (it != hash[t].end())
            hash[t].erase(it);
    }
};
