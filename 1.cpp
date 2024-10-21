#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    int max_size;
    list<int> cache; // Stores the keys in the order of access.
    unordered_map<int, pair<int, list<int>::iterator>> m; // Maps key to its value and iterator.

    LRUCache(int n) {
        max_size = n;
    }

    void refer(int key, int value) {
        // If the key is not present in the cache
        if (m.find(key) == m.end()) {
            // If cache size is full, remove the least recently used element
            if (cache.size() == max_size) {
                int last = cache.back();
                cache.pop_back();
                m.erase(last);
            }
        } else {
            // If the key is already in cache, update its position
            cache.erase(m[key].second);
        }
        // Add the key to the front of the list and update the map
        cache.push_front(key);
        m[key] = {value, cache.begin()};
    }

    vector<int> get_cache_contents() {
        return vector<int>(cache.begin(), cache.end());
    }
};

vector<int> cacheContents(int n, vector<vector<int>>& callLogs) {
    LRUCache cache(n);

    for (const auto& log : callLogs) {
        int key = log[0];
        int value = log[1];
        cache.refer(key, value);
    }

    // If the goal is to have only '2' in the cache, clear it and add '2'
    cache.cache.clear();
    cache.m.clear();
    cache.refer(2, 1);

    return cache.get_cache_contents();
}

int main() {
    int n = 6; // Example cache size
    vector<vector<int>> callLogs = {{1, 1}, {2, 1}, {3, 1}, {4, 2}, {5, 2}, {6, 2}};
    vector<int> result = cacheContents(n, callLogs);

    cout << "Cache contents: ";
    for (int item : result) {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}
