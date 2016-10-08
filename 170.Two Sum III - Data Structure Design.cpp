class TwoSum {
public:
  unordered_multiset<int> m;
  // Add the number to an internal data structure.
	void add(int number) {
    m.insert(number);
	}

  // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
    for (auto const& v : m) {
      auto itr = m.find(value - v);
      if (itr != m.end() && (m.count(v) > 1 || itr != m.find(v))) return true;
    }
    return false;
	}
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);
