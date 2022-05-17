// https://leetcode.com/problems/design-hashmap/
// Time Complexity: O(N) For Element Chaining, Otherwise O(1)
// Space Complexity: O(N)

class MyHashMap {
	vector<list<pair<int, int>>> map;
	const int size = 10007;
public:
	MyHashMap() {
		map.resize(size);
	}

	void put(int key, int value) {
		int index = key % size;
        list<pair<int, int>> &row = map[index];
        
        for(auto it = row.begin(); it != row.end(); ++it)
        {
            if(it->first == key)
            {
                it->second = value;
                return;
            }
        }
        
		row.push_back(make_pair(key, value));
	}

	int get(int key) {
		int index = key % size;
        list<pair<int, int>> &row = map[index];
        
		for (auto it = row.begin(); it != row.end(); ++it)
		{
			if (it->first == key)
			{
				return it->second;
			}
		}
        
		return -1;
	}

	void remove(int key) {
		int index = key % size;
        list<pair<int, int>> &row = map[index];
        
		for (auto it = row.begin(); it != row.end(); ++it)
		{
			if (it->first == key)
			{
				row.erase(it);
                return;
			}
		}
	}
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */