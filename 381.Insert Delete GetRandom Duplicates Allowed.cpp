typedef unordered_multimap<int, int> IMap;
typedef IMap::iterator IMAPI;
typedef vector<IMAPI> IVec;

class RandomizedCollection {
private:
  IMap m;
  IVec v;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        srand(NULL);
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        bool r = m.find(val) == m.end() ? true : false;
        v.push_back(m.insert(make_pair(val, v.size())));
        return r;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto itr = m.find(val);
        if (itr == m.end()) return false;
        if (itr->second + 1 != v.size()) {
            v.back()->second = itr->second;
            v[itr->second] = v.back();
        }
        v.pop_back();
        m.erase(itr);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return v[rand() % v.size()]->first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
