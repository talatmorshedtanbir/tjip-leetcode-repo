//Time Complexity - O(1)
//Space Complexity - O(N)

class RandomizedSet {
public:
    RandomizedSet() {
    }

    bool insert(int val) {
        if(mapValues.count(val) == 0) {
            values.push_back(val);
            mapValues[val] = values.size() - 1;

            return true;
        }

        return false;
    }

    bool remove(int val) {
        if(mapValues.count(val) != 0) {
            int index = mapValues[val];
            values[index] = values[values.size()-1];
            values.pop_back();
            mapValues[values[index]] = index;
            mapValues.erase(val);

            return true;
        }

        return false;
    }

    int getRandom() {
        return values[rand() % values.size()];
    }

private:
    vector<int> values;
    unordered_map<int, int> mapValues;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */