typedef unordered_set<int> IMap;

class RandomizedSet {
private:
  IMap m;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(NULL);
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (m.find(val) != m.end()) return false;
        m.insert(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (m.find(val) == m.end()) return false;
        m.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return *next(m.begin(), rand() % m.size());
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
